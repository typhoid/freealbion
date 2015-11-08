## header ##
  * 10 bytes
| **Offset** | **Length** | **Name** | **Description** |
|:-----------|:-----------|:---------|:----------------|
|0           |1           | ceiling  | 0x01 - 0x03 = no ceiling / 0x04 - 0x05 (0xFF?) = ceiling |
|1           |1           | NPC/monster count | amount of NPCs and monsters (+spare) |
|2           |1           | map type | 0x01 = 3D map, 0x02 = 2D map |
|3           |1           | unknown  | unknown         |
|4           |1           | x dim    | map x dimension |
|5           |1           | y dim    | map y dimension |
|6           |1           | labdata  | labdata id      |
|7           |1           | music    | background music id |
|8           |1           | palette  | map palette (0x01 - 0x38) |
|9           |1           | unknown  | unknown         |

## NPC/monster data ##
  * 10 bytes per NPC/monster
  * overall: #npc/monster `*` 10 bytes
  * if #npc/monster (header byte 1) == 0x00: 32 `*` 10 bytes
  * if #npc/monster (header byte 1) == 0x40: 96 `*` 10 bytes
| **Offset** | **Length** | **Name** | **Description** |
|:-----------|:-----------|:---------|:----------------|
|0           |1           | npc id   | NPC-chardata/Monster-group or Message shown (see offset 6), dummy object if 0 |
|1           |1           | sound    | NPC Sound FX    |
|2           |2           | event    | Linked event ID (upon any form of interaction) |
|4           |1           | object id | object id (-> labdata, NPC gfx) |
|5           |1           | unknown1 | unknown (part of object id?) |
|6           |1           | activity | 01=Dialogue, 02=auto-attack, 11=return message |
|7           |1           | movement type | movement type:<br> <code>*</code> bit 1/2: if bit 1 and/or 2 are set: random; if neither is set: use a 0x900 byte structure containing positioning data<br> <code>*</code> bit 3: follows party<br> <code>*</code> actual data: <a href='MAPDATA3D#NPC/monster_position_structure.md'>MAPDATA3D#NPC/monster_position_structure</a> <br>
<tr><td>8           </td><td>2           </td><td> unknown2 </td><td> unknown         </td></tr></li></ul></tbody></table>

<h2>actual map data ##
  * 3 bytes per tile
  * overall: x dim `*` y dim `*` 3 bytes
| **Offset** | **Length** | **Name** | **Description** |
|:-----------|:-----------|:---------|:----------------|
|0           |1           | object/wall id | object/wall id (object if: 1 - 101; wall if: 102+) |
|1           |1           | floor id | floor id        |
|2           |1           | ceiling id | ceiling id      |

## map events ##
  * see [mapevents](mapevents.md)

## NPC/monster position structure ##
  * note: these correspond directly with "NPC/monster events" (first event entry ^= first position structure entry)
  * overall: #npc/monster sub-structures
  * if corresponding movement type & 0x3 != 0 (2 bytes)
```
[X-Pos - Byte]
[Y-Pos - Byte]
```
  * else (0x900 bytes)
```
[FOR 0x480; 48 positions per hour or one position each 1.25 minutes]
	[X-Pos - Byte]
	[Y-Pos - Byte]
```

## automap info / goto points ##
  * first word: amount of goto points
  * 19 bytes per goto point
  * overall: #goto points `*` 19 bytes
| **Offset** | **Length** | **Description** |
|:-----------|:-----------|:----------------|
|0           |1           | x pos           |
|1           |1           | y pos           |
|2           |1           | unknown         |
|3           |1           | unknown         |
|4           |15          | name/text       |

## automap gfx remapping structure ##
  * 0x40 Bytes

## Active map events ##
  * 2 bytes per event
  * 64 total entries
  * if a map event is not listed here, it cannot be triggered
|0|2| block number | Block number of active event (0xFFFF=disabled) |
|:|:|:-------------|:-----------------------------------------------|