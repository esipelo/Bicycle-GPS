
#include <Adafruit_NeoPixel.h>

#define PIN      6
#define N_LEDS 24
int pin=8;
unsigned long freq;
unsigned long freq1;
unsigned long new_freq;
unsigned long duration;
int somme=0;
int z=0;
float freq_moy;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
	strip.begin();
	rainbowCycle(1);
	pinMode(pin,INPUT);
	Serial.begin(9600);
}
 
void loop() {    
	chase(strip.Color(255, 0, 0)); // Red
	chase(strip.Color(0, 255, 0)); // Green
	chase(strip.Color(0, 0, 255)); // Blue
	while ( z < 5)
	{      
		duration = pulseIn(pin,HIGH);
		freq= 680000/duration;   	       
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
			strip.setPixelColor(i ,0,0,0); // Draw new pixel
			strip.show();
   
		}
	}
	//turn left
	if(freq_moy>400 && freq_moy <499){
		for(uint16_t i=0; i<24; i++) {
			strip.setPixelColor(i ,0,0,0); // Draw new pixel
			strip.show();
		}
		for(uint16_t i=0; i<12; i++) {
			strip.setPixelColor(i ,0,255,0); // Draw new pixel
			strip.show();
		}
	}
 
	//turn right
	if(freq_moy>500 && freq_moy <599 ){
		for(uint16_t i=0; i<24; i++) {
			strip.setPixelColor(i ,0,0,0); // Draw new pixel
			strip.show();
		}
		for(uint16_t i=12; i<24; i++) {
			strip.setPixelColor(i ,0,255,0); // Draw new pixel
			strip.show();
		}
	}
	// make a u-turn
    if(freq_moy>600 && freq_moy<699){
		for(uint16_t i=0; i<24; i++) {
			strip.setPixelColor(i ,0,0,0); // Draw new pixel
			strip.show();
		}
		for(uint16_t i=0; i<6; i++ ) {
			for(uint16_t j=18; j<24; j++ ) {
				strip.setPixelColor(i ,255,0,0); // Draw new pixel
				strip.setPixelColor(j ,255,0,0); // Draw new pixel

				strip.show();
			}
		}
	}
// Finish
	if(freq_moy>700 && freq_moy <799 ){
		for(uint16_t i=0; i<24; i++) {
			strip.setPixelColor(i ,0,0,0); // Draw new pixel
			strip.show();
		}
		for(uint16_t i=0; i<24; i++) {
			strip.setPixelColor(i ,0,255,0); // Draw new pixel
			strip.show();
		}
	}

// Changement itinéraire
	if(freq_moy>800 && freq_moy <899 ){

		rainbowCycle(1);
	}

 
//turn slightly left
	if(freq_moy>1100 && freq_moy <1250){
		for(uint16_t i=0; i<24; i++) {
			strip.setPixelColor(i ,0,0,0); // set all the pixels off
			strip.show();
		}
		strip.setPixelColor(6 ,0,255,0); // Draw green pixel
		strip.setPixelColor(7 ,0,255,0); // Draw green pixel
		strip.setPixelColor(8 ,0,255,0); // Draw white pixel
		strip.setPixelColor(9 ,255,255,255); // Draw white pixel
		strip.setPixelColor(10 ,0,255,0); // Draw white pixel
		strip.setPixelColor(11 ,0,255,0); // Draw green pixel
		strip.setPixelColor(12 ,0,255,0); // Draw green pixel
		strip.show();
	}

	//turn slightly right
	if(freq_moy>1251 && freq_moy <1400){
		for(uint16_t i=0; i<24; i++) {
			strip.setPixelColor(i ,0,0,0); // set all the pixels off
			strip.show();
		}
		strip.setPixelColor(12 ,0,255,0); // Draw green pixel
		strip.setPixelColor(13 ,0,255,0); // Draw green pixel
		strip.setPixelColor(14 ,0,255,0); // Draw white pixel
		strip.setPixelColor(15 ,255,255,255); // Draw white pixel
		strip.setPixelColor(16 ,0,255,0); // Draw white pixel
		strip.setPixelColor(17 ,0,255,0); // Draw green pixel
		strip.setPixelColor(18 ,0,255,0); // Draw green pixel
		strip.show();
	}
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
	for(uint16_t i=0; i<strip.numPixels(); i++) {
		strip.setPixelColor(i, c);
		strip.show();
		delay(wait);
	}
}



// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
	uint16_t i, j;

	for(j=0; j<256*8; j++) { // 5 cycles of all colors on wheel
		for(i=0; i< strip.numPixels(); i++) {
			strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
		}
		strip.show();
		delay(wait);
	}
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
	WheelPos = 255 - WheelPos;
	if(WheelPos < 85) {
		return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
	} else if(WheelPos < 170) {
		WheelPos -= 85;
		return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
	} else {
		WheelPos -= 170;
		return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
	}
}
