// Test: Brittle (STATUS2_BRITTLE / condition2 bit 14) — attacker takes 1/20 HP on contact
//
// The enemy Beedrill (maxHP=140) uses Tackle (physical contact) against the player
// who has STATUS2_BRITTLE active.  Brittle triggers like Iron Barbs and deals
// 1/20 of the attacker's max HP back to the attacker each contact hit.
//
// Expected Brittle recoil: 140 / 20 = 7 HP

#ifndef GET_TEST_CASE_ONLY

#include "../../../../include/battle.h"
#include "../../../../include/constants/ability.h"
#include "../../../../include/constants/item.h"
#include "../../../../include/constants/moves.h"
#include "../../../../include/constants/species.h"
#include "../../../../include/test_battle.h"

const struct TestBattleScenario BattleTests[] = {

#endif

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
                .moves     = { MOVE_SPLASH, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                .hp        = FULL_HP,
                .status    = 0,
                .condition2 = STATUS2_BRITTLE,
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
                // Beedrill L50 31 IVs: maxHP = 140; 1/20 = 7
                .species   = SPECIES_BEEDRILL,
                .level     = 50,
                .form      = 0,
                .ability   = ABILITY_SWARM,
                .item      = ITEM_NONE,
                .moves     = { MOVE_TACKLE, MOVE_NONE, MOVE_NONE, MOVE_NONE },
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

        // Beedrill maxHP=140; 1/20 = 7
        .expectations = {
            { .expectationType = EXPECTATION_TYPE_HP_BAR, .battlerIDOrPartySlot = BATTLER_ENEMY_FIRST,
              .expectationValue.hpTaken = { 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 } },
        },

        .expectationPassCount = 0,
        .knownFailing = 0,
    },

#ifndef GET_TEST_CASE_ONLY
};
#endif
