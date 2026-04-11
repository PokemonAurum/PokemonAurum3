.include "asm/include/battle_commands.inc"

.data

// Cure the Splinter condition2 status on BATTLER_CATEGORY_ATTACKER.
// Splinter is stored in STATUS2_SPLINTER (condition2, bit 13), not condition3.
// Uses standard UpdateMonData / CompareMonDataToValue via ROM accessor.
//
// Guard order:
//   a. HP == 0 (fainted)?       → silent End
//   b. STATUS2_SPLINTER set?    → _DoCure, else silent End
//   c. UpdateMonData OPCODE_FLAG_OFF STATUS2_SPLINTER
//   d. Print "{0} had its Splinters removed!" (message 1752)

_000:
    CompareMonDataToValue OPCODE_EQU, BATTLER_CATEGORY_ATTACKER, BMON_DATA_HP, 0, _End
    CompareMonDataToValue OPCODE_FLAG_SET, BATTLER_CATEGORY_ATTACKER, BMON_DATA_STATUS2, STATUS2_SPLINTER, _DoCure
    GoTo _End

_DoCure:
    UpdateMonData OPCODE_FLAG_OFF, BATTLER_CATEGORY_ATTACKER, BMON_DATA_STATUS2, STATUS2_SPLINTER
    // {0} had its Splinters removed!
    PrintMessage 1752, TAG_NICKNAME, BATTLER_CATEGORY_ATTACKER
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_ATTACKER, BATTLE_ANIMATION_NONE
    WaitButtonABTime 30

_End:
    End
