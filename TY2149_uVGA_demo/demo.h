/****************************************************************************

demo.h      Graphical demo effects by Stefan Sjogren 2017
 
The MIT License (MIT)

Copyright (c) 2017 Stefan Sjogren

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. 
    
*****************************************************************************/


static const uint8_t PROGMEM scrolltext[] = "         DEMO CREATED FOR TEENSY YM2149 EMULATION PROJECT, TY2149, BY STEFAN SJOGREN.   YM2149 EMULATION CODE BY MITSUTAKA OKAZAKI.  TEENSY VGA DRIVER BY ERIC PREVOTEAU.  MUSIC FROM ATARI ST COMPOSED BY JOCHEN MADMAX HIPPEL.           ";

static const uint8_t PROGMEM BannerSine [1024] =  {


64,64,65,65,66,66,66,67,67,68,68,68,69,69,69,70,
70,71,71,71,72,72,73,73,73,74,74,75,75,75,76,76,
76,77,77,78,78,78,79,79,80,80,80,81,81,81,82,82,
83,83,83,84,84,84,85,85,86,86,86,87,87,87,88,88,
88,89,89,90,90,90,91,91,91,92,92,92,93,93,93,94,
94,95,95,95,96,96,96,97,97,97,98,98,98,99,99,99,
100,100,100,101,101,101,101,102,102,102,103,103,103,104,104,104,
105,105,105,106,106,106,106,107,107,107,108,108,108,108,109,109,
109,110,110,110,110,111,111,111,111,112,112,112,112,113,113,113,
113,114,114,114,114,115,115,115,115,116,116,116,116,117,117,117,
117,117,118,118,118,118,118,119,119,119,119,119,120,120,120,120,
120,121,121,121,121,121,122,122,122,122,122,122,123,123,123,123,
123,123,123,124,124,124,124,124,124,124,125,125,125,125,125,125,
125,125,125,126,126,126,126,126,126,126,126,126,126,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,128,128,128,128,
128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
128,128,128,128,128,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,126,126,126,126,126,126,126,126,126,126,125,125,
125,125,125,125,125,125,125,124,124,124,124,124,124,124,123,123,
123,123,123,123,123,122,122,122,122,122,122,121,121,121,121,121,
120,120,120,120,120,119,119,119,119,119,118,118,118,118,118,117,
117,117,117,117,116,116,116,116,115,115,115,115,114,114,114,114,
113,113,113,113,112,112,112,112,111,111,111,111,110,110,110,110,
109,109,109,108,108,108,108,107,107,107,106,106,106,106,105,105,
105,104,104,104,103,103,103,102,102,102,101,101,101,101,100,100,
100,99,99,99,98,98,98,97,97,97,96,96,96,95,95,95,
94,94,93,93,93,92,92,92,91,91,91,90,90,90,89,89,
88,88,88,87,87,87,86,86,86,85,85,84,84,84,83,83,
83,82,82,81,81,81,80,80,80,79,79,78,78,78,77,77,
76,76,76,75,75,75,74,74,73,73,73,72,72,71,71,71,
70,70,69,69,69,68,68,68,67,67,66,66,66,65,65,64,
64,64,63,63,62,62,62,61,61,60,60,60,59,59,59,58,
58,57,57,57,56,56,55,55,55,54,54,53,53,53,52,52,
52,51,51,50,50,50,49,49,48,48,48,47,47,47,46,46,
45,45,45,44,44,44,43,43,42,42,42,41,41,41,40,40,
40,39,39,38,38,38,37,37,37,36,36,36,35,35,35,34,
34,33,33,33,32,32,32,31,31,31,30,30,30,29,29,29,
28,28,28,27,27,27,27,26,26,26,25,25,25,24,24,24,
23,23,23,22,22,22,22,21,21,21,20,20,20,20,19,19,
19,18,18,18,18,17,17,17,17,16,16,16,16,15,15,15,
15,14,14,14,14,13,13,13,13,12,12,12,12,11,11,11,
11,11,10,10,10,10,10,9,9,9,9,9,8,8,8,8,
8,7,7,7,7,7,6,6,6,6,6,6,5,5,5,5,
5,5,5,4,4,4,4,4,4,4,3,3,3,3,3,3,
3,3,3,2,2,2,2,2,2,2,2,2,2,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,
3,3,3,3,3,3,3,4,4,4,4,4,4,4,5,5,
5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,
8,8,8,8,8,9,9,9,9,9,10,10,10,10,10,11,
11,11,11,11,12,12,12,12,13,13,13,13,14,14,14,14,
15,15,15,15,16,16,16,16,17,17,17,17,18,18,18,18,
19,19,19,20,20,20,20,21,21,21,22,22,22,22,23,23,
23,24,24,24,25,25,25,26,26,26,27,27,27,27,28,28,
28,29,29,29,30,30,30,31,31,31,32,32,32,33,33,33,
34,34,35,35,35,36,36,36,37,37,37,38,38,38,39,39,
40,40,40,41,41,41,42,42,42,43,43,44,44,44,45,45,
45,46,46,47,47,47,48,48,48,49,49,50,50,50,51,51,
52,52,52,53,53,53,54,54,55,55,55,56,56,57,57,57,
58,58,59,59,59,60,60,60,61,61,62,62,62,63,63,64
};


static const uint8_t PROGMEM RasterSine [128] =  {
  20,21,22,23,24,25,26,27,
  28,29,29,30,31,32,33,33,
  34,35,35,36,37,37,38,38,
  38,39,39,39,40,40,40,40,
  40,40,40,40,40,39,39,39,
  38,38,38,37,37,36,35,35,
  34,33,33,32,31,30,29,29,
  28,27,26,25,24,23,22,21,
  20,19,18,17,16,15,14,13,
  12,11,11,10,9,8,7,7,
  6,5,5,4,3,3,2,2,
  2,1,1,1,0,0,0,0,
  0,0,0,0,0,1,1,1,
  2,2,2,3,3,4,5,5,
  6,7,7,8,9,10,11,11,
  12,13,14,15,16,17,18,19
        };

static const uint8_t PROGMEM rainbow[] = {224,228,232,236,240,244,248,252,188,220,156,124,60,92,28,29,30,31,27,23,19,15,11,7,3,67,35,99,131,195,163,227,226,225,224};

static const uint8_t PROGMEM atarifuji[575] =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1
,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1
,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1
,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1
,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1
,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1
,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1
,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1};

static const uint8_t PROGMEM affade[115] = 
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,128,128,192,192,224,224,224,192,192,128,128,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


static const uint8_t PROGMEM banner[165] = 
                      {0,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,1,1,0,0,1,0,0,1,0,1,1,1,1,0,0,
                       0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,
                       0,0,0,1,0,0,0,1,1,1,1,1,0,1,1,1,1,0,0,1,0,0,1,1,1,1,0,1,1,1,1,0,0,
                       0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,
                       0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0};


// 5x5 font by Stefan Sjogren 217
static const uint8_t PROGMEM scrollfont[][5] = {

{0b00111110, // A
 0b00100010,
 0b00111110,
 0b00100010,
 0b00100010},

{0b00111100, // B 
 0b00100100,
 0b00111110,
 0b00100010,
 0b00111110},

{0b00111110, // C
 0b00100000,
 0b00100000,
 0b00100000,
 0b00111110},

{0b00111100, // D
 0b00100100,
 0b00100110,
 0b00100010,
 0b00111110},

{0b00111110, // E
 0b00100000,
 0b00111100,
 0b00100000,
 0b00111110},

 
{0b00111110, // F
 0b00100000,
 0b00111100,
 0b00100000,
 0b00100000},
 
{0b00111110, // G
 0b00100000,
 0b00101110,
 0b00100010,
 0b00111110},

{0b00100010, // H
 0b00100010,
 0b00111110,
 0b00100010,
 0b00100010},


{0b00111110, // I
 0b00001000,
 0b00001000,
 0b00001000,
 0b00111110},

 
{0b00111110, // J
 0b00000010,
 0b00000010,
 0b00100010,
 0b00111110},
 
{0b00100100, // K
 0b00100100,
 0b00111110,
 0b00100010,
 0b00100010},
 
{0b00100000, // L
 0b00100000,
 0b00100000,
 0b00100000,
 0b00111110},
 
{0b00111110, // M
 0b00101010,
 0b00101010,
 0b00100010,
 0b00100010},
 
{0b00111110, // N
 0b00100010,
 0b00100010,
 0b00100010,
 0b00100010},
 
{0b00111110, // O
 0b00100010,
 0b00100010,
 0b00100010,
 0b00111110},
 
{0b00111110, // P
 0b00100010,
 0b00111110,
 0b00100000,
 0b00100000},
 
{0b00111110, // Q
 0b00100010,
 0b00100010,
 0b00100110,
 0b00111110},
 
{0b00111100, // R
 0b00100100,
 0b00111110,
 0b00100010,
 0b00100010},
 
{0b00111110, // S
 0b00100000,
 0b00111110,
 0b00000010,
 0b00111110},
 
{0b00111110, // T
 0b00001000,
 0b00001000,
 0b00001000,
 0b00001000},
 
{0b00100010, // U
 0b00100010,
 0b00100010,
 0b00100010,
 0b00111110},
 
{0b00100010, // V
 0b00100010,
 0b00110110,
 0b00010100,
 0b00011100},
 
{0b00100010, // W
 0b00100010,
 0b00101010,
 0b00101010,
 0b00111110},
 
{0b00100010, // X
 0b00110110,
 0b00011100,
 0b00110110,
 0b00100010},
 
{0b00100010, // Y
 0b00100010,
 0b00111110,
 0b00001000,
 0b00001000},
 
{0b00111110, // Z
 0b00000110,
 0b00011100,
 0b00110000,
 0b00111110},
 
{0b00000000, // ' '
 0b00000000,
 0b00000000,
 0b00000000,
 0b00000000},
 
{0b00111110, // 0
 0b00100010,
 0b00100010,
 0b00100010,
 0b00111110},
 
{0b00011000, // 1
 0b00001000,
 0b00001000,
 0b00001000,
 0b00111110},
 
{0b00111110, // 2
 0b00000010,
 0b00111110,
 0b00100000,
 0b00111110},
 
{0b00111110, // 3
 0b00000010,
 0b00001110,
 0b00000010,
 0b00111110},

{0b00100010, // 4
 0b00100010,
 0b00111110,
 0b00000010,
 0b00000010},

{0b00111110, // 5
 0b00100000,
 0b00111110,
 0b00000010,
 0b00111110},

{0b00100000, // 6
 0b00100000,
 0b00111110,
 0b00100010,
 0b00111110},

{0b00111110, // 7
 0b00000010,
 0b00001110,
 0b00000010,
 0b00000010},

{0b00111110, // 8
 0b00100010,
 0b00111110,
 0b00100010,
 0b00111110},

{0b00111110, // 9
 0b00100010,
 0b00111110,
 0b00000010,
 0b00000010},

{0b00000000, // .
 0b00000000,
 0b00000000,
 0b00000000,
 0b00001000},

{0b00000000, // ,
 0b00000000,
 0b00000000,
 0b00001000,
 0b00011000},

{0b00000000, // -
 0b00000000,
 0b00111110,
 0b00000000,
 0b00000000},
};
  



