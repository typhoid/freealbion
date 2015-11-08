## general palette format ##
Plain array of RGB8 (24bpp) colors:
| **Offset** | **Length** | **Description** |
|:-----------|:-----------|:----------------|
|0           |1           |Red              |
|1           |1           |Green            |
|2           |1           |Blue             |

## PALETTE.000 ##

This file contains 64 colors.

## PALETTE0.XLD ##

This file stores 56 palettes, each containing 192 colors.

When using a palette, one 192-color palette of this file and PALETTE.000 (64 colors) are merged to one final 256 color palette, with the latter occupying the upper 64 colors/indices.

Images then use an 8-bit index (hence 256-color palette) to use a color.