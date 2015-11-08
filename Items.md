# Items #

There are 462 items in the game.

## Types ##

|Id|Name|
|:-|:---|
|1 |Armour|
|2 |Helmet|
|3 |Shoes|
|4 |Shield|
|5 |Melee|
|6 |Ranged|
|7 |Ammo|
|8 |Document|
|9 |Spell|
|10|Drink|
|11|Amulet|
|12|**NOT USED**|
|13|Ring|
|14|Jewel|
|15|Tool|
|16|Key |
|17|Normal|
|18|Magical|
|19|Special|
|20|**NOT USED**|
|21|Lockpick|
|22|Staff|

## Slots ##

|Id|Description|
|:-|:----------|
|0 |Inventory  |
|1 |Neck       |
|2 |Head       |
|4 |Left hand  |
|5 |Chest      |
|6 |Right hand |
|7 |Left finger|
|8 |Feet       |
|9 |Right finger|
|10|Left hand or tail|

## Attributes ##

|Id|Name|
|:-|:---|
|0 |Strength|
|1 |Intelligence|
|2 |Dexterity|
|3 |Speed|
|4 |Stamina|
|5 |Luck|
|6 |Magic resistance|
|7 |Magic talent|

## Skills ##

|Id|Name|
|:-|:---|
|0 |Close range combat|
|1 |Long range combat|
|2 |Critical hit|
|3 |Lockpicking|

## Spell Class ##

|Id|Name|
|:-|:---|
|0 |Dji-Kas mage|
|1 |Enlightened One|
|2 |Druids|
|3 |Oqulo Kamulos|

## Ranged Values ##

Some of the values for items are negative but stored within a single byte. This is achieved by using two ranges of numbers to indicate if the value is positive or negative.

|0x0 (0d)|0x7f (127d)|Positive|
|:-------|:----------|:-------|
|0x80 (128d)|0xff (255d)|Negative|

To obtain the negative value, simply minus 127 from the negative value.

```
  int value = (0x80 - 0x7f);
```