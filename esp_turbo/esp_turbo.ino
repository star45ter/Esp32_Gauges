

#include <SPI.h>

#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library


TFT_eSprite back = TFT_eSprite(&tft);




boolean up = true;
float angle_turbine=0;
float pression=1;
int x_trembl = 0;
int y_trembl = 0;

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

 
    x_trembl = random(-pression*2,pression*2);
    y_trembl = random(-pression*2,pression*2);
  
  if(up)
  {
    if(pression>=4)
    {
      up=!up;
    }
    else
    {
      pression+=0.05;
    }
  }
  else
  {
    if(pression<=0)
    {
      up=!up;
    }
    else
    {
      pression-=0.05;
    }
  }
  back.drawWideLine(120,49,192,49,3,0xffff);
  back.drawWideLine(190,97,192,97,3,0xffff);
  back.drawWideLine(192,49,192,97,3,0xffff);
  back.drawSmoothArc(120,120,72,70,0,360,0xffff,TFT_TRANSPARENT,true);
  back.drawSmoothArc(120,120,22,20,0,360,0xffff,TFT_TRANSPARENT);
  back.drawWideLine(120, 120, 120+cos(angle_turbine*PI/180)*15, 120+sin(angle_turbine*PI/180)*15, 3, TFT_WHITE);
  back.drawWideLine(120, 120, 120+cos((angle_turbine+60)*PI/180)*15, 120+sin((angle_turbine+60)*PI/180)*15, 3, TFT_WHITE);
  back.drawWideLine(120, 120, 120+cos((angle_turbine+120)*PI/180)*15, 120+sin((angle_turbine+120)*PI/180)*15, 3, TFT_WHITE);
  back.drawWideLine(120, 120, 120+cos((angle_turbine+180)*PI/180)*15, 120+sin((angle_turbine+180)*PI/180)*15, 3, TFT_WHITE);
  back.drawWideLine(120, 120, 120+cos((angle_turbine+240)*PI/180)*15, 120+sin((angle_turbine+240)*PI/180)*15, 3, TFT_WHITE);
  back.drawWideLine(120, 120, 120+cos((angle_turbine+300)*PI/180)*15, 120+sin((angle_turbine+300)*PI/180)*15, 3, TFT_WHITE);
  if(pression>0){
    back.drawSmoothArc(120,120,27,25,0,360,0x07E0,TFT_TRANSPARENT);    
  }
  if(pression>0.44)
  {
  back.drawSmoothArc(120,120,32,30,0,360,0x07E0,TFT_TRANSPARENT);
  }
  if(pression>0.88)
  {
  back.drawSmoothArc(120,120,37,35,0,360,0x07E0,TFT_TRANSPARENT);
  }
  if(pression>1.32)
  {
  back.drawSmoothArc(120,120,42,40,0,360,0xBFE0,TFT_TRANSPARENT);
  }
  if(pression>1.76)
  {
  back.drawSmoothArc(120,120,47,45,0,360,0xE7E0,TFT_TRANSPARENT);
  }
  if(pression>2.20)
  {
  back.drawSmoothArc(120,120,52,50,0,360,0xFEE0,TFT_TRANSPARENT);
  }
  if(pression>2.64)
  {
  back.drawSmoothArc(120,120,57,55,0,360,0xFD60,TFT_TRANSPARENT);
  }
  if(pression>3.08)
  {
  back.drawSmoothArc(120,120,62,60,0,360,0xFB20,TFT_TRANSPARENT);
  }
  if(pression>3.52)
  {
  back.drawSmoothArc(120,120,67,65,0,360,0xF800,TFT_TRANSPARENT);
  }
  back.setTextColor(0xA534);
  back.setTextDatum(MC_DATUM);
  back.setTextSize(2);
  back.drawString(String(pression)+" bar",145,40);
  back.pushSprite(x_trembl,y_trembl,TFT_TRANSPARENT);
  angle_turbine+=(3+pression*2);

  
}
