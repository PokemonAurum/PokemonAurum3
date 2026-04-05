// Test: Splinter (condition3 bit 8) end-of-turn damage
//
// Scenario 1: Non-Rock-type afflicted Pokemon (Wooper, maxHP=130) takes 1/16 HP = 8
// Scenario 2: Rock-type afflicted Pokemon (Geodude, maxHP=115) takes 1/12 HP = 9
//
// The enemy uses Splash so no incoming damage pollutes the HP_BAR expectations.

#ifndef GET_TEST_CASE_ONLY

#include "../../../../include/battle.h"
#include "../../../../include/constants/ability.h"
#include "../../../../include/constants/item.h"
#include "../../../../include/constants/moves.h"
#include "../../../../include/constants/species.h"
#include "../../../../include/test_battle.h"

const struct TestBattleScenario BattleTests[] = {

#endif

    // Scenario 1: non-Rock-type — expects 1/16 max HP damage (130 / 16 = 8)
    {
        .battleType     = BATTLE_TYPE_SINGLE,
        .weather        = WEATHER_NONE,
        .fieldCondition = 0,
        .terrain        = TERRAIN_NONE,

        .playerParty = {
            {
                .species   = SPECIES_WOOPER,
                .level     = 50,
                .form      = 0,
                .ability   = ABILITY_WATER_ABSORB,
                .item      = ITEM_NONE,
                .moves     = { MOVE_TACKLE, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                .hp        = FULL_HP,
                .status    = 0,
                .condition2 = STATUS2_SPLINTER,
                .winded_turns    = 0,
                .awestruck_turns = 0,
                .migraine_turns  = 0,
                .idolize_turns   = 0,
                .fatigue_turns   = 0,
                .moveEffectFlags = 0,
            },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
        },

        .enemyParty = {
            {
                .species   = SPECIES_WOOPER,
                .level     = 50,
                .form      = 0,
                .ability   = ABILITY_WATER_ABSORB,
                .item      = ITEM_NONE,
                .moves     = { MOVE_SPLASH, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                .hp        = FULL_HP,
                .status    = 0,
                .condition2 = 0,
                .condition3 = 0,
                .winded_turns    = 0,
                .awestruck_turns = 0,
                .migraine_turns  = 0,
                .idolize_turns   = 0,
                .fatigue_turns   = 0,
                .moveEffectFlags = 0,
            },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
        },

        .playerScript = {
            {
                { ACTION_MOVE_SLOT_1, BATTLER_ENEMY_FIRST },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
            },
            {
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
            },
        },

        .enemyScript = {
            {
                { ACTION_MOVE_SLOT_1, BATTLER_PLAYER_FIRST },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
            },
            {
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
            },
        },

        // Wooper maxHP=130; 1/16 = 8
        .expectations = {
            { .expectationType = EXPECTATION_TYPE_HP_BAR, .battlerIDOrPartySlot = BATTLER_PLAYER_FIRST,
              .expectationValue.hpTaken = { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 } },
        },

        .expectationPassCount = 0,
        .knownFailing = 0,
    },

    // Scenario 2: Rock-type — expects 1/12 max HP damage (115 / 12 = 9)
    {
        .battleType     = BATTLE_TYPE_SINGLE,
        .weather        = WEATHER_NONE,
        .fieldCondition = 0,
        .terrain        = TERRAIN_NONE,

        .playerParty = {
            {
                .species   = SPECIES_GEODUDE,
                .level     = 50,
                .form      = 0,
                .ability   = ABILITY_ROCK_HEAD,
                .item      = ITEM_NONE,
                .moves     = { MOVE_TACKLE, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                .hp        = FULL_HP,
                .status    = 0,
                .condition2 = STATUS2_SPLINTER,
                .winded_turns    = 0,
                .awestruck_turns = 0,
                .migraine_turns  = 0,
                .idolize_turns   = 0,
                .fatigue_turns   = 0,
                .moveEffectFlags = 0,
            },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
        },

        .enemyParty = {
            {
                .species   = SPECIES_WOOPER,
                .level     = 50,
                .form      = 0,
                .ability   = ABILITY_WATER_ABSORB,
                .item      = ITEM_NONE,
                .moves     = { MOVE_SPLASH, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                .hp        = FULL_HP,
                .status    = 0,
                .condition2 = 0,
                .condition3 = 0,
                .winded_turns    = 0,
                .awestruck_turns = 0,
                .migraine_turns  = 0,
                .idolize_turns   = 0,
                .fatigue_turns   = 0,
                .moveEffectFlags = 0,
            },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
        },

        .playerScript = {
            {
                { ACTION_MOVE_SLOT_1, BATTLER_ENEMY_FIRST },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
            },
            {
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
            },
        },

        .enemyScript = {
            {
                { ACTION_MOVE_SLOT_1, BATTLER_PLAYER_FIRST },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
            },
            {
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
            },
        },

        // Geodude maxHP=115; 1/12 = 9
        .expectations = {
            { .expectationType = EXPECTATION_TYPE_HP_BAR, .battlerIDOrPartySlot = BATTLER_PLAYER_FIRST,
              .expectationValue.hpTaken = { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 } },
        },

        .expectationPassCount = 0,
        .knownFailing = 0,
    },

#ifndef GET_TEST_CASE_ONLY
};
#endif
