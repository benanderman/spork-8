#ruledef {
  SetPageReg     A                                         => 0x00                                      
  SetPageReg     B                                         => 0x01                                      
  SetPageReg     C                                         => 0x02                                      
  SetPageReg     Swap                                      => 0x03                                      
  SetPageI                            {value}              => 0x04                @ value`8             
  SetAddrReg     A                                         => 0x05                                      
  SetAddrReg     B                                         => 0x06                                      
  SetAddrReg     C                                         => 0x07                                      
  SetAddrReg     Swap                                      => 0x08                                      
  SetAddrI                            {value}              => 0x09                @ value`8             
  Load           A                    {address}            => 0x0A                @ address`16          
  Load           B                    {address}            => 0x0B                @ address`16          
  Load           C                    {address}            => 0x0C                @ address`16          
  Load           Swap                 {address}            => 0x0D                @ address`16          
  Load           OutA                 {address}            => 0x0E                @ address`16          
  Load           InOutA               {address}            => 0x0F                @ address`16          
  Load           InOutB               {address}            => 0x10                @ address`16          
  LoadI          A                    {value}              => 0x11                @ value`8             
  LoadI          B                    {value}              => 0x12                @ value`8             
  LoadI          C                    {value}              => 0x13                @ value`8             
  LoadI          Swap                 {value}              => 0x14                @ value`8             
  LoadI          OutA                 {value}              => 0x15                @ value`8             
  LoadI          InOutA               {value}              => 0x16                @ value`8             
  LoadI          InOutB               {value}              => 0x17                @ value`8             
  LoadP          A                    {value}              => 0x18                @ value`8             
  LoadP          B                    {value}              => 0x19                @ value`8             
  LoadP          C                    {value}              => 0x1A                @ value`8             
  LoadP          Swap                 {value}              => 0x1B                @ value`8             
  LoadP          OutA                 {value}              => 0x1C                @ value`8             
  LoadP          InOutA               {value}              => 0x1D                @ value`8             
  LoadP          InOutB               {value}              => 0x1E                @ value`8             
  LoadInc        A, 0                                      => 0x1F                                      
  LoadInc        B, 0                                      => 0x20                                      
  LoadInc        C, 0                                      => 0x21                                      
  LoadInc        Swap, 0                                   => 0x22                                      
  LoadInc        OutA, 0                                   => 0x23                                      
  LoadInc        A, 1                                      => 0x24                                      
  LoadInc        B, 1                                      => 0x25                                      
  LoadInc        C, 1                                      => 0x26                                      
  LoadInc        Swap, 1                                   => 0x27                                      
  LoadInc        OutA, 1                                   => 0x28                                      
  LoadStck       A                    {value}              => 0x29                @ value`8             
  LoadStck       B                    {value}              => 0x2A                @ value`8             
  LoadStck       C                    {value}              => 0x2B                @ value`8             
  LoadStck       Swap                 {value}              => 0x2C                @ value`8             
  LoadStck       OutA                 {value}              => 0x2D                @ value`8             
  Store          A                    {address}            => 0x2E                @ address`16          
  Store          B                    {address}            => 0x2F                @ address`16          
  Store          C                    {address}            => 0x30                @ address`16          
  Store          Swap                 {address}            => 0x31                @ address`16          
  Store          OutA                 {address}            => 0x32                @ address`16          
  Store          InOutA               {address}            => 0x33                @ address`16          
  Store          InOutB               {address}            => 0x34                @ address`16          
  StoreI                              {address} {value}    => 0x35                @ address`16 @ value`8
  StoreP         A                    {value}              => 0x36                @ value`8             
  StoreP         B                    {value}              => 0x37                @ value`8             
  StoreP         C                    {value}              => 0x38                @ value`8             
  StoreP         Swap                 {value}              => 0x39                @ value`8             
  StoreP         OutA                 {value}              => 0x3A                @ value`8             
  StoreP         InOutA               {value}              => 0x3B                @ value`8             
  StoreP         InOutB               {value}              => 0x3C                @ value`8             
  StoreInc       A, 0                                      => 0x3D                                      
  StoreInc       B, 0                                      => 0x3E                                      
  StoreInc       C, 0                                      => 0x3F                                      
  StoreInc       Swap, 0                                   => 0x40                                      
  StoreInc       OutA, 0                                   => 0x41                                      
  StoreInc       InOutA, 0                                 => 0x42                                      
  StoreInc       InOutB, 0                                 => 0x43                                      
  StoreInc       A, 1                                      => 0x44                                      
  StoreInc       B, 1                                      => 0x45                                      
  StoreInc       C, 1                                      => 0x46                                      
  StoreInc       Swap, 1                                   => 0x47                                      
  StoreInc       OutA, 1                                   => 0x48                                      
  StoreInc       InOutA, 1                                 => 0x49                                      
  StoreInc       InOutB, 1                                 => 0x4A                                      
  StoreStck      A                    {value}              => 0x4B                @ value`8             
  StoreStck      B                    {value}              => 0x4C                @ value`8             
  StoreStck      C                    {value}              => 0x4D                @ value`8             
  StoreStck      Swap                 {value}              => 0x4E                @ value`8             
  StoreNStck     A                    {value}              => 0x4F                @ value`8             
  StoreNStck     B                    {value}              => 0x50                @ value`8             
  StoreNStck     C                    {value}              => 0x51                @ value`8             
  StorePStck     C                    {value}              => 0x5201              @ value`8             
  StoreStckI                          {value1} {value2}    => 0x53                @ value1`8 @ value2`8 
  StoreNStckI                         {value1} {value2}    => 0x54                @ value1`8 @ value2`8 
  StorePStckI                         {value1} {value2}    => 0x5501              @ value1`8 @ value2`8 
  Copy           A, B                                      => 0x56                                      
  Copy           A, C                                      => 0x57                                      
  Copy           A, Swap                                   => 0x58                                      
  Copy           A, Stack                                  => 0x59                                      
  Copy           A, OutA                                   => 0x5A                                      
  Copy           A, InOutA                                 => 0x5B                                      
  Copy           A, InOutB                                 => 0x5C                                      
  Copy           B, A                                      => 0x5D                                      
  Copy           C, A                                      => 0x5E                                      
  Copy           Swap, A                                   => 0x5F                                      
  Copy           Stack, A                                  => 0x60                                      
  Copy           OutA, A                                   => 0x61                                      
  Copy           InOutA, A                                 => 0x62                                      
  Copy           InOutB, A                                 => 0x63                                      
  Copy           PCnt, A                                   => 0x64                                      
  Copy           PCnt, A, HighB                            => 0x65                                      
  Copy           MAdr, A                                   => 0x66                                      
  Copy           MAdr, A, HighB                            => 0x67                                      
  Jump                                {address}            => 0x68                @ address`16          
  JumpZ                               {address}            => 0x69                @ address`16          
  JumpC                               {address}            => 0x6A                @ address`16          
  JumpNZ                              {address}            => 0x6B                @ address`16          
  JumpNC                              {address}            => 0x6C                @ address`16          
  Call                                {address}            => 0x6D00 @ ($ + 6)`16 @ address`16          
  CallZ                               {address}            => 0x6E00 @ ($ + 6)`16 @ address`16          
  CallC                               {address}            => 0x6F00 @ ($ + 6)`16 @ address`16          
  CallNZ                              {address}            => 0x7000 @ ($ + 6)`16 @ address`16          
  CallNC                              {address}            => 0x7100 @ ($ + 6)`16 @ address`16          
  Return                                                   => 0x7200                                    
  ReturnZ                                                  => 0x7300                                    
  ReturnC                                                  => 0x7400                                    
  ReturnNZ                                                 => 0x7500                                    
  ReturnNC                                                 => 0x7600                                    
  CmpI                                {value}              => 0x77                @ value`8             
  CmpAndI                             {value}              => 0x78                @ value`8             
  Cmp                                 {address}            => 0x79                @ address`16          
  CmpAnd                              {address}            => 0x7A                @ address`16          
  CmpReg         C                                         => 0x7B                                      
  CmpReg         Swap                                      => 0x7C                                      
  CmpReg         Stack                                     => 0x7D                                      
  CmpReg         OutA                                      => 0x7E                                      
  CmpReg         InOutA                                    => 0x7F                                      
  CmpReg         InOutB                                    => 0x80                                      
  CmpAndReg      C                                         => 0x81                                      
  CmpAndReg      Swap                                      => 0x82                                      
  CmpAndReg      Stack                                     => 0x83                                      
  CmpAndReg      OutA                                      => 0x84                                      
  CmpAndReg      InOutA                                    => 0x85                                      
  CmpAndReg      InOutB                                    => 0x86                                      
  ShiftL         1                                         => 0x87                                      
  ShiftL         2                                         => 0x88                                      
  ShiftL         3                                         => 0x89                                      
  ShiftL         4                                         => 0x8A                                      
  ShiftL         5                                         => 0x8B                                      
  ShiftL         6                                         => 0x8C                                      
  ShiftL         7                                         => 0x8D                                      
  ShiftR         1                                         => 0x8E                                      
  ShiftR         2                                         => 0x8F                                      
  ShiftR         3                                         => 0x90                                      
  ShiftR         4                                         => 0x91                                      
  ShiftR         5                                         => 0x92                                      
  ShiftR         6                                         => 0x93                                      
  ShiftR         7                                         => 0x94                                      
  RotateL                                                  => 0x95                                      
  RotateR                                                  => 0x96                                      
  AddI                                {value}              => 0x97                @ value`8             
  AddIZ                               {value}              => 0x98                @ value`8             
  AddIC                               {value}              => 0x99                @ value`8             
  AddINZ                              {value}              => 0x9A                @ value`8             
  AddINC                              {value}              => 0x9B                @ value`8             
  SubI                                {value}              => 0x9C                @ value`8             
  SubIZ                               {value}              => 0x9D                @ value`8             
  SubIC                               {value}              => 0x9E                @ value`8             
  SubINZ                              {value}              => 0x9F                @ value`8             
  SubINC                              {value}              => 0xA0                @ value`8             
  AndI                                {value}              => 0xA1                @ value`8             
  AndIZ                               {value}              => 0xA2                @ value`8             
  AndIC                               {value}              => 0xA3                @ value`8             
  AndINZ                              {value}              => 0xA4                @ value`8             
  AndINC                              {value}              => 0xA5                @ value`8             
  AddINF                              {value}              => 0xA6                @ value`8             
  AddINFZ                             {value}              => 0xA7                @ value`8             
  AddINFC                             {value}              => 0xA8                @ value`8             
  AddINFNZ                            {value}              => 0xA9                @ value`8             
  AddINFNC                            {value}              => 0xAA                @ value`8             
  SubINF                              {value}              => 0xAB                @ value`8             
  SubINFZ                             {value}              => 0xAC                @ value`8             
  SubINFC                             {value}              => 0xAD                @ value`8             
  SubINFNZ                            {value}              => 0xAE                @ value`8             
  SubINFNC                            {value}              => 0xAF                @ value`8             
  AndINF                              {value}              => 0xB0                @ value`8             
  AndINFZ                             {value}              => 0xB1                @ value`8             
  AndINFC                             {value}              => 0xB2                @ value`8             
  AndINFNZ                            {value}              => 0xB3                @ value`8             
  AndINFNC                            {value}              => 0xB4                @ value`8             
  AccumulateAdd                                            => 0xB5                                      
  AccumulateSub                                            => 0xB6                                      
  AccumulateAnd                                            => 0xB7                                      
  OrI                                 {value}              => 0xB8                @ value`8             
  OrIZ                                {value}              => 0xB9                @ value`8             
  OrIC                                {value}              => 0xBA                @ value`8             
  OrINZ                               {value}              => 0xBB                @ value`8             
  OrINC                               {value}              => 0xBC                @ value`8             
  XorI                                {value}              => 0xBD                @ value`8             
  XorIZ                               {value}              => 0xBE                @ value`8             
  XorIC                               {value}              => 0xBF                @ value`8             
  XorINZ                              {value}              => 0xC0                @ value`8             
  XorINC                              {value}              => 0xC1                @ value`8             
  Not                                                      => 0xC2                                      
  NotZ                                                     => 0xC3                                      
  NotC                                                     => 0xC4                                      
  NotNZ                                                    => 0xC5                                      
  NotNC                                                    => 0xC6                                      
  Add                                 {address}            => 0xC7                @ address`16          
  AddZ                                {address}            => 0xC8                @ address`16          
  AddC                                {address}            => 0xC9                @ address`16          
  AddNZ                               {address}            => 0xCA                @ address`16          
  AddNC                               {address}            => 0xCB                @ address`16          
  Sub                                 {address}            => 0xCC                @ address`16          
  SubZ                                {address}            => 0xCD                @ address`16          
  SubC                                {address}            => 0xCE                @ address`16          
  SubNZ                               {address}            => 0xCF                @ address`16          
  SubNC                               {address}            => 0xD0                @ address`16          
  And                                 {address}            => 0xD1                @ address`16          
  AndZ                                {address}            => 0xD2                @ address`16          
  AndC                                {address}            => 0xD3                @ address`16          
  AndNZ                               {address}            => 0xD4                @ address`16          
  AndNC                               {address}            => 0xD5                @ address`16          
  Or                                  {address}            => 0xD6                @ address`16          
  OrZ                                 {address}            => 0xD7                @ address`16          
  OrC                                 {address}            => 0xD8                @ address`16          
  OrNZ                                {address}            => 0xD9                @ address`16          
  OrNC                                {address}            => 0xDA                @ address`16          
  Xor                                 {address}            => 0xDB                @ address`16          
  XorZ                                {address}            => 0xDC                @ address`16          
  XorC                                {address}            => 0xDD                @ address`16          
  XorNZ                               {address}            => 0xDE                @ address`16          
  XorNC                               {address}            => 0xDF                @ address`16          
  Nop                                                      => 0xE0                                      
  Nop1                                                     => 0xE1                                      
  Nop2                                                     => 0xE2                                      
  Halt                                                     => 0xE3                                      
}

; Constants for updating a 10 x 20 shift-register display
RCLCK  = 0b00000100
SRCLCK = 0b00000010
SER    = 0b00000001
PIXELW = 10
PIXELH = 20
PIXELS = PIXELW * PIXELH

; Memory page constants
DISP_BUF     = 0x02

; Constants for input from a 74HC166-based controller
CONTROLLER_SER  = 0b00000001
CONTROLLER_CONN = 0b00000010
CONTROLLER_SHLD = 0b00000001
CONTROLLER_CLK  = 0b00000010

; Button constants, for storing button states in one byte
BUTTON_LEFT    = 1 << 0
BUTTON_UP      = 1 << 1
BUTTON_RIGHT   = 1 << 2
BUTTON_DOWN    = 1 << 3
BUTTON_START   = 1 << 4
BUTTON_SELECT  = 1 << 5
BUTTON_A       = 1 << 6
BUTTON_B       = 1 << 7

; Zero page addresses
MEM_PAGE      = 0x10 ; Address of the screen we're on (high byte)
MEM_ADDR      = 0x11 ; Address of the screen we're on (low byte)
MEM_OFFSET    = 0x12 ; Offset to edit on the current screen
TICKS0        = 0x13
TICKS1        = 0x14
TICKS2        = 0x15
TICKS3        = 0x16
ITER          = 0x17
ITER2         = 0x18
SPEED         = 0x19
BUTTON_STATES = 0x21
LAST_EDIT     = 0x22

#addr 0x8000
main:
  Jump  init
  init_return:
  Jump  main_loop
  main_loop_return:
  Jump  main

init:
  ; Zero out a bunch of "variables".
  LoadI  A  0
  Store  A  TICKS0
  Store  A  TICKS1
  Store  A  TICKS2
  Store  A  TICKS3
  Store  A  LAST_EDIT

  Store  A  MEM_PAGE
  Store  A  MEM_ADDR
  Store  A  MEM_OFFSET
  Store  A  SPEED

  Jump init_return

main_loop:
  ; Update tick counters (effectively increment a 32 bit number)
  Load  A TICKS0
  AddI  1
  Store A TICKS0
  JumpNZ .done_updating_ticks
  Load  A TICKS1
  AddI  1
  Store A TICKS1
  JumpNZ .done_updating_ticks
  Load  A TICKS2
  AddI  1
  Store A TICKS2
  JumpNZ .done_updating_ticks
  Load  A TICKS3
  AddI  1
  Store A TICKS3
  .done_updating_ticks:

  Jump        handle_input
  handle_input_return:
  
  Jump move_cursor
  move_cursor_return:

  Jump modify_value
  modify_value_return:

  Jump update_display
  update_display_return:

  Jump draw_display
  draw_display_return:

  Jump main_loop
  ; Return

handle_input:
  ; Load button states into shift register, before shifting them out.
  LoadI      InOutA 0
  LoadI      InOutA CONTROLLER_CLK
  LoadI      InOutA 0
  LoadI      InOutA CONTROLLER_SHLD

  ; Start with empty state to load button press states into.
  LoadI      C      0

  LoadI      A      CONTROLLER_SER
  CmpAndReg  InOutA ; Left
  Copy       C, A
  AddINFNZ          BUTTON_LEFT
  Copy       A, C
  
  LoadI      A      CONTROLLER_SER
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Up
  Copy       C, A
  AddINFNZ          BUTTON_UP
  Copy       A, C
  
  LoadI      A      CONTROLLER_SER
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Right
  Copy       C, A
  AddINFNZ          BUTTON_RIGHT
  Copy       A, C
  
  LoadI      A      CONTROLLER_SER
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Down
  Copy       C, A
  AddINFNZ          BUTTON_DOWN
  Copy       A, C
  
  LoadI      A      CONTROLLER_SER
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Start
  Copy       C, A
  AddINFNZ          BUTTON_START
  Copy       A, C
  
  LoadI      A      CONTROLLER_SER
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Select
  Copy       C, A
  AddINFNZ          BUTTON_SELECT
  Copy       A, C
  
  LoadI      A      CONTROLLER_SER
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; A
  Copy       C, A
  AddINFNZ          BUTTON_A
  Copy       A, C
  
  LoadI      A      CONTROLLER_SER
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; B
  Copy       C, A
  AddINFNZ          BUTTON_B
  Copy       A, C

  Store      C      BUTTON_STATES

  Jump handle_input_return
  ;Return

move_cursor:
  ; Calculate offset to move
  LoadI     C       0
  Load      A       BUTTON_STATES
  CmpAndI           BUTTON_UP
  Copy      C, A
  SubINZ            1
  Copy      A, C
  Load      A       BUTTON_STATES
  CmpAndI           BUTTON_DOWN
  Copy      C, A
  AddINZ            1
  CmpI              0
  JumpZ             move_cursor_return
  Copy      A, B

  ; Move cursor
  Load      A       MEM_OFFSET
  AccumulateAdd
  CmpI              -1
  JumpZ     .overflow_down
  CmpI              PIXELH
  JumpZ     .overflow_up
  Store     A       MEM_OFFSET
  Jump move_cursor_return
  
  .overflow_up:
    LoadI     A       0
    Store     A       MEM_OFFSET
    Load      A       MEM_ADDR
    AddI              20
    Store     A       MEM_ADDR
    Load      A       MEM_PAGE
    AddIZ             1
    Store     A       MEM_PAGE
    Jump move_cursor_return

  .overflow_down:
    LoadI     A       19
    Store     A       MEM_OFFSET
    Load      A       MEM_ADDR
    SubI              20
    Store     A       MEM_ADDR
    Load      A       MEM_PAGE
    SubINC            1
    Store     A       MEM_PAGE

  Jump move_cursor_return

modify_value:
  ; Calculate offset to change
  LoadI     C       0
  Load      A       BUTTON_STATES
  CmpAndI           BUTTON_LEFT
  Copy      C, A
  SubINZ            1
  Copy      A, C
  Load      A       BUTTON_STATES
  CmpAndI           BUTTON_RIGHT
  Copy      C, A
  AddINZ            1
  Copy      A, C
  CmpI              0
  JumpZ             modify_value_return

  ; Update last edit
  Load       A     TICKS1
  Store      A     LAST_EDIT

  ; Make modification
  Load       A     MEM_ADDR
  Load       Swap  MEM_PAGE
  Add              MEM_OFFSET
  SetAddrReg A
  Copy       Swap, A
  AddINC           1      ; If the addr overflowed, then increment the page
  OrI              0x80   ; Make sure we're dealing with addresses on the cartridge
  SetPageReg A
  LoadInc    B,    0      ; Load the actual byte we're modifying into A
  Copy       C,    A      ; Get our offset back and add it, then save
  AccumulateAdd
  StoreInc   A,    0
  Jump modify_value_return

update_display:
  SetPageI  DISP_BUF
  SetAddrI  0
  LoadI A   PIXELS
  LoadI C   0
  .clear_loop:
    StoreInc C, 1
    SubI 1
    JumpNZ .clear_loop
  
  LoadI     A   0
  Store     A   ITER
  .data_loop:
    Load       A   MEM_ADDR
    Load       C   MEM_PAGE
    Add            ITER
    SetAddrReg A
    Copy       C,  A
    AddINC         1        ; If the addr overflowed, then increment the page
    OrI            0x80     ; Make sure we're dealing with addresses on the cartridge
    SetPageReg A
    LoadInc    C,  0        ; Load the actual byte we're displaying into C

    ; Go to starting pixel position: ITER * 10 (that's ITER as Y, and X = 0)
    Load       A   ITER
    Copy       A,  B
    AccumulateAdd ; A = A * 2
    ShiftL         3
    AccumulateAdd ; A = A * 2 + A * 8 = A * 10
    SetAddrReg A
    SetPageI       DISP_BUF

    ; Draw each bit
    Copy       C,  A
    AndINF         0b10000000
    StoreInc   A,  1
    Copy       C,  A
    AndINF         0b01000000
    StoreInc   A,  1
    Copy       C,  A
    AndINF         0b00100000
    StoreInc   A,  1
    Copy       C,  A
    AndINF         0b00010000
    StoreInc   A,  1
    Copy       C,  A
    AndINF         0b00001000
    StoreInc   A,  1
    Copy       C,  A
    AndINF         0b00000100
    StoreInc   A,  1
    Copy       C,  A
    AndINF         0b00000010
    StoreInc   A,  1
    Copy       C,  A
    AndINF         0b00000001
    StoreInc   A,  1

    Load       A   ITER
    AddI           1
    Store      A   ITER
    CmpI           PIXELH
    JumpNZ        .data_loop

  ; Draw address, low byte
  Load         C  MEM_ADDR
  LoadI        A  PIXELW - 1 ; Origin X position
  SetAddrReg   A
  SetPageI     DISP_BUF

  Copy         C, A
  AndINF       0b00000001
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b00000010
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b00000100
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b00001000
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b00010000
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b00100000
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b01000000
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b10000000
  StoreInc     A, 0

  ; Draw address, high byte
  Load         C  MEM_PAGE
  LoadI        A  8 * PIXELW + PIXELW - 1 ; Origin Y + X position
  SetAddrReg   A
  SetPageI     DISP_BUF

  Copy         C, A
  AndINF       0b00000001
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b00000010
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b00000100
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b00001000
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b00010000
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b00100000
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b01000000
  StoreInc     A, 0
  Copy         MAdr, A
  AddI         10
  SetAddrReg   A
  Copy         C, A
  AndINF       0b10000000
  StoreInc     A, 0
  
  ; Set offset "scroll bar"
  Load       A   MEM_OFFSET
  Copy       A,  B
  AccumulateAdd ; A = A * 2
  ShiftL         3
  AccumulateAdd ; A = A * 2 + A * 8 = A * 10
  AddI           8 ; X position, just after all the data bytes
  SetAddrReg A
  SetPageI       DISP_BUF
  LoadI      A   1
  StoreInc   A,  0

  Jump update_display_return
  ; Return

draw_display:
  LoadI A   PIXELS - 1
  Store A   ITER
  SetPageI  DISP_BUF
  SetAddrI  0
  .loop:
    SetPageI   DISP_BUF
    SetAddrReg A
    LoadInc A, 0
    CmpI    0
    JumpZ   .send_zero

    .send_one:
    LoadI OutA  SER
    LoadI OutA  SER | SRCLCK
    Jump .loop_end

    .send_zero:
    LoadI OutA  0
    LoadI OutA  SRCLCK

    .loop_end:
    Load  A  ITER
    SubI     1
    Store A  ITER
    JumpC  .loop
  LoadI OutA  RCLCK
  LoadI OutA  0
  Jump draw_display_return
  ; Return