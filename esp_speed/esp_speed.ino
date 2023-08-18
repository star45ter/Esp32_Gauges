

#include <SPI.h>

#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library
TFT_eSprite needle = TFT_eSprite(&tft);
TFT_eSprite Small_Dash= TFT_eSprite(&tft);
TFT_eSprite Really_Small_Dash= TFT_eSprite(&tft);

TFT_eSprite back = TFT_eSprite(&tft);




int initi = 0;
float anglecadrant = 0;
int speed = 0;
float angle=225;
void setup(void) {
  tft.init();

  tft.fillScreen(TFT_BLACK);
  

  needle.setColorDepth(8);      // Create an 8bpp Sprite of 60x30 pixels
  needle.createSprite(20, 100);  // 8bpp requires 64 * 30 = 1920 bytes
  needle.setPivot(10, 90);      // Set pivot relative to top left corner of Sprite
  needle.fillSprite(TFT_BLACK);
  needle.fillTriangle(10, 0, 5, 90, 15, 90, 0x04FF);
  needle.drawWideLine(10, 0, 5, 90, 1, 0x04FF);
  needle.drawWideLine(10, 0, 15, 90, 1, 0x04FF);
  needle.fillSmoothCircle(10, 90, 7, 0x04FF);
  needle.fillSmoothCircle(10, 90, 5, TFT_BLACK);

  Small_Dash.createSprite(2, 10);
  Small_Dash.setPivot(1, 110);
  Small_Dash.fillSprite(0xffff);


  Really_Small_Dash.createSprite(1, 5);
  Really_Small_Dash.setPivot(1, 110);
  Really_Small_Dash.fillSprite(0xffff);

  back.setColorDepth(8);      // Create an 8bpp Sprite of 60x30 pixels
  back.createSprite(240, 240);  // 8bpp requires 64 * 30 = 1920 bytes

  tft.setPivot(120, 120); 
}

void loop() {
  back.fillSprite(TFT_TRANSPARENT);
  back.fillCircle(120 , 120, 120, 0x0000);
 
  back.setTextSize(2);
  back.setTextDatum(MC_DATUM);
  speed=(angle-225)*250/270;
  back.drawString(String(speed)+" km/h",120,190);
  needle.pushRotated(&back,angle,TFT_BLACK);
  for(int i = 0;i<46;i++)
  {
    if(i<36)
    {
    Small_Dash.fillSprite(0xffff);
    Really_Small_Dash.fillSprite(0xffff);
    }
    else
    {
    Small_Dash.fillSprite(0xf800);
    Really_Small_Dash.fillSprite(0xf800);
    }
    if(i%3 == 0)
    {
      Small_Dash.pushRotated(&back,i*anglecadrant+225);
    }
    else
    {
      Really_Small_Dash.pushRotated(&back,i*anglecadrant+225);
    }
  } 
  if(anglecadrant<5.8)
  {
    anglecadrant+=0.20;
  }
  else if(initi==0)
  {
    angle+=7.5;
    if(angle==495)initi++;
  }
  else if(initi==1)
  {
    angle-=7.5;
    if(angle==225)initi++;
  }

 
  back.pushSprite(0,0,TFT_TRANSPARENT);
 

  
}
