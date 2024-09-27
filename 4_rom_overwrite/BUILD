load("//platforms:gameboy.bzl", "gameboy_rom")

gameboy_rom(
    name = "rom_1",
    srcs = [
        "main_1.c",
        # these are in bank 1
        "//assets:asset_src",
        # this is also in bank 1
        "//assets:tilesheet_src",
        "//assets:elsie_right_bank_1_src",
    ],
    extra_lcc_args = "-Wa-l -Wl-m -Wm-yc -Wm-yo{rom_banks} -Wm-ya{ram_banks} -Wm-yt0x1A".format(rom_banks=64, ram_banks=1),
)