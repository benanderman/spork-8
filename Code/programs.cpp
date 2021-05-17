#include "programs.h"

byte getMovingDotByte(uint16_t address) {
  static const unsigned char PROGMEM data[] = {
    /* 0x00 */ 0x4a, 0x00, 0x9c, 0x20, 0x00, 0x00, 0x03, 0x20, 0x00, 0x01, 0x07, 0x31, 0x06, 0x40, 0x68, 0x4d, 
    /* 0x10 */ 0x00, 0x33, 0x06, 0x20, 0x68, 0x4d, 0x00, 0x41, 0x06, 0x10, 0x68, 0x4d, 0x00, 0x4f, 0x06, 0x08, 
    /* 0x20 */ 0x68, 0x4d, 0x00, 0x5d, 0x06, 0x80, 0x68, 0x4d, 0x00, 0x9c, 0x06, 0x01, 0x68, 0x48, 0x00, 0xb6, 
    /* 0x30 */ 0x45, 0x00, 0x0b, 0x56, 0x0c, 0x01, 0x6b, 0x01, 0x6c, 0x0f, 0x21, 0x01, 0x57, 0x4a, 0x00, 0x6b, 
    /* 0x40 */ 0x4f, 0x56, 0x0c, 0x01, 0x6a, 0x01, 0x6c, 0x0f, 0x21, 0x01, 0x57, 0x4a, 0x00, 0x6b, 0x4f, 0x56, 
    /* 0x50 */ 0x0c, 0x00, 0x6b, 0x01, 0x6c, 0x07, 0x21, 0x00, 0x57, 0x4a, 0x00, 0x6b, 0x4f, 0x56, 0x0c, 0x00, 
    /* 0x60 */ 0x6a, 0x01, 0x6c, 0x07, 0x21, 0x00, 0x57, 0x4a, 0x00, 0x6b, 0x4f, 0x56, 0x06, 0x00, 0x21, 0x02, 
    /* 0x70 */ 0x08, 0x00, 0x0c, 0x00, 0x5c, 0x4d, 0x00, 0xac, 0x48, 0x00, 0x86, 0x0c, 0x01, 0x5a, 0x00, 0x02, 
    /* 0x80 */ 0x4b, 0x00, 0xb1, 0x4d, 0x00, 0xac, 0x3a, 0x6a, 0x01, 0x34, 0x58, 0x08, 0x48, 0x00, 0x72, 0x0c, 
    /* 0x90 */ 0x02, 0x6a, 0x01, 0x21, 0x02, 0x58, 0x10, 0x48, 0x00, 0x70, 0x57, 0x4f, 0x06, 0x80, 0x0a, 0x00, 
    /* 0xa0 */ 0x0a, 0x40, 0x6b, 0x01, 0x48, 0x00, 0x9e, 0x0a, 0x80, 0x0a, 0x00, 0x4f, 0x0a, 0x00, 0x0a, 0x40, 
    /* 0xb0 */ 0x4f, 0x0a, 0x20, 0x0a, 0x60, 0x4f, 0x78
  };
  int len = sizeof(data) / sizeof(*data);
  return address < len ? pgm_read_byte(&data[address]) : 0;
}

/*
 * Program generated on https://hlorenzi.github.io/customasm/web/ from:

#ruledef {
  Load           A                    {address}            => 0x00 @ address`16
  Load           B                    {address}            => 0x01 @ address`16
  Load           C                    {address}            => 0x02 @ address`16
  Load           Swap                 {address}            => 0x03 @ address`16
  Load           OutA                 {address}            => 0x04 @ address`16
  Load           OutB                 {address}            => 0x05 @ address`16
  LoadI          A                    {value}              => 0x06 @ value`8
  LoadI          B                    {value}              => 0x07 @ value`8
  LoadI          C                    {value}              => 0x08 @ value`8
  LoadI          Swap                 {value}              => 0x09 @ value`8
  LoadI          OutA                 {value}              => 0x0A @ value`8
  LoadI          OutB                 {value}              => 0x0B @ value`8
  LoadZP         A                    {value}              => 0x0C @ value`8
  LoadZP         B                    {value}              => 0x0D @ value`8
  LoadZP         C                    {value}              => 0x0E @ value`8
  LoadZP         Swap                 {value}              => 0x0F @ value`8
  LoadZP         OutA                 {value}              => 0x10 @ value`8
  LoadZP         OutB                 {value}              => 0x11 @ value`8
  LoadN          A                                         => 0x12 
  LoadN          B                                         => 0x13 
  LoadN          C                                         => 0x14 
  LoadN          Swap                                      => 0x15 
  LoadN          OutA                                      => 0x16 
  LoadN          OutB                                      => 0x17 
  Store          A                    {address}            => 0x18 @ address`16
  Store          B                    {address}            => 0x19 @ address`16
  Store          C                    {address}            => 0x1A @ address`16
  Store          Swap                 {address}            => 0x1B @ address`16
  Store          OutA                 {address}            => 0x1C @ address`16
  Store          OutB                 {address}            => 0x1D @ address`16
  Store          InA                  {address}            => 0x1E @ address`16
  Store          InB                  {address}            => 0x1F @ address`16
  StoreI                              {address} {value}    => 0x20 @ address`16 @ value`8
  StoreZP        A                    {value}              => 0x21 @ value`8
  StoreZP        B                    {value}              => 0x22 @ value`8
  StoreZP        C                    {value}              => 0x23 @ value`8
  StoreZP        Swap                 {value}              => 0x24 @ value`8
  StoreZP        OutA                 {value}              => 0x25 @ value`8
  StoreZP        OutB                 {value}              => 0x26 @ value`8
  StoreZP        InA                  {value}              => 0x27 @ value`8
  StoreZP        InB                  {value}              => 0x28 @ value`8
  StoreN         A                                         => 0x29 
  StoreN         B                                         => 0x2A 
  StoreN         C                                         => 0x2B 
  StoreN         Swap                                      => 0x2C 
  StoreN         OutA                                      => 0x2D 
  StoreN         OutB                                      => 0x2E 
  StoreN         InA                                       => 0x2F 
  StoreN         InB                                       => 0x30 
  Read           InA                                       => 0x31 
  Read           InB                                       => 0x32 
  Copy           A, B                                      => 0x33 
  Copy           A, C                                      => 0x34 
  Copy           A, Swap                                   => 0x35 
  Copy           A, Stack                                  => 0x36 
  Copy           A, OutA                                   => 0x37 
  Copy           A, OutB                                   => 0x38 
  Copy           B, A                                      => 0x39 
  Copy           C, A                                      => 0x3A 
  Copy           Swap, A                                   => 0x3B 
  Copy           Stack, A                                  => 0x3C 
  Copy           OutA, A                                   => 0x3D 
  Copy           OutB, A                                   => 0x3E 
  Copy           InA, A                                    => 0x3F 
  Copy           InB, A                                    => 0x40 
  Copy           PCnt, A                                   => 0x41 
  Copy           PCnt, A, HighB                            => 0x42 
  Copy           MAdr, A                                   => 0x43 
  Copy           MAdr, A, HighB                            => 0x44 
  Jump                                {address}            => 0x45 @ address`16
  JumpZ                               {address}            => 0x46 @ address`16
  JumpC                               {address}            => 0x47 @ address`16
  JumpNZ                              {address}            => 0x48 @ address`16
  JumpNC                              {address}            => 0x49 @ address`16
  Call                                {address}            => 0x4A @ address`16
  CallZ                               {address}            => 0x4B @ address`16
  CallC                               {address}            => 0x4C @ address`16
  CallNZ                              {address}            => 0x4D @ address`16
  CallNC                              {address}            => 0x4E @ address`16
  Return                                                   => 0x4F 
  Push           A                                         => 0x50 
  Push           B                                         => 0x51 
  Push           C                                         => 0x52 
  Pop            A                                         => 0x53 
  Pop            B                                         => 0x54 
  Pop            C                                         => 0x55 
  PushAll                                                  => 0x56 
  PopAll                                                   => 0x57 
  CmpI                                {value}              => 0x58 @ value`8
  CmpAndI                             {value}              => 0x59 @ value`8
  Cmp                                 {address}            => 0x5A @ address`16
  CmpAnd                              {address}            => 0x5B @ address`16
  CmpReg         C                                         => 0x5C 
  CmpReg         Swap                                      => 0x5D 
  CmpReg         Stack                                     => 0x5E 
  CmpReg         OutA                                      => 0x5F 
  CmpReg         OutB                                      => 0x60 
  CmpReg         InA                                       => 0x61 
  CmpReg         InB                                       => 0x62 
  CmpAndReg      C                                         => 0x63 
  CmpAndReg      Swap                                      => 0x64 
  CmpAndReg      Stack                                     => 0x65 
  CmpAndReg      OutA                                      => 0x66 
  CmpAndReg      OutB                                      => 0x67 
  CmpAndReg      InA                                       => 0x68 
  CmpAndReg      InB                                       => 0x69 
  AddI                                {value}              => 0x6A @ value`8
  SubI                                {value}              => 0x6B @ value`8
  AndI                                {value}              => 0x6C @ value`8
  OrI                                 {value}              => 0x6D @ value`8
  XorI                                {value}              => 0x6E @ value`8
  Not                                                      => 0x6F 
  Add                                 {address}            => 0x70 @ address`16
  Sub                                 {address}            => 0x71 @ address`16
  And                                 {address}            => 0x72 @ address`16
  Or                                  {address}            => 0x73 @ address`16
  Xor                                 {address}            => 0x74 @ address`16
  Nop                                                      => 0x75 
  Nop1                                                     => 0x76 
  Nop2                                                     => 0x77 
  Halt                                                     => 0x78 
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
      CallNZ    send_zero
      JumpNZ    .break
      LoadZP A  DOT_Y
      Cmp     ITER_Y
      CallZ   send_one
      CallNZ    send_zero
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
