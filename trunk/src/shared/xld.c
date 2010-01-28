/*
Copyright (C) 2010 Neil Ramsbottom

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include "types.h"
#include "xld.h"

static uint32_t XldGetBaseOffset(XldArchive *archive);
static uint32_t XldGetEntryOffset(uint16_t entryIndex, XldArchive *archive);
static uint32_t XldGetEntryLength(uint16_t entryIndex, XldArchive *archive);

/*
 * Open the archive and read the header information, including the entry table.
 */
XldArchive* XldOpen(const char *filename) {

	XldArchive *archive = (XldArchive*)malloc(sizeof(XldArchive));
	int index;

	memset(archive, 0, sizeof(XldArchive));

	if ( (archive->fp = fopen(filename, "rb")) != NULL ) {
		// read the header
		if ( fread(&archive->header, 1, sizeof(XldHeader), archive->fp) == sizeof(XldHeader)) {

			// allocate memory for entry length data
			archive->lengths = (ulong_t*)malloc(sizeof(ulong_t)*archive->header.entries);

			// read in the lengths of the files, stored as long integers
			fread(archive->lengths, sizeof(ulong_t), archive->header.entries, archive->fp);

		} else {
			// unable to read the header.
			free(archive);
			archive = NULL;
		}

		return archive;

	} else {
		free(archive);
		return NULL;
	}
}

/*
 * Close archive file and release internally allocated resources.
 */
void XldClose(XldArchive *archive) {
	if (archive != NULL) {
		if (archive->fp)
			fclose(archive->fp);
		if (archive->lengths)
			free(archive->lengths);
	}
} // XldClose

/*
 * Read a specific entry from the archive.
 */
XldEntry* XldGetEntry (uint16_t index, XldArchive *archive, XldEntry *entry) {

	assert(archive != NULL);
	assert(entry != NULL);
	assert(index < archive->header.entries);

	entry->offset = XldGetEntryOffset(index, archive);
	entry->length = XldGetEntryLength(index, archive);
	entry->index = index;

	return entry;
}

/*
 * Reads the specified entry into a data buffer.
 */
uchar_t* XldGetEntryData (uint16_t index, XldArchive *archive, uchar_t *buffer) {

	XldEntry entry;

	assert(archive != NULL);
	assert(index >= 0);
	assert(index < archive->header.entries);
	assert(buffer != NULL);

	if (XldGetEntry(index, archive, &entry) != NULL) {

		fseek(archive->fp, entry.offset, SEEK_SET);

		// read data into bufffer
		fread(buffer, sizeof(uchar_t), entry.length, archive->fp);

		return buffer;

	} else {
		return NULL;
	}

} //

/*
 * Read the next entry in the archive.
 */
XldEntry* XldGetNextEntry(XldArchive *archive, XldEntry *buffer) {

	assert(archive != NULL);
	assert(buffer != NULL);

	if (archive->entryIndex < archive->header.entries) {

		if (XldGetEntry(archive->entryIndex, archive, buffer) == NULL) {
			return NULL;
		} else {
			archive->entryIndex++;
			return buffer;
		}
	} else {
		return NULL;
	}

} //

/*
 * Calculate the absolute offset that the entry data starts within the archive.
 */
static ulong_t XldGetEntryOffset(uint16_t entryIndex, XldArchive *archive) {

	ulong_t	offset = XldGetBaseOffset(archive);
	int		index = 0;

	for (index=0;index<entryIndex;index++)
		offset += archive->lengths[index];

	return offset;
} //

/*
 * Determine the length of the specified entry data.
 */
static ulong_t XldGetEntryLength(uint16_t entryIndex, XldArchive *archive) {
	return archive->lengths[entryIndex];
} //

/*
 * Calculate the length of the archive header.
 */
static ulong_t XldGetBaseOffset(XldArchive *archive) {
	// size of the header plus the length of the lengths table.
	return sizeof(XldHeader) + (archive->header.entries * sizeof(ulong_t));
} //