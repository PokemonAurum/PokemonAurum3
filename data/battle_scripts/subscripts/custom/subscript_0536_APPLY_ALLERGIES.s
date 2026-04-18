.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} has allergies!
    PrintMessage 1676, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
    Wait
    PlayBattleAnimation BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_ALLERGIES
    Wait
    WaitButtonABTime 30
    End
    