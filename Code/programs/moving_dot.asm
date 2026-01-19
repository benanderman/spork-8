#ruledef {
  SetPageReg     A                                         => 0x00                               
  SetPageReg     B                                         => 0x01                               
  SetPageReg     C                                         => 0x02                               
  SetPageReg     Swap                                      => 0x03                               
  SetPageI                            {value}              => 0x04   @ value`8                   
  SetAddrReg     A                                         => 0x05                               
  SetAddrReg     B                                         => 0x06                               
  SetAddrReg     C                                         => 0x07                               
  SetAddrReg     Swap                                      => 0x08                               
  SetAddrI                            {value}              => 0x09   @ value`8                   
  Load           A                    {address}            => 0x0A   @ address`16                
  Load           B                    {address}            => 0x0B   @ address`16                
  Load           C                    {address}            => 0x0C   @ address`16                
  Load           Swap                 {address}            => 0x0D   @ address`16                
  Load           OutA                 {address}            => 0x0E   @ address`16                
  Load           InOutA               {address}            => 0x0F   @ address`16                
  Load           InOutB               {address}            => 0x10   @ address`16                ; Has 5th bit
  LoadI          A                    {value}              => 0x11   @ value`8                   ; Has 5th bit
  LoadI          B                    {value}              => 0x12   @ value`8                   ; Has 5th bit
  LoadI          C                    {value}              => 0x13   @ value`8                   ; Has 5th bit
  LoadI          Swap                 {value}              => 0x14   @ value`8                   ; Has 5th bit
  LoadI          OutA                 {value}              => 0x15   @ value`8                   ; Has 5th bit
  LoadI          InOutA               {value}              => 0x16   @ value`8                   ; Has 5th bit
  LoadI          InOutB               {value}              => 0x17   @ value`8                   ; Has 5th bit
  LoadZP         A                    {value}              => 0x18   @ value`8                   ; Has 5th bit
  LoadZP         B                    {value}              => 0x19   @ value`8                   ; Has 5th bit
  LoadZP         C                    {value}              => 0x1A   @ value`8                   ; Has 5th bit
  LoadZP         Swap                 {value}              => 0x1B   @ value`8                   ; Has 5th bit
  LoadZP         OutA                 {value}              => 0x1C   @ value`8                   ; Has 5th bit
  LoadZP         InOutA               {value}              => 0x1D   @ value`8                   ; Has 5th bit
  LoadZP         InOutB               {value}              => 0x1E   @ value`8                   ; Has 5th bit
  LoadP          A                    {value}              => 0x1F   @ value`8                   ; Has 5th bit
  LoadP          B                    {value}              => 0x20   @ value`8                   
  LoadP          C                    {value}              => 0x21   @ value`8                   
  LoadP          Swap                 {value}              => 0x22   @ value`8                   
  LoadP          OutA                 {value}              => 0x23   @ value`8                   
  LoadP          InOutA               {value}              => 0x24   @ value`8                   
  LoadP          InOutB               {value}              => 0x25   @ value`8                   
  LoadInc        A, 0                                      => 0x26                               
  LoadInc        B, 0                                      => 0x27                               
  LoadInc        C, 0                                      => 0x28                               
  LoadInc        Swap, 0                                   => 0x29                               
  LoadInc        OutA, 0                                   => 0x2A                               
  LoadInc        A, 1                                      => 0x2B                               
  LoadInc        B, 1                                      => 0x2C                               
  LoadInc        C, 1                                      => 0x2D                               
  LoadInc        Swap, 1                                   => 0x2E                               
  LoadInc        OutA, 1                                   => 0x2F                               
  Store          A                    {address}            => 0x30   @ address`16                ; Has 5th bit
  Store          B                    {address}            => 0x31   @ address`16                ; Has 5th bit
  Store          C                    {address}            => 0x32   @ address`16                ; Has 5th bit
  Store          Swap                 {address}            => 0x33   @ address`16                ; Has 5th bit
  Store          OutA                 {address}            => 0x34   @ address`16                ; Has 5th bit
  Store          InOutA               {address}            => 0x35   @ address`16                ; Has 5th bit
  Store          InOutB               {address}            => 0x36   @ address`16                ; Has 5th bit
  StoreI                              {address} {value}    => 0x37   @ address`16 @ value`8      ; Has 5th bit
  StoreZP        A                    {value}              => 0x38   @ value`8                   ; Has 5th bit
  StoreZP        B                    {value}              => 0x39   @ value`8                   ; Has 5th bit
  StoreZP        C                    {value}              => 0x3A   @ value`8                   ; Has 5th bit
  StoreZP        Swap                 {value}              => 0x3B   @ value`8                   ; Has 5th bit
  StoreZP        OutA                 {value}              => 0x3C   @ value`8                   ; Has 5th bit
  StoreZP        InOutA               {value}              => 0x3D   @ value`8                   ; Has 5th bit
  StoreZP        InOutB               {value}              => 0x3E   @ value`8                   ; Has 5th bit
  StoreP         A                    {value}              => 0x3F   @ value`8                   ; Has 5th bit
  StoreP         B                    {value}              => 0x40   @ value`8                   
  StoreP         C                    {value}              => 0x41   @ value`8                   
  StoreP         Swap                 {value}              => 0x42   @ value`8                   
  StoreP         OutA                 {value}              => 0x43   @ value`8                   
  StoreP         InOutA               {value}              => 0x44   @ value`8                   
  StoreP         InOutB               {value}              => 0x45   @ value`8                   
  StoreInc       A, 0                                      => 0x46                               
  StoreInc       B, 0                                      => 0x47                               
  StoreInc       C, 0                                      => 0x48                               
  StoreInc       Swap, 0                                   => 0x49                               
  StoreInc       OutA, 0                                   => 0x4A                               
  StoreInc       InOutA                                    => 0x4B                               
  StoreInc       InOutB                                    => 0x4C                               
  StoreInc       A, 1                                      => 0x4D                               
  StoreInc       B, 1                                      => 0x4E                               
  StoreInc       C, 1                                      => 0x4F                               
  StoreInc       Swap, 1                                   => 0x50                               ; Has 5th bit
  StoreInc       OutA, 1                                   => 0x51                               ; Has 5th bit
  StoreInc       InOutA                                    => 0x52                               ; Has 5th bit
  StoreInc       InOutB                                    => 0x53                               ; Has 5th bit
  Copy           A, B                                      => 0x54                               ; Has 5th bit
  Copy           A, C                                      => 0x55                               ; Has 5th bit
  Copy           A, Swap                                   => 0x56                               ; Has 5th bit
  Copy           A, Stack                                  => 0x57                               ; Has 5th bit
  Copy           A, OutA                                   => 0x58                               ; Has 5th bit
  Copy           A, InOutA                                 => 0x59                               ; Has 5th bit
  Copy           A, InOutB                                 => 0x5A                               ; Has 5th bit
  Copy           B, A                                      => 0x5B                               ; Has 5th bit
  Copy           C, A                                      => 0x5C                               ; Has 5th bit
  Copy           Swap, A                                   => 0x5D                               ; Has 5th bit
  Copy           Stack, A                                  => 0x5E                               ; Has 5th bit
  Copy           OutA, A                                   => 0x5F                               ; Has 5th bit
  Copy           InOutA                                    => 0x60                               
  Copy           InOutB                                    => 0x61                               
  Copy           PCnt, A                                   => 0x62                               
  Copy           PCnt, A, HighB                            => 0x63                               
  Copy           MAdr, A                                   => 0x64                               
  Copy           MAdr, A, HighB                            => 0x65                               
  Jump                                {address}            => 0x66   @ address`16                
  JumpZ                               {address}            => 0x67   @ address`16                
  JumpC                               {address}            => 0x68   @ address`16                
  JumpNZ                              {address}            => 0x69   @ address`16                
  JumpNC                              {address}            => 0x6A   @ address`16                
  Call                                {address}            => 0x6B01 @ address`16                
  CallZ                               {address}            => 0x6C01 @ address`16                
  CallC                               {address}            => 0x6D01 @ address`16                
  CallNZ                              {address}            => 0x6E01 @ address`16                
  CallNC                              {address}            => 0x6F01 @ address`16                
  Return                                                   => 0x7001                             ; Has 5th bit
  Push           A                                         => 0x7101                             ; Has 5th bit
  Push           B                                         => 0x7201                             ; Has 5th bit
  Push           C                                         => 0x7301                             ; Has 5th bit
  Pop            A                                         => 0x7401                             ; Has 5th bit
  Pop            B                                         => 0x7501                             ; Has 5th bit
  Pop            C                                         => 0x7601                             ; Has 5th bit
  PushAll                                                  => 0x7701                             ; Has 5th bit
  PopAll                                                   => 0x7801                             ; Has 5th bit
  CmpI                                {value}              => 0x79   @ value`8                   ; Has 5th bit
  CmpAndI                             {value}              => 0x7A   @ value`8                   ; Has 5th bit
  Cmp                                 {address}            => 0x7B   @ address`16                ; Has 5th bit
  CmpAnd                              {address}            => 0x7C   @ address`16                ; Has 5th bit
  CmpReg         C                                         => 0x7D                               ; Has 5th bit
  CmpReg         Swap                                      => 0x7E                               ; Has 5th bit
  CmpReg         Stack                                     => 0x7F                               ; Has 5th bit
  CmpReg         OutA                                      => 0x80                               
  CmpReg         InOutA                                    => 0x81                               
  CmpReg         InOutB                                    => 0x82                               
  CmpAndReg      C                                         => 0x83                               
  CmpAndReg      Swap                                      => 0x84                               
  CmpAndReg      Stack                                     => 0x85                               
  CmpAndReg      OutA                                      => 0x86                               
  CmpAndReg      InOutA                                    => 0x87                               
  CmpAndReg      InOutB                                    => 0x88                               
  ShiftL         1                                         => 0x89                               
  ShiftL         2                                         => 0x8A                               
  ShiftL         3                                         => 0x8B                               
  ShiftL         4                                         => 0x8C                               
  ShiftL         5                                         => 0x8D                               
  ShiftL         6                                         => 0x8E                               
  ShiftL         7                                         => 0x8F                               
  ShiftR         1                                         => 0x90                               ; Has 5th bit
  ShiftR         2                                         => 0x91                               ; Has 5th bit
  ShiftR         3                                         => 0x92                               ; Has 5th bit
  ShiftR         4                                         => 0x93                               ; Has 5th bit
  ShiftR         5                                         => 0x94                               ; Has 5th bit
  ShiftR         6                                         => 0x95                               ; Has 5th bit
  ShiftR         7                                         => 0x96                               ; Has 5th bit
  RotateL                                                  => 0x97                               ; Has 5th bit
  RotateR                                                  => 0x98                               ; Has 5th bit
  AddI                                {value}              => 0x99   @ value`8                   ; Has 5th bit
  AddIZ                               {value}              => 0x9A   @ value`8                   ; Has 5th bit
  AddIC                               {value}              => 0x9B   @ value`8                   ; Has 5th bit
  AddINZ                              {value}              => 0x9C   @ value`8                   ; Has 5th bit
  AddINC                              {value}              => 0x9D   @ value`8                   ; Has 5th bit
  SubI                                {value}              => 0x9E   @ value`8                   ; Has 5th bit
  SubIZ                               {value}              => 0x9F   @ value`8                   ; Has 5th bit
  SubIC                               {value}              => 0xA0   @ value`8                   
  SubINZ                              {value}              => 0xA1   @ value`8                   
  SubINC                              {value}              => 0xA2   @ value`8                   
  AndI                                {value}              => 0xA3   @ value`8                   
  AndIZ                               {value}              => 0xA4   @ value`8                   
  AndIC                               {value}              => 0xA5   @ value`8                   
  AndINZ                              {value}              => 0xA6   @ value`8                   
  AndINC                              {value}              => 0xA7   @ value`8                   
  AddINF                              {value}              => 0xA8   @ value`8                   
  AddINFZ                             {value}              => 0xA9   @ value`8                   
  AddINFC                             {value}              => 0xAA   @ value`8                   
  AddINFNZ                            {value}              => 0xAB   @ value`8                   
  AddINFNC                            {value}              => 0xAC   @ value`8                   
  SubINF                              {value}              => 0xAD   @ value`8                   
  SubINFZ                             {value}              => 0xAE   @ value`8                   
  SubINFC                             {value}              => 0xAF   @ value`8                   
  SubINFNZ                            {value}              => 0xB0   @ value`8                   ; Has 5th bit
  SubINFNC                            {value}              => 0xB1   @ value`8                   ; Has 5th bit
  AndINF                              {value}              => 0xB2   @ value`8                   ; Has 5th bit
  AndINFZ                             {value}              => 0xB3   @ value`8                   ; Has 5th bit
  AndINFC                             {value}              => 0xB4   @ value`8                   ; Has 5th bit
  AndINFNZ                            {value}              => 0xB5   @ value`8                   ; Has 5th bit
  AndINFNC                            {value}              => 0xB6   @ value`8                   ; Has 5th bit
  AccumulateAdd                                            => 0xB7                               ; Has 5th bit
  AccumulateSub                                            => 0xB8                               ; Has 5th bit
  AccumulateAnd                                            => 0xB9                               ; Has 5th bit
  OrI                                 {value}              => 0xBA   @ value`8                   ; Has 5th bit
  OrIZ                                {value}              => 0xBB   @ value`8                   ; Has 5th bit
  OrIC                                {value}              => 0xBC   @ value`8                   ; Has 5th bit
  OrINZ                               {value}              => 0xBD   @ value`8                   ; Has 5th bit
  OrINC                               {value}              => 0xBE   @ value`8                   ; Has 5th bit
  XorI                                {value}              => 0xBF   @ value`8                   ; Has 5th bit
  XorIZ                               {value}              => 0xC0   @ value`8                   
  XorIC                               {value}              => 0xC1   @ value`8                   
  XorINZ                              {value}              => 0xC2   @ value`8                   
  XorINC                              {value}              => 0xC3   @ value`8                   
  Not                                                      => 0xC4                               
  NotZ                                                     => 0xC5                               
  NotC                                                     => 0xC6                               
  NotNZ                                                    => 0xC7                               
  NotNC                                                    => 0xC8                               
  Add                                 {address}            => 0xC9   @ address`16                
  AddZ                                {address}            => 0xCA   @ address`16                
  AddC                                {address}            => 0xCB   @ address`16                
  AddNZ                               {address}            => 0xCC   @ address`16                
  AddNC                               {address}            => 0xCD   @ address`16                
  Sub                                 {address}            => 0xCE   @ address`16                
  SubZ                                {address}            => 0xCF   @ address`16                
  SubC                                {address}            => 0xD0   @ address`16                ; Has 5th bit
  SubNZ                               {address}            => 0xD1   @ address`16                ; Has 5th bit
  SubNC                               {address}            => 0xD2   @ address`16                ; Has 5th bit
  And                                 {address}            => 0xD3   @ address`16                ; Has 5th bit
  AndZ                                {address}            => 0xD4   @ address`16                ; Has 5th bit
  AndC                                {address}            => 0xD5   @ address`16                ; Has 5th bit
  AndNZ                               {address}            => 0xD6   @ address`16                ; Has 5th bit
  AndNC                               {address}            => 0xD7   @ address`16                ; Has 5th bit
  Or                                  {address}            => 0xD8   @ address`16                ; Has 5th bit
  OrZ                                 {address}            => 0xD9   @ address`16                ; Has 5th bit
  OrC                                 {address}            => 0xDA   @ address`16                ; Has 5th bit
  OrNZ                                {address}            => 0xDB   @ address`16                ; Has 5th bit
  OrNC                                {address}            => 0xDC   @ address`16                ; Has 5th bit
  Xor                                 {address}            => 0xDD   @ address`16                ; Has 5th bit
  XorZ                                {address}            => 0xDE   @ address`16                ; Has 5th bit
  XorC                                {address}            => 0xDF   @ address`16                ; Has 5th bit
  XorNZ                               {address}            => 0xE0   @ address`16                
  XorNC                               {address}            => 0xE1   @ address`16                
  Nop                                                      => 0xE2                               
  Nop1                                                     => 0xE3                               
  Nop2                                                     => 0xE4                               
  Halt                                                     => 0xE5                               
}


; Constants for updating a 10 x 20 shift-register display
RCLCK  = 0b00000100
SRCLCK = 0b00000010
SER    = 0b00000001
PIXELW = 10
PIXELH = 20
PIXELS = PIXELW * PIXELH

; Constants for input
BUTTON_CLEAR  = 0b10000000
BUTTON_UP     = 0b01000000
BUTTON_DOWN   = 0b00100000
BUTTON_LEFT   = 0b00010000
BUTTON_RIGHT  = 0b00001000
BUTTON_HALT   = 0b00000001

; Constants for input from a controller
CONTROLLER_SER  = 0b00000001
CONTROLLER_CONN = 0b00000010
CONTROLLER_SHLD = 0b00000001
CONTROLLER_CLK  = 0b00000010

; Zero page addresses
DOT_X  = 0x00
DOT_Y  = 0x01
ITER_Y = 0x02
ITER_X = 0x03

#addr 0x8000
main:
  Call clear_display
  LoadI   A 4
  StoreZP A DOT_X
  LoadI   A 1
  StoreZP A DOT_Y
  
  input_loop:
  LoadI A       CONTROLLER_SER
  LoadI InOutA  0
  LoadI InOutA  CONTROLLER_CLK
  LoadI InOutA  0
  LoadI InOutA  CONTROLLER_SHLD
  
  CmpAndReg  InOutA ; Left
  JumpNZ     right ; left
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Up
  JumpNZ     down ; up
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Right
  JumpNZ     left ; right
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Down
  JumpNZ     up ; down
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Start
  CallNZ     clear_display
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  CmpAndReg  InOutA ; Select
  CallNZ     fill_display
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  ; CmpAndReg  InOutA ; A
  
  LoadI      InOutA CONTROLLER_SHLD | CONTROLLER_CLK
  LoadI      InOutA CONTROLLER_SHLD
  ; CmpAndReg  InOutA ; B
  
  Jump      input_loop

up:
  Load    A  DOT_Y
  CmpI    0
  JumpZ   display
  SubI    1
  Store   A  DOT_Y
  Jump    display

down:
  Load    A  DOT_Y
  AddI    1
  CmpI    PIXELH
  JumpZ   display
  Store   A  DOT_Y
  Jump    display

left:
  Load    A  DOT_X
  CmpI    0
  JumpZ   display
  SubI    1
  Store   A  DOT_X
  Jump    display

right:
  Load    A  DOT_X
  AddI    1
  CmpI    PIXELW
  JumpZ   display
  Store   A  DOT_X
  Jump    display

display:
  LoadI A 0
  StoreZP A ITER_Y
  .row_loop:
    ;LoadI C 0
  LoadI A 0
    StoreZP A ITER_X
      .col_loop:
      Load A  DOT_X
      Cmp  ITER_X
      JumpNZ    .send_zero
      ; JumpNC    .break
      ; CallNC    send_zero

      Load A  DOT_Y
      Cmp     ITER_Y
      ; CallC     send_one
      ; CallNC    send_zero
      JumpNZ    .send_zero
      LoadI OutA  SER
      LoadI OutA  SER | SRCLCK
      Jump .break

      .send_zero:
      LoadI OutA  0
      LoadI OutA  SRCLCK

      .break:
      Load A  ITER_X
      AddI  1
      Store A  ITER_X
      CmpI  PIXELW
      JumpNZ  .col_loop
    Load A  ITER_Y
    AddI    1
    Store A ITER_Y
    CmpI  PIXELH
    JumpNZ  .row_loop
  LoadI OutA  RCLCK
  LoadI OutA  0
  ; Return
  Jump input_loop

clear_display:
  LoadI  A  PIXELS
  .loop:
    Cmp DOT_X
  JumpNZ .send_zero
  LoadI OutA  SER
  LoadI OutA  SER | SRCLCK
  Jump .loop_end
  .send_zero:
    LoadI OutA  0
    LoadI OutA  SRCLCK
  .loop_end:
    SubI    1
    JumpNZ    .loop
  ; LoadI OutA  SER
  ; LoadI OutA  SER | SRCLCK
  LoadI OutA  RCLCK
  LoadI OutA  0
  Return
  ; Jump input_loop

fill_display:
  LoadI A PIXELS
  .loop:
    LoadI OutA  SER
    LoadI OutA  SER | SRCLCK
    SubI    1
    JumpNZ    .loop
  LoadI OutA  RCLCK
  LoadI OutA  0
  ; Return
  Jump input_loop

halt:
;  Halt