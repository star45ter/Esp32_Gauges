

#include <SPI.h>

#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library


TFT_eSprite back = TFT_eSprite(&tft);




boolean up = true;
float volt=1;

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

 
  
  
  if(up)
  {
    if(volt>=16)
    {
      up=!up;
    }
    else
    {
      volt+=0.5;
    }
  }
  else
  {
    if(volt<=0)
    {
      up=!up;
    }
    else
    {
      volt-=0.5;
    }
  }

  
  
  
  
  
  
  

  if(volt>0)
  {
  back.drawWideLine(68, 160, 171, 160, 3, 0x07E0);
  }
  if(volt>2){back.drawWideLine(68, 152, 171, 152, 3, 0x07E0);}
  if(volt>4){back.drawWideLine(68, 144, 171, 144, 3, 0x07E0);}
  if(volt>6){back.drawWideLine(68, 136, 171, 136, 3, 0xA7E0);}
  if(volt>8){back.drawWideLine(68, 128, 171, 128, 3, 0xD7E0);}
  if(volt>10){back.drawWideLine(68, 120, 171, 120, 3, 0xFDC0);}
  if(volt>12){back.drawWideLine(68, 112, 171, 112, 3, 0xF800);}
  if(volt>14){
    int r1 = random(60,100);
    back.drawWideLine(95, 85, 105, r1, 3, 0x04FF);
    int r2 = random(60,100);
    back.drawWideLine(105, r1, 115, r2, 3, 0x04FF);
    int r3 = random(60,100);
    back.drawWideLine(115, r2, 125, r3, 3, 0x04FF);
    int r4 = random(60,100);
    back.drawWideLine(125, r3, 135, r4, 3, 0x04FF);
    back.drawWideLine(135, r4, 145, 85, 3, 0x04FF);
  

    }



  back.drawRect(60 ,100,120,70,0xffff);
  back.drawRect(61 ,101,118,68,0xffff);
  back.drawRect(62 ,102,116,66,0xffff);
  back.drawWideLine(80, 100, 95, 85, 3, 0xffff);
  back.drawWideLine(160, 100, 145, 85, 3, 0xffff);
  back.drawWideLine(80, 110, 80, 120, 3, 0xffff);
  back.drawWideLine(75, 115, 85, 115, 3, 0xffff);
  back.drawWideLine(165, 115, 155, 115, 3, 0xffff);
  back.setTextColor(0xA534);
  back.setTextDatum(MC_DATUM);
  back.setTextSize(2);
  back.drawString(String(volt)+" VOLT",120  ,200);
  back.pushSprite(0,0,TFT_TRANSPARENT);

  
}
