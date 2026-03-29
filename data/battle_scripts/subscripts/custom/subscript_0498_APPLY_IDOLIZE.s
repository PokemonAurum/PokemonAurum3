.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} is idolizing {1}!
    PrintMessage 1667, TAG_NICKNAME_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLER_CATEGORY_ATTACKER
    Wait
    PlayBattleAnimation BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_IDOLIZE
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_IDOLIZE
    WaitButtonABTime 30
    End
    