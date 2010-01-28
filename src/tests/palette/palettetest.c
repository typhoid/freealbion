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
#include <assert.h>
#include "../../shared/types.h"
#include "../../shared/xld.h"

#define ALBION_PALETTE_COUNT		56

 static uint32_t	palettes[ALBION_PALETTE_COUNT][256];
 
 int main(int argc, const char *argv[]) {
 		
 	uchar_t		shared[192];	// 3 x 64   = 192
 	uchar_t		custom[576];	// 3 x 192  = 576
 								// 192 + 64 = 256
 		
 	
 	XldArchive	*xld;
 	XldEntry	e;
 	int 		n = 0;
	int			x = 0;

 	// load the shared palette
 	FILE *fp = fopen("PALETTE.000", "rb");
 	
 	if (fp) {
 	
 		// read the entire shared palette file
 		fread(shared, 192, 1, fp);
 		
 		fclose(fp);
 		
 	} else {
 		fprintf(stderr, "error: unable to open shared palette.\n");
 		return EXIT_FAILURE;	
 	}

 	xld = XldOpen("PALETTE0.XLD");
 	
 	if (xld) {
 	
 		while (XldGetNextEntry(xld, &e) != NULL) {
 			
 			// read the entry data into the custom palette
 			XldGetEntryData(e.index, xld, custom);
 			
 			// now transfer the shared and custom palettes into the appropriate
 			// global palette. use the entry index as the palette index, as thats
 			// what they appear to use in the game.
 			for (n=0;n<192;n+=3) {
 				palettes[e.index][n] = shared[n];
				palettes[e.index][n + 1] = shared[n + 1];
				palettes[e.index][n + 2] = shared[n + 2];
 			}
 			
 			// copy the custom palete data
 			for (n=0;n<576;n+=3) {
				palettes[e.index][n] = custom[n];
				palettes[e.index][n + 1] = custom[n + 1];
				palettes[e.index][n + 2] = custom[n + 2];	
 			}
 			
 		}
 		
 		// all palettes should now be loaded
 		XldClose(xld);	
 		
 		fprintf(stdout, "All palettes loaded.\n");

		for (n=0;n<ALBION_PALETTE_COUNT;n++) {
			fprintf(stdout, "Palette %d\n\n", n);
			for (x=0;x<=256;x++) {
				fprintf(stdout, "%02X ", palettes[n][x]);
			}
			fprintf(stdout, "\n\n\n");
		}

 	} else {
 		fprintf(stderr, "error: unable to open archive.\n");
 		return EXIT_FAILURE;
 	}
 	
 }