## Header ##
  * 10 bytes
| **Offset** | **Length** | **Name** | **Description** |
|:-----------|:-----------|:---------|:----------------|
|0           |1           | unknown1 | Switch for wait/rest, light-environment, NPC converge range, possibly more |
|1           |1           | NPC/monster count | amount of NPCs and monsters (+spare) |
|2           |1           | map type | 0x01 = 3D map, 0x02 = 2D map |
|3           |1           | sound    | Sound (Music + FX) |
|4           |1           | x dim    | Width of map    |
|5           |1           | y dim    | Height of map   |
|6           |1           | tileset  | tileset id      |
|7           |1           | combat gfx | Combat background gfx |
|8           |1           | npc/party palette | npc/party palette |
|9           |1           | unknown2 | unknown         |

## NPC/monster data ##
  * see [MAPDATA3D#NPC/monster\_data](MAPDATA3D#NPC/monster_data.md)

## map data ##
  * 3 bytes per tile
  * overall: x dim `*` y dim `*` 3 bytes
| **Offset** | **Length** | **Name** | **Description** |
|:-----------|:-----------|:---------|:----------------|
|0           |12 bit      | overlay  | overlay id      |
|12 bit      |12 bit      | underlay | underlay id     |

## map events ##
  * see [mapevents](mapevents.md)

## NPC/monster position structure ##
  * see [MAPDATA3D#NPC/monster\_position\_structure](MAPDATA3D#NPC/monster_position_structure.md)

## Active map events ##
  * 2 bytes per event
  * 250 total entries
  * if a map event is not listed here, it cannot be triggered
|0|2| block number | Block number of active event (0xFFFF=disabled) |
|:|:|:-------------|:-----------------------------------------------|