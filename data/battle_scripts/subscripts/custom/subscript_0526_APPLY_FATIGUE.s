.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} became fatigued!
    PrintMessage 1646, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
    Wait
    PlayBattleAnimation BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_FATIGUE
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_FATIGUE
    WaitButtonABTime 30
    End
    