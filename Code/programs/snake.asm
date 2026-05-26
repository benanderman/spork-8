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
  StoreInc       InOutA                                    => 0x42                                      
  StoreInc       InOutB                                    => 0x43                                      
  StoreInc       A, 1                                      => 0x44                                      
  StoreInc       B, 1                                      => 0x45                                      
  StoreInc       C, 1                                      => 0x46                                      
  StoreInc       Swap, 1                                   => 0x47                                      
  StoreInc       OutA, 1                                   => 0x48                                      
  StoreInc       InOutA                                    => 0x49                                      
  StoreInc       InOutB                                    => 0x4A                                      
  StoreStck      A                    {value}              => 0x4B                @ value`8             
  StoreStck      B                    {value}              => 0x4C                @ value`8             
  StoreStck      C                    {value}              => 0x4D                @ value`8             
  StoreStck      Swap                 {value}              => 0x4E                @ value`8             
  StoreNStck     A                    {value}              => 0x4F                @ value`8             
  StoreNStck     B                    {value}              => 0x50                @ value`8             
  StoreNStck     C                    {value}              => 0x51                @ value`8             
  StorePStck     C                    {value}              => 0x5201              @ value`8             
  StoreStckI                          {address}            => 0x53                @ address`16          
  StoreNStckI                         {address}            => 0x54                @ address`16          
  StorePStckI                         {address}            => 0x5501              @ address`16          
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
  Copy           InOutA                                    => 0x62                                      
  Copy           InOutB                                    => 0x63                                      
  Copy           PCnt, A                                   => 0x64                                      
  Copy           PCnt, A, HighB                            => 0x65                                      
  Copy           MAdr, A                                   => 0x66                                      
  Copy           MAdr, A, HighB                            => 0x67                                      
  Jump                                {address}            => 0x68                @ address`16          
  JumpZ                               {address}            => 0x69                @ address`16          
  JumpC                               {address}            => 0x6A                @ address`16          
  JumpNZ                              {address}            => 0x6B                @ address`16          
  JumpNC                              {address}            => 0x6C                @ address`16          
  Call                                {address}            => 0x6D01 @ ($ + 6)`16 @ address`16          
  CallZ                               {address}            => 0x6E01 @ ($ + 6)`16 @ address`16          
  CallC                               {address}            => 0x6F01 @ ($ + 6)`16 @ address`16          
  CallNZ                              {address}            => 0x7001 @ ($ + 6)`16 @ address`16          
  CallNC                              {address}            => 0x7101 @ ($ + 6)`16 @ address`16          
  Return                                                   => 0x7200                                    
  ReturnZ                                                  => 0x7301                                    
  ReturnC                                                  => 0x7401                                    
  ReturnNZ                                                 => 0x7501                                    
  ReturnNC                                                 => 0x7601                                    
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
SNAKE_PAGE_X = 0x03
SNAKE_PAGE_Y = 0x04

; Constants for input
BUTTON_PAUSE  = 0b10000000
BUTTON_UP     = 0b01000000
BUTTON_DOWN   = 0b00100000
BUTTON_LEFT   = 0b00010000
BUTTON_RIGHT  = 0b00001000
BUTTON_HALT   = 0b00000001

; Constants for input from a 74HC166-based controller
CONTROLLER_SER  = 0b00000001
CONTROLLER_CONN = 0b00000010
CONTROLLER_SHLD = 0b00000001
CONTROLLER_CLK  = 0b00000010

; Game constants
UP              = 0b00
DOWN            = 0b01
LEFT            = 0b10
RIGHT           = 0b11
HORIZONTAL_MASK = 0b10

; Zero page addresses
FOOD_X   = 0x10
FOOD_Y   = 0x11
DIR      = 0x12
LAST_DIR = 0x13
PAUSED   = 0x14
FOOD     = 0x15
RAND     = 0x16
SPEED    = 0x17
ITER     = 0x18
ITER2    = 0x19

SNAKE_HEAD = 0x20
SNAKE_TAIL = 0x21

#addr 0x8000
main:
  Jump  init
  init_return:
  Jump  game_loop
  game_loop_return:
  Jump  main

init:
  SetAddrI  0
  LoadI A   255
  LoadI C   0
  .clear_loop:
    SetPageI  SNAKE_PAGE_X
    StoreInc C, 1
    SetPageI  SNAKE_PAGE_Y
    StoreInc C, 1
    SubI 1
    JumpNZ .clear_loop
  LoadI  A  DOWN
  Store  A  DIR
  LoadI  A  DOWN
  Store  A  LAST_DIR
  LoadI  A  0
  Store  A  SNAKE_TAIL
  LoadI  A  2
  Store  A  SNAKE_HEAD
  LoadI  A  4
  Store  A  SNAKE_PAGE_X * 0x100 + 0
  LoadI  A  4
  Store  A  SNAKE_PAGE_X * 0x100 + 1
  LoadI  A  4
  Store  A  SNAKE_PAGE_X * 0x100 + 2
  LoadI  A  0
  Store  A  SNAKE_PAGE_Y * 0x100 + 0
  LoadI  A  1
  Store  A  SNAKE_PAGE_Y * 0x100 + 1
  LoadI  A  2
  Store  A  SNAKE_PAGE_Y * 0x100 + 2
  LoadI  A  8 * 10 + 5
  Store  A  FOOD
  LoadI  A  255
  Store  A  SPEED

  Jump init_return

game_loop:
  Load  A SPEED ; Check for input n times before doing anything else, to add delay
  Store A ITER
  input_loop:
    LoadI A 4 ; Check for input 4 times per loop
    Store A ITER2
    inner_input_loop:
      Jump        handle_input
      handle_input_return:
      Load  A ITER2
      SubI    1
      Store A ITER2
      JumpNZ  inner_input_loop
    Load  A ITER
    SubI    1
    Store A ITER
    JumpNZ  input_loop

  Jump advance_snake
  advance_snake_return:

  Jump update_display
  update_display_return:

  Jump draw_display
  draw_display_return:

  Jump game_loop
  ; Return

handle_input:
  Load       A      RAND
  Add        DIR
  Add        SNAKE_HEAD
  Store      A      RAND

  ; Load button states into shift register, before shifting them out.
  LoadI      InOutA 0
  LoadI      InOutA CONTROLLER_CLK
  LoadI      InOutA 0
  LoadI      InOutA CONTROLLER_SHLD
  
  LoadI      A      CONTROLLER_SER
  CmpAndReg  InOutA ; Left
  JumpNZ     .left
  .left_return:
  
  LoadI      A      CONTROLLER_SER
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Up
  JumpNZ     .up
  .up_return:
  
  LoadI      A      CONTROLLER_SER
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Right
  JumpNZ     .right
  .right_return:
  
  LoadI      A      CONTROLLER_SER
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Down
  JumpNZ     .down
  .down_return:
  
  LoadI      A      CONTROLLER_SER
  ; LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  ; LoadI      InOutA CONTROLLER_SHLD
  ; CmpAndReg  InOutA ; Start
  ; CallNZ     clear_display
  
  LoadI      A      CONTROLLER_SER
  ; LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  ; LoadI      InOutA CONTROLLER_SHLD
  ; CmpAndReg  InOutA ; Select
  ; CallNZ     fill_display
  
  LoadI      A      CONTROLLER_SER
  ; LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  ; LoadI      InOutA CONTROLLER_SHLD
  ; CmpAndReg  InOutA ; A
  
  LoadI      A      CONTROLLER_SER
  ; LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  ; LoadI      InOutA CONTROLLER_SHLD
  ; CmpAndReg  InOutA ; B

  Jump handle_input_return
  ;Return

  .up:
    LoadI A DOWN
    Cmp     LAST_DIR
    JumpZ .up_return
    LoadI A  UP
    Store A  DIR
    Jump .up_return
    ; Return
  .down:
    LoadI A UP
    Cmp     LAST_DIR
    JumpZ .down_return
    LoadI A  DOWN
    Store A  DIR
    Jump .down_return
    ; Return
  .left:
    LoadI A RIGHT
    Cmp     LAST_DIR
    JumpZ .left_return
    LoadI A  LEFT
    Store A  DIR
    Jump .left_return
    ; Return
  .right:
    LoadI A LEFT
    Cmp     LAST_DIR
    JumpZ .right_return
    LoadI A  RIGHT
    Store A  DIR
    Jump .right_return
    ; Return

advance_snake:
  Load   A      DIR
  Store  A      LAST_DIR
  CmpAndI       HORIZONTAL_MASK
  JumpNZ        .horizontal
  JumpZ         .vertical

  .horizontal:
  ; Advance snake head, save old X to C, copy old Y to new Y.
  Load       A     SNAKE_HEAD
  SetAddrReg A
  SetPageI         SNAKE_PAGE_X
  LoadInc    C,    0             ; Load current head X into C
  SetPageI         SNAKE_PAGE_Y
  LoadInc    SWAP, 1             ; Load current head Y into SWAP, and increment MADR
  SetPageI         SNAKE_PAGE_Y  ; Go to Y page again, in case the address increment overflowed
  StoreInc   SWAP, 0             ; Store current head Y in head+1
  AddI       1
  Store      A     SNAKE_HEAD    ; Advance snake head by 1

  ; Increment or decrement old Y, with the result stored in A.
  Load       A     DIR
  CmpI       LEFT
  Copy       C,    A
  AddINFNZ   1
  SubINFZ    1

  ; Save modified X to new head.
  Load       C     SNAKE_HEAD
  SetPageI   SNAKE_PAGE_X
  SetAddrReg C
  StoreInc   A, 0

  ; Reset if we went off the screen.
  CmpI       -1
  JumpZ      main
  CmpI       PIXELW
  JumpZ      main

  Jump .finish

  .vertical:
  ; Advance snake head, save old Y to C, copy old X to new X.
  Load       A     SNAKE_HEAD
  SetAddrReg A
  SetPageI         SNAKE_PAGE_Y
  LoadInc    C,    0             ; Load current head Y into C
  SetPageI         SNAKE_PAGE_X
  LoadInc    SWAP, 1             ; Load current head X into SWAP, and increment MADR
  SetPageI         SNAKE_PAGE_X  ; Go to X page again, in case the address increment overflowed
  StoreInc   SWAP, 0             ; Store current head X in head+1
  AddI       1
  Store      A     SNAKE_HEAD    ; Advance snake head by 1

  ; Increment or decrement old Y, with the result stored in A.
  Load       A     DIR
  CmpI       UP
  Copy       C,    A
  AddINFNZ   1
  SubINFZ    1

  ; Save modified Y to new head.
  Load       C     SNAKE_HEAD
  SetPageI   SNAKE_PAGE_Y
  SetAddrReg C
  StoreInc   A, 0

  ; Reset if we went off the screen.
  CmpI       -1
  JumpZ      main
  CmpI       PIXELH
  JumpZ      main

  .finish:
  ; Check for collision with food
  ; Load head Y into A
  Load       C     SNAKE_HEAD
  SetPageI   SNAKE_PAGE_Y
  SetAddrReg C
  LoadInc A, 0

  ; Multiply Y by 10 and add X
  Copy A, B
  AccumulateAdd ; A = A * 2
  ShiftL  3
  AccumulateAdd ; A = A * 2 + A * 8 = A * 10
  SetPageI   SNAKE_PAGE_X
  LoadInc B, 0
  AccumulateAdd ; A = Y * 10 + X

  ; If it matches the location of food, don't advance the tail, and do move food
  Cmp         FOOD
  JumpZ       .move_food

  ; Advance tail
  Load  A     SNAKE_TAIL
  AddI        1
  Store A     SNAKE_TAIL
  Jump        advance_snake_return

  .move_food:
  ; Speed -= Speed / 16
  Load   A    SPEED
  Copy   A, B
  ShiftR 4
  AccumulateSub
  Store  A    SPEED

  .move_food_loop:
    Load   A    RAND
    AddI   1
    Store  A    RAND
    Load   A    FOOD
    Add         RAND
    Store  A    FOOD
    ; If new location > PIXELS, loop.
    CmpI        PIXELS
    JumpC       .move_food_loop
    ; If new location wasn't empty on the screen this cycle
    SetPageI    DISP_BUF
    SetAddrReg  A
    LoadInc     A, 0
    CmpI        0
    JumpNZ     .move_food_loop

  Jump        advance_snake_return

update_display:
  SetPageI  DISP_BUF
  SetAddrI  0
  LoadI A   PIXELS
  LoadI C   0
  .clear_loop:
    StoreInc C, 1
    SubI 1
    JumpNZ .clear_loop

  Load   C  SNAKE_TAIL
  .snake_loop:
    SetPageI   SNAKE_PAGE_Y
    SetAddrReg C
    LoadInc A, 0

    Copy A, B
    AccumulateAdd ; A = A * 2
    ShiftL  3
    AccumulateAdd ; A = A * 2 + A * 8 = A * 10

    SetPageI   SNAKE_PAGE_X
    LoadInc B, 0
    AccumulateAdd ; A = Y * 10 + X

    ; Set DISP_BUF[Y * 10 + X] = 1
    SetPageI      DISP_BUF
    SetAddrReg A
    LoadI A       1
    StoreInc A, 0

    ; Increment iterator (C), and loop if <= SNAKE_HEAD
    Copy C, A
    Cmp           SNAKE_HEAD
    AddINF        1
    Copy A, C
    JumpNZ        .snake_loop

  ; Set DISP_BUF[FOOD] = 1
  Load C        FOOD
  SetPageI      DISP_BUF
  SetAddrReg C
  LoadI A       1
  StoreInc A, 0

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

    ; LoadI A 0
    ; AddINZ  SER
    ; Copy    A, OutA
    ; AddI    SRCLCK
    ; Copy    A, OutA

    .loop_end:
    Load  A  ITER
    SubI     1
    Store A  ITER
    JumpC  .loop
  LoadI OutA  RCLCK
  LoadI OutA  0
  Jump draw_display_return
  ; Return