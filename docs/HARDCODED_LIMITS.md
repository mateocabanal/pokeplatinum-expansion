# Hardcoded-limit audit

This document tracks limits that must be understood before expanding game data.

Status meanings:

- **Confirmed:** observed directly in the current source.
- **Trace required:** a visible boundary exists, but all consumers/storage formats have
  not yet been audited.
- **Expected:** subsystem is likely to contain a limit and must be inspected before work.

## Species

### Confirmed

`include/constants/species.h` currently derives:

```c
#define MAX_SPECIES        SPECIES_BAD_EGG
#define NATIONAL_DEX_COUNT (MAX_SPECIES - 2)
```

The species IDs themselves come from `generated/species.h`.

### Trace required

Before adding IDs after the Gen 4 roster, trace:

- how `generated/species.h` is produced;
- every persistent species field and its integer width;
- party/box Pokémon serialization;
- save-data Pokédex seen/caught bitsets;
- species-to-resource indexing;
- egg/bad-egg sentinel assumptions;
- forms and alternate-form encoding;
- National/Regional Pokédex ordering and UI;
- trainer, encounter, breeding, evolution, and learnset tables.

Do **not** simply redefine `MAX_SPECIES`.

## Moves

### Confirmed

`include/constants/moves.h` derives:

```c
#define NUM_VALID_MOVES (MAX_MOVES - 1)
```

from generated move definitions.

### Trace required

Audit:

- the move-definition generator/input;
- move IDs stored in Pokémon/save data;
- move tables and battle-script dispatch;
- move animations/effects;
- TM/HM mappings;
- tutor and learnset representations;
- UI lookup tables and resource indexing;
- any sentinel values that happen to share widths with move-related fields.

Note: `MOVE_NOT_SELECTED == 0xFF` exists in this header, but it must not be treated as
proof that move IDs themselves are 8-bit; Platinum already has more than 255 moves.

## Types

### Expected

Locate the canonical Pokémon type enum/count and audit:

- species type fields;
- move type fields;
- type-effectiveness table;
- battle-script assumptions;
- UI icons/text/resources;
- Hidden Power and other type-derived mechanics;
- Arceus/Multitype and plate mappings.

Fairy should be the first new type once this path is understood.

## Abilities

### Expected

Locate the generated or canonical ability definitions and audit:

- ability field widths in Pokémon/save structures;
- species ability slots;
- battle dispatch/tables;
- text/resources;
- trainer/generated Pokémon creation;
- later-generation hidden-ability support.

## Items

### Expected

Audit IDs, bag pockets, save storage, battle item dispatch, held-item behavior,
text/icons, marts, pickup tables, berries, TMs/HMs, and script-facing item commands.

## Resources / NARCs

### Expected

Species and move expansion must trace every indexed resource archive rather than assume
IDs can grow without corresponding archive/table changes. At minimum inspect:

- Pokémon front/back sprites;
- palettes;
- icons;
- cries;
- battle animations;
- Pokédex assets;
- move effects;
- item icons;
- localized text archives.

## Save compatibility

### Expected / high priority

Before committing to a maximum species count, document all affected save blocks and
their checksums/sizes. Decide explicitly whether the expansion will:

1. preserve vanilla save layout where possible;
2. version/extend save data; or
3. intentionally break vanilla save compatibility.

This decision should happen before bulk content import.

## Next audit targets

1. Find the source inputs/generators for species, moves, abilities, items, and types.
2. Trace species ID storage from `Pokemon`/box structs into save serialization.
3. Trace Pokédex seen/caught storage.
4. Trace species-indexed NARCs/resources.
5. Trace canonical type count/effectiveness tables.
6. Record every fixed-size array discovered along those paths.
