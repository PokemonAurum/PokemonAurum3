.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} became scared!
    PrintMessage 1658, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
    Wait
    PlayBattleAnimation BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_SCARED
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_SCARED
    WaitButtonABTime 30
    End
    