//We always have to include the library
#include "LedControl.h"

LedControl lc=LedControl(12,11,10,1);

const int POT=0;
int val = 0;
int dt = 33;

/* we always wait a bit between updates of the display */
unsigned long delaytime=100;

void setup() {

  
  Serial.begin(9600);
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

 
void f01() {



//Desce
for(int row=0;row<8;row++){
       
      lc.setLed(0,row,0,true);
      delay(dt);
      lc.setLed(0,row,0,false);
      delay(dt);
}


//Direita
for(int col=1;col<8;col++){
       
      lc.setLed(0,7,col,true);
      delay(dt);
      lc.setLed(0,7,col,false);
      delay(dt);
}

//Sobe
for(int row=6;row>=0;row--){
       
      lc.setLed(0,row,7,true);
      delay(dt);
      lc.setLed(0,row,7,false);
      delay(dt);
      
}

//Esquerda
for(int col=7;col>0;col--){
       
      lc.setLed(0,0,col,true);
      delay(dt);
      lc.setLed(0,0,col,false);
      delay(dt);
      
          
}


      
      }
      



void loop() { 

 
  dt = analogRead(POT);  
  delay(100);
  dt = 10 + dt/30;
  f01();
   
  
}
