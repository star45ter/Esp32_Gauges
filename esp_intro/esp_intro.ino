

#include <SPI.h>

#include <TFT_eSPI.h>       // Hardware-specific library
#include "fs.h"

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library
TFT_eSprite FSlogo = TFT_eSprite(&tft);
float x_vel=20;
int x_logo=350;
int x_warn=350;
int go = 0;
void setup(void) {
  tft.init();
  tft.fillScreen(TFT_BLACK);
  FSlogo.setColorDepth(8);      
  FSlogo.createSprite(435, 130); 
  FSlogo.fillSprite(TFT_BLACK);
  FSlogo.pushImage(15,15,100,100,FS);
  FSlogo.setTextColor(0xffff);
  FSlogo.setTextDatum(MC_DATUM);
  FSlogo.setTextSize(3);
  FSlogo.drawString("Drive Safe",330,65);
  delay(500);
}
 
void loop() {

  FSlogo.pushSprite(x_logo,60);
  switch(go)
  {
    case 0:
    if(x_logo>60)
      {
        x_logo-=x_vel;
        x_vel=max(float(1),float(x_vel-0.6));
      }
    else
    {
      go=1;
    }
    break;
    case 1:
      delay(1000);
      x_vel=1;
      go=2;
    break;
    case 2:
    if(x_logo>-200)
      {
        x_logo-=x_vel;
        x_vel=x_vel+0.4;
      }
    else
    {
      go=3;
    }
    break;
    case 3:
      delay(1000);
      x_vel=1;
      go=4;
    break;
     case 4:
    if(x_logo>-440)
      {
        x_logo-=x_vel;
        x_vel=x_vel+0.4;
      }
    else
    {
      go=5;
    }
    break;
  }
  
  
  
}
