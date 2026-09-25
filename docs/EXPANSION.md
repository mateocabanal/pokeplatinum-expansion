# pokeplatinum-expansion architecture

This repository is intended to become a reusable expansion layer over
[pret/pokeplatinum](https://github.com/pret/pokeplatinum), not a single ROM hack.

## Goals

- Preserve a clean relationship with upstream `pret/pokeplatinum`.
- Make modern mechanics configurable rather than hard-coded.
- Expand species, moves, abilities, items, forms, and related resources systematically.
- Keep content/data expansion separate from engine changes.
- Make downstream hacks consume the expansion instead of mixing story/map changes into it.
- Prefer generated data and explicit feature gates over scattered magic-number patches.

## Layering

```text
pret/pokeplatinum
        |
        v
pokeplatinum-expansion
        |
        v
downstream ROM hacks
```

The expansion layer may change engine behavior and data formats when necessary, but
project-specific maps, story, trainers, dialogue, and region design should live in
downstream repositories.

## Configuration

Expansion switches live under `include/expansion/`.

The initial policy is conservative: new feature switches default off so the bootstrap
can remain build-compatible with vanilla Platinum while individual systems are migrated.

Feature flags should be independent when possible. For example, enabling later-generation
species should not implicitly require Mega Evolution, Dynamax, or Terastallization.

## Development rules

1. **No blind constant bumps.** Before increasing a limit, trace storage widths, save
   structures, generated data, resource archives, serialization, UI assumptions, and
   sentinel values.
2. **Prefer generated data.** If a value is already produced from a generator, extend
   the generator/input format rather than maintaining a second hand-written table.
3. **Keep upstream mergeable.** Expansion-specific code should be namespaced or isolated
   where practical, and upstream files should receive the smallest coherent changes.
4. **Preserve vanilla behavior by default.** New mechanics should enter behind explicit
   configuration until they are mature enough to become an expansion default.
5. **Test vertical slices.** Add one complete feature/species through every affected
   subsystem before bulk-importing hundreds of entries.

## First vertical slice

A good architecture test is **Sylveon + Fairy type** rather than immediately importing
every later-generation Pokémon. That slice forces us to solve:

- a post-Gen-4 species entry;
- a new type and type-chart behavior;
- species/base-stat data;
- evolution handling;
- moves/learnsets as needed;
- sprites/icons/resources;
- party and battle rendering;
- Pokédex handling;
- save/load compatibility.

If that can be added without one-off patches, the underlying expansion architecture is
probably healthy enough to scale.

## Initial phases

### Phase 0 — Baseline
- Confirm matching vanilla build.
- Confirm modified `make rom` build.
- Establish CI/build checks.
- Keep an easy upstream-sync path.

### Phase 1 — Expansion framework
- Configuration header and naming conventions.
- Hardcoded-limit/storage-width audit.
- Data/resource generator inventory.
- Document save-format constraints.

### Phase 2 — First engine extension
- Add Fairy type behind a feature flag.
- Add one later-generation species end-to-end.
- Extend resources and Pokédex safely.

### Phase 3 — Generalized content expansion
- Species/forms.
- Moves.
- Abilities.
- Items.
- Evolution methods.
- Learnsets.
- Trainer data.

### Phase 4 — Modern mechanics
- Generation-selectable battle behavior.
- Modern status/weather/terrain changes.
- QoL systems.
- Optional battle gimmicks.
