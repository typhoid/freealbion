These are mostly used for NPC dialogue events; the event set ID is referenced in the NPC's character data. However, inside EVNTSET0 there are also some general events used throughout the game, like cursed items, potions, documents that can be combined, etc.
For every file in EVNTSET there should also be a file in EVNTTXT to go  with it (unless empty).

## Event set header ##
| **Offset** | **Length** | **Name** |
|:-----------|:-----------|:---------|
|0           |2           | Number of active event blocks |
|2           |2           | Number of event blocks |

## Active event blocks ##
  * 2 bytes per active event block
  * for the # of active event blocks:
| **Offset** | **Length** | **Name** |
|:-----------|:-----------|:---------|
|0           |2           | Block number |

## Event blocks ##
  * 12 bytes per event block
  * for the # of event blocks:
| **Offset** | **Length** | **Name** |
|:-----------|:-----------|:---------|
|0           |1           | event type |
|1           |1           | byte 1   |
|2           |1           | byte 2   |
|3           |1           | byte 3   |
|4           |1           | byte 4   |
|5           |1           | byte 5   |
|6           |2           | word 6   |
|8           |2           | word 8   |
|10          |2           | next event |