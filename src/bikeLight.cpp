

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN        6 //D6
#define SWITCH     5 //D5
#define NUMPIXELS  20

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint32_t PINK = pixels.Color(255, 0, 64);
uint32_t RED = pixels.Color(255, 0, 0);

int brightness = 255;
byte pink = LOW;

void updatePixels(){

  for(int i=0; i<NUMPIXELS; i++) {
    if (pink == LOW){
      pixels.setPixelColor(i, RED);
    } else {
      pixels.setPixelColor(i, PINK);
    }
  }
  pixels.setBrightness(brightness);
  pixels.show();
}

void setup() {
  Serial.begin(115200);

  pinMode(SWITCH, INPUT_PULLUP);

  pixels.begin();
  pixels.clear();
}

void loop() {

  pink = digitalRead(SWITCH);

  if (brightness > 2) {
    --brightness;
  } else {
    brightness = 255;
  }
  updatePixels();
  delay(5);
}