.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} is too pestered to move!
    PrintMessage 1694, TAG_NICKNAME, BATTLER_CATEGORY_ATTACKER
    Wait
    WaitButtonABTime 30
    PlayBattleAnimation BATTLER_CATEGORY_ATTACKER, BATTLE_ANIMATION_PESTER
    Wait
    UnlockMoveChoice BATTLER_CATEGORY_ATTACKER
    End
    