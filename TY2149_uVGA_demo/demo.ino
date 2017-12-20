/****************************************************************************

demo.ino      Graphical demo effects by Stefan Sjogren 2017
 
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



#define STARFIELD 400
static uint16_t stars[STARFIELD][5], sc;

void InitStarfield()
{
  for(int s = 0; s < STARFIELD; s++)
  {
    stars[s][0] = random(1,200); //x
    stars[s][1] = random(1,200); //y
    stars[s][2] = random(400,700); //z
    stars[s][3] = stars[s][0]; // last sx
    stars[s][4] = stars[s][1]; // last sy
  }
}

void fillscreen(uint8_t col)
{
  for(int y = 0; y < fb_height; y++)
  {
    Rasterline(y, col);
  }
}

void Starfield()
{
    for(int s = 0; s < STARFIELD; s++)
    {
      stars[s][2] = stars[s][2] - 5;  //                 

      if((s <= (STARFIELD/4)))
      {
        sx = stars[s][0]*256/stars[s][2] + 452/2;  
        sy = stars[s][1]*256/stars[s][2] + 200/2;  
      }
      else if((s > (STARFIELD/4)) && (s <= (STARFIELD/2)))
      {
        sx = -stars[s][0]*256/stars[s][2] + 452/2;  
        sy = stars[s][1]*256/stars[s][2] + 200/2; 
      }
      else if((s > (STARFIELD/2)) && (s <= (3*(STARFIELD/4))))
      {
        sx = stars[s][0]*256/stars[s][2] + 452/2;  
        sy = -stars[s][1]*256/stars[s][2] + 200/2; 
      }
      else if((s > (3*(STARFIELD/4))))
      {
        sx = -stars[s][0]*256/stars[s][2] + 452/2; 
        sy = -stars[s][1]*256/stars[s][2] + 200/2; 
      }
    
      if((stars[s][2] <= 1) || (sy > 250) || (sy < 1) || (sx > 450) || (sx < 1))
      {
        stars[s][2] = random(400,700); 
      }
      else
      {
        if(stars[s][2] > 400) 
        {
         sc = 1;
        }
        else if(stars[s][2] > 200) 
        {
         sc = 73;
        }
        else
        {
         sc = 255; 
        }
        screen[stars[s][4] * UVGA_FB_ROW_STRIDE(fb_width) + stars[s][3]] = 0;
        screen[sy * UVGA_FB_ROW_STRIDE(fb_width) + sx] = sc;          
        stars[s][3] = sx;
        stars[s][4] = sy;
      }
  }
}

void DrawBanner()
{
  static volatile uint32_t tx,ty,distidx = 0,teensyrainbowscroll = 0;
  
  ty = 20;
  for(int ly = 0; ly < 5; ly++)
  {
    tx = 52;
    ty = ty + 6;
    distidx = distidx + 1;  
    if(distidx>1024)
    {
            distidx = 0;
    }  
    for(int lx = 0; lx < 33; lx++)
    {
      tx = tx + 6;
      for(int toy = 0; toy < 6; toy++)
      {
        for(int tox = 0; tox < 6; tox++)
        {
          if((banner[ly*33+lx]) > 0)
          {
            screen[(ty + toy ) * UVGA_FB_ROW_STRIDE(fb_width) + (tx + tox + ((BannerSine[(distidx+(ly*12)+(toy*2))%1024])))] = rainbow[((teensyrainbowscroll >> 1) + ty + toy) % 34];
          }
          else
          {
            screen[(ty + toy) * UVGA_FB_ROW_STRIDE(fb_width) + (tx + tox + ((BannerSine[(distidx+(ly*12)+(toy*2))%1024])))] = 0;
          }
        }
      }
    }
  }
  teensyrainbowscroll++;
  if(teensyrainbowscroll>=340)
     teensyrainbowscroll = 0;
}

void DrawAtariFuji()
{
  static volatile uint16_t af_xoffset = 177, af_yoffset = 90, affadetick = 0;
 
  for(uint16_t afy = 0; afy < 23; afy++)
  {
    for(uint16_t afx = 0; afx < 25; afx++)
    {
      if(((atarifuji[afy*25+afx]) > 0) && ((affadetick < 260)))
      {
        screen[(af_yoffset + (afy*5)) * UVGA_FB_ROW_STRIDE(fb_width) + (af_xoffset+afx*2)] = affade[((affadetick>>2)+afy)%115];   
        screen[(af_yoffset + (afy*5)) * UVGA_FB_ROW_STRIDE(fb_width) + (af_xoffset+(98-afx*2))] = affade[((affadetick>>2)+afy)%115];   
      }
      else
      {
        screen[(af_yoffset + (afy*5)) * UVGA_FB_ROW_STRIDE(fb_width) + (af_xoffset+afx*2)] = 0;     
        screen[(af_yoffset + (afy*5)) * UVGA_FB_ROW_STRIDE(fb_width) + (af_xoffset+(98-afx*2))] = 0;  
      }
    }
  }
  affadetick++;
  if(affadetick>460)
    affadetick = 0;
}

void Scroll32()
{
   for(int scy = 251; scy < 300; scy++)
   {
     for(uint16_t scx = 1; scx < 110; scx++)
     {
       *((116*(scy)) + screen_dword + 108 + (scx+4)+ 3) = *((116*(scy)) + screen_dword + 108 + (scx+5)+ 3);   
     }
   }
}

void Rasterline(uint16_t rline, uint8_t col)
{
  uint32_t dwordcol = 0;

    dwordcol = dwordcol | col;
    dwordcol = dwordcol << 8;
    dwordcol = dwordcol | col;
    dwordcol = dwordcol << 8;
    dwordcol = dwordcol | col;
    dwordcol = dwordcol << 8;
    dwordcol = dwordcol | col;    
  for(uint16_t scx = 1; scx < 110; scx++)
  {
    *((116*rline) + screen_dword + 108 + (scx+4)+ 3) = dwordcol;   
  }
}

void Rasterbars()
{
  static uint32_t stepper1 = 0,stepper2 = 10,stepper3 = 20,stepper4 = 30, barsyoffset = 200;

  stepper1= stepper1 + 1;
  if(stepper1>127)
  {
    stepper1 = 0;
  }
  Rasterline(barsyoffset+1+((RasterSine[stepper1])),0);
  Rasterline(barsyoffset+2+((RasterSine[stepper1])),1);
  Rasterline(barsyoffset+3+((RasterSine[stepper1])),2);
  Rasterline(barsyoffset+4+((RasterSine[stepper1])),3);
  Rasterline(barsyoffset+5+((RasterSine[stepper1])),2);
  Rasterline(barsyoffset+6+((RasterSine[stepper1])),1);
  Rasterline(barsyoffset+7+((RasterSine[stepper1])),0);

  stepper2= stepper2 + 1;
  if(stepper2>127)
  {
    stepper2 = 0;
  }
  Rasterline(barsyoffset+1+((RasterSine[stepper2])),0);
  Rasterline(barsyoffset+2+((RasterSine[stepper2])),1);
  Rasterline(barsyoffset+3+((RasterSine[stepper2])),2);
  Rasterline(barsyoffset+4+((RasterSine[stepper2])),3);
  Rasterline(barsyoffset+5+((RasterSine[stepper2])),2);
  Rasterline(barsyoffset+6+((RasterSine[stepper2])),1);
  Rasterline(barsyoffset+7+((RasterSine[stepper2])),0);

  stepper3= stepper3 + 1;
  if(stepper3>127)
  {
    stepper3 = 0;
  }
  Rasterline(barsyoffset+1+((RasterSine[stepper3])),0);
  Rasterline(barsyoffset+2+((RasterSine[stepper3])),1);
  Rasterline(barsyoffset+3+((RasterSine[stepper3])),2);
  Rasterline(barsyoffset+4+((RasterSine[stepper3])),3);
  Rasterline(barsyoffset+5+((RasterSine[stepper3])),2);
  Rasterline(barsyoffset+6+((RasterSine[stepper3])),1);
  Rasterline(barsyoffset+7+((RasterSine[stepper3])),0);
 
  stepper4= stepper4 + 1;
  if(stepper4>127)
  {
    stepper4 = 0;
  }
  Rasterline(barsyoffset+1+((RasterSine[stepper4])),0);
  Rasterline(barsyoffset+2+((RasterSine[stepper4])),1);
  Rasterline(barsyoffset+3+((RasterSine[stepper4])),2);
  Rasterline(barsyoffset+4+((RasterSine[stepper4])),3);
  Rasterline(barsyoffset+5+((RasterSine[stepper4])),2);
  Rasterline(barsyoffset+6+((RasterSine[stepper4])),1);
  Rasterline(barsyoffset+7+((RasterSine[stepper4])),0);
}

void YM_VUmeter()
{
  uint32_t dwordcol = 0;
  for(uint8_t c = 0; c < 3; c++)
  {
    ymch[c] = PSG_get_ch_out(&ym2149, c) >> 6;
  }
  for(uint8_t c = 0; c < 3; c++)
  {
    for(uint16_t vuy = 1; vuy < oldymch[c]; vuy++)
    {
      *(23200 - (116*vuy) + screen_dword + 108 + (1+4)+(c*4)+ 3) = 0x00000000;
      *(23200 - (116*vuy) + screen_dword + 108 + (2+4)+(c*4)+ 3) = 0x00000000;  
      *(23200 - (116*vuy) + screen_dword + 108 + (3+4)+(c*4)+ 3) = 0x00000000;   

      *(23200 - (116*vuy) + screen_dword + 108 + (99+4)+(c*4)+ 3) = 0x00000000;
      *(23200 - (116*vuy) + screen_dword + 108 + (100+4)+(c*4)+ 3) = 0x00000000;  
      *(23200 - (116*vuy) + screen_dword + 108 + (101+4)+(c*4)+ 3) = 0x00000000;  
    }  
    for(uint16_t vuy = 1; vuy < ymch[c]; vuy++)
    {
      dwordcol = dwordcol | rainbow[(vuy>>2)+10];
      dwordcol = dwordcol << 8;
      dwordcol = dwordcol | rainbow[(vuy>>2)+10];
      dwordcol = dwordcol << 8;
      dwordcol = dwordcol | rainbow[(vuy>>2)+10];
      dwordcol = dwordcol << 8;
      dwordcol = dwordcol | rainbow[(vuy>>2)+10];  
      
      *(23200 - (116*vuy) + screen_dword + 108 + (1+4)+(c*4)+ 3) = dwordcol;  
      *(23200 - (116*vuy) + screen_dword + 108 + (2+4)+(c*4)+ 3) = dwordcol;    
      *(23200 - (116*vuy) + screen_dword + 108 + (3+4)+(c*4)+ 3) = dwordcol;   

      *(23200 - (116*vuy) + screen_dword + 108 + (99+4)+(c*4)+ 3) = dwordcol;  
      *(23200 - (116*vuy) + screen_dword + 108 + (100+4)+(c*4)+ 3) = dwordcol;    
      *(23200 - (116*vuy) + screen_dword + 108 + (101+4)+(c*4)+ 3) = dwordcol; 
    }
  }
  for(uint8_t c = 0; c < 3; c++)
  {
    oldymch[c] = ymch[c];
  }
}

void scrolline()
{
  static volatile uint32_t fontptr = 0, scry , fntx = 6, charptr = 0, scalex = 0;
  static volatile uint32_t dwordfntcol = 0;

switch (scrolltext[charptr]) 
    {
     case 65:
          fontptr = 0;
          break;
     case 66:
          fontptr = 1;
          break;
     case 67:
          fontptr = 2;
          break;
     case 68:
          fontptr = 3;
          break;
     case 69:
          fontptr = 4;
          break;
     case 70:
          fontptr = 5;
          break;
     case 71:
          fontptr = 6;
          break;
     case 72:
          fontptr = 7;
          break;
     case 73:
          fontptr = 8;
          break;
     case 74:
          fontptr = 9;
          break;
     case 75:
          fontptr = 10;
          break;
     case 76:
          fontptr = 11;
          break;
     case 77:
          fontptr = 12;
          break;
     case 78:
          fontptr = 13;
          break;
     case 79:
          fontptr = 14;
          break;
     case 80:
          fontptr = 15;
          break;
     case 81:
          fontptr = 16;
          break;
     case 82:
          fontptr = 17;
          break;
     case 83:
          fontptr = 18;
          break;
     case 84:
          fontptr = 19;
          break;
     case 85:
          fontptr = 20;
          break;
     case 86:
          fontptr = 21;
          break;
     case 87:
          fontptr = 22;
          break;
     case 88:
          fontptr = 23;
          break;
     case 89:
          fontptr = 24;
          break;
     case 90:
          fontptr = 25;
          break;
     case 32:
          fontptr = 26;
          break;
     case 48:
          fontptr = 27;
          break;
     case 49:
          fontptr = 28;
          break;
     case 50:
          fontptr = 29;
          break;
     case 51:
          fontptr = 30;
          break;
     case 52:
          fontptr = 31;
          break;
     case 53:
          fontptr = 32;
          break;
     case 54:
          fontptr = 33;
          break;
     case 55:
          fontptr = 34;
          break;
     case 56:
          fontptr = 35;
          break;
     case 57:
          fontptr = 36;
          break;
     case 46:
          fontptr = 37;
          break;
     case 44:
          fontptr = 38;
          break;
     case 45:
          fontptr = 39;
          break;
     case 0:
          fontptr = 26;
          break;
     default:
     fontptr = 0;
     charptr=0;
     break;
    } 

    scry = 250;
    for(uint16_t fnty = 0; fnty < 5; fnty++)
    {
      if((scrollfont[fontptr][fnty]>>fntx) & 1)
      {
        for(uint16_t scaley = 0; scaley < 10; scaley++)
        {
          dwordfntcol = dwordfntcol | (scry)%255;
          dwordfntcol = dwordfntcol << 8;
          dwordfntcol = dwordfntcol | (scry+1)%255;
          dwordfntcol = dwordfntcol << 8;
          dwordfntcol = dwordfntcol | (scry+2)%255;
          dwordfntcol = dwordfntcol << 8;
          dwordfntcol = dwordfntcol | (scry+3)%255;  
          *((116*(scry)) + screen_dword + 108 + (110+4)+ 3) = dwordfntcol;
          scry++;
        }
      }
      else  
      {
        for(uint16_t scaley = 0; scaley < 10; scaley++)
        {
          *((116*(scry)) + screen_dword + 108 + (110+4)+ 3) = 0;
          scry++;
        }
      }
    }
    Scroll32();
    scalex++;
    if(scalex > 1)
    {
      fntx--;
      scalex = 0;
    }

    if(fntx<1)
    {
      fntx = 6;
      charptr++;
    }  
}


