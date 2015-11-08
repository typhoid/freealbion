# Party character data #

| **Offset** | **Length** | **Description** |
|:-----------|:-----------|:----------------|
|0           |1           | Possibly type ? (0=party, 1=npc, 2=monster) |
|1           |1           | Gender          |
|2           |1           | Race            |
|3           |1           | Class           |
|4           |1           | Spell class     |
|5           |1           | Level           |
|6           |1           | Unknown         |
|7           |1           | Unknown         |
|8           |1           | Languages       |
|9           |1           | Unknown         |
|10          |1           | Portrait        |
|11          |1           | Unknown         |
|12          |1           | Unknown         |
|13          |1           | Unknown         |
|14          |1           | Unknown         |
|15          |1           | Unknown         |
|16          |1           | Unknown         |
|17          |1           | Combat action points |
|18          |2           | Event set       |
|20          |2           | Another event set |
|22          |2           | Training points |
|24          |2           | Gold            |
|26          |2           | Rations         |
|28          |2           | Unknown         |
|30          |2           | Unknown         |
|32          |2           | Conditions      |
|34          |2           | Unknown         |
|36          |2           | Unknown         |
|38          |2           | Unknown         |
|40          |2           | Unknown         |
|42          |2           | Strength current |
|44          |2           | Strength maximum |
|46          |2           | Unknown         |
|48          |2           | Unknown         |
|50          |2           | Intelligence current |
|52          |2           | Intelligence maximum |
|54          |2           | Unknown         |
|56          |2           | Unknown         |
|58          |2           | Dexterity current |
|60          |2           | Dexterity maximum |
|62          |2           | Unknown         |
|64          |2           | Unknown         |
|66          |2           | Speed current   |
|68          |2           | Speed maximum   |
|70          |2           | Unknown         |
|72          |2           | Unknown         |
|74          |2           | Stamina current |
|76          |2           | Stamina maximum |
|78          |2           | Unknown         |
|80          |2           | Unknown         |
|82          |2           | Luck current    |
|84          |2           | Luck maximum    |
|86          |2           | Unknown         |
|88          |2           | Unknown         |
|90          |2           | Magic resistance current |
|92          |2           | Magic resistance maximum |
|94          |2           | Unknown         |
|96          |2           | Unknown         |
|98          |2           | Magic talent current |
|100         |2           | Magic talent maximum |
|102         |2           | Unknown         |
|104         |2           | Unknown         |
|106         |2           | Age             |
|108         |14          | Unknown         |
|122         |2           | Close range combat current |
|124         |2           | Close range combat maximum |
|126         |2           | Unknown         |
|128         |2           | Unknown         |
|130         |2           | Long range combat current |
|132         |2           | Long range combat maximum |
|134         |2           | Unknown         |
|136         |2           | Unknown         |
|138         |2           | Critical hit current |
|140         |2           | Critical hit maximum |
|142         |2           | Unknown         |
|144         |2           | Unknown         |
|146         |2           | Lockpicking current |
|148         |2           | Lockpicking maximum |
|150         |52          | Unknown         |
|202         |2           | Life points current |
|204         |2           | Life points maximum |
|206         |2           | Unknown         |
|208         |2           | Unknown         |
|210         |2           | Spell points current |
|212         |2           | Spell points maximum |
|214         |2           | Base protection |
|216         |2           | Unknown         |
|218         |2           | Base damage     |
|220         |18          | Unknown         |
|238         |4           | Experience points |
|242         |4           | Spell class 0 (Dji-Kas mage) spells |
|246         |4           | Spell class 1 (Enlightened One) spells |
|250         |4           | Spell class 2 (Druid) spells |
|254         |4           | Spell class 3 (Oqulo Kamulos) spells |
|258         |4           | Spell class 4 spells |
|262         |4           | Spell class 5 spells |
|266         |4           | Spell class 6 spells |
|270         |2           | Unknown         |
|272         |2           | Unknown         |
|274         |16          | German name     |
|290         |16          | English name    |
|306         |16          | French name     |
|322         |60          | Spell class 0 (Dji-Kas mage) spell strength |
|382         |60          | Spell class 1 (Enlightened One) spell strength |
|442         |60          | Spell class 2 (Druid) spell strength |
|502         |60          | Spell class 3 (Oqulo Kamulos) spell strength |
|562         |60          | Spell class 4 spell strength |
|622         |60          | Spell class 5 spell strength |
|682         |60          | Spell class 6 spell strength |
|742         |6           | Neck equipment slot |
|748         |6           | Head equipment slot |
|754         |6           | Tail equipment slot |
|760         |6           | Left hand equipment slot |
|766         |6           | Chest equipment slot |
|772         |6           | Right hand equipment slot |
|778         |6           | Left finger equipment slot |
|784         |6           | Feet equipment slot |
|790         |6           | Right finger equipment slot |
|796         |144         | 24 Backpack item slots (l-to-r, t-to-b) |