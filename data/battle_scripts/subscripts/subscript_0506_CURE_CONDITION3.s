.include "asm/include/battle_commands.inc"

.data

// Clear all condition3 flags and counters on BATTLER_CATEGORY_ATTACKER.
// Called by Full Heal and Full Restore item-use subscripts.
//
// Guard order:
//   a. HP == 0 (fainted)?      → silent End
//   b. No condition3 active?   → silent End
//   c. ClearCondition3
//   d. Print cure message (TODO: message ID TBD — per-condition triplets TBD)
//   e. SetHealthbarStatus BATTLE_ANIMATION_NONE + WaitButtonABTime 30

_000:
    CompareMonDataToValue OPCODE_EQU, BATTLER_CATEGORY_ATTACKER, BMON_DATA_HP, 0, _End
    GotoIfHasCondition3 BATTLER_CATEGORY_ATTACKER, CONDITION3_ALL, _DoCure
    GoTo _End

_DoCure:
    ClearCondition3 BATTLER_CATEGORY_ATTACKER
    // TODO: replace 0 with the final cure message ID once per-condition triplets are added
    PrintMessage 0, TAG_NICKNAME, BATTLER_CATEGORY_ATTACKER
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_ATTACKER, BATTLE_ANIMATION_NONE
    WaitButtonABTime 30

_End:
    End
