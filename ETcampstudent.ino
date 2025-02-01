#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDR 0x3C

#define DHTPIN 14
#define DHTTYPE DHT22

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("ไม่พบ OLED!");
    for (;;);
  }
  Serial.println("OLED พร้อมใช้งาน");
  display.clearDisplay();

  dht.begin();
  Serial.println("DHT22 พร้อมใช้งาน");
}

void loop() {
  delay(2000);

  float f = dht.readTemperature(true);

  Serial.print("อุณหภูมิ: ");
  Serial.print(f);
  Serial.println("°F)");

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Temp (F): ");
  display.println(f);
  display.display();
}
