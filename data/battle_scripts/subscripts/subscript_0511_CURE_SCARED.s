.include "asm/include/battle_commands.inc"

.data

// Cure the Scared condition3 status on BATTLER_CATEGORY_ATTACKER.
// ClearCondition3 is used (safe: exclusive flags cannot stack).
//
// Guard order:
//   a. HP == 0 (fainted)?     → silent End
//   b. CONDITION3_SCARED set? → _DoCure, else silent End
//   c. ClearCondition3
//   d. Print "{0} is no longer frightened." (message 1749)

_000:
    CompareMonDataToValue OPCODE_EQU, BATTLER_CATEGORY_ATTACKER, BMON_DATA_HP, 0, _End
    GotoIfHasCondition3 BATTLER_CATEGORY_ATTACKER, CONDITION3_SCARED, _DoCure
    GoTo _End

_DoCure:
    ClearCondition3 BATTLER_CATEGORY_ATTACKER
    // {0} is no longer frightened.
    PrintMessage 1749, TAG_NICKNAME, BATTLER_CATEGORY_ATTACKER
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_ATTACKER, BATTLE_ANIMATION_NONE
    WaitButtonABTime 30

_End:
    End
