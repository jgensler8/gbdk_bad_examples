#include <gbdk/platform.h>
#include "../assets/elsie_hair_wave_96_128_1.h"
#include "../assets/elsie_hair_wave_96_128_2.h"
#include "../assets/elsie_hair_wave_96_128_3.h"
#include "../assets/elsie_hair_wave_96_128_4.h"
#include "../assets/elsie_hair_wave_96_128_5.h"

// set_bkg_data constants
#define TILE_START 0
// set_bkg_tiles constants
#define WIDTH_IN_TILES (96 / 8)
#define HEIGHT_IN_TILES (128 / 8)
#define BKG_TILE_X 0
#define BKG_TILE_Y 0
// loop constants
#define FRAME_START 1
#define MAX_FRAMES 5
#define DELAY_MS 150
void main(void)
{
    SHOW_BKG;
    uint8_t frame = 1;
    while (1)
    {
        vsync();
        switch (frame)
        {
        case 1:
            set_bkg_data(TILE_START, elsie_hair_wave_96_128_1_TILE_COUNT, elsie_hair_wave_96_128_1_tiles);
            set_bkg_tiles(BKG_TILE_X, BKG_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_hair_wave_96_128_1_map);
            break;
        case 2:
            set_bkg_data(TILE_START, elsie_hair_wave_96_128_2_TILE_COUNT, elsie_hair_wave_96_128_2_tiles);
            set_bkg_tiles(BKG_TILE_X, BKG_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_hair_wave_96_128_2_map);
            break;
        case 3:
            set_bkg_data(TILE_START, elsie_hair_wave_96_128_3_TILE_COUNT, elsie_hair_wave_96_128_3_tiles);
            set_bkg_tiles(BKG_TILE_X, BKG_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_hair_wave_96_128_3_map);
            break;
        case 4:
            set_bkg_data(TILE_START, elsie_hair_wave_96_128_4_TILE_COUNT, elsie_hair_wave_96_128_4_tiles);
            set_bkg_tiles(BKG_TILE_X, BKG_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_hair_wave_96_128_4_map);
            break;
        case 5:
            set_bkg_data(TILE_START, elsie_hair_wave_96_128_5_TILE_COUNT, elsie_hair_wave_96_128_5_tiles);
            set_bkg_tiles(BKG_TILE_X, BKG_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_hair_wave_96_128_5_map);
            break;
        }

        frame += 1;
        if (frame > MAX_FRAMES)
        {
            frame = FRAME_START;
        }
        delay(DELAY_MS);
    }
}