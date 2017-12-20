/****************************************************************************

 emu2149.h      YM2149/AY-3-8910 emulator by Mitsutaka Okazaki 2001-2016 
 
The MIT License (MIT)

Copyright (c) 2014 Mitsutaka Okazaki

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
#ifndef _EMU2149_H_
#define _EMU2149_H_

#include <stdint.h>

#define EMU2149_VOL_DEFAULT 1
#define EMU2149_VOL_YM2149 0
#define EMU2149_VOL_AY_3_8910 1

#define PSG_MASK_CH(x) (1<<(x))

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct __PSG
  {

    /* Volume Table */
    uint32_t *voltbl;

    uint8_t reg[0x20];
    int32_t out;

    uint32_t clk, rate, base_incr, quality;

    uint32_t count[3];
    uint32_t volume[3];
    uint32_t freq[3];
    uint32_t edge[3];
    uint32_t tmask[3];
    uint32_t nmask[3];
    uint32_t mask;

    uint32_t base_count;

    uint32_t env_volume;
    uint32_t env_ptr;
    uint32_t env_face;

    uint32_t env_continue;
    uint32_t env_attack;
    uint32_t env_alternate;
    uint32_t env_hold;
    uint32_t env_pause;
    uint32_t env_reset;

    uint32_t env_freq;
    uint32_t env_count;

    uint32_t noise_seed;
    uint32_t noise_count;
    uint32_t noise_freq;

    /* rate converter */
    uint32_t realstep;
    uint32_t psgtime;
    uint32_t psgstep;

    /* I/O Ctrl */
    uint32_t adr;

    /* output of channels */
    int16_t ch_out[3];

  } PSG;

  void PSG_set_quality (PSG * psg, uint32_t q);
  void PSG_set_rate (PSG * psg, uint32_t r);
  PSG *PSG_new (uint32_t clk, uint32_t rate);
  void PSG_reset (PSG *);
  void PSG_delete (PSG *);
  void PSG_writeReg (PSG *, uint32_t reg, uint32_t val);
  void PSG_writeIO (PSG * psg, uint32_t adr, uint32_t val);
  uint8_t PSG_readReg (PSG * psg, uint32_t reg);
  uint8_t PSG_readIO (PSG * psg);
  int16_t PSG_calc (PSG *);
  void PSG_setVolumeMode (PSG * psg, int type);
  uint32_t PSG_setMask (PSG *, uint32_t mask);
  uint32_t PSG_toggleMask (PSG *, uint32_t mask);
  uint32_t PSG_get_clk (PSG *);
  void PSG_set_clk (PSG *, uint32_t c);
  int16_t PSG_get_ch_out(PSG * psg, uint8_t ch);
      
#ifdef __cplusplus
}
#endif

#endif
