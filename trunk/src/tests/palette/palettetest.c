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
// #include "../../shared/palette.h"

 static uint32_t	palettes[54][256];
 
 int main(int argc, const char *argv[]) {
 		
 	uchar_t		shared[192];	// 3 x 64   = 192
 	uchar_t		custom[576];	// 3 x 192  = 576
 								// 192 + 64 = 256
 		
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
 	
 	XldArchive	*xld;
 	XldEntry	e;
 	int 		n = 0;
 	
 	xld = XldOpen("PALETTE0.XLD");
 	
 	if (xld) {
 	
 		while (XldGetNextEntry(xld, &e) != NULL) {
 			
 			// read the entry data into the custom palette
 			XldGetEntryData(e.index, xld, custom);
 			
 			// now transfer the shared and custom palettes into the appropriate
 			// global palette. use the entry index as the palette index, as thats
 			// what they appear to use in the game.
 			for (n=0;n<64;n++) {
 				palettes[e.index][n] = shared[n];
				palettes[e.index][n] = shared[n + 1];
				palettes[e.index][n] = shared[n + 2];	
 			}
 			
 			// copy the custom palete data
 			for (n=0;n<192;n++) {
				palettes[e.index][n] = custom[n];
				palettes[e.index][n] = custom[n + 1];
				palettes[e.index][n] = custom[n + 2];	
 			}
 			
 		}
 		
 		// all palettes should now be loaded
 		XldClose(xld);	
 		
 		printf("All palettes loaded.\n");
 		
 	} else {
 		fprintf(stderr, "error: unable to open archive.\n");
 		return EXIT_FAILURE;
 	}
 	
 }