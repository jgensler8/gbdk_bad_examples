def _gameboy_rom_impl(ctx):
    rom_file = ctx.actions.declare_file(ctx.label.name + ".gb")
    gbdk_root = "C:/Users/jgens/Downloads/gbdk"
    lcc = gbdk_root + "/bin/lcc.exe"
    ctx.actions.run_shell(
        inputs=ctx.files.srcs,
        outputs=[rom_file],
        use_default_shell_env=True,
        command="{lcc} -v -o {rom_file} {extra_lcc_args} {srcs}".format(
            lcc=lcc,
            rom_file=rom_file.path,
            extra_lcc_args=ctx.attr.extra_lcc_args,
            srcs=" ".join([f.path for f in ctx.files.srcs]),
        ),
    )
    return [DefaultInfo(
        files=depset([rom_file])
    )]

gameboy_rom = rule(
    implementation = _gameboy_rom_impl,
    attrs = {
        "srcs": attr.label_list(allow_files=True),
        "extra_lcc_args": attr.string(default=""),
    }
)