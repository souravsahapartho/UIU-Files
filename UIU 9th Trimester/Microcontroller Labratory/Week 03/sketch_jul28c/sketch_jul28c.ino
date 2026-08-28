#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(115200);

  dht.begin();

  Wire.begin(21,22);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println("OLED not found");
    while(true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if(isnan(temperature) || isnan(humidity)){
    Serial.println("Failed to read DHT");
    delay(2000);
    return;
  }

  display.clearDisplay();

  display.setCursor(0,0);
  display.println("DHT11 Sensor");

  display.setCursor(0,20);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");

  display.setCursor(0,40);
  display.print("Hum : ");
  display.print(humidity);
  display.println(" %");

  display.display();

  delay(2000);
}