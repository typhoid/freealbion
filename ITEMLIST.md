There are 462 records this file and each record is 40 bytes long. It is believe that, in the absence of any unique identifier in the file, the item ID is determined from its position in the file.

| **Offset** | **Length** | **Name** | **Description** |
|:-----------|:-----------|:---------|:----------------|
|0           |1           |unknown   |Always 0         |
|1           |1           |typeid    |[Item type](Items#Types.md)|
|2           |1           |slotType  |[Slot that can hold the item](Items#Slots.md)|
|3           |1           |breakrate |Chance to break the item|
|4           |1           |gender    |Determines which gender can use this item. 2 = female, 3 = any|
|5           |1           |hands     |Determines how many free hands are required to equip the item.|
|6           |1           |lpMaxBonus|Bonus value to life points.|
|7           |1           |lpMaxBonus|Bonus value to spell points.|
|8           |1           |attributeType|[Attribute bonus type](Items#Attributes.md)|
|9           |1           |attributeBonus|Attribute bonus value.|
|10          |1           |skillType |[Skill bonus type](Items#Skills.md)|
|11          |1           |skillBonus|Skill bonus value.|
|12          |1           |protection|Protection from physical damage.|
|13          |1           |damage    |Physical damage caused.|
|14          |1           |ammoType  |Ammunition type. |
|15          |1           |skillTax1Type|Skill Tax 1 Type |
|16          |1           |skillTax2Type|Skill Tax 2 Type |
|17          |1           |skillTax1 |Skill Tax 1 value. [Ranged Values](Items#Ranged_Values.md)|
|18          |1           |skillTax2 |Skill Tax 2 value. [Ranged Values](Items#Ranged_Values.md)|
|19          |1           |activate  |Activate enables compass (0), monster eye (1) or clock (3) (if type=0x13) / Torch intensity (if type=0x16) |
|20          |1           |ammoAnim  |Ammo combat animation (long-range weapons only)|
|21          |1           |spellClass|[Spell Class](Items#Spell_Class.md)|
|22          |1           |spellEffect|Spell id         |
|23          |1           |charges   |Charges left in item / Torch lifetime (if type=0x16)|
|24          |1           |enchantments|Number of times item was enchanted/recharged|
|25          |1           |maxEnchantments|Maximum possible enchantments|
|26          |1           |maxCharges|Maxiumum number of charges|
|27          |1           |count     |Switch for vital, stackable and single-use items|
|28          |1           |count2    |Switch for extra info, broken and cursed items|
|29          |1           |iconAnim  |Number of animated images|
|30          |2           |weight    |weight of the item in grammes|
|32          |2           |value     |Base resell value / 10.|
|34          |2           |icon      |Image for the item|
|36          |2           |class     |A bitfield that controls which classes can use the item.|
|38          |2           |race      |Likely meant to control which race can use the item - but does not seem to work ?|


Please be aware that these values are all derived from observation and not guaranteed to be correct.

![http://freealbion.googlecode.com/svn/wiki/img/item-list-hex.png](http://freealbion.googlecode.com/svn/wiki/img/item-list-hex.png)