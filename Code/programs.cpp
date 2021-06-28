#include "programs.h"

byte getMovingDotByte(uint16_t address) {
  static const unsigned char PROGMEM data[] = {
    /* 0x00 */ 0x70, 0x00, 0xa0, 0x36, 0x00, 0x00, 0x03, 0x36, 0x00, 0x01, 0x07, 0x57, 0x10, 0x40, 0x8e, 0x73, 
    /* 0x10 */ 0x00, 0x33, 0x10, 0x20, 0x8e, 0x73, 0x00, 0x41, 0x10, 0x10, 0x8e, 0x73, 0x00, 0x4f, 0x10, 0x08, 
    /* 0x20 */ 0x8e, 0x73, 0x00, 0x5d, 0x10, 0x80, 0x8e, 0x73, 0x00, 0xa0, 0x10, 0x01, 0x8e, 0x6e, 0x00, 0xba, 
    /* 0x30 */ 0x6b, 0x00, 0x0b, 0x7c, 0x16, 0x01, 0xaa, 0x01, 0xaf, 0x0f, 0x37, 0x01, 0x7d, 0x70, 0x00, 0x6b, 
    /* 0x40 */ 0x75, 0x7c, 0x16, 0x01, 0xa5, 0x01, 0xaf, 0x0f, 0x37, 0x01, 0x7d, 0x70, 0x00, 0x6b, 0x75, 0x7c, 
    /* 0x50 */ 0x16, 0x00, 0xaa, 0x01, 0xaf, 0x07, 0x37, 0x00, 0x7d, 0x70, 0x00, 0x6b, 0x75, 0x7c, 0x16, 0x00, 
    /* 0x60 */ 0xa5, 0x01, 0xaf, 0x07, 0x37, 0x00, 0x7d, 0x70, 0x00, 0x6b, 0x75, 0x7c, 0x10, 0x00, 0x37, 0x02, 
    /* 0x70 */ 0x12, 0x00, 0x16, 0x00, 0x82, 0x74, 0x00, 0xb0, 0x6f, 0x00, 0x86, 0x16, 0x01, 0x80, 0x00, 0x02, 
    /* 0x80 */ 0x72, 0x00, 0xb5, 0x74, 0x00, 0xb0, 0x60, 0xa5, 0x01, 0x5a, 0x7e, 0x08, 0x6e, 0x00, 0x72, 0x16, 
    /* 0x90 */ 0x02, 0xa5, 0x01, 0x37, 0x02, 0x7e, 0x10, 0x6e, 0x00, 0x70, 0x14, 0x80, 0x14, 0x00, 0x7d, 0x75, 
    /* 0xa0 */ 0x10, 0x80, 0x14, 0x00, 0x14, 0x40, 0xaa, 0x01, 0x6e, 0x00, 0xa2, 0x14, 0x80, 0x14, 0x00, 0x75, 
    /* 0xb0 */ 0x14, 0x00, 0x14, 0x40, 0x75, 0x14, 0x20, 0x14, 0x60, 0x75, 0xdf
  };
  int len = sizeof(data) / sizeof(*data);
  return address < len ? pgm_read_byte(&data[address]) : 0;
}

/*
 * Program generated on https://hlorenzi.github.io/customasm/web/ from:

#ruledef {
  SetPageReg     A                                         => 0x00 
  SetPageReg     B                                         => 0x01 
  SetPageReg     C                                         => 0x02 
  SetPageReg     Swap                                      => 0x03 
  SetPageI                            {value}              => 0x04 @ value`8
  SetAddrReg     A                                         => 0x05 
  SetAddrReg     B                                         => 0x06 
  SetAddrReg     C                                         => 0x07 
  SetAddrReg     Swap                                      => 0x08 
  SetAddrI                            {value}              => 0x09 @ value`8
  Load           A                    {address}            => 0x0A @ address`16
  Load           B                    {address}            => 0x0B @ address`16
  Load           C                    {address}            => 0x0C @ address`16
  Load           Swap                 {address}            => 0x0D @ address`16
  Load           OutA                 {address}            => 0x0E @ address`16
  Load           OutB                 {address}            => 0x0F @ address`16
  LoadI          A                    {value}              => 0x10 @ value`8
  LoadI          B                    {value}              => 0x11 @ value`8
  LoadI          C                    {value}              => 0x12 @ value`8
  LoadI          Swap                 {value}              => 0x13 @ value`8
  LoadI          OutA                 {value}              => 0x14 @ value`8
  LoadI          OutB                 {value}              => 0x15 @ value`8
  LoadZP         A                    {value}              => 0x16 @ value`8
  LoadZP         B                    {value}              => 0x17 @ value`8
  LoadZP         C                    {value}              => 0x18 @ value`8
  LoadZP         Swap                 {value}              => 0x19 @ value`8
  LoadZP         OutA                 {value}              => 0x1A @ value`8
  LoadZP         OutB                 {value}              => 0x1B @ value`8
  LoadP          A                    {value}              => 0x1C @ value`8
  LoadP          B                    {value}              => 0x1D @ value`8
  LoadP          C                    {value}              => 0x1E @ value`8
  LoadP          Swap                 {value}              => 0x1F @ value`8
  LoadP          OutA                 {value}              => 0x20 @ value`8
  LoadP          OutB                 {value}              => 0x21 @ value`8
  LoadInc        A, 0                                      => 0x22 
  LoadInc        B, 0                                      => 0x23 
  LoadInc        C, 0                                      => 0x24 
  LoadInc        Swap, 0                                   => 0x25 
  LoadInc        OutA, 0                                   => 0x26 
  LoadInc        OutB, 0                                   => 0x27 
  LoadInc        A, 1                                      => 0x28 
  LoadInc        B, 1                                      => 0x29 
  LoadInc        C, 1                                      => 0x2A 
  LoadInc        Swap, 1                                   => 0x2B 
  LoadInc        OutA, 1                                   => 0x2C 
  LoadInc        OutB, 1                                   => 0x2D 
  Store          A                    {address}            => 0x2E @ address`16
  Store          B                    {address}            => 0x2F @ address`16
  Store          C                    {address}            => 0x30 @ address`16
  Store          Swap                 {address}            => 0x31 @ address`16
  Store          OutA                 {address}            => 0x32 @ address`16
  Store          OutB                 {address}            => 0x33 @ address`16
  Store          InA                  {address}            => 0x34 @ address`16
  Store          InB                  {address}            => 0x35 @ address`16
  StoreI                              {address} {value}    => 0x36 @ address`16 @ value`8
  StoreZP        A                    {value}              => 0x37 @ value`8
  StoreZP        B                    {value}              => 0x38 @ value`8
  StoreZP        C                    {value}              => 0x39 @ value`8
  StoreZP        Swap                 {value}              => 0x3A @ value`8
  StoreZP        OutA                 {value}              => 0x3B @ value`8
  StoreZP        OutB                 {value}              => 0x3C @ value`8
  StoreZP        InA                  {value}              => 0x3D @ value`8
  StoreZP        InB                  {value}              => 0x3E @ value`8
  StoreP         A                    {value}              => 0x3F @ value`8
  StoreP         B                    {value}              => 0x40 @ value`8
  StoreP         C                    {value}              => 0x41 @ value`8
  StoreP         Swap                 {value}              => 0x42 @ value`8
  StoreP         OutA                 {value}              => 0x43 @ value`8
  StoreP         OutB                 {value}              => 0x44 @ value`8
  StoreP         InA                  {value}              => 0x45 @ value`8
  StoreP         InB                  {value}              => 0x46 @ value`8
  StoreInc       A, 0                                      => 0x47 
  StoreInc       B, 0                                      => 0x48 
  StoreInc       C, 0                                      => 0x49 
  StoreInc       Swap, 0                                   => 0x4A 
  StoreInc       OutA, 0                                   => 0x4B 
  StoreInc       OutB, 0                                   => 0x4C 
  StoreInc       InA, 0                                    => 0x4D 
  StoreInc       InB, 0                                    => 0x4E 
  StoreInc       A, 1                                      => 0x4F 
  StoreInc       B, 1                                      => 0x50 
  StoreInc       C, 1                                      => 0x51 
  StoreInc       Swap, 1                                   => 0x52 
  StoreInc       OutA, 1                                   => 0x53 
  StoreInc       OutB, 1                                   => 0x54 
  StoreInc       InA, 1                                    => 0x55 
  StoreInc       InB, 1                                    => 0x56 
  Read           InA                                       => 0x57 
  Read           InB                                       => 0x58 
  Copy           A, B                                      => 0x59 
  Copy           A, C                                      => 0x5A 
  Copy           A, Swap                                   => 0x5B 
  Copy           A, Stack                                  => 0x5C 
  Copy           A, OutA                                   => 0x5D 
  Copy           A, OutB                                   => 0x5E 
  Copy           B, A                                      => 0x5F 
  Copy           C, A                                      => 0x60 
  Copy           Swap, A                                   => 0x61 
  Copy           Stack, A                                  => 0x62 
  Copy           OutA, A                                   => 0x63 
  Copy           OutB, A                                   => 0x64 
  Copy           InA, A                                    => 0x65 
  Copy           InB, A                                    => 0x66 
  Copy           PCnt, A                                   => 0x67 
  Copy           PCnt, A, HighB                            => 0x68 
  Copy           MAdr, A                                   => 0x69 
  Copy           MAdr, A, HighB                            => 0x6A 
  Jump                                {address}            => 0x6B @ address`16
  JumpZ                               {address}            => 0x6C @ address`16
  JumpC                               {address}            => 0x6D @ address`16
  JumpNZ                              {address}            => 0x6E @ address`16
  JumpNC                              {address}            => 0x6F @ address`16
  Call                                {address}            => 0x70 @ address`16
  CallZ                               {address}            => 0x71 @ address`16
  CallC                               {address}            => 0x72 @ address`16
  CallNZ                              {address}            => 0x73 @ address`16
  CallNC                              {address}            => 0x74 @ address`16
  Return                                                   => 0x75 
  Push           A                                         => 0x76 
  Push           B                                         => 0x77 
  Push           C                                         => 0x78 
  Pop            A                                         => 0x79 
  Pop            B                                         => 0x7A 
  Pop            C                                         => 0x7B 
  PushAll                                                  => 0x7C 
  PopAll                                                   => 0x7D 
  CmpI                                {value}              => 0x7E @ value`8
  CmpAndI                             {value}              => 0x7F @ value`8
  Cmp                                 {address}            => 0x80 @ address`16
  CmpAnd                              {address}            => 0x81 @ address`16
  CmpReg         C                                         => 0x82 
  CmpReg         Swap                                      => 0x83 
  CmpReg         Stack                                     => 0x84 
  CmpReg         OutA                                      => 0x85 
  CmpReg         OutB                                      => 0x86 
  CmpReg         InA                                       => 0x87 
  CmpReg         InB                                       => 0x88 
  CmpAndReg      C                                         => 0x89 
  CmpAndReg      Swap                                      => 0x8A 
  CmpAndReg      Stack                                     => 0x8B 
  CmpAndReg      OutA                                      => 0x8C 
  CmpAndReg      OutB                                      => 0x8D 
  CmpAndReg      InA                                       => 0x8E 
  CmpAndReg      InB                                       => 0x8F 
  Mult           0                                         => 0x90 
  Mult           1                                         => 0x91 
  Mult           2                                         => 0x92 
  Mult           3                                         => 0x93 
  Mult           4                                         => 0x94 
  Mult           5                                         => 0x95 
  Mult           6                                         => 0x96 
  Mult           7                                         => 0x97 
  Mult           8                                         => 0x98 
  Mult           9                                         => 0x99 
  Mult           10                                        => 0x9A 
  Mult           11                                        => 0x9B 
  Mult           12                                        => 0x9C 
  Mult           13                                        => 0x9D 
  ShiftL         1                                         => 0x9E 
  ShiftL         2                                         => 0x9F 
  ShiftL         3                                         => 0xA0 
  ShiftL         4                                         => 0xA1 
  ShiftL         5                                         => 0xA2 
  ShiftL         6                                         => 0xA3 
  ShiftL         7                                         => 0xA4 
  AddI                                {value}              => 0xA5 @ value`8
  AddIZ                               {value}              => 0xA6 @ value`8
  AddIC                               {value}              => 0xA7 @ value`8
  AddINZ                              {value}              => 0xA8 @ value`8
  AddINC                              {value}              => 0xA9 @ value`8
  SubI                                {value}              => 0xAA @ value`8
  SubIZ                               {value}              => 0xAB @ value`8
  SubIC                               {value}              => 0xAC @ value`8
  SubINZ                              {value}              => 0xAD @ value`8
  SubINC                              {value}              => 0xAE @ value`8
  AndI                                {value}              => 0xAF @ value`8
  AndIZ                               {value}              => 0xB0 @ value`8
  AndIC                               {value}              => 0xB1 @ value`8
  AndINZ                              {value}              => 0xB2 @ value`8
  AndINC                              {value}              => 0xB3 @ value`8
  OrI                                 {value}              => 0xB4 @ value`8
  OrIZ                                {value}              => 0xB5 @ value`8
  OrIC                                {value}              => 0xB6 @ value`8
  OrINZ                               {value}              => 0xB7 @ value`8
  OrINC                               {value}              => 0xB8 @ value`8
  XorI                                {value}              => 0xB9 @ value`8
  XorIZ                               {value}              => 0xBA @ value`8
  XorIC                               {value}              => 0xBB @ value`8
  XorINZ                              {value}              => 0xBC @ value`8
  XorINC                              {value}              => 0xBD @ value`8
  Not                                                      => 0xBE 
  NotZ                                                     => 0xBF 
  NotC                                                     => 0xC0 
  NotNZ                                                    => 0xC1 
  NotNC                                                    => 0xC2 
  Add                                 {address}            => 0xC3 @ address`16
  AddZ                                {address}            => 0xC4 @ address`16
  AddC                                {address}            => 0xC5 @ address`16
  AddNZ                               {address}            => 0xC6 @ address`16
  AddNC                               {address}            => 0xC7 @ address`16
  Sub                                 {address}            => 0xC8 @ address`16
  SubZ                                {address}            => 0xC9 @ address`16
  SubC                                {address}            => 0xCA @ address`16
  SubNZ                               {address}            => 0xCB @ address`16
  SubNC                               {address}            => 0xCC @ address`16
  And                                 {address}            => 0xCD @ address`16
  AndZ                                {address}            => 0xCE @ address`16
  AndC                                {address}            => 0xCF @ address`16
  AndNZ                               {address}            => 0xD0 @ address`16
  AndNC                               {address}            => 0xD1 @ address`16
  Or                                  {address}            => 0xD2 @ address`16
  OrZ                                 {address}            => 0xD3 @ address`16
  OrC                                 {address}            => 0xD4 @ address`16
  OrNZ                                {address}            => 0xD5 @ address`16
  OrNC                                {address}            => 0xD6 @ address`16
  Xor                                 {address}            => 0xD7 @ address`16
  XorZ                                {address}            => 0xD8 @ address`16
  XorC                                {address}            => 0xD9 @ address`16
  XorNZ                               {address}            => 0xDA @ address`16
  XorNC                               {address}            => 0xDB @ address`16
  Nop                                                      => 0xDC 
  Nop1                                                     => 0xDD 
  Nop2                                                     => 0xDE 
  Halt                                                     => 0xDF 
}



; Constants for updating an 8 x 16 shift-register display
RCLCK  = 0b10000000
SRCLCK = 0b01000000
SER    = 0b00100000
PIXELW = 8
PIXELH = 16
PIXELS = PIXELW * PIXELH

; Constants for input
BUTTON_CLEAR  = 0b10000000
BUTTON_UP     = 0b01000000
BUTTON_DOWN   = 0b00100000
BUTTON_LEFT   = 0b00010000
BUTTON_RIGHT  = 0b00001000
BUTTON_HALT   = 0b00000001

; Zero page addresses
DOT_X  = 0x00
DOT_Y  = 0x01
ITER_Y = 0x02

main:
  Call clear_display
  StoreI  DOT_X 3
  StoreI  DOT_Y 7
  
  input_loop:
  Read InA
  
  LoadI A     BUTTON_UP
  CmpAndReg InA
  CallNZ      up
  
  LoadI A     BUTTON_DOWN
  CmpAndReg InA
  CallNZ      down
  
  LoadI A     BUTTON_LEFT
  CmpAndReg InA
  CallNZ      left
  
  LoadI A     BUTTON_RIGHT
  CmpAndReg InA
  CallNZ      right
  
  LoadI A     BUTTON_CLEAR
  CmpAndReg InA
  CallNZ      clear_display
  
  LoadI A     BUTTON_HALT
  CmpAndReg InA
  JumpNZ      halt
  
  Jump      input_loop

up:
  PushAll
  LoadZP A  DOT_Y
  SubI    1
  AndI    0b00001111
  StoreZP A DOT_Y
  PopAll
  Call display
  Return

down:
  PushAll
  LoadZP A  DOT_Y
  AddI    1
  AndI    0b00001111
  StoreZP A DOT_Y
  PopAll
  Call display
  Return

left:
  PushAll
  LoadZP A  DOT_X
  SubI    1
  AndI    0b00000111
  StoreZP A DOT_X
  PopAll
  Call display
  Return

right:
  PushAll
  LoadZP A  DOT_X
  AddI    1
  AndI    0b00000111
  StoreZP A DOT_X
  PopAll
  Call display
  Return

display:
  PushAll
  LoadI A   0
  StoreZP A ITER_Y
  .row_loop:
    LoadI C 0
      .col_loop:
      LoadZP A  DOT_X
      CmpReg C
      CallNC    send_zero
      JumpNC    .break
      LoadZP A  DOT_Y
      Cmp     ITER_Y
      CallC   send_one
      CallNC    send_zero
      .break:
      Copy C, A
      AddI  1
      Copy A, C
      CmpI  PIXELW
      JumpNZ  .col_loop
    LoadZP A  ITER_Y
    AddI    1
    StoreZP A ITER_Y
    CmpI  PIXELH
    JumpNZ  .row_loop
  LoadI OutA  RCLCK
  LoadI OutA  0
  PopAll
  Return

clear_display:
  LoadI A PIXELS
  .loop:
    LoadI OutA  0
    LoadI OutA  SRCLCK
    SubI    1
    JumpNZ    .loop
  LoadI OutA  RCLCK
  LoadI OutA  0
  Return

send_zero:
  LoadI OutA  0
  LoadI OutA  SRCLCK
  Return

send_one:
  LoadI OutA  SER
  LoadI OutA  SER | SRCLCK
  Return

halt:
  Halt
  
 */

 byte getSnakeByte(uint16_t address) {
  static const unsigned char PROGMEM data[] = {
    /* 0x000 */ 0x70, 0x00, 0x09, 0x70, 0x00, 0x33, 0x6b, 0x00, 0x00, 0x04, 0x03, 0x09, 0x00, 0x10, 0xff, 0x12, 
    /* 0x010 */ 0x00, 0x51, 0xaa, 0x01, 0x6e, 0x00, 0x11, 0x36, 0x00, 0x11, 0x01, 0x36, 0x00, 0x21, 0x00, 0x36, 
    /* 0x020 */ 0x00, 0x20, 0x02, 0x36, 0x03, 0x00, 0x03, 0x36, 0x03, 0x01, 0x0b, 0x36, 0x03, 0x02, 0x13, 0x36, 
    /* 0x030 */ 0x00, 0x10, 0x44, 0x12, 0x40, 0x70, 0x00, 0x4c, 0x60, 0xaa, 0x01, 0x5a, 0x6e, 0x00, 0x35, 0x70, 
    /* 0x040 */ 0x00, 0x77, 0x70, 0x00, 0xc7, 0x70, 0x00, 0xf4, 0x6b, 0x00, 0x33, 0x75, 0x57, 0x65, 0x7f, 0x40, 
    /* 0x050 */ 0x6e, 0x00, 0x63, 0x7f, 0x20, 0x6e, 0x00, 0x68, 0x7f, 0x10, 0x6e, 0x00, 0x6d, 0x7f, 0x08, 0x6e, 
    /* 0x060 */ 0x00, 0x72, 0x75, 0x36, 0x00, 0x11, 0x00, 0x75, 0x36, 0x00, 0x11, 0x01, 0x75, 0x36, 0x00, 0x11, 
    /* 0x070 */ 0x02, 0x75, 0x36, 0x00, 0x11, 0x03, 0x75, 0x16, 0x20, 0x04, 0x03, 0x05, 0x24, 0xa5, 0x01, 0x37, 
    /* 0x080 */ 0x20, 0x60, 0xaf, 0x07, 0x37, 0x13, 0x60, 0xaf, 0x78, 0x37, 0x14, 0x16, 0x11, 0x7f, 0x02, 0x6e, 
    /* 0x090 */ 0x00, 0x95, 0x6c, 0x00, 0xa9, 0x7e, 0x02, 0x60, 0xab, 0x01, 0x16, 0x11, 0x7e, 0x02, 0x60, 0xa8, 
    /* 0x0a0 */ 0x01, 0xaf, 0x07, 0xc3, 0x00, 0x14, 0x6b, 0x00, 0xba, 0x7e, 0x00, 0x60, 0xab, 0x08, 0x16, 0x11, 
    /* 0x0b0 */ 0x7e, 0x00, 0x60, 0xa8, 0x08, 0xaf, 0x78, 0xc3, 0x00, 0x13, 0x18, 0x20, 0x04, 0x03, 0x07, 0x47, 
    /* 0x0c0 */ 0x16, 0x21, 0xa5, 0x01, 0x37, 0x21, 0x75, 0x04, 0x02, 0x09, 0x00, 0x10, 0x80, 0x12, 0x00, 0x51, 
    /* 0x0d0 */ 0xaa, 0x01, 0x6e, 0x00, 0xcf, 0x18, 0x21, 0x04, 0x03, 0x07, 0x22, 0x04, 0x02, 0x05, 0x10, 0x01, 
    /* 0x0e0 */ 0x47, 0x60, 0xa5, 0x01, 0x5a, 0x80, 0x00, 0x20, 0x6e, 0x00, 0xd7, 0x18, 0x10, 0x04, 0x02, 0x07, 
    /* 0x0f0 */ 0x10, 0x01, 0x47, 0x75, 0x12, 0x80, 0x04, 0x02, 0x09, 0x00, 0x28, 0x7e, 0x00, 0x10, 0x00, 0xa8, 
    /* 0x100 */ 0x20, 0x5d, 0xa5, 0x40, 0x5d, 0x60, 0xaa, 0x01, 0x5a, 0x6e, 0x00, 0xfa, 0x14, 0x80, 0x14, 0x00, 
    /* 0x110 */ 0x75
  };
  int len = sizeof(data) / sizeof(*data);
  return address < len ? pgm_read_byte(&data[address]) : 0;
}

/*
 * Program generated on https://hlorenzi.github.io/customasm/web/ from:
 
#ruledef {
  SetPageReg     A                                         => 0x00
  SetPageReg     B                                         => 0x01
  SetPageReg     C                                         => 0x02
  SetPageReg     Swap                                      => 0x03
  SetPageI                            {value}              => 0x04 @ value`8
  SetAddrReg     A                                         => 0x05
  SetAddrReg     B                                         => 0x06
  SetAddrReg     C                                         => 0x07
  SetAddrReg     Swap                                      => 0x08
  SetAddrI                            {value}              => 0x09 @ value`8
  Load           A                    {address}            => 0x0A @ address`16
  Load           B                    {address}            => 0x0B @ address`16
  Load           C                    {address}            => 0x0C @ address`16
  Load           Swap                 {address}            => 0x0D @ address`16
  Load           OutA                 {address}            => 0x0E @ address`16
  Load           OutB                 {address}            => 0x0F @ address`16
  LoadI          A                    {value}              => 0x10 @ value`8
  LoadI          B                    {value}              => 0x11 @ value`8
  LoadI          C                    {value}              => 0x12 @ value`8
  LoadI          Swap                 {value}              => 0x13 @ value`8
  LoadI          OutA                 {value}              => 0x14 @ value`8
  LoadI          OutB                 {value}              => 0x15 @ value`8
  LoadZP         A                    {value}              => 0x16 @ value`8
  LoadZP         B                    {value}              => 0x17 @ value`8
  LoadZP         C                    {value}              => 0x18 @ value`8
  LoadZP         Swap                 {value}              => 0x19 @ value`8
  LoadZP         OutA                 {value}              => 0x1A @ value`8
  LoadZP         OutB                 {value}              => 0x1B @ value`8
  LoadP          A                    {value}              => 0x1C @ value`8
  LoadP          B                    {value}              => 0x1D @ value`8
  LoadP          C                    {value}              => 0x1E @ value`8
  LoadP          Swap                 {value}              => 0x1F @ value`8
  LoadP          OutA                 {value}              => 0x20 @ value`8
  LoadP          OutB                 {value}              => 0x21 @ value`8
  LoadInc        A, 0                                      => 0x22
  LoadInc        B, 0                                      => 0x23
  LoadInc        C, 0                                      => 0x24
  LoadInc        Swap, 0                                   => 0x25
  LoadInc        OutA, 0                                   => 0x26
  LoadInc        OutB, 0                                   => 0x27
  LoadInc        A, 1                                      => 0x28
  LoadInc        B, 1                                      => 0x29
  LoadInc        C, 1                                      => 0x2A
  LoadInc        Swap, 1                                   => 0x2B
  LoadInc        OutA, 1                                   => 0x2C
  LoadInc        OutB, 1                                   => 0x2D
  Store          A                    {address}            => 0x2E @ address`16
  Store          B                    {address}            => 0x2F @ address`16
  Store          C                    {address}            => 0x30 @ address`16
  Store          Swap                 {address}            => 0x31 @ address`16
  Store          OutA                 {address}            => 0x32 @ address`16
  Store          OutB                 {address}            => 0x33 @ address`16
  Store          InA                  {address}            => 0x34 @ address`16
  Store          InB                  {address}            => 0x35 @ address`16
  StoreI                              {address} {value}    => 0x36 @ address`16 @ value`8
  StoreZP        A                    {value}              => 0x37 @ value`8
  StoreZP        B                    {value}              => 0x38 @ value`8
  StoreZP        C                    {value}              => 0x39 @ value`8
  StoreZP        Swap                 {value}              => 0x3A @ value`8
  StoreZP        OutA                 {value}              => 0x3B @ value`8
  StoreZP        OutB                 {value}              => 0x3C @ value`8
  StoreZP        InA                  {value}              => 0x3D @ value`8
  StoreZP        InB                  {value}              => 0x3E @ value`8
  StoreP         A                    {value}              => 0x3F @ value`8
  StoreP         B                    {value}              => 0x40 @ value`8
  StoreP         C                    {value}              => 0x41 @ value`8
  StoreP         Swap                 {value}              => 0x42 @ value`8
  StoreP         OutA                 {value}              => 0x43 @ value`8
  StoreP         OutB                 {value}              => 0x44 @ value`8
  StoreP         InA                  {value}              => 0x45 @ value`8
  StoreP         InB                  {value}              => 0x46 @ value`8
  StoreInc       A, 0                                      => 0x47
  StoreInc       B, 0                                      => 0x48
  StoreInc       C, 0                                      => 0x49
  StoreInc       Swap, 0                                   => 0x4A
  StoreInc       OutA, 0                                   => 0x4B
  StoreInc       OutB, 0                                   => 0x4C
  StoreInc       InA, 0                                    => 0x4D
  StoreInc       InB, 0                                    => 0x4E
  StoreInc       A, 1                                      => 0x4F
  StoreInc       B, 1                                      => 0x50
  StoreInc       C, 1                                      => 0x51
  StoreInc       Swap, 1                                   => 0x52
  StoreInc       OutA, 1                                   => 0x53
  StoreInc       OutB, 1                                   => 0x54
  StoreInc       InA, 1                                    => 0x55
  StoreInc       InB, 1                                    => 0x56
  Read           InA                                       => 0x57
  Read           InB                                       => 0x58
  Copy           A, B                                      => 0x59
  Copy           A, C                                      => 0x5A
  Copy           A, Swap                                   => 0x5B
  Copy           A, Stack                                  => 0x5C
  Copy           A, OutA                                   => 0x5D
  Copy           A, OutB                                   => 0x5E
  Copy           B, A                                      => 0x5F
  Copy           C, A                                      => 0x60
  Copy           Swap, A                                   => 0x61
  Copy           Stack, A                                  => 0x62
  Copy           OutA, A                                   => 0x63
  Copy           OutB, A                                   => 0x64
  Copy           InA, A                                    => 0x65
  Copy           InB, A                                    => 0x66
  Copy           PCnt, A                                   => 0x67
  Copy           PCnt, A, HighB                            => 0x68
  Copy           MAdr, A                                   => 0x69
  Copy           MAdr, A, HighB                            => 0x6A
  Jump                                {address}            => 0x6B @ address`16
  JumpZ                               {address}            => 0x6C @ address`16
  JumpC                               {address}            => 0x6D @ address`16
  JumpNZ                              {address}            => 0x6E @ address`16
  JumpNC                              {address}            => 0x6F @ address`16
  Call                                {address}            => 0x70 @ address`16
  CallZ                               {address}            => 0x71 @ address`16
  CallC                               {address}            => 0x72 @ address`16
  CallNZ                              {address}            => 0x73 @ address`16
  CallNC                              {address}            => 0x74 @ address`16
  Return                                                   => 0x75
  Push           A                                         => 0x76
  Push           B                                         => 0x77
  Push           C                                         => 0x78
  Pop            A                                         => 0x79
  Pop            B                                         => 0x7A
  Pop            C                                         => 0x7B
  PushAll                                                  => 0x7C
  PopAll                                                   => 0x7D
  CmpI                                {value}              => 0x7E @ value`8
  CmpAndI                             {value}              => 0x7F @ value`8
  Cmp                                 {address}            => 0x80 @ address`16
  CmpAnd                              {address}            => 0x81 @ address`16
  CmpReg         C                                         => 0x82
  CmpReg         Swap                                      => 0x83
  CmpReg         Stack                                     => 0x84
  CmpReg         OutA                                      => 0x85
  CmpReg         OutB                                      => 0x86
  CmpReg         InA                                       => 0x87
  CmpReg         InB                                       => 0x88
  CmpAndReg      C                                         => 0x89
  CmpAndReg      Swap                                      => 0x8A
  CmpAndReg      Stack                                     => 0x8B
  CmpAndReg      OutA                                      => 0x8C
  CmpAndReg      OutB                                      => 0x8D
  CmpAndReg      InA                                       => 0x8E
  CmpAndReg      InB                                       => 0x8F
  Mult           0                                         => 0x90
  Mult           1                                         => 0x91
  Mult           2                                         => 0x92
  Mult           3                                         => 0x93
  Mult           4                                         => 0x94
  Mult           5                                         => 0x95
  Mult           6                                         => 0x96
  Mult           7                                         => 0x97
  Mult           8                                         => 0x98
  Mult           9                                         => 0x99
  Mult           10                                        => 0x9A
  Mult           11                                        => 0x9B
  Mult           12                                        => 0x9C
  Mult           13                                        => 0x9D
  ShiftL         1                                         => 0x9E
  ShiftL         2                                         => 0x9F
  ShiftL         3                                         => 0xA0
  ShiftL         4                                         => 0xA1
  ShiftL         5                                         => 0xA2
  ShiftL         6                                         => 0xA3
  ShiftL         7                                         => 0xA4
  AddI                                {value}              => 0xA5 @ value`8
  AddIZ                               {value}              => 0xA6 @ value`8
  AddIC                               {value}              => 0xA7 @ value`8
  AddINZ                              {value}              => 0xA8 @ value`8
  AddINC                              {value}              => 0xA9 @ value`8
  SubI                                {value}              => 0xAA @ value`8
  SubIZ                               {value}              => 0xAB @ value`8
  SubIC                               {value}              => 0xAC @ value`8
  SubINZ                              {value}              => 0xAD @ value`8
  SubINC                              {value}              => 0xAE @ value`8
  AndI                                {value}              => 0xAF @ value`8
  AndIZ                               {value}              => 0xB0 @ value`8
  AndIC                               {value}              => 0xB1 @ value`8
  AndINZ                              {value}              => 0xB2 @ value`8
  AndINC                              {value}              => 0xB3 @ value`8
  OrI                                 {value}              => 0xB4 @ value`8
  OrIZ                                {value}              => 0xB5 @ value`8
  OrIC                                {value}              => 0xB6 @ value`8
  OrINZ                               {value}              => 0xB7 @ value`8
  OrINC                               {value}              => 0xB8 @ value`8
  XorI                                {value}              => 0xB9 @ value`8
  XorIZ                               {value}              => 0xBA @ value`8
  XorIC                               {value}              => 0xBB @ value`8
  XorINZ                              {value}              => 0xBC @ value`8
  XorINC                              {value}              => 0xBD @ value`8
  Not                                                      => 0xBE
  NotZ                                                     => 0xBF
  NotC                                                     => 0xC0
  NotNZ                                                    => 0xC1
  NotNC                                                    => 0xC2
  Add                                 {address}            => 0xC3 @ address`16
  AddZ                                {address}            => 0xC4 @ address`16
  AddC                                {address}            => 0xC5 @ address`16
  AddNZ                               {address}            => 0xC6 @ address`16
  AddNC                               {address}            => 0xC7 @ address`16
  Sub                                 {address}            => 0xC8 @ address`16
  SubZ                                {address}            => 0xC9 @ address`16
  SubC                                {address}            => 0xCA @ address`16
  SubNZ                               {address}            => 0xCB @ address`16
  SubNC                               {address}            => 0xCC @ address`16
  And                                 {address}            => 0xCD @ address`16
  AndZ                                {address}            => 0xCE @ address`16
  AndC                                {address}            => 0xCF @ address`16
  AndNZ                               {address}            => 0xD0 @ address`16
  AndNC                               {address}            => 0xD1 @ address`16
  Or                                  {address}            => 0xD2 @ address`16
  OrZ                                 {address}            => 0xD3 @ address`16
  OrC                                 {address}            => 0xD4 @ address`16
  OrNZ                                {address}            => 0xD5 @ address`16
  OrNC                                {address}            => 0xD6 @ address`16
  Xor                                 {address}            => 0xD7 @ address`16
  XorZ                                {address}            => 0xD8 @ address`16
  XorC                                {address}            => 0xD9 @ address`16
  XorNZ                               {address}            => 0xDA @ address`16
  XorNC                               {address}            => 0xDB @ address`16
  Nop                                                      => 0xDC
  Nop1                                                     => 0xDD
  Nop2                                                     => 0xDE
  Halt                                                     => 0xDF
}


; Constants for updating an 8 x 16 shift-register display
RCLCK  = 0b10000000
SRCLCK = 0b01000000
SER    = 0b00100000
PIXELW = 8
PIXELH = 16
PIXELS = PIXELW * PIXELH

; Memory page constants
DISP_BUF   = 0x02
SNAKE_PAGE = 0x03

; Constants for input
BUTTON_PAUSE  = 0b10000000
BUTTON_UP     = 0b01000000
BUTTON_DOWN   = 0b00100000
BUTTON_LEFT   = 0b00010000
BUTTON_RIGHT  = 0b00001000
BUTTON_HALT   = 0b00000001

; Game constants
UP              = 0b00
DOWN            = 0b01
LEFT            = 0b10
RIGHT           = 0b11
HORIZONTAL_MASK = 0b10

X_BIT_MASK      = 0b00000111
Y_BIT_MASK      = 0b01111000

; Zero page addresses
FOOD    = 0x10
DIR     = 0x11
PAUSED  = 0x12
X_BITS  = 0x13
Y_BITS  = 0x14

SNAKE_HEAD = 0x20
SNAKE_TAIL = 0x21

main:
  Call  init
  Call  game_loop
  Jump  main

init:
  StoreI    DIR                       DOWN
  StoreI    SNAKE_TAIL                0
  StoreI    SNAKE_HEAD                2
  StoreI    SNAKE_PAGE * 0x100 + 0    0 * 0b1000 + 3
  StoreI    SNAKE_PAGE * 0x100 + 1    1 * 0b1000 + 3
  StoreI    SNAKE_PAGE * 0x100 + 2    2 * 0b1000 + 3
  StoreI    FOOD                      8 * 0b1000 + 4

game_loop:
  LoadI C 64 ; Check for input 64 times before doing anything else, to add delay
  .input_loop:
    Call        handle_input
    Copy C, A
    SubI        1
    Copy A, C
    JumpNZ .input_loop

  Call advance_snake
  Call update_display
  Call draw_display
  Jump game_loop
  Return

handle_input:
  Read InA
  Copy InA, A

  CmpAndI BUTTON_UP
  JumpNZ  .up
  CmpAndI BUTTON_DOWN
  JumpNZ  .down
  CmpAndI BUTTON_LEFT
  JumpNZ  .left
  CmpAndI BUTTON_RIGHT
  JumpNZ  .right
  Return

  .up:
    StoreI  DIR UP
    Return
  .down:
    StoreI  DIR DOWN
    Return
  .left:
    StoreI  DIR LEFT
    Return
  .right:
    StoreI  DIR RIGHT
    Return

advance_snake:
  LoadZP A      SNAKE_HEAD
  SetPageI      SNAKE_PAGE
  SetAddrReg A
  LoadInc C, 0              ; Load current snake head into C
  AddI          1
  StoreZP A     SNAKE_HEAD

  Copy C, A
  AndI        X_BIT_MASK
  StoreZP A   X_BITS
  Copy C, A
  AndI        Y_BIT_MASK
  StoreZP A   Y_BITS

  LoadZP A      DIR
  CmpAndI       HORIZONTAL_MASK
  JumpNZ        .horizontal
  JumpZ         .vertical

  .horizontal:
  CmpI        LEFT
  Copy C, A
  SubIZ       1
  LoadZP A    DIR         ; Have to reload DIR and redo comparison, because SubIZ may set flags
  CmpI        LEFT
  Copy C, A
  AddINZ      1
  AndI        X_BIT_MASK
  Add         Y_BITS      ; This is an OR, but using Add for efficiency
  Jump .finish

  .vertical:
  CmpI        UP
  Copy C, A
  SubIZ       1 << 3
  LoadZP A    DIR         ; Have to reload DIR and redo comparison, because SubIZ may set flags
  CmpI        UP
  Copy C, A
  AddINZ      1 << 3
  AndI        Y_BIT_MASK
  Add         X_BITS      ; This is an OR, but using Add for efficiency

  .finish:
  LoadZP C      SNAKE_HEAD
  SetPageI      SNAKE_PAGE
  SetAddrReg C
  StoreInc A, 0
  LoadZP A      SNAKE_TAIL
  AddI          1
  StoreZP A     SNAKE_TAIL
  Return

update_display:
  SetPageI  DISP_BUF
  SetAddrI  0
  LoadI A   PIXELS
  LoadI C   0
  .clear_loop:
    StoreInc C, 1
    SubI 1
    JumpNZ .clear_loop

  LoadZP C  SNAKE_TAIL
  .snake_loop:
    SetPageI      SNAKE_PAGE
    SetAddrReg C
    LoadInc A, 0
    SetPageI      DISP_BUF
    SetAddrReg A
    LoadI A       1
    StoreInc A, 0
    Copy C, A
    AddI          1
    Copy A, C
    Cmp           SNAKE_HEAD
    JumpNZ        .snake_loop

  LoadZP C      FOOD
  SetPageI      DISP_BUF
  SetAddrReg C
  LoadI A       1
  StoreInc A, 0

  Return

draw_display:
  LoadI C   PIXELS
  SetPageI  DISP_BUF
  SetAddrI  0
  .loop:
    LoadInc A, 1
    CmpI    0
    LoadI A 0
    AddINZ  SER
    Copy    A, OutA
    AddI    SRCLCK
    Copy    A, OutA
    Copy    C, A
    SubI    1
    Copy    A, C
    JumpNZ  .loop
  LoadI OutA  RCLCK
  LoadI OutA  0
  Return
  
 */
