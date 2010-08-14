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
#include <string.h>
#include "types.h"
#include "utils.h"
#include "systexts.h"

/*
 * Stores a list of all systexts.
 */
systext *texts = NULL;

/*
 * Append a systext onto the internal list.
 */
static void append_systext(systext *text) {
	
	systext *t = texts;

	if (t == NULL) {
		texts = text;
		texts->next = NULL;
	} else {
		while (t->next != NULL) {
			t = t->next;
		}
		t->next = text;
		text->next = NULL;
	}
}

/*
 *
 */
int InitSysTexts() {

	FILE *fp;
	uchar_t		filename[128];
	uchar_t		buffer[ALBION_MAX_SYSTEXT];
	char *start;
	char *sep, *end;
	uchar_t		idbuffer[6];

	systext *t;

	sprintf(filename, "%s\\%s", "ENGLISH", "SYSTEXTS");

	fp = fopen(filename, "rb");

	if (!fp)
		return EXIT_FAILURE;

	memset(buffer, 0, ALBION_MAX_SYSTEXT);
	memset(idbuffer, 0, 6);

	while ( NULL != fgets(buffer, ALBION_MAX_SYSTEXT, fp) )
	{

		/* process non-blank lines that begin with a brace */
		if (strlen(buffer) > 0 && buffer[0] == '[') {
			
			start = buffer;
			sep = strchr(start, ':');		/* find the colon character */
			end = strrchr(buffer, ']');		/* find the end brace */

			/* found seperator */
			if (sep) {

				/* dont include seperator in text */
				++sep; 

				/* filter out blank strings */
				if ( (end - sep) == 0)
					continue;

				/* copy text into newly allocated buffer */
				t = (systext*)malloc(sizeof(systext));
				t->text = (uchar_t*)malloc((end-sep) + 1);
				substring(t->text, sep, 0, end - sep);

				/* copy the id into structure */
				substring(idbuffer, buffer, 1, 4);
				t->id = atoi(idbuffer);					

				/* add the systext to the internal list */
				append_systext(t);
			}

		}
	}

	fclose(fp);

	return EXIT_SUCCESS;

}

/*
 * Release systext resources.
 */
void FreeSysTexts() {

	systext *t = texts;
	systext *tmp;

	while (t) {
		tmp = t->next;
		free(t);
		t = tmp;
	}

}


/*
 * Lookup a systext by it's associated ID key.
 */
systext* SysTextById(uint16_t id) {
	systext* t = texts;
	while ( NULL != (t = t->next)) {
		if (t->id == id)
			return t;
	}	
	return NULL;
}