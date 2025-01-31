#include <Adafruit_GFX.h>
#include <ESP_Adafruit_SSD1306.h>
#define OLED_RESET 4
#include "DHT.h"
#define DHTPIN D5     
#define DHTTYPE DHT22 

Adafruit_SSD1306 display(OLED_RESET);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x78>>1);
  display.display();
  delay(2000);
  display.clearDisplay();  
  dht.begin();
}

void loop() {
  delay(2000);
  float f = dht.readTemperature(true);
  float t = dht.readTemperature();
  display.setTextSize(1);
  display.setTextColor(WHITE);  
  display.println("F"); 
  display.println(f);
  display.setCursor(0, 0);
  display.display();
  delay(1000);
  display.clearDisplay(); 


}
