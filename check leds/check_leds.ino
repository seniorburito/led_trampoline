// Use this code to check that your leds are working
// The loop lights up one led at a time so if there is a weird one
// you can find it 

#include <FastLED.h>

#define LED_PIN     5     // the digital pin that is connected to the strip
#define NUM_LEDS    30    // here you enter how many leds you have 
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS]; 

void setup() {
	delay( 3000 ); // power-up safety delay
	FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
	FastLED.setBrightness(  BRIGHTNESS );
}

// change the delay to make it faster or slower
// also leds[dot] = CRGB::Blue; can be changed to any color you want

void loop() {
	for(int dot = 0; dot < NUM_LEDS; dot++) { 
		leds[dot] = CRGB::Blue;
		FastLED.show();
		delay(200);
	}
}
