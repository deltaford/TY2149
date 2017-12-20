/****************************************************************************

TY2149_uVGA_demo     Example of YM2149 emulation together with VGA visuals
                     by Stefan Sjögren 2017
                     
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

// Requires: 
// - Teensy 3.6 @240Mhz
// - Speaker/headphone connected to DAC0/A21 (preferrably with a 10uF cap) 
// - uVGA library (https://forum.pjrc.com/threads/45916-Teensy-3-6-VGA-driver) 
// 
// Uses two interrupts, one to feed register data, one to generate and output audio



#include <uVGA.h>
uVGA uvga;

#define UVGA_240M_452X300
#include <uVGA_valid_settings.h>
DMAMEM uint8_t screen[UVGA_FB_SIZE(UVGA_HREZ, UVGA_VREZ, UVGA_RPTL, UVGA_TOP_MARGIN, UVGA_BOTTOM_MARGIN)];
#include "ymdata.h"
#include "demo.h"
#include "emu2149.h"

IntervalTimer ISR1, ISR2;
PSG ym2149;
int32_t ymoutput, ymoutraw, ymr = 0, ymdataidx = 0, vbltimer; 
int16_t ymch[3] = {0,0,0}, oldymch[3] = {0,0,0};
uint32_t  vbl = 0;
uint32_t *screen_dword = (uint32_t*) &screen;
int fb_width , fb_height, sx, sy; 


void uVGA_init()
{
  int ret;
  uvga.set_static_framebuffer(screen);
  ret = uvga.begin(&modeline);
  if(ret != 0)
  {
    Serial.println("fatal error");
    while(1);
  }
   uvga.get_frame_buffer_size(&fb_width, &fb_height);
}

void YM_init()
{
  pinMode(A21,OUTPUT);
  analogReference(2);         
  analogWriteResolution(12);
  analogWrite(A21,0);
  ISR1.begin(ISR1_YMtoDAC, 10);
  ISR2.begin(ISR2_YMupdate, 20000);
  PSG_reset(&ym2149);
  PSG_set_quality(&ym2149, 1);   //Rendering quality 0:LOW 1:HIGH
  PSG_setVolumeMode(&ym2149, 1);
  PSG_set_clk(&ym2149,2000000);
  PSG_set_rate(&ym2149, 44100);
}

void ISR1_YMtoDAC()
{
  __disable_irq();
  ymoutraw = PSG_calc(&ym2149);
  ymoutput = (ymoutraw >> 3) + 2048;
  analogWrite(A21, ymoutput);
  __enable_irq();
}

void ISR2_YMupdate()
{
  __disable_irq();
  for(unsigned long ymreg = 0; ymreg < 14 ; ymreg++)
  {
      ymdataidx = ((ymdata_len/14)*ymreg)+ vbl;
      PSG_writeReg(&ym2149,ymreg,ymdata[ymdataidx]);
  }
  vbl++;
  if(vbl>(ymdata_len/14))
  {
    vbl = 0;
  }
  __enable_irq();
}

void setup()
{
  Serial.begin(115200);
  delay(2000);
  Serial.println("TY2149 VGA demo starting...");
  uVGA_init();
  YM_init();
  InitStarfield();
  fillscreen(0);
}

void loop()
{
	while(1)
  {
    Starfield();
    DrawBanner();
    scrolline();
    Rasterbars();
    YM_VUmeter();
    DrawAtariFuji();
    uvga.waitSync();
  }
}



