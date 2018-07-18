#include <FastLED.h>
 
#define LED_PIN     5
#define NUM_LEDS    30
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define SWITCH_IN_PIN 53
#define SWITCH_OUT_PIN 35
CRGB leds[NUM_LEDS];
CRGB rainbow[7] = {CRGB::Red,CRGB::Green,CRGB::Orange,CRGB::Purple,CRGB::Yellow,CRGB::Blue,CRGB::Cyan};

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
    Serial.print(digitalRead(SWITCH_IN_PIN));
    if(read_jumps()){
      for(int dot = 0; dot < NUM_LEDS; dot++) {
        leds[dot] = rainbow[count];
      }
      FastLED.show();
      while(read_jumps()){
        delay(10);
        }
      if(count < 6){
          count++;
        }
      else{
          count = 0;
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
