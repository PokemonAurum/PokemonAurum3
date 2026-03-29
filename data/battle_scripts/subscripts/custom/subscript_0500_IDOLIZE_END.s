.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} snapped out of its idolizing!
    PrintMessage 1670, TAG_NICKNAME, BATTLER_CATEGORY_MSG_TEMP
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_MSG_TEMP, BATTLE_ANIMATION_NONE
    WaitButtonABTime 30
    End
    