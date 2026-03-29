.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} is awestruck!
    PrintMessage 1682, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
    Wait
    PlayBattleAnimation BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_AWESTRUCK
    Wait
    WaitButtonABTime 30
    End
    