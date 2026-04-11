.include "asm/include/battle_commands.inc"

.data

// Cure the Brittle condition2 status on BATTLER_CATEGORY_ATTACKER.
// Brittle is stored in STATUS2_BRITTLE (condition2, bit 14), not condition3.
// Uses standard UpdateMonData / CompareMonDataToValue via ROM accessor.
//
// Guard order:
//   a. HP == 0 (fainted)?      → silent End
//   b. STATUS2_BRITTLE set?    → _DoCure, else silent End
//   c. UpdateMonData OPCODE_FLAG_OFF STATUS2_BRITTLE
//   d. Print "{0} is no longer Brittle!" (message 1755)

_000:
    CompareMonDataToValue OPCODE_EQU, BATTLER_CATEGORY_ATTACKER, BMON_DATA_HP, 0, _End
    CompareMonDataToValue OPCODE_FLAG_SET, BATTLER_CATEGORY_ATTACKER, BMON_DATA_STATUS2, STATUS2_BRITTLE, _DoCure
    GoTo _End

_DoCure:
    UpdateMonData OPCODE_FLAG_OFF, BATTLER_CATEGORY_ATTACKER, BMON_DATA_STATUS2, STATUS2_BRITTLE
    // {0} is no longer Brittle!
    PrintMessage 1755, TAG_NICKNAME, BATTLER_CATEGORY_ATTACKER
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_ATTACKER, BATTLE_ANIMATION_NONE
    WaitButtonABTime 30

_End:
    End
