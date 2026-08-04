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
DISP_BUF       = 0x7F
SNAKE_PAGE_1_X = 0x7E
SNAKE_PAGE_1_Y = 0x7D
SNAKE_PAGE_2_X = 0x7C
SNAKE_PAGE_2_Y = 0x7B
PLAYER_1_STATE = 0x7A
PLAYER_2_STATE = 0x79

; Constants for input from 74HC166-based controllers
CONTROLLER_1_SER  = 0b00000001
CONTROLLER_1_CONN = 0b00000010
CONTROLLER_2_SER  = 0b00000100
CONTROLLER_2_CONN = 0b00001000
CONTROLLER_SHLD   = 0b00000001
CONTROLLER_CLK    = 0b00000010

; Button constants, for storing button states in one byte
BUTTON_LEFT    = 1 << 0
BUTTON_UP      = 1 << 1
BUTTON_RIGHT   = 1 << 2
BUTTON_DOWN    = 1 << 3
BUTTON_START   = 1 << 4
BUTTON_SELECT  = 1 << 5
BUTTON_A       = 1 << 6
BUTTON_B       = 1 << 7

; Game constants
UP              = 0b00
DOWN            = 0b01
LEFT            = 0b10
RIGHT           = 0b11
HORIZONTAL_MASK = 0b10

; Zero page addresses
PAUSED   = 0x01
FOOD     = 0x02
RAND     = 0x03
SPEED    = 0x04

; Player state offsets
DIR            = 0x01
LAST_DIR       = 0x02
SNAKE_HEAD     = 0x03
SNAKE_TAIL     = 0x04
BUTTON_STATES  = 0x05

#addr 0x8000
main:
  Call  init
  Call  game_loop
  Jump  main

init:
  SetAddrI  0
  LoadI A   255
  LoadI C   0
  .clear_loop:
    SetPageI  SNAKE_PAGE_1_X
    StoreInc C, 0
    SetPageI  SNAKE_PAGE_1_Y
    StoreInc C, 0
    SetPageI  SNAKE_PAGE_2_X
    StoreInc C, 0
    SetPageI  SNAKE_PAGE_2_Y
    StoreInc C, 1
    SubI 1
    JumpNZ .clear_loop

  StoreNStckI  0x02 PLAYER_1_STATE
  StoreNStckI  0x03 SNAKE_PAGE_1_X
  StoreNStckI  0x04 SNAKE_PAGE_1_Y
  StoreNStckI  0x05 4
  StoreNStckI  0x06 0
  StoreNStckI  0x07 1
  StoreNStckI  0x08 DOWN
  Call init_player_state

  StoreNStckI  0x02 PLAYER_2_STATE
  StoreNStckI  0x03 SNAKE_PAGE_2_X
  StoreNStckI  0x04 SNAKE_PAGE_2_Y
  StoreNStckI  0x05 5
  StoreNStckI  0x06 19
  StoreNStckI  0x07 255 ; aka -1
  StoreNStckI  0x08 UP
  Call init_player_state

  ; Constant food location, because on init there's no way to be random
  LoadI  A  8 * 10 + 6
  Store  A  FOOD
  LoadI  A  32
  Store  A  SPEED

  Return

init_player_state:
  ; Arguments
  .STATE_PAGE = 0x02
  .X_PAGE     = 0x03
  .Y_PAGE     = 0x04
  .X_ORIGIN   = 0x05
  .Y_ORIGIN   = 0x06
  .Y_DELTA    = 0x07
  .DIR        = 0x08

  LoadStck C   .STATE_PAGE
  LoadStck A   .DIR
  SetPageReg C
  StoreP A     DIR
  StoreP A     LAST_DIR
  LoadI A      2
  StoreP A     SNAKE_HEAD
  LoadI A      0
  StoreP A     SNAKE_TAIL

  LoadStck C   .X_PAGE
  LoadStck A   .X_ORIGIN
  SetPageReg C
  SetAddrI     0
  StoreInc A, 1
  StoreInc A, 1
  StoreInc A, 1

  LoadStck C   .Y_PAGE
  LoadStck A   .Y_ORIGIN
  LoadStck B   .Y_DELTA
  SetPageReg C
  SetAddrI     0
  StoreInc A, 1
  AccumulateAdd
  StoreInc A, 1
  AccumulateAdd
  StoreInc A, 1

  Return

game_loop:
  .ITER  = 0x02
  .ITER2 = 0x03

  Load      A SPEED ; Check for input n times before doing anything else, to add delay
  StoreStck A .ITER
  .input_loop:
    StoreStckI .ITER2 4 ; Check for input 4 times per loop
    .inner_input_loop:
      Call        update_button_states
      LoadStck A  .ITER2
      SubI    1
      StoreStck A .ITER2
      JumpNZ  .inner_input_loop
    LoadStck  A .ITER
    SubI    1
    StoreStck A .ITER
    JumpNZ  .input_loop

  StoreNStckI  0x02 PLAYER_1_STATE
  Call    handle_input
  StoreNStckI  0x02 PLAYER_2_STATE
  Call    handle_input

  StoreNStckI  0x02 PLAYER_1_STATE
  StoreNStckI  0x03 SNAKE_PAGE_1_X
  StoreNStckI  0x04 SNAKE_PAGE_1_Y
  Call advance_snake

  StoreNStckI  0x02 PLAYER_2_STATE
  StoreNStckI  0x03 SNAKE_PAGE_2_X
  StoreNStckI  0x04 SNAKE_PAGE_2_Y
  Call advance_snake

  Call update_display
  ; If the return value was 1 then return.
  LoadStck A 0xFF
  CmpI 1
  ReturnZ

  Call draw_display

  Jump game_loop

update_button_states:
  ; Local variables.
  .STATE_1 = 0x02
  .STATE_2 = 0x03

  ; Add to random.
  Load       A      RAND
  Add        (PLAYER_1_STATE * 0x100 + DIR)
  Add        (PLAYER_1_STATE * 0x100 + SNAKE_HEAD)
  Add        (PLAYER_2_STATE * 0x100 + DIR)
  Add        (PLAYER_2_STATE * 0x100 + SNAKE_HEAD)
  Store      A      RAND

  StoreStckI .STATE_1 0
  StoreStckI .STATE_2 0

  ; Load button states into shift register, before shifting them out.
  LoadI      InOutA 0
  LoadI      InOutA CONTROLLER_CLK
  LoadI      InOutA 0
  LoadI      InOutA CONTROLLER_SHLD

  Copy       InOutA, A
  CmpAndI    CONTROLLER_1_SER ; Left
  LoadStck   A      .STATE_1
  AddINFNZ          BUTTON_LEFT
  StoreStck  A      .STATE_1
  Copy       InOutA, A
  CmpAndI    CONTROLLER_2_SER ; Left
  LoadStck   A      .STATE_2
  AddINFNZ          BUTTON_LEFT
  StoreStck  A      .STATE_2
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  Copy       InOutA, A
  CmpAndI    CONTROLLER_1_SER ; Up
  LoadStck   A      .STATE_1
  AddINFNZ          BUTTON_UP
  StoreStck  A      .STATE_1
  Copy       InOutA, A
  CmpAndI    CONTROLLER_2_SER ; Up
  LoadStck   A      .STATE_2
  AddINFNZ          BUTTON_UP
  StoreStck  A      .STATE_2
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  Copy       InOutA, A
  CmpAndI    CONTROLLER_1_SER ; Right
  LoadStck   A      .STATE_1
  AddINFNZ          BUTTON_RIGHT
  StoreStck  A      .STATE_1
  Copy       InOutA, A
  CmpAndI    CONTROLLER_2_SER ; Right
  LoadStck   A      .STATE_2
  AddINFNZ          BUTTON_RIGHT
  StoreStck  A      .STATE_2
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  Copy       InOutA, A
  CmpAndI    CONTROLLER_1_SER ; Down
  LoadStck   A      .STATE_1
  AddINFNZ          BUTTON_DOWN
  StoreStck  A      .STATE_1
  Copy       InOutA, A
  CmpAndI    CONTROLLER_2_SER ; Down
  LoadStck   A      .STATE_2
  AddINFNZ          BUTTON_DOWN
  StoreStck  A      .STATE_2
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  Copy       InOutA, A
  CmpAndI    CONTROLLER_1_SER ; Start
  LoadStck   A      .STATE_1
  AddINFNZ          BUTTON_START
  StoreStck  A      .STATE_1
  Copy       InOutA, A
  CmpAndI    CONTROLLER_2_SER ; Start
  LoadStck   A      .STATE_2
  AddINFNZ          BUTTON_START
  StoreStck  A      .STATE_2
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  Copy       InOutA, A
  CmpAndI    CONTROLLER_1_SER ; Select
  LoadStck   A      .STATE_1
  AddINFNZ          BUTTON_SELECT
  StoreStck  A      .STATE_1
  Copy       InOutA, A
  CmpAndI    CONTROLLER_2_SER ; Select
  LoadStck   A      .STATE_2
  AddINFNZ          BUTTON_SELECT
  StoreStck  A      .STATE_2
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  Copy       InOutA, A
  CmpAndI    CONTROLLER_1_SER ; A
  LoadStck   A      .STATE_1
  AddINFNZ          BUTTON_A
  StoreStck  A      .STATE_1
  Copy       InOutA, A
  CmpAndI    CONTROLLER_2_SER ; A
  LoadStck   A      .STATE_2
  AddINFNZ          BUTTON_A
  StoreStck  A      .STATE_2
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  Copy       InOutA, A
  CmpAndI    CONTROLLER_1_SER ; B
  LoadStck   A      .STATE_1
  AddINFNZ          BUTTON_B
  StoreStck  A      .STATE_1
  Copy       InOutA, A
  CmpAndI    CONTROLLER_2_SER ; B
  LoadStck   A      .STATE_2
  AddINFNZ          BUTTON_B
  StoreStck  A      .STATE_2

  LoadStck   A      .STATE_1
  Store      A      (PLAYER_1_STATE * 0x100 + BUTTON_STATES)

  LoadStck   A      .STATE_2
  Store      A      (PLAYER_2_STATE * 0x100 + BUTTON_STATES)

  Return

handle_input:
  ; Arguments
  .STATE_PAGE = 0x02

  LoadStck   C      .STATE_PAGE
  SetPageReg C

  LoadP      A      BUTTON_STATES
  CmpAndI    BUTTON_UP
  JumpZ      .after_up ; Skip if the button is not pressed
  LoadP      A      LAST_DIR
  CmpI       DOWN
  JumpZ      .after_up ; Skip if the opposite direction was the last direction
  LoadI      A      UP
  StoreP     A      DIR
  .after_up:

  LoadP      A      BUTTON_STATES
  CmpAndI    BUTTON_DOWN
  JumpZ      .after_down ; Skip if the button is not pressed
  LoadP      A      LAST_DIR
  CmpI       UP
  JumpZ      .after_down ; Skip if the opposite direction was the last direction
  LoadI      A      DOWN
  StoreP     A      DIR
  .after_down:

  LoadP      A      BUTTON_STATES
  CmpAndI    BUTTON_LEFT
  JumpZ      .after_left ; Skip if the button is not pressed
  LoadP      A      LAST_DIR
  CmpI       RIGHT
  JumpZ      .after_left ; Skip if the opposite direction was the last direction
  LoadI      A      LEFT
  StoreP     A      DIR
  .after_left:

  LoadP      A      BUTTON_STATES
  CmpAndI    BUTTON_RIGHT
  JumpZ      .after_right ; Skip if the button is not pressed
  LoadP      A      LAST_DIR
  CmpI       LEFT
  JumpZ      .after_right ; Skip if the opposite direction was the last direction
  LoadI      A      RIGHT
  StoreP     A      DIR
  .after_right:

  Return

; Returns 1 if player died, 0 otherwise
advance_snake:
  ; Arguments
  .STATE_PAGE = 0x02
  .X_PAGE     = 0x03
  .Y_PAGE     = 0x04

  ; Local variables
  .NEW_X      = 0x05
  .NEW_Y      = 0x06
  .NEW_HEAD   = 0x07

  LoadStck   C  .STATE_PAGE
  SetPageReg C
  LoadP      A  SNAKE_HEAD

  LoadStck   C  .X_PAGE
  SetPageReg C
  SetAddrReg A  ; Go to current head in X_PAGE
  LoadInc    B, 0
  StoreStck  B  .NEW_X

  LoadStck   C  .Y_PAGE
  SetPageReg C
  SetAddrReg A  ; Go to current head in Y_PAGE
  LoadInc    B, 0
  StoreStck  B  .NEW_Y

  AddI       1
  StoreStck  A  .NEW_HEAD

  LoadStck   C  .STATE_PAGE
  SetPageReg C
  StoreP     A  SNAKE_HEAD
  LoadP      A  DIR
  StoreP     A  LAST_DIR
  CmpAndI       HORIZONTAL_MASK
  JumpNZ        .horizontal
  JumpZ         .vertical

  .horizontal:
  CmpI       LEFT
  LoadStck   A .NEW_X
  AddINFNZ   1
  SubINFZ    1
  CmpI       PIXELW
  SubIZ      PIXELW ; Set X to 0 if it went off the right side; Sub because it has a conditional version
  CmpI       -1
  JumpNZ      .store_x_value
  LoadI      A PIXELW-1
  .store_x_value:
  StoreStck  A .NEW_X
  Jump .finish

  .vertical:
  CmpI       UP
  LoadStck   A .NEW_Y
  AddINFNZ   1
  SubINFZ    1
  CmpI       PIXELH
  SubIZ      PIXELH ; Set Y to 0 if it went off the bottom; Sub because it has a conditional version
  CmpI       -1
  JumpNZ      .store_y_value
  LoadI      A PIXELH-1
  .store_y_value:
  StoreStck  A .NEW_Y
  Jump .finish

  .finish:
  ; Store new X
  LoadStck   A  .NEW_X
  LoadStck   B  .NEW_HEAD
  LoadStck   C  .X_PAGE
  SetPageReg C
  SetAddrReg B  ; Go to new head in X_PAGE
  StoreInc   A, 0

  ; Store new Y
  LoadStck   A  .NEW_Y
  LoadStck   B  .NEW_HEAD
  LoadStck   C  .Y_PAGE
  SetPageReg C
  SetAddrReg B  ; Go to new head in Y_PAGE
  StoreInc   A, 0

  ; Check for collision with food
  ; Multiply Y by 10 and add X
  LoadStck   A .NEW_Y
  Copy A, B
  AccumulateAdd ; A = A * 2
  ShiftL     3
  AccumulateAdd ; A = A * 2 + A * 8 = A * 10
  LoadStck   B .NEW_X
  AccumulateAdd ; A = Y * 10 + X

  ; If it matches the location of food, don't advance the tail, and do move food
  Cmp         FOOD
  JumpZ       .move_food

  ; Advance tail
  LoadStck   C  .STATE_PAGE
  SetPageReg C
  LoadP A       SNAKE_TAIL
  AddI          1
  StoreP A      SNAKE_TAIL
  Return

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

  Return

update_display:
  ; Set return value to 1 in case we return early.
  LoadI      C  1
  StorePStck C  0xFF

  SetPageI  DISP_BUF
  SetAddrI  0
  LoadI A   PIXELS
  LoadI C   0
  .clear_loop:
    StoreInc C, 1
    SubI 1
    JumpNZ .clear_loop

  StoreNStckI  0x02 PLAYER_1_STATE
  StoreNStckI  0x03 SNAKE_PAGE_1_X
  StoreNStckI  0x04 SNAKE_PAGE_1_Y
  Call draw_snake
  LoadStck A   0xFF
  CmpI         0
  JumpZ        .still_alive1
  LoadI       C 1
  StorePStck   C 0xFF
  Return
  .still_alive1:

  StoreNStckI  0x02 PLAYER_2_STATE
  StoreNStckI  0x03 SNAKE_PAGE_2_X
  StoreNStckI  0x04 SNAKE_PAGE_2_Y
  Call draw_snake
  LoadStck A   0xFF
  CmpI         0
  JumpZ        .still_alive2
  LoadI       C 1
  StorePStck   C 0xFF
  Return
  .still_alive2:

  ; Set DISP_BUF[FOOD] = 1
  Load C        FOOD
  SetPageI      DISP_BUF
  SetAddrReg C
  LoadI A       1
  StoreInc A, 0

  LoadI        C 0
  StorePStck   C 0xFF
  Return

draw_snake:
  ; Arguments
  .STATE_PAGE = 0x02
  .X_PAGE     = 0x03
  .Y_PAGE     = 0x04

  ; Local variables
  .SNAKE_HEAD = 0x05

  LoadStck   C  .STATE_PAGE
  SetPageReg C
  LoadP      A  SNAKE_HEAD
  StoreStck  A  .SNAKE_HEAD ; Store snake head in a local variable for easier access
  SetPageReg C
  LoadP      C  SNAKE_TAIL
  .snake_loop:
    LoadStck B .Y_PAGE
    SetPageReg B
    SetAddrReg C
    LoadInc A, 0

    Copy A, B
    AccumulateAdd ; A = A * 2
    ShiftL  3
    AccumulateAdd ; A = A * 2 + A * 8 = A * 10

    LoadStck B    .X_PAGE
    SetPageReg B
    SetAddrReg C
    LoadInc B, 0
    AccumulateAdd ; A = Y * 10 + X

    ; Set DISP_BUF[Y * 10 + X] = .STATE_PAGE (ideally this would be just 0 or 1, but any unique value works)
    LoadStck Swap .STATE_PAGE
    SetPageI      DISP_BUF
    SetAddrReg A
    LoadInc A, 0
    CmpI          0
    JumpZ        .not_overlap
    LoadI       C 1
    StorePStck  C 0xFF
    Return
    .not_overlap:
    StoreInc Swap, 0
    LoadI A     1
    StoreInc A, 0

    ; Increment iterator (C), and loop if <= .SNAKE_HEAD
    Copy C, A
    LoadStck Swap .SNAKE_HEAD
    CmpReg Swap
    AddINF        1
    Copy A, C
    JumpNZ        .snake_loop
  
  LoadI        C 0
  StorePStck   C 0xFF
  Return

draw_display:
  .ITER = 2
  LoadI A   PIXELS - 1
  StoreStck A   .ITER
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
    LoadStck  A  .ITER
    SubI     1
    StoreStck A  .ITER
    JumpC  .loop
  LoadI OutA  RCLCK
  LoadI OutA  0
  Return
