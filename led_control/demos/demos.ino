#include <FastLED.h>
 
#define LED_PIN     5
#define NUM_LEDS    30
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define SWITCH_IN_PIN 35
#define SWITCH_OUT_PIN 53
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

// This example shows several ways to set up and use 'palettes' of colors
// with FastLED.
//
// These compact palettes provide an easy way to re-colorize your
// animation on the fly, quickly, easily, and with low overhead.
//
// USING palettes is MUCH simpler in practice than in theory, so first just
// run this sketch, and watch the pretty lights as you then read through
// the code.  Although this sketch has eight (or more) different color schemes,
// the entire sketch compiles down to about 6.5K on AVR.
//
// FastLED provides a few pre-configured color palettes, and makes it
// extremely easy to make up your own color schemes with palettes.
//
// Some notes on the more abstract 'theory and practice' of
// FastLED compact palettes are at the bottom of this file.
CRGB rainbow[7] = {CRGB::Red,CRGB::Green,CRGB::Orange,CRGB::Purple,CRGB::Yellow,CRGB::Blue};

int SWITCH_STATE = 0;

void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    pinMode(SWITCH_IN_PIN, INPUT);
    pinMode(SWITCH_OUT_PIN, OUTPUT);
    digitalWrite(SWITCH_OUT_PIN, HIGH);
    Serial.begin(9600);
}
int count = 0;

void loop()
{
    if(read_jumps()){
      int red = random(0,255);
      int green = random(0,255);
      int blue = random(0,255);
      if(count >= 5){count = 0;}
      else{count++;};
      for(int dot = 0; dot < NUM_LEDS; dot++) {
        leds[dot] = rainbow[count];
      }
      FastLED.show();
      while(read_jumps()){
        delay(10);
        }
    }
    else{
      while(!read_jumps()){
        delay(10);
        }
    }
    delay(10);
}

bool read_jumps(){
    SWITCH_STATE = digitalRead(SWITCH_IN_PIN);
    if(SWITCH_STATE){
      return SWITCH_STATE;
    }
    return SWITCH_STATE;
  }
