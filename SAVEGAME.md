**TODO**: a lot still needs to be done here, this is just a collection of various observations and notes, without any details !

# Header #
| **Offset** | **Length** | **Description** |
|:-----------|:-----------|:----------------|
|0           |2           | Length of the savename |
|2           |2           | Unknown         |
|4           |variable    | Name of the savegame |

|0|4| Unknown |
|:|:|:--------|
|4|1| Version number |
|5|7| Unknown |
|12|2| In-game days ? |
|14|2| In-game hours |
|16|2| In-game minutes |
|18|2| Map number |
|20|2| Party X-coordinate |
|22|2| Party Y-coordinate |

  * For the next part no clear structure was yet identified. For reference purposes it is convenient to use v\_offs as a designation for the offset of the version number.
  * Starting at offset 0x19E + v\_offs there are 2 byte switches that determine which characters are available.
  * Some kind of bool tables related to event switches and disabled event chains were found in the vicinity of 0x286 + v\_offs and 0x1067 + v\_offs. The exact scope and details of these are still unknown. Likely the changes are directly related to events with the "Modify" type.
  * The first easily discernible structure consists of 0x80 byte blocks for each NPC. There are at least values for NPC-chardata, NPC-gfx, linked NPC-event, movement type, step-in-sequence, current X, current Y, next X, next Y, facing/orientation.
  * Directly after there are some unknown bytes that seemingly belong to 0x23 blocks.
  * The final part of the savegame header contains a list that stores various in-game changes, like disabled events, removed item overlay graphics, etc. The list is divided into several chunks, where each chunk is preceded by 4 bytes to indicate the chunk size, and 2 bytes for the number of entries. Between chunks there can be variations in the size of the individual entries (e.g. 8 or 6 bytes), but never within chunks.

# Archived XLD files #

At the start of a new game these are loaded from the INITIAL directory, and during play they are temporarily stored in the CURRENT directory.
The default sequence is:<br>
PRTCHAR0.XLD<br>
PRTCHAR1.XLD<br>
PRTCHAR2.XLD<br>
AUTOMAP1.XLD<br>
AUTOMAP2.XLD<br>
AUTOMAP3.XLD<br>
CHESTDT0.XLD<br>
CHESTDT1.XLD<br>
CHESTDT2.XLD<br>
CHESTDT5.XLD<br>
MERCHDT0.XLD<br>
MERCHDT1.XLD<br>
MERCHDT2.XLD<br>
NPCCHAR0.XLD<br>
NPCCHAR1.XLD<br>
NPCCHAR2.XLD<br>
Before every XLD there are 8 bytes; the first 4 indicate the file size, the next 2 seem to indicate the data category (e.g. PRTCHAR or NPCCHAR) and the final 2 correlate with the number in the filename (0, 1, etc.).<br>
<br>
PRTCHARx.XLD: see <a href='PRTCHAR.md'>PRTCHAR</a>