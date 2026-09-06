export fn _start() noreturn {
    inline for (0..100) |_| {
        setOutputA(0b00000001);
        setOutputA(0b00000011);
        setOutputA(0b00000000);
        setOutputA(0b00000010);
    }
    setOutputA(0b00000100);
    @trap();
}

inline fn setOutputA(value: u8) void {
    asm volatile ("LoadI OutA %[arg]"
        :
        : [arg] "I" (value),
    );
}
