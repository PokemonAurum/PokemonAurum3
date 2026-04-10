.include "asm/include/battle_commands.inc"

.data

// Inflict the Idolize condition3 status on BATTLER_CATEGORY_SIDE_EFFECT_MON.
// Fairy-type, exclusive, random 3-5 turns.
//
// idolize_turns encoding: 1 = 3 turns, 2 = 4 turns, 3 = 5 turns (2-bit field).
// Random 1, 3 → result in BSCRIPT_VAR_CALC_TEMP ∈ {1, 2, 3} — these are the
// encoded values directly, so no translation needed.
//
// Guard order:
//   a. Already has Idolize?  → silent End
//   b. Wonder Guard?         → "It doesn't affect X!" + MOVE_STATUS_NO_MORE_WORK → End
//   c. InflictCondition3, randomise 3-5 turns, SetCondition3Counter
//   d. Print "{X} became captivated!" (message 1722)

_000:
    GotoIfHasCondition3 BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_IDOLIZE, _End
    CheckIgnorableAbility CHECK_OPCODE_HAVE, BATTLER_CATEGORY_SIDE_EFFECT_MON, ABILITY_WONDER_GUARD, _WonderGuard
    InflictCondition3 BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_IDOLIZE
    // Pick encoded turn value 1, 2, or 3 (= 3, 4, or 5 actual turns).
    Random 1, 3
    CompareVarToValue OPCODE_EQU, BSCRIPT_VAR_CALC_TEMP, 3, _Turns3Enc
    CompareVarToValue OPCODE_EQU, BSCRIPT_VAR_CALC_TEMP, 2, _Turns2Enc
    SetCondition3Counter BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_CTR_IDOLIZE, 1
    GoTo _Print

_Turns3Enc:
    SetCondition3Counter BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_CTR_IDOLIZE, 3
    GoTo _Print

_Turns2Enc:
    SetCondition3Counter BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_CTR_IDOLIZE, 2

_Print:
    // {0} became captivated!
    PrintMessage 1722, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
    Wait
    WaitButtonABTime 30
    End

_WonderGuard:
    // It doesn't affect {0}...
    PrintMessage 27, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
    Wait
    WaitButtonABTime 30
    UpdateVar OPCODE_FLAG_ON, BSCRIPT_VAR_MOVE_STATUS_FLAGS, MOVE_STATUS_NO_MORE_WORK

_End:
    End
