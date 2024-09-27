#include <gbdk/platform.h>
#include "../assets/numbered_tiles.h"

void main(void)
{
    SPRITES_8x8;
    SHOW_SPRITES;
    set_sprite_data(0, 2 * (160 / 8), numbered_tiles_tiles);
    for (int sp = 0; sp < 20; sp++)
    {
        set_sprite_tile(sp, sp);
        move_sprite(sp, sp * 8 + 8, 16);
    }
}