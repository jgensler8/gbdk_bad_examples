#include <gbdk/platform.h>
#include "../assets/numbered_tiles.h"

void main(void)
{
    SPRITES_8x16;
    SHOW_SPRITES;
    set_sprite_data(0, 2 * (160 / 8), numbered_tiles_tiles);
    for (int sp = 0; sp < 10; sp++)
    {
        set_sprite_tile(sp, sp*2);
        move_sprite(sp, sp * 8 + 8, 16);
    }
    // move the second row down, one pixel at a time
    for(int sp = 0; sp < 20; sp++) {
        set_sprite_tile(10 + sp, sp*2);
        move_sprite(10 + sp, sp * 8 + 8, 16 + (sp/2));
    }
}