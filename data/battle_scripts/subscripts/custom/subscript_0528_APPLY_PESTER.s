.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} is feeling itchy and bothered!
    PrintMessage 1652, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
    Wait
    PlayBattleAnimation BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_PESTER
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_PESTER
    WaitButtonABTime 30
    End
    