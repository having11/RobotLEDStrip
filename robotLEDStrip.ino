#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#define PIN 6
#define LEDNUM 150

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

/* The I2C color codes are as follows:
'r' = Set to red, 'g' = Set to green, 'b' = Set to blue, 'u' = Rainbow, 'c' = Rainbow cycle,
'h' = Chase, 'o' = Off
*/
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDNUM, PIN, NEO_GRB + NEO_KHZ800);

char currentColor = 'n';
char IData = 'o';

void setup() {
	Wire.begin(8);
	Wire.onReceive(receiveEvent);
  strip.begin();
  strip.setBrightness(30); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
	switch(IData){
		case 'r': //Set color to red
			colorWipe(strip.Color(255, 0, 0), 50); // Red
			break;
		case 'g':
			colorWipe(strip.Color(0, 255, 0), 50); // Green
			break;
		case 'b':
			colorWipe(strip.Color(0, 0, 255), 50); // Blue
			break;
		case 'u':
			rainbow(20);
			break;
		case 'c':
			rainbowCycle(20);
			break;
		case 'h':
			if(currentColor == 'r'){
				chase(strip.Color(255,0,0)); //Chase red
			}
			else if(currentColor == 'g'){
				chase(strip.Color(0,255,0)); //Chase green
			}
			else if(currentColor == 'b'){
				chase(strip.Color(0,0,255)); //Chase blue
			}
			break;
		case 'o':
			colorWipe(strip.Color(0,0,0), 50); //Off
			break;
}

void receiveEvent(int howMany){
	while(1<Wire.available()){
		char c = Wire.read();
		
	}
	if(c == 'r'){
		currentColor = 'r';
	}
	else if(c=='g'){
		currentColor = 'g';
	}
	else if(c=='b'){
		currentColor = 'b';
	}
	else if(c=='o'){
		currentColor = 'o';
	}
	IData = c;
}
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
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
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
 
static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }
}