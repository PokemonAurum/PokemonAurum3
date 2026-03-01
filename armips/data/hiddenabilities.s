// armips/data/hiddenabilities.s
.align 2
.global gHiddenAbilityTable
gHiddenAbilityTable:
    // Index 0 usually SPECIES_NONE
    .halfword ABILITY_NONE

    // Fill in species in exact species-ID order
    // Example (ONLY examples—use your species order):
    // Bulbasaur
    .halfword ABILITY_CHLOROPHYLL
    // Ivysaur
    .halfword ABILITY_CHLOROPHYLL
    // Venusaur
    .halfword ABILITY_CHLOROPHYLL

    // ...