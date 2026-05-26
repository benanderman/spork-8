const std = @import("std");
const emulator = @import("emulator");

pub fn main(init: std.process.Init) !u8 {
    const gpa = init.gpa;

    var args = try init.minimal.args.iterateAllocator(gpa);
    defer args.deinit();

    const io = init.io;

    return try emulator.run(args, gpa, io);
}
