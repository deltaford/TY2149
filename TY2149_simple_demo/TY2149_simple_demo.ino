/****************************************************************************

TY2149_simple_demo     Example of YM2149 emulation
                       By Stefan Sjögren 2017
                     
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
// - Teensy 3.x (only tested on 3.6)
// - Speaker/headphone connected to DAC0/21  (preferrably with a 10uF cap) 
// 
// Uses two interrupts, one to feed register data, one to generate and output audio
// YM channel levels displayed on serial

#include "ymdata.h"
#include "emu2149.h"

IntervalTimer ISR1, ISR2;
int32_t ymoutput, ymoutraw, ymr = 0;
int32_t ymdataidx = 0, vbltimer; 
unsigned long vbl = 0;

PSG ym2149;
void setup() 
{
 Serial.begin(115200);
 delay(2000);
 Serial.println("TY2149 simple demo starting...");
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

void loop() 
{
  Serial.print(" YM Channel 0: ");Serial.print(PSG_get_ch_out(&ym2149, 0));
  Serial.print(" \t YM Channel 1: ");Serial.print(PSG_get_ch_out(&ym2149, 1));
  Serial.print(" \t YM Channel 2: ");Serial.print(PSG_get_ch_out(&ym2149, 2));
  Serial.println("");
  delay(20);
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


