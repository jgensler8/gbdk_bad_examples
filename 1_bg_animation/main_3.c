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
// #define WIDTH_IN_TILES 10
// #define HEIGHT_IN_TILES 10
#define BKG_TILE_X 0
#define BKG_TILE_Y 0
// loop constants
#define FRAME_START 1
#define MAX_FRAMES 5
#define DELAY_MS 150

void scene_set_bkg_submap_fixed(uint8_t map_x,
                                uint8_t map_y,
                                uint8_t dest_x,
                                uint8_t dest_y,
                                uint8_t w,
                                uint8_t h,
                                const uint8_t *map,
                                uint8_t map_w,
                                uint8_t tile_offset)
{
    // uint8_t upper_left = map_x + map_x*map_w;
    for (uint8_t dy = 0; dy < h; dy++)
    {
        uint16_t y_map_offset = map_y + dy * map_w;
        for (uint8_t dx = 0; dx < w; dx++)
        {
            uint8_t x_map_offset = map_x + dx;
            uint16_t idx = x_map_offset + y_map_offset;
            uint8_t tile = map[idx];
            set_bkg_tile_xy(dest_x + dx, dest_y + dy, tile + tile_offset);
        }
    }
    // set_bkg_submap(x,y, w,h, map, map_w);
}


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
            scene_set_bkg_submap_fixed(0,0, BKG_TILE_X, BKG_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_hair_wave_96_128_1_map, WIDTH_IN_TILES,TILE_START);
            break;
        case 2:
            set_bkg_data(TILE_START, elsie_hair_wave_96_128_2_TILE_COUNT, elsie_hair_wave_96_128_2_tiles);
            scene_set_bkg_submap_fixed(0,0,BKG_TILE_X, BKG_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_hair_wave_96_128_2_map, WIDTH_IN_TILES,TILE_START);
            break;
        case 3:
            set_bkg_data(TILE_START, elsie_hair_wave_96_128_3_TILE_COUNT, elsie_hair_wave_96_128_3_tiles);
            scene_set_bkg_submap_fixed(0,0,BKG_TILE_X, BKG_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_hair_wave_96_128_3_map, WIDTH_IN_TILES,TILE_START);
            break;
        case 4:
            set_bkg_data(TILE_START, elsie_hair_wave_96_128_4_TILE_COUNT, elsie_hair_wave_96_128_4_tiles);
            scene_set_bkg_submap_fixed(0,0,BKG_TILE_X, BKG_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_hair_wave_96_128_4_map, WIDTH_IN_TILES,TILE_START);
            break;
        case 5:
            set_bkg_data(TILE_START, elsie_hair_wave_96_128_5_TILE_COUNT, elsie_hair_wave_96_128_5_tiles);
            scene_set_bkg_submap_fixed(0,0,BKG_TILE_X, BKG_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_hair_wave_96_128_5_map, WIDTH_IN_TILES,TILE_START);
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