#include <gbdk/platform.h>
#include "../assets/elsie_hair_wave_96_128_1.h"
#include "../assets/elsie_hair_wave_96_128_2.h"
#include "../assets/elsie_hair_wave_96_128_3.h"
#include "../assets/elsie_hair_wave_96_128_4.h"
// #include "../assets/elsie_hair_wave_96_128_5.h"
#include "../assets/heading_text_1.h"
#include "../assets/heading_text_2.h"
#include "../assets/heading_text_3.h"
#include "../assets/heading_text_4.h"
#include "../assets/elsie_right.h"

// set_bkg_data constants
#define TEXT_TILE_START 0
#define TILE_START 100
// set_bkg_tiles constants
#define WIDTH_IN_TILES (96 / 8)
#define HEIGHT_IN_TILES (128 / 8)
#define TEXT_TILE_X 1
#define TEXT_TILE_Y 0
#define PERSON_LEFT_TILE_X 0
#define PERSON_LEFT_TILE_Y 4
#define PERSON_RIGHT_TILE_X 6
#define PERSON_RIGHT_TILE_Y 4
// loop constants
#define FRAME_START 1
#define MAX_FRAMES 4
// #define DELAY_MS 1400
#define DELAY_MS 300
// #define DELAY_MS 150

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

inline void fill_bkg_to_unmapped(void) {
    // map all tiles to the last tile
    fill_bkg_rect(0,0, 160/8, 144/8, 254);
}

void main(void)
{   
    SHOW_BKG;
    uint8_t frame = 1;
    while (1)
    {
        // vsync();
        SHOW_WIN;
        // fill_bkg_to_unmapped();
        switch (frame)
        {
        case 1:
            // left
            set_bkg_data(TEXT_TILE_START, heading_text_1_TILE_COUNT, heading_text_1_tiles);
            scene_set_bkg_submap_fixed(0,0, 0,0, 160/8,4, heading_text_1_map, 160/8, TEXT_TILE_START);
            set_bkg_data(TILE_START, elsie_hair_wave_96_128_1_TILE_COUNT, elsie_hair_wave_96_128_1_tiles);
            scene_set_bkg_submap_fixed(0,0, PERSON_LEFT_TILE_X, PERSON_LEFT_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_hair_wave_96_128_1_map, WIDTH_IN_TILES, TILE_START);
            break;
        case 2:
            // right
            set_bkg_data(TEXT_TILE_START, heading_text_2_TILE_COUNT, heading_text_2_tiles);
            scene_set_bkg_submap_fixed(0,0, 0,0, 160/8,4, heading_text_2_map, 160/8, TEXT_TILE_START);
            set_bkg_data(TILE_START, elsie_right_TILE_COUNT, elsie_right_tiles);
            scene_set_bkg_submap_fixed(0,0, PERSON_RIGHT_TILE_X, PERSON_RIGHT_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_right_map, WIDTH_IN_TILES, TILE_START);
            break;
        case 3:
            // left
            set_bkg_data(TEXT_TILE_START, heading_text_3_TILE_COUNT, heading_text_3_tiles);
            scene_set_bkg_submap_fixed(0,0, 0,0, 160/8,4, heading_text_3_map, 160/8, TEXT_TILE_START);
            set_bkg_data(TILE_START, elsie_hair_wave_96_128_2_TILE_COUNT, elsie_hair_wave_96_128_2_tiles);
            scene_set_bkg_submap_fixed(0,0, PERSON_LEFT_TILE_X, PERSON_LEFT_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_hair_wave_96_128_2_map, WIDTH_IN_TILES, TILE_START);
            break;
        case 4:
            // right
            set_bkg_data(TEXT_TILE_START, heading_text_4_TILE_COUNT, heading_text_4_tiles);
            scene_set_bkg_submap_fixed(0,0, 0,0, 160/8,4, heading_text_4_map, 160/8, TEXT_TILE_START);
            set_bkg_data(TILE_START, elsie_right_TILE_COUNT, elsie_right_tiles);
            scene_set_bkg_submap_fixed(0,0, PERSON_RIGHT_TILE_X, PERSON_RIGHT_TILE_Y, WIDTH_IN_TILES, HEIGHT_IN_TILES, elsie_right_map, WIDTH_IN_TILES, TILE_START);
            break;
        }
        HIDE_WIN;

        frame += 1;
        if (frame > MAX_FRAMES)
        {
            frame = FRAME_START;
        }
        delay(DELAY_MS);
    }
}