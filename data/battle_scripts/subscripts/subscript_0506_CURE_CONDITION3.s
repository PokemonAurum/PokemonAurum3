.include "asm/include/battle_commands.inc"

.data

// Silent generic fallback: clear all condition3 flags and counters.
// Called by Full Heal and Full Restore item-use subscripts.
// Per-condition message/animation is NOT printed here — individual cure
// subscripts (0507-0513) handle per-flag messaging when called directly.
//
// Guard order:
//   a. HP == 0 (fainted)?    → silent End
//   b. No condition3 active? → silent End
//   c. ClearCondition3

_000:
    CompareMonDataToValue OPCODE_EQU, BATTLER_CATEGORY_ATTACKER, BMON_DATA_HP, 0, _End
    GotoIfHasCondition3 BATTLER_CATEGORY_ATTACKER, CONDITION3_ALL, _DoCure
    GoTo _End

_DoCure:
    ClearCondition3 BATTLER_CATEGORY_ATTACKER

_End:
    End
