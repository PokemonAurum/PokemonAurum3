.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} is embedded with splinters!
    PrintMessage 1783, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
    Wait
    PlayBattleAnimation BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_SPLINTER
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_SPLINTER
    WaitButtonABTime 30
    End
