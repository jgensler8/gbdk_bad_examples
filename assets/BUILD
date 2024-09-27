filegroup(
    name = "asset_header",
    srcs = glob(["elsie_hair_wave_96_128_{}.h".format(i) for i in range(1,5+1)]),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "asset_src",
    srcs = glob(["elsie_hair_wave_96_128_{}.c".format(i) for i in range(1,5+1)]),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "tilesheet_src",
    srcs = [
        "elsie_hair_wave_96_128_tilesheet.c",
    ],
    visibility = ["//visibility:public"],
)

filegroup(
    name = "headings_src",
    srcs = glob(["heading_text_{}.c".format(i) for i in range(1,4+1)]),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "elsie_right_src",
    srcs = ["elsie_right.c"],
    visibility = ["//visibility:public"],
)

filegroup(
    name = "elsie_right_bank_1_src",
    srcs = ["elsie_right_bank_1.c"],
    visibility = ["//visibility:public"],
)

filegroup(
    name = "numbered_tiles_src",
    srcs = ["numbered_tiles.c"],
    visibility = ["//visibility:public"],
)
