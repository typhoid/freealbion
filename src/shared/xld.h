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
#include "types.h"

#ifndef XLD_H
#define XLD_H

	/*
	 * XLD archive file header.
	 */
	typedef struct {
		uint32_t magic;			/* magic number / file type signature */
		uint16_t version;		/* version number */
		uint16_t entries;		/* number of entries in this archive */
	} XldHeader;

	typedef struct {
		FILE *fp;				/* archive file pointer */
		XldHeader	header;		/* file header */
		ulong_t		*lengths;	/* array of entry lengths */
		uint16_t	entryIndex;	/* points to the next available entry */
	} XldArchive;

	typedef struct {
		uint16_t	index;		/* position within the file */
		ulong_t		offset;		/* location within the file */
		ulong_t		length;		/* length of the stored data */
	} XldEntry;

	/*
	 * Open the archive and read the header information, including the entry table.
	 */
	XldArchive*		XldOpen				(const char *filename);

	/*
	 * Close archive file and release internally allocated resources.
	 */
	void			XldClose			(XldArchive *archive);

	/*
	 * Read a specific entry from the archive.
	 */
	XldEntry*		XldGetEntry			(uint16_t index, XldArchive *archive, XldEntry *buffer);

	/*
	 * Reads the specified entry into a data buffer.
	 */
	uchar_t*		XldGetEntryData		(uint16_t index, XldArchive *archive, uchar_t *buffer);

	/*
	 * Read the next entry in the archive.
	 */
	XldEntry*		XldGetNextEntry		(XldArchive *archive, XldEntry *buffer);

#endif