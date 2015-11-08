From the SYSTEXTS it can be determined that there are 7 spell classes (# 0 to 6). Only 4 of these are available to the player in-game. Each class has room for 30 spells, but many spots are empty. The SPELLDAT file is a simple list with 5 bytes of basic information for each spell. At 210 possible spells this results in a filesize of 1050 bytes.

### Structure ###
  * 5 bytes
| **Offset** | **Length** | **Name** | **Description** |
|:-----------|:-----------|:---------|:----------------|
|0           |1           | spell type | Cast environment |
|1           |1           | spell cost | Spell point cost |
|2           |1           | level req | Level required to learn |
|3           |1           | target   | Cast target(s)  |
|4           |1           | unknown1 | Unknown         |