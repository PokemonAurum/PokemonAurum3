.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} got ahold of itself!
    PrintMessage 1685, TAG_NICKNAME, BATTLER_CATEGORY_MSG_TEMP
    Wait
    WaitButtonABTime 30
    End
    