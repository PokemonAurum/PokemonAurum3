// Test: Polar Power boosts Ice/Water/Flying moves 1.3x in snow
// Arcanine lv50 SpAtk=120 (no STAB), Ice Beam 90->117 (1.3x), vs Poliwrath lv50 SpDef=90
// base_damage = floor(floor(22*117*120/90)/50)+2 = 70; no STAB, neutral type => range 59-70
#ifndef GET_TEST_CASE_ONLY

#include "../../../../include/battle.h"
#include "../../../../include/constants/ability.h"
#include "../../../../include/constants/battle_message_constants.h"
#include "../../../../include/constants/item.h"
#include "../../../../include/constants/moves.h"
#include "../../../../include/constants/species.h"
#include "../../../../include/test_battle.h"

const struct TestBattleScenario BattleTests[] = {

#endif

    {
        .battleType = BATTLE_TYPE_SINGLE,
        .weather = WEATHER_SNOW,
        .fieldCondition = 0,
        .terrain = TERRAIN_NONE,
        .playerParty = {
            {
                .species = SPECIES_ARCANINE,
                .level = 50,
                .form = 0,
                .ability = ABILITY_POLAR_POWER,
                .item = ITEM_NONE,
                .moves = { MOVE_ICE_BEAM, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                .hp = FULL_HP,
                .status = 0,
                .condition2 = 0,
                .moveEffectFlags = 0,
            },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE } },
        .enemyParty = { {
                            .species = SPECIES_POLIWRATH,
                            .level = 50,
                            .form = 0,
                            .ability = ABILITY_WATER_ABSORB,
                            .item = ITEM_NONE,
                            .moves = { MOVE_SPLASH, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                            .hp = FULL_HP,
                            .status = 0,
                            .condition2 = 0,
                            .moveEffectFlags = 0,
                        },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE } },
        .playerScript = { {
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
            } },
        .enemyScript = { {
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
            } },
        .expectations = {
            { .expectationType = EXPECTATION_TYPE_HP_BAR, .battlerIDOrPartySlot = BATTLER_ENEMY_FIRST, .expectationValue.hpTaken = { 59, 60, 60, 61, 62, 63, 63, 64, 65, 65, 66, 67, 67, 68, 69, 70 } },
        }
    },
#ifndef GET_TEST_CASE_ONLY
};
#endif
