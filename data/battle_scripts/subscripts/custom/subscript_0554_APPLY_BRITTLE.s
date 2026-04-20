.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} has become brittle!
    PrintMessage 1780, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
    Wait
    PlayBattleAnimation BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_BRITTLE
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_BRITTLE
    WaitButtonABTime 30
    End
