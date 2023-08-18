

#include <SPI.h>

#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library
TFT_eSprite back = TFT_eSprite(&tft);

int oil_temper = 130;
int eng_temper = 0;
boolean up = true;
void setup(void) {
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setPivot(120, 120);
  back.setColorDepth(8);      // Create an 8bpp Sprite of 60x30 pixels
  back.createSprite(240, 240);  // 8bpp requires 64 * 30 = 1920 bytes
  back.fillSprite(TFT_BLACK);
  
}
 
void loop() {

  back.fillSprite(TFT_BLACK);
  back.drawSmoothArc(70,150,22,20,200,160,0xffff,TFT_TRANSPARENT);
  back.drawSmoothArc(70,70,9,7,90,270,0xffff,TFT_TRANSPARENT);
  back.drawWideLine(62, 70, 62, 130, 3, 0xffff);
  back.drawWideLine(78, 70, 78, 130, 3, 0xffff);
  back.drawWideLine(78, 80, 88, 80, 3, 0xffff);
  back.drawWideLine(78, 90, 88, 90, 3, 0xffff);
  back.drawWideLine(78, 110, 88, 110, 3, 0xffff);
  back.fillSmoothCircle(70, 150, 15, 0xf800, TFT_TRANSPARENT);
  back.drawWideLine(70, 160, 70,max(150-(oil_temper*80/130),70),5,0xf800);
  back.setTextColor(0xA534);
  back.setTextDatum(MC_DATUM);
  back.setTextSize(2);
  back.drawString(String(oil_temper)+" C",70,190);
  back.drawString("OIL",70,50);


   back.drawSmoothArc(170,150,22,20,200,160,0xffff,TFT_TRANSPARENT);
  back.drawSmoothArc(170,70,9,7,90,270,0xffff,TFT_TRANSPARENT);
  back.drawWideLine(162, 70, 162, 130, 3, 0xffff);
  back.drawWideLine(178, 70, 178, 130, 3, 0xffff);
  back.drawWideLine(178, 80, 188, 80, 3, 0xffff);
  back.drawWideLine(178, 90, 188, 90, 3, 0xffff);
  back.drawWideLine(178, 110, 188, 110, 3, 0xffff);
  back.fillSmoothCircle(170, 150, 15, 0xf800, TFT_TRANSPARENT);
  back.drawWideLine(170, 160, 170,max(150-(eng_temper*80/130),70),5,0xf800);
  back.setTextColor(0xA534);
  back.setTextDatum(MC_DATUM);
  back.setTextSize(2);
  back.drawString(String(eng_temper)+" C",170,190);
  back.drawString("ENG",170,50);

  back.pushSprite(0,0,TFT_TRANSPARENT);

  if(up)
  {
    if(eng_temper>=130)
    {
      up=!up;
    }
    else
    {
      eng_temper+=1;
      oil_temper-=1;
    }
  }
  else
  {
    if(eng_temper<=0)
    {
      up=!up;
    }
    else
    {
     eng_temper-=1;
      oil_temper+=1;
    }
  }
  
}
