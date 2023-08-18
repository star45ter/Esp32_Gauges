

#include <SPI.h>

#include <TFT_eSPI.h>       // Hardware-specific library
#include "bielle.h"
#include "piston_head.h"

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library
TFT_eSprite bielle_spr = TFT_eSprite(&tft);
TFT_eSprite piston_head_spr = TFT_eSprite(&tft);
TFT_eSprite piston = TFT_eSprite(&tft);

float pistony=120;
int angle=0;
boolean rotate = true;
boolean goup=false;

String menu[5]={"Settings","Boost","Speed","Voltage","Temperature"};

int menu_selected=0;

void setup(void) {
  tft.init();
  tft.fillScreen(TFT_BLACK);

  bielle_spr.setColorDepth(8);      
  bielle_spr.createSprite(54 , 176); 
  bielle_spr.fillSprite(TFT_BLACK);
  bielle_spr.pushImage(0,0,54,176,bielle);

  piston_head_spr.setColorDepth(8);      
  piston_head_spr.createSprite(78 , 64); 
  piston_head_spr.fillSprite(TFT_BLACK);
  piston_head_spr.pushImage(0,0,78,64,pistonhead);

  piston.setColorDepth(8);      
  piston.createSprite(240 , 240); 
  piston.fillSprite(TFT_BLACK);

  delay(500);
  
}
 
void loop() {
  piston.fillSprite(TFT_BLACK);

  piston.setPivot(120-sin(angle*PI/180)*(bielle_spr.height()/2),pistony+cos(angle*PI/180)*(bielle_spr.height()/2)+(piston_head_spr.height()/2));
 
  bielle_spr.pushRotated(&piston,angle);

  piston_head_spr.pushToSprite(&piston,120-(piston_head_spr.width()/2),pistony);

  piston.setTextColor(0xA534);
  piston.setTextDatum(MC_DATUM);
  piston.setTextSize(2);
  piston.drawString(menu[menu_selected],120,min(120,int(pistony-20)));

  piston.pushSprite(0,0);


if(rotate)
{
    if(pistony>40 && goup)
  {
    pistony-=max(float(8),2*float(-0.0015625*pow(pistony,2)+0.375*pistony-12.5));
    angle=20*sin(0.0196*(pistony-40));
  }
  else if(pistony<200 && !goup)
  {
    pistony+=max(float(8),2*float(-0.0015625*pow(pistony,2)+0.375*pistony-12.5));
    angle=-20*sin(0.0196*(pistony-40));
  }
  else
  {
    goup = !goup;
    if(goup)
    {
      rotate=!rotate;
      delay(1000);
      rotate=true;
    }
    else
    {
      menu_selected++;
      if(menu_selected>4)
      {
        menu_selected=0;
      }
    }
  }
  
}


}
