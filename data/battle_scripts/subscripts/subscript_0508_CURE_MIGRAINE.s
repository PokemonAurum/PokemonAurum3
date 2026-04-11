.include "asm/include/battle_commands.inc"

.data

// Cure the Migraine condition3 status on BATTLER_CATEGORY_ATTACKER.
// ClearCondition3 is used (safe: exclusive flags cannot stack).
//
// Guard order:
//   a. HP == 0 (fainted)?       → silent End
//   b. CONDITION3_MIGRAINE set? → _DoCure, else silent End
//   c. ClearCondition3
//   d. Print "{0} recovered from its Migraine!" (message 1740)

_000:
    CompareMonDataToValue OPCODE_EQU, BATTLER_CATEGORY_ATTACKER, BMON_DATA_HP, 0, _End
    GotoIfHasCondition3 BATTLER_CATEGORY_ATTACKER, CONDITION3_MIGRAINE, _DoCure
    GoTo _End

_DoCure:
    ClearCondition3 BATTLER_CATEGORY_ATTACKER
    // {0} recovered from its Migraine!
    PrintMessage 1740, TAG_NICKNAME, BATTLER_CATEGORY_ATTACKER
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_ATTACKER, BATTLE_ANIMATION_NONE
    WaitButtonABTime 30

_End:
    End
