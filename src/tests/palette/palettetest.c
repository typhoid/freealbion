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
#include "../../shared/palette.h"

extern uint32_t palettes[1][1];

void dumptohtml(uint32_t palette[], int colours)
{
	FILE *fp = fopen("c:\\tmp\\palette.html", "wb");
	int n;
	uint32_t col;

	fprintf(fp, "<html><body><table>");
	
	fprintf(fp, "<tr>");
	for (n=0;n<colours;n++) {
		if (n % 16 == 0)
			fprintf(fp, "</tr><tr>");
		col = palette[n];
		fprintf(fp, "<td style=\"background-color: #%02x%02x%02x;\">&nbsp;&nbsp;&nbsp;</td>",
			(unsigned char)(col >> 16),
			(unsigned char)(col >> 8),
			(unsigned char)col);
	}

	fprintf(fp, "</table></body></html>");
	fflush(fp);
	fclose(fp);
}

int main(int argc, const char *argv[]) {
 	
	int n = 0;

	InitPalettes();
	
	// list all the colors in the first palette
	for (n=0;n<256;n++) {
		printf("#%08x ", palettes[0][n]);
	}

	dumptohtml(palettes[0], 256);

	/*
 	uchar_t		shared[192];	// 3 x 64   = 192
 	uchar_t		custom[576];	// 3 x 192  = 576
 								// 192 + 64 = 256
 	
	uint32_t custom_xrgb[192];
	uint32_t shared_xrgb[64];
	
	unsigned int colour = 0;
	int r, g, b;
 	
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

	for (n=0,x=0;n<192;n+=3,x++) {
		
		r = shared[n];
		g = shared[n+1];
		b = shared[n+2];

		colour = 0xff000000;
		colour += r << 16;
		colour += g << 8;
		colour += b;
		
		printf("%08x ", colour);
		shared_xrgb[x] = colour;


	}
	*/

	
	

	/*

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
	*/
 	
 }