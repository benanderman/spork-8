//! By convention, root.zig is the root source file when making a library.

const print = std.debug.print;
const std = @import("std");
const builtin = @import("builtin");
const os = std.os;
const assert = std.debug.assert;

const c = @cImport({
    @cDefine("SDL_DISABLE_OLD_NAMES", {});
    @cInclude("SDL3/SDL.h");
    @cInclude("SDL3/SDL_revision.h");
    @cDefine("SDL_MAIN_HANDLED", {}); // We are providing our own entry point
    @cInclude("SDL3/SDL_main.h");
    @cInclude("spork_8_state.h");
});

// Constants for peripherals.
const screen_RCLCK: u8 = 0b00000100;
const screen_SRCLCK: u8 = 0b00000010;
const screen_SER: u8 = 0b00000001;
const controller_SER: u8 = 0b00000001;
const controller_CONN: u8 = 0b00000010;
const controller_SHLD: u8 = 0b00000001;
const controller_CLK: u8 = 0b00000010;

const pixel_w = 10;
const pixel_h = 20;
const pixel_size = 20;
const window_w = pixel_w * pixel_size;
const window_h = pixel_h * pixel_size;
var window: *c.SDL_Window = undefined;
var renderer: *c.SDL_Renderer = undefined;

// var progmem = [_]u8{0} ** 65536;
var ram = [_]u8{0} ** 65536;
var state: c.struct_Spork8State = .{
    .inst_reg = 0,
    .flags_reg = 0,
    .mi_counter = 0,
    .bus = 0,

    .get_progmem_byte = get_progmem_byte,
    .get_ram_byte = get_ram_byte,
    .set_ram_byte = set_ram_byte,
};

var screen_buffer: u200 = 2;
var screen_buffer_internal: u200 = 2;
var controller_buffer: u8 = 0;

// Moving Dot
// const cartridge = [_]u8{
//     0x6b, 0x80, 0xd2, 0x11, 0x04, 0x38, 0x00, 0x11, 0x01, 0x38, 0x01, 0x11, 0x01, 0x16, 0x00, 0x16,
//     0x02, 0x16, 0x00, 0x16, 0x01, 0x87, 0x69, 0x80, 0x7c, 0x16, 0x03, 0x16, 0x01, 0x87, 0x69, 0x80,
//     0x5c, 0x16, 0x03, 0x16, 0x01, 0x87, 0x69, 0x80, 0x6c, 0x16, 0x03, 0x16, 0x01, 0x87, 0x69, 0x80,
//     0x4c, 0x16, 0x03, 0x16, 0x01, 0x87, 0x6e, 0x80, 0xd2, 0x16, 0x03, 0x16, 0x01, 0x87, 0x6e, 0x80,
//     0xf1, 0x16, 0x03, 0x16, 0x01, 0x16, 0x03, 0x16, 0x01, 0x66, 0x80, 0x0b, 0x0a, 0x00, 0x01, 0x79,
//     0x00, 0x67, 0x80, 0x8c, 0x95, 0x01, 0x30, 0x00, 0x01, 0x66, 0x80, 0x8c, 0x0a, 0x00, 0x01, 0x90,
//     0x01, 0x79, 0x14, 0x67, 0x80, 0x8c, 0x30, 0x00, 0x01, 0x66, 0x80, 0x8c, 0x0a, 0x00, 0x00, 0x79,
//     0x00, 0x67, 0x80, 0x8c, 0x95, 0x01, 0x30, 0x00, 0x00, 0x66, 0x80, 0x8c, 0x0a, 0x00, 0x00, 0x90,
//     0x01, 0x79, 0x0a, 0x67, 0x80, 0x8c, 0x30, 0x00, 0x00, 0x66, 0x80, 0x8c, 0x11, 0x00, 0x38, 0x02,
//     0x11, 0x00, 0x38, 0x03, 0x0a, 0x00, 0x00, 0x7b, 0x00, 0x03, 0x69, 0x80, 0xad, 0x0a, 0x00, 0x01,
//     0x7b, 0x00, 0x02, 0x69, 0x80, 0xad, 0x15, 0x01, 0x15, 0x03, 0x66, 0x80, 0xb1, 0x15, 0x00, 0x15,
//     0x02, 0x0a, 0x00, 0x03, 0x90, 0x01, 0x30, 0x00, 0x03, 0x79, 0x0a, 0x69, 0x80, 0x94, 0x0a, 0x00,
//     0x02, 0x90, 0x01, 0x30, 0x00, 0x02, 0x79, 0x14, 0x69, 0x80, 0x90, 0x15, 0x04, 0x15, 0x00, 0x66,
//     0x80, 0x0b, 0x11, 0xc8, 0x7b, 0x00, 0x00, 0x69, 0x80, 0xe1, 0x15, 0x01, 0x15, 0x03, 0x66, 0x80,
//     0xe5, 0x15, 0x00, 0x15, 0x02, 0x95, 0x01, 0x69, 0x80, 0xd4, 0x15, 0x04, 0x15, 0x00, 0x66, 0x80,
//     0x0b, 0x11, 0xc8, 0x15, 0x01, 0x15, 0x03, 0x95, 0x01, 0x69, 0x80, 0xf3, 0x15, 0x04, 0x15, 0x00,
//     0x66, 0x80, 0x0b,
// };

// Moving Dot with return and 01 constants
// const cartridge = [_]u8{
//     0x6b, 0x01, 0x80, 0xd5, 0x11, 0x04, 0x38, 0x00, 0x11, 0x01, 0x38, 0x01, 0x11, 0x01, 0x16, 0x00,
//     0x16, 0x02, 0x16, 0x00, 0x16, 0x01, 0x87, 0x69, 0x80, 0x7f, 0x16, 0x03, 0x16, 0x01, 0x87, 0x69,
//     0x80, 0x5f, 0x16, 0x03, 0x16, 0x01, 0x87, 0x69, 0x80, 0x6f, 0x16, 0x03, 0x16, 0x01, 0x87, 0x69,
//     0x80, 0x4f, 0x16, 0x03, 0x16, 0x01, 0x87, 0x6e, 0x01, 0x80, 0xd5, 0x16, 0x03, 0x16, 0x01, 0x87,
//     0x6e, 0x01, 0x80, 0xf3, 0x16, 0x03, 0x16, 0x01, 0x16, 0x03, 0x16, 0x01, 0x66, 0x80, 0x0c, 0x0a,
//     0x00, 0x01, 0x79, 0x00, 0x67, 0x80, 0x8f, 0x9e, 0x01, 0x30, 0x00, 0x01, 0x66, 0x80, 0x8f, 0x0a,
//     0x00, 0x01, 0x99, 0x01, 0x79, 0x14, 0x67, 0x80, 0x8f, 0x30, 0x00, 0x01, 0x66, 0x80, 0x8f, 0x0a,
//     0x00, 0x00, 0x79, 0x00, 0x67, 0x80, 0x8f, 0x9e, 0x01, 0x30, 0x00, 0x00, 0x66, 0x80, 0x8f, 0x0a,
//     0x00, 0x00, 0x99, 0x01, 0x79, 0x0a, 0x67, 0x80, 0x8f, 0x30, 0x00, 0x00, 0x66, 0x80, 0x8f, 0x11,
//     0x00, 0x38, 0x02, 0x11, 0x00, 0x38, 0x03, 0x0a, 0x00, 0x00, 0x7b, 0x00, 0x03, 0x69, 0x80, 0xb0,
//     0x0a, 0x00, 0x01, 0x7b, 0x00, 0x02, 0x69, 0x80, 0xb0, 0x15, 0x01, 0x15, 0x03, 0x66, 0x80, 0xb4,
//     0x15, 0x00, 0x15, 0x02, 0x0a, 0x00, 0x03, 0x99, 0x01, 0x30, 0x00, 0x03, 0x79, 0x0a, 0x69, 0x80,
//     0x97, 0x0a, 0x00, 0x02, 0x99, 0x01, 0x30, 0x00, 0x02, 0x79, 0x14, 0x69, 0x80, 0x93, 0x15, 0x04,
//     0x15, 0x00, 0x66, 0x80, 0x0c, 0x11, 0xc8, 0x7b, 0x00, 0x00, 0x69, 0x80, 0xe4, 0x15, 0x01, 0x15,
//     0x03, 0x66, 0x80, 0xe8, 0x15, 0x00, 0x15, 0x02, 0x9e, 0x01, 0x69, 0x80, 0xd7, 0x15, 0x04, 0x15,
//     0x00, 0x70, 0x01, 0x11, 0xc8, 0x15, 0x01, 0x15, 0x03, 0x9e, 0x01, 0x69, 0x80, 0xf5, 0x15, 0x04,
//     0x15, 0x00, 0x66, 0x80, 0x0c,
// };

// Snake 2
const static_cartridge = [_]u8{
    0x66, 0x80, 0x09, 0x66, 0x80, 0x5d, 0x66, 0x80, 0x00, 0x09, 0x00, 0x11, 0xff, 0x13, 0x00, 0x04,
    0x03, 0x4f, 0x04, 0x04, 0x4f, 0x9e, 0x01, 0x69, 0x80, 0x0f, 0x37, 0x00, 0x12, 0x01, 0x37, 0x00,
    0x21, 0x00, 0x37, 0x00, 0x20, 0x05, 0x37, 0x03, 0x00, 0x04, 0x37, 0x03, 0x01, 0x04, 0x37, 0x03,
    0x02, 0x04, 0x37, 0x03, 0x03, 0x04, 0x37, 0x03, 0x04, 0x04, 0x37, 0x03, 0x05, 0x04, 0x37, 0x04,
    0x00, 0x00, 0x37, 0x04, 0x01, 0x01, 0x37, 0x04, 0x02, 0x02, 0x37, 0x04, 0x03, 0x03, 0x37, 0x04,
    0x04, 0x04, 0x37, 0x04, 0x05, 0x05, 0x37, 0x00, 0x14, 0x54, 0x66, 0x80, 0x03, 0x13, 0x80, 0x66,
    0x80, 0x75, 0x5c, 0x9e, 0x01, 0x55, 0x69, 0x80, 0x5f, 0x66, 0x80, 0xba, 0x66, 0x81, 0x27, 0x66,
    0x81, 0x60, 0x66, 0x80, 0x5d, 0x11, 0x01, 0x16, 0x00, 0x16, 0x02, 0x16, 0x00, 0x16, 0x01, 0x87,
    0x69, 0x80, 0xac, 0x16, 0x03, 0x16, 0x01, 0x87, 0x69, 0x80, 0x9e, 0x16, 0x03, 0x16, 0x01, 0x87,
    0x69, 0x80, 0xb3, 0x16, 0x03, 0x16, 0x01, 0x87, 0x69, 0x80, 0xa5, 0x66, 0x80, 0x62, 0x37, 0x00,
    0x12, 0x00, 0x66, 0x80, 0x8b, 0x37, 0x00, 0x12, 0x01, 0x66, 0x80, 0x9b, 0x37, 0x00, 0x12, 0x02,
    0x66, 0x80, 0x83, 0x37, 0x00, 0x12, 0x03, 0x66, 0x80, 0x93, 0x0a, 0x00, 0x12, 0x7a, 0x02, 0x69,
    0x80, 0xc5, 0x67, 0x80, 0xf2, 0x0a, 0x00, 0x20, 0x05, 0x04, 0x03, 0x28, 0x04, 0x04, 0x2e, 0x49,
    0x99, 0x01, 0x30, 0x00, 0x20, 0x0a, 0x00, 0x12, 0x79, 0x02, 0x5c, 0x67, 0x80, 0xe3, 0x99, 0x01,
    0x66, 0x80, 0xe8, 0x9e, 0x01, 0x66, 0x80, 0xe8, 0x0c, 0x00, 0x20, 0x04, 0x03, 0x07, 0x46, 0x66,
    0x81, 0x1c, 0x0a, 0x00, 0x20, 0x05, 0x04, 0x04, 0x28, 0x04, 0x03, 0x2e, 0x49, 0x99, 0x01, 0x30,
    0x00, 0x20, 0x0a, 0x00, 0x12, 0x79, 0x00, 0x5c, 0x67, 0x81, 0x10, 0x99, 0x01, 0x66, 0x81, 0x15,
    0x9e, 0x01, 0x66, 0x81, 0x15, 0x0c, 0x00, 0x20, 0x04, 0x04, 0x07, 0x46, 0x0a, 0x00, 0x21, 0x99,
    0x01, 0x30, 0x00, 0x21, 0x66, 0x80, 0x6c, 0x04, 0x02, 0x09, 0x00, 0x11, 0xc8, 0x13, 0x00, 0x4f,
    0x9e, 0x01, 0x69, 0x81, 0x2f, 0x0c, 0x00, 0x21, 0x04, 0x04, 0x07, 0x26, 0x54, 0xa8, 0x8b, 0xa8,
    0x04, 0x03, 0x27, 0xa8, 0x04, 0x02, 0x05, 0x11, 0x01, 0x46, 0x5c, 0x99, 0x01, 0x55, 0x7b, 0x00,
    0x20, 0x68, 0x81, 0x38, 0x0c, 0x00, 0x14, 0x04, 0x02, 0x07, 0x11, 0x01, 0x46, 0x66, 0x80, 0x6f,
    0x13, 0xc8, 0x04, 0x02, 0x09, 0x00, 0x2b, 0x79, 0x00, 0x11, 0x00, 0x9c, 0x01, 0x58, 0x99, 0x02,
    0x58, 0x5c, 0x9e, 0x01, 0x55, 0x69, 0x81, 0x66, 0x15, 0x04, 0x15, 0x00, 0x66, 0x80, 0x72,
};

var cartridge = [_]u8{0} ** 65536;

// Jump to cartridge
const progmem_eeprom = [_]u8{ 0x66, 0x80, 0x00 };

fn get_progmem_byte(address: c_ushort) callconv(.c) u8 {
    if (address & 1 << 15 != 0) {
        const cart_address = address & 0x7FFF;
        if (cart_address >= cartridge.len) return 0;
        return cartridge[cart_address];
    }
    return progmem_eeprom[address];
}

fn get_ram_byte(address: c_ushort) callconv(.c) u8 {
    return ram[address];
}

fn set_ram_byte(address: c_ushort, value: u8) callconv(.c) void {
    ram[address] = value;
}

var fully_initialized = false;

pub fn run() !u8 {
    app_err.reset();
    var empty_argv: [0:null]?[*:0]u8 = .{};
    const status: u8 = @truncate(@as(c_uint, @bitCast(c.SDL_RunApp(empty_argv.len, @ptrCast(&empty_argv), sdlMainC, null))));
    return app_err.load() orelse status;
}

fn sdlAppInit(appstate: ?*?*anyopaque, argv: [][*:0]u8) !c.SDL_AppResult {
    _ = appstate;
    _ = argv;

    try errify(c.SDL_SetAppMetadata("Spork 8", "0.0.1", "com.happyspork.Spork8Emulator"));

    try errify(c.SDL_Init(c.SDL_INIT_VIDEO));

    errify(c.SDL_SetHint(c.SDL_HINT_RENDER_VSYNC, "1")) catch {};

    try errify(c.SDL_CreateWindowAndRenderer("Spork 8", window_w, window_h, 0, @ptrCast(&window), @ptrCast(&renderer)));
    errdefer c.SDL_DestroyWindow(window);
    errdefer c.SDL_DestroyRenderer(renderer);

    if (std.os.argv.len > 1) {
        const asm_path = std.mem.span(std.os.argv[1]);

        // Call customasm directly - doesn't work because customasm doesn't print the same thing with -p
        // var gpa = std.heap.GeneralPurposeAllocator(.{}){};
        // defer std.debug.assert(gpa.deinit() == .ok);
        // const allocator = gpa.allocator();
        // const result = try std.process.Child.run(.{
        //     .allocator = allocator,
        //     .argv = &[_][]const u8{ "customasm", asm_path, "-p", "-q", "-f", "binary" }, // The command and its arguments
        //     .max_output_bytes = 65536, // Set a limit for output size
        // });
        // defer allocator.free(result.stdout);
        // defer allocator.free(result.stderr);

        // 1. Get the current working directory as a starting point.
        const cwd = std.fs.cwd();

        // 2. Open the file. The `.{}` uses default open flags (read-only is common).
        // The `try` keyword handles potential errors.
        const file = try cwd.openFile(asm_path, .{});
        defer file.close(); // Ensure the file is closed when the function exits.

        // 3. Get a general purpose allocator for dynamic memory management.
        // The `defer gpa.deinit()` ensures memory leak detection in debug mode.
        var gpa = std.heap.GeneralPurposeAllocator(.{ .thread_safe = true }){};
        const allocator = gpa.allocator();
        defer std.debug.assert(gpa.deinit() == .ok);

        // 4. Read the entire file content into an allocated buffer.
        // This function handles the allocation based on the file size.
        // You provide a maximum size limit as a safety check.
        const file_contents = try file.deprecatedReader().readAllAlloc(allocator, 65_536);
        defer allocator.free(file_contents); // Free the allocated buffer.

        for (file_contents[0x8000..], 0x8000..) |value, index| {
            cartridge[index - 0x8000] = value;
        }
    } else {
        for (static_cartridge, 0..) |value, index| {
            cartridge[index] = value;
        }
    }

    // for (cartridge[0..300], 0..300) |value, index| {
    //     std.debug.print("Cartridge index, value: {}, val: {x}\n", .{ index, value });
    // }

    // for (progmem_eeprom, 0..) |value, index| {
    //     progmem[index] = value;
    // }

    c.spork8_state_reset(&state);

    errdefer comptime unreachable;

    fully_initialized = true;

    return c.SDL_APP_CONTINUE;
}

fn sdlAppIterate(appstate: ?*anyopaque) !c.SDL_AppResult {
    _ = appstate;

    const old_outa_value = state.module_values[c.OUTA];
    const old_ioa_value = c.spork8_state_get_output_value(&state, c.IOA);

    c.spork8_state_cycle(&state);

    // Update screen.
    const new_outa_state = state.module_values[c.OUTA];
    if ((old_outa_value & screen_SRCLCK) == 0 and (new_outa_state & screen_SRCLCK) != 0) {
        screen_buffer_internal <<= 1;
        if ((new_outa_state & screen_SER) != 0)
            screen_buffer_internal |= 1;
    }
    var need_redraw = false;
    if ((old_outa_value & screen_RCLCK) == 0 and (new_outa_state & screen_RCLCK) != 0) {
        screen_buffer = screen_buffer_internal;
        need_redraw = true;
        // print("Need redraw: {}\n", .{need_redraw});
    }

    // Update controller.
    const new_ioa_value = c.spork8_state_get_output_value(&state, c.IOA);
    if ((old_ioa_value & controller_CLK) == 0 and (new_ioa_value & controller_CLK) != 0) {
        if (new_ioa_value & controller_SHLD != 0) {
            // print("Shifting controller\n", .{});
            controller_buffer >>= 1;
        } else {
            var count: c_int = 0;
            const keyboard_state = c.SDL_GetKeyboardState(&count);
            const scancodes = [8]c_int{
                c.SDL_SCANCODE_LEFT,
                c.SDL_SCANCODE_UP,
                c.SDL_SCANCODE_RIGHT,
                c.SDL_SCANCODE_DOWN,
                c.SDL_SCANCODE_ESCAPE,
                c.SDL_SCANCODE_RETURN,
                c.SDL_SCANCODE_A,
                c.SDL_SCANCODE_S,
            };
            controller_buffer = 0;
            for (scancodes, 0..) |value, index| {
                const u3_index: u3 = @intCast(index);
                const u8_value: u8 = if (keyboard_state[@intCast(value)]) 1 else 0;
                controller_buffer |= (u8_value << u3_index);
            }
            // print("Set controller state: {}\n", .{controller_buffer});
        }
        const ser_value = if (controller_buffer & 1 != 0) controller_SER else 0;
        c.spork8_state_set_input_value(&state, c.IOA, controller_CONN | ser_value);
    }

    // Draw.
    if (need_redraw) {
        // print("Drawing\n", .{});
        try errify(c.SDL_SetRenderDrawColor(renderer, 0x47, 0x5b, 0x8d, 0xff));
        try errify(c.SDL_RenderClear(renderer));

        try errify(c.SDL_SetRenderScale(renderer, 1, 1));
        {
            try errify(c.SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff));
            for (0..pixel_h) |y| {
                for (0..pixel_w) |x| {
                    const index = y * pixel_w + x;
                    if (screen_buffer & (@as(u200, 1) <<| index) == 0) {
                        continue;
                    }
                    const rect: c.SDL_FRect = .{ .x = @floatFromInt(x * pixel_size), .y = @floatFromInt(y * pixel_size), .w = @floatFromInt(pixel_size), .h = @floatFromInt(pixel_size) };
                    try errify(c.SDL_RenderFillRect(renderer, &rect));
                }
            }
        }
        try errify(c.SDL_SetRenderScale(renderer, 1, 1));

        try errify(c.SDL_RenderPresent(renderer));
    }

    return c.SDL_APP_CONTINUE;
}

fn sdlAppEvent(appstate: ?*anyopaque, event: *c.SDL_Event) !c.SDL_AppResult {
    _ = appstate;

    switch (event.type) {
        c.SDL_EVENT_QUIT => {
            return c.SDL_APP_SUCCESS;
        },
        else => {},
    }

    return c.SDL_APP_CONTINUE;
}

fn sdlAppQuit(appstate: ?*anyopaque, result: anyerror!c.SDL_AppResult) void {
    _ = appstate;

    _ = result catch |err| if (err == error.SdlError) {
        // sdl_log.err("{s}", .{c.SDL_GetError()});
    };

    if (fully_initialized) {
        c.SDL_DestroyRenderer(renderer);
        c.SDL_DestroyWindow(window);
        fully_initialized = false;
    }
}

/// Converts the return value of an SDL function to an error union.
inline fn errify(value: anytype) error{SdlError}!switch (@typeInfo(@TypeOf(value))) {
    .bool => void,
    .pointer, .optional => @TypeOf(value.?),
    .int => |info| switch (info.signedness) {
        .signed => @TypeOf(@max(0, value)),
        .unsigned => @TypeOf(value),
    },
    else => @compileError("unerrifiable type: " ++ @typeName(@TypeOf(value))),
} {
    return switch (@typeInfo(@TypeOf(value))) {
        .bool => if (!value) error.SdlError,
        .pointer, .optional => value orelse error.SdlError,
        .int => |info| switch (info.signedness) {
            .signed => if (value >= 0) @max(0, value) else error.SdlError,
            .unsigned => if (value != 0) value else error.SdlError,
        },
        else => comptime unreachable,
    };
}

//#region SDL main callbacks boilerplate

pub fn main() !u8 {
    app_err.reset();
    var empty_argv: [0:null]?[*:0]u8 = .{};
    const status: u8 = @truncate(@as(c_uint, @bitCast(c.SDL_RunApp(empty_argv.len, @ptrCast(&empty_argv), sdlMainC, null))));
    return app_err.load() orelse status;
}

fn sdlMainC(argc: c_int, argv: ?[*:null]?[*:0]u8) callconv(.c) c_int {
    return c.SDL_EnterAppMainCallbacks(argc, @ptrCast(argv), sdlAppInitC, sdlAppIterateC, sdlAppEventC, sdlAppQuitC);
}

fn sdlAppInitC(appstate: ?*?*anyopaque, argc: c_int, argv: ?[*:null]?[*:0]u8) callconv(.c) c.SDL_AppResult {
    return sdlAppInit(appstate.?, @ptrCast(argv.?[0..@intCast(argc)])) catch |err| app_err.store(err);
}

fn sdlAppIterateC(appstate: ?*anyopaque) callconv(.c) c.SDL_AppResult {
    return sdlAppIterate(appstate) catch |err| app_err.store(err);
}

fn sdlAppEventC(appstate: ?*anyopaque, event: ?*c.SDL_Event) callconv(.c) c.SDL_AppResult {
    return sdlAppEvent(appstate, event.?) catch |err| app_err.store(err);
}

fn sdlAppQuitC(appstate: ?*anyopaque, result: c.SDL_AppResult) callconv(.c) void {
    sdlAppQuit(appstate, app_err.load() orelse result);
}

var app_err: ErrorStore = .{};

const ErrorStore = struct {
    const status_not_stored = 0;
    const status_storing = 1;
    const status_stored = 2;

    status: c.SDL_AtomicInt = .{},
    err: anyerror = undefined,
    trace_index: usize = undefined,
    trace_addrs: [32]usize = undefined,

    fn reset(es: *ErrorStore) void {
        _ = c.SDL_SetAtomicInt(&es.status, status_not_stored);
    }

    fn store(es: *ErrorStore, err: anyerror) c.SDL_AppResult {
        if (c.SDL_CompareAndSwapAtomicInt(&es.status, status_not_stored, status_storing)) {
            es.err = err;
            if (@errorReturnTrace()) |src_trace| {
                es.trace_index = src_trace.index;
                const len = @min(es.trace_addrs.len, src_trace.instruction_addresses.len);
                @memcpy(es.trace_addrs[0..len], src_trace.instruction_addresses[0..len]);
            }
            _ = c.SDL_SetAtomicInt(&es.status, status_stored);
        }
        return c.SDL_APP_FAILURE;
    }

    fn load(es: *ErrorStore) ?anyerror {
        if (c.SDL_GetAtomicInt(&es.status) != status_stored) return null;
        if (@errorReturnTrace()) |dst_trace| {
            dst_trace.index = es.trace_index;
            const len = @min(dst_trace.instruction_addresses.len, es.trace_addrs.len);
            @memcpy(dst_trace.instruction_addresses[0..len], es.trace_addrs[0..len]);
        }
        return es.err;
    }
};

//#endregion SDL main callbacks boilerplate
