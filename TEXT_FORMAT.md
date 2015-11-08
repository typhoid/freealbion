Note:
  * this is the same for EVNTTXT and MAPTEXT.
  * the character encoding is very odd (IBM-850 comes pretty close, but it can't display 'ß')


Header:
| **Offset** | **Length** | **Description** |
|:-----------|:-----------|:----------------|
|0           |2 (Word)    |# of texts = text\_count|
|2           |2 (Word) `*` text\_count|length of each text|

Content, for each text string:
|-|text length+1|text itself, ended by 0x00|
|:|:------------|:-------------------------|

special tokens:
| **Token** | **Note** | **Description** |
|:----------|:---------|:----------------|
|{WORD`*`}  | `*` = any word | this adds the word to the 'ask npc about word' list|
|{BLOK###}  |### = number, starting at 000|list of answer options (like "are you ready? {BLOK000}Yes {BLOK001}No")|
|{LEAD}{NAME}|these two seem to always appear in conjunction|name of party leader|
|{CNTR}     |          |centered text    |
|{FAT }     |note the extra space char|bold text        |
|{BIG }     |          |big text, larger font size|
|{HIS }     |          |"his"/"her" text token, obviously dependent on the party leaders gender|
|{INK ###}  |### = number, starting at 001|ink --TODO: 001/002/006 = white/gold/??? text color|
--TODO: more tokens