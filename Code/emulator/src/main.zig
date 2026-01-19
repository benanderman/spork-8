const std = @import("std");
const emulator = @import("emulator");

pub fn main() !u8 {
    return try emulator.run();
}
