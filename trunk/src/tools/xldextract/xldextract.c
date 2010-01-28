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

/*
 *
 * TODO: output filename should be more configurable
 */

#include <stdio.h>
#include <string.h>
#include "../../shared/types.h"
#include "../../shared/xld.h"

/*
 * Dump data buffer to disk file.
 */
static int SaveToFile(const char *filename, ulong_t length, uchar_t *data) {

	FILE *fp = fopen(filename, "wb");

	if (!fp) {
		return EXIT_FAILURE;
	} else {
		fwrite(data, length, 1, fp);
		fflush(fp);
		fclose(fp);
		return EXIT_SUCCESS;
	}

} //

static void Usage(int argc, const char *argv[]) {
	fprintf(stderr, "usage: %s <archive> <extension> <directory>\n\n", argv[0]);
}

int main(int argc, const char* argv[])
{
	XldArchive *xld;
	XldEntry	entry;
	uchar_t		data[20*1024];	// NGR: Not happy about using a static size, but also not happy about having a huge memory buffer
	char		filename[255];
	int			index;
	int			verbose = 0;

	const char 	*source;
	const char	*extension;
	const char 	*directory;
			char *tmp;
	fprintf(stdout, "\n");
	fprintf(stdout, "XLD Extraction Utility\n");
	fprintf(stdout, "Copyright (c)2010 FreeAlbion project.\n\n");

	if (argc < 4) {
		// needs more parameters
		Usage(argc, argv);
		return EXIT_FAILURE;
	} else {
		directory = argv[3];
		extension = argv[2];
		source = argv[1];
	}

	xld = XldOpen(source);

	if (xld != NULL) {

		fprintf(stdout, "%d entries in archive. Extracting...\n\n", xld->header.entries);

		index = 0 ;

		while (NULL != XldGetNextEntry(xld, &entry)) {

			index++;

			sprintf(filename, "%s/out%d.%s", directory, index, extension);

			if (verbose) {
				fprintf(stdout, "extracting entry %d\n", index);
				fprintf(stdout, "\toffset: %d\n", entry.offset);
				fprintf(stdout, "\tlength: %d\n", entry.length);

				//fprintf(stdout, "Extracting entry %d to %s\n", index, strrchr(filename, '/') + 1);
			}

			if (XldGetEntryData(entry.index, xld, data) != NULL) {

				if (SaveToFile(filename, entry.length, data) != EXIT_SUCCESS) {
					fprintf(stderr, "error: unable to extract entry %d to file '%s'.\n", index, filename);
				}

			} else {
				fprintf(stderr, "error: unable read data for entry %d from archive.\n", index);
			}

		}

		fprintf(stdout, "Extraction complete.\n\n");

	} else {
		fprintf(stderr, "error: unable to open archive.\n\n");
	}

	XldClose(xld);

	return EXIT_SUCCESS;
}

