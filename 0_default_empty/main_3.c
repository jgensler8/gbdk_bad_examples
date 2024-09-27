#include <gbdk/platform.h>

const uint8_t bg_tiles_data[16] = {
	0x01,0x00,
    0x02,0x00,
	0x03,0x00,
    0x04,0x00,
	0x01,0x01,
    0x01,0x02,
	0x01,0x03,
    0x01,0x04,
};

#define NUM_TILES 1
#define TILE_START 0
#define TILE_X 1
#define TILE_Y 1

void main(void) {
    // docs: https://gbdk-2020.github.io/gbdk-2020/docs/api/gb_8h.html#a1f5101f2b7bb0123c26a3e257f843626
    set_bkg_data(TILE_START, NUM_TILES, bg_tiles_data);

    // docs: https://gbdk-2020.github.io/gbdk-2020/docs/api/gb_8h.html#aaad2823459f54a08a18be59d4c3d63d8
    set_bkg_tile_xy(TILE_X,TILE_Y, TILE_START);

    SHOW_BKG;
}