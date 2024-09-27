# GBDK "Bad" Examples

You want to make a game for the Game Boy?
Want to see and feel its limitations before you start?
You're in the right place!

## Examples

### 0: nothing

no code:

```
C:\Users\jgens\Downloads\gbdk\bin\romusage.exe .\bazel-bin\0_default_empty\rom_1.gb

Bank         Range                Size     Used  Used%     Free  Free% 
--------     ----------------  -------  -------  -----  -------  -----
ROM_0        0x0000 -> 0x3FFF    16384      500     3%    15884    97%
```

one tile:

```
C:\Users\jgens\Downloads\gbdk\bin\romusage.exe .\bazel-bin\0_default_empty\rom_3.gb

Bank         Range                Size     Used  Used%     Free  Free%
--------     ----------------  -------  -------  -----  -------  -----
ROM_0        0x0000 -> 0x3FFF    16384      669     4%    15715    96%
```

### 1: maybe don't animate with background data

#### 1.1 individual pictures

even just 5 frames of data (albeit large and uniquely-tiled) takes up 73% of a ROM slot!

```
C:\Users\jgens\Downloads\gbdk\bin\romusage.exe .\bazel-bin\1_bg_animation\rom_2.gb

Bank         Range                Size     Used  Used%     Free  Free%
--------     ----------------  -------  -------  -----  -------  -----
ROM_0        0x0000 -> 0x3FFF    16384      941     6%    15443    94%
ROM_1        0x4000 -> 0x7FFF    16384    11898    73%     4486    27%
```

#### 1.2 what about a single tile sheet?

```
C:\Users\jgens\Downloads\gbdk\bin\romusage.exe .\bazel-bin\1_bg_animation\rom_1_tilesheet.gb

Bank         Range                Size     Used  Used%     Free  Free%
--------     ----------------  -------  -------  -----  -------  -----
ROM_0        0x0000 -> 0x3FFF    16384      500     3%    15884    97%
ROM_1        0x4000 -> 0x7FFF    16384     5298    32%    11086    68%
```

WOW! save 40% of a ROM slot!

However, you should get these errors when using png2asset on a large tilesheet:

```
Warning: found more than 256 tiles on x:424,y:112
Warning: tile count (257) + tile origin (0) exceeds 256 at x:424,y:112
Warning: found more than 256 tiles on x:0,y:120
Warning: tile count (258) + tile origin (0) exceeds 256 at x:0,y:120
Warning: found more than 256 tiles on x:8,y:120
...
Warning: tile count (273) + tile origin (0) exceeds 256 at x:384,y:120
Warning: found more than 256 tiles on x:416,y:120
Warning: tile count (274) + tile origin (0) exceeds 256 at x:416,y:120
```

This is because png2asset assumes you'll show the whole image at once.
This means all tiles into background ram (256 limit).
Note the the individual photoes only require about 140 individually the following:

```
$ grep TILE_COUNT ./*
./elsie_hair_wave_96_128_1.h:#define elsie_hair_wave_96_128_1_TILE_COUNT 140
./elsie_hair_wave_96_128_2.h:#define elsie_hair_wave_96_128_2_TILE_COUNT 139
./elsie_hair_wave_96_128_3.h:#define elsie_hair_wave_96_128_3_TILE_COUNT 140
./elsie_hair_wave_96_128_4.h:#define elsie_hair_wave_96_128_4_TILE_COUNT 139
./elsie_hair_wave_96_128_5.h:#define elsie_hair_wave_96_128_5_TILE_COUNT 140
./elsie_hair_wave_96_128_tilesheet.h:#define elsie_hair_wave_96_128_tilesheet_TILE_COUNT 274
```

### 2: window flicker options

see blog post

### 3: sprite limits

see blog post

### 4: rom overwrite

by default, compilation will succeed and give you a warning.

romusage has a flag: `-R  : Return error code for Area warnings and errors`

```
C:\Users\jgens\Downloads\gbdk\bin\romusage.exe .\bazel-bin\4_rom_overwrite\rom_1.gb

Bank         Range                Size     Used  Used%     Free  Free% 
--------     ----------------  -------  -------  -----  -------  -----
ROM_0        0x0000 -> 0x3FFF    16384      500     3%    15884    97%
ROM_1        0x4000 -> 0x7FFF    16384    16059    98%      325     2%
ROM_2        0x4000 -> 0x7FFF    16384     3468    21%    12916    79%
```