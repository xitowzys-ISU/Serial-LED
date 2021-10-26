#include <FastLED.h>

#define DATA_PIN 2
#define CLOCK_PI 3
#define NUM_LEDS 15

CRGB leds[NUM_LEDS];
void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
}

bool get_leds() {
  int i = 0;
  while (Serial.available() > 2) {
    if (i == 0) {
      delay(100);
    }
    uint8_t r = Serial.read();
    uint8_t g = Serial.read();
    uint8_t b = Serial.read();
    leds[i] = CRGB(r, g, b);
    i++;
  }
  if (i != 0) {
    return true;
  }
  return false;
}

void loop() {
  bool state = get_leds();
  if (state) {
    FastLED.show();
  }
  state = false;
}
