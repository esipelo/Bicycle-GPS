/* include the libraries */
#include <Adafruit_NeoPixel.h>

#define PIN      6
#define N_LEDS 24
int pin=8;
unsigned long freq;
unsigned long new_freq;
unsigned long duration;
int somme=0;
int z=0;
float freq_moy;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  strip.begin();
  //strip.show();
  pinMode(pin,INPUT);
Serial.begin(9600);
}
 
void loop() {
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue


    while(z<5)
    {
      
    duration = pulseIn(pin,HIGH);
 // Serial.println(duration);
    freq= 611000/duration;
   //freq= 56000/duration;
   Serial.print("freq = ");
   Serial.println(freq);
   if(z==0){
    new_freq=freq;
   }
 
    
    if ( abs(freq-new_freq)<20  ){
      somme = somme +freq;
      z++;
    }
    else 
    {
      z=0;
      somme=0;
      new_freq=0;
    }
  //  Serial.print("somme = ");
//Serial.println(somme);
    new_freq= freq;  
}

freq_moy=somme/5;
Serial.print("freq_moy = ");
Serial.println(freq_moy);
z=0;
somme=0;
}
 
static void chase(uint32_t c) {


// nothing to show
if(freq_moy<400 || freq_moy>2000){
  for(uint16_t i=0; i<24; i++) {
   strip.setBrightness(10);
   strip.setPixelColor(i ,255,0,0); // Draw new pixel
   strip.show();
   }
}
  //turn left
 if(freq_moy>400 && freq_moy <499){
  for(uint16_t i=0; i<24; i++) {
   strip.setBrightness(10);
   strip.setPixelColor(i ,0,0,0); // Draw new pixel
   strip.show();
   }
for(uint16_t i=0; i<12; i++) {
   strip.setBrightness(100);
   strip.setPixelColor(i ,0,255,0); // Draw new pixel
   strip.show();
   }
 }
 
 //turn right
 if(freq_moy>500 && freq_moy <599 ){
for(uint16_t i=0; i<24; i++) {
   strip.setBrightness(10);
   strip.setPixelColor(i ,0,0,0); // Draw new pixel
   strip.show();
   }
   for(uint16_t i=12; i<24; i++) {
   strip.setBrightness(10);
   strip.setPixelColor(i ,0,255,0); // Draw new pixel
   strip.show();
   }
 }
   // make a u-turn
    if(freq_moy>600 && freq_moy<699){
    for(uint16_t i=0; i<24; i++) {
    strip.setBrightness(10);
    strip.setPixelColor(i ,0,0,0); // Draw new pixel
    strip.show();
   }
for(uint16_t i=0; i<6; i++ ) {
   for(uint16_t j=18; j<24; j++ ) {
   strip.setBrightness(10);
   strip.setPixelColor(i ,255,0,0); // Draw new pixel
   strip.setPixelColor(j ,255,0,0); // Draw new pixel

   strip.show();
   }
   }
 }
// Finish
 if(freq_moy>700 && freq_moy <799 ){
   for(uint16_t i=0; i<24; i++) {
   strip.setBrightness(10);
   strip.setPixelColor(i ,0,0,0); // Draw new pixel
   strip.show();
   }
   for(uint16_t i=0; i<24; i++) {
   strip.setBrightness(10);
   strip.setPixelColor(i ,0,255,0); // Draw new pixel
   strip.show();
   }
 }


//turn slightly left
 if(freq_moy>1100 && freq_moy <1199){
  for(uint16_t i=0; i<24; i++) {
   strip.setBrightness(10);
   strip.setPixelColor(i ,0,0,0); // set all the pixels off
   strip.show();
   }
   strip.setPixelColor(6 ,0,255,0); // Draw green pixel
   strip.setPixelColor(7 ,0,255,0); // Draw green pixel
   strip.setPixelColor(8 ,255,255,255); // Draw white pixel
   strip.setPixelColor(9 ,255,255,255); // Draw white pixel
   strip.setPixelColor(10 ,255,255,255); // Draw white pixel
   strip.setPixelColor(11 ,0,255,0); // Draw green pixel
   strip.setPixelColor(12 ,0,255,0); // Draw green pixel
   strip.show();
 }

 //turn slightly right
 if(freq_moy>1200 && freq_moy <1299){
  for(uint16_t i=0; i<24; i++) {
   strip.setBrightness(100);
   strip.setPixelColor(i ,0,0,0); // set all the pixels off
   strip.show();
   }
   strip.setPixelColor(12 ,0,255,0); // Draw green pixel
   strip.setPixelColor(13 ,0,255,0); // Draw green pixel
   strip.setPixelColor(14 ,255,255,255); // Draw white pixel
   strip.setPixelColor(15 ,255,255,255); // Draw white pixel
   strip.setPixelColor(16 ,255,255,255); // Draw white pixel
   strip.setPixelColor(17 ,0,255,0); // Draw green pixel
   strip.setPixelColor(18 ,0,255,0); // Draw green pixel
   strip.show();
 }
}
