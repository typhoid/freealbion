## event header ##
  * first word: #"positionless"/automatically executed events (== auto events)
  * for #auto events:
| **Offset** | **Length** | **Name** | **Description** |
|:-----------|:-----------|:---------|:----------------|
|0           |2           | "x pos"  | always 0x0000?  |
|2           |2           | event trigger | event trigger   |
|4           |2           | block number | block number    |

  * for map y dim/each row:
    * first word: #events in this row
    * for #row events
| **Offset** | **Length** | **Name** | **Description** |
|:-----------|:-----------|:---------|:----------------|
|0           |2           | x pos    | actually one byte |
|2           |2           | event trigger | event trigger   |
|4           |2           | block number | block number    |

## events ##
  * first word: #events
  * 12 bytes per event
  * for #events:
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


### event trigger ###
```
byte 1:
bit 1: Normal
bit 2: Examine
bit 3: Touch
bit 4: Speak
bit 5: Use item
bit 6: Map init
bit 7: Every step
bit 8: Every hour

byte 2:
bit 1: Every day
bit 2: Default
bit 3: Action
bit 4: NPC
bit 5: Take
bit 6: -
bit 7: -
bit 8: -
```

### event type ###
```
00: Script
01: Map exit
02: Door
03: Chest
04: Text
05: Spinner
06: Trap
07: Change used item
08: Datachange
09: Change icon
0A: Encounter
0B: Place action
0C: Query
0D: Modify
0E: Action
0F: Signal
10: Clone automap
11: Sound
12: Start dialogue
13: Create transport
14: Execute
15: Remove party member
16: End dialogue
17: Wipe
18: Play animation
19: Offset
1A: Pause
1B: Simple chest
1C: Ask surrender
1D: Do script
```

## specific event type descriptions ##
### Action ###
  * catches a user action
```
byte 1: action type (00=word, 06=start dialogue, 08=dialogue line, 2E=use item, 2F=equip item, 30=unequip item, 36=pick up item in inventory)
byte 3: text "BLOK" clicked (if byte 01=08)
Word 6: word id (if byte 01=00) / text id (if byte 01=08) / item id (if byte 01=2E/2F/30/36)
```

### Chest ###
  * opens the chest screen
```
byte 1: lock strength (00 = no lock; 01-63 = normal lock; > 63 = can't be picked)
word 6: chest id
word 8: event used for traps?
```

### Map exit ###
  * for map transitions
```
byte 1: destination x position (if 0: keep current player x position)
byte 2: destination y position (if 0: keep current player y position)
byte 3: direction/rotation (0: up, 1: right, 2: down, 3: left)
byte 4: always 255?
word 6: map id/number
```

### Modify ###
  * make in-game changes to events
```
byte 1: modify type (00=set temporary switch, 01=disable event chain)
byte 3: chain number (only for modify type 01)
word 6: switch id (only for modify type 00)
```

### Query ###
  * a conditional check for event branching
```
byte 1: query type (0=check temporary switch, 14=check choice, 1F=window with two choices)
word 6: switch id (if byte 1=00) / window text id (if byte 1=1F)
word 8: next event (if switch is true / if second choice)
next event: next event (if switch is false / if first choice)
```

### Script ###
  * executes a script
```
word 6: script id
```

### Simple chest ###
  * gives you an item
```
word 6: item id
word 8: could be the amount, for stackable items?
```

### Text ###
  * outputs a text
```
byte 1: text type (0 = window, 2 = window with portrait, 6 = quickinfo)
byte 4: portrait id
byte 5: text id/number
```