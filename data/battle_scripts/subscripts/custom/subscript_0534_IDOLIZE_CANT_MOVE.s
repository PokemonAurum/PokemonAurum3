.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} can't move! It's idolizing {1}!
    PrintMessage 1673, TAG_NICKNAME_NICKNAME, BATTLER_CATEGORY_ATTACKER, BATTLER_CATEGORY_MSG_TEMP
    Wait
    WaitButtonABTime 30
    PlayBattleAnimation BATTLER_CATEGORY_ATTACKER, BATTLE_ANIMATION_IDOLIZE
    Wait
    UnlockMoveChoice BATTLER_CATEGORY_ATTACKER
    End
    