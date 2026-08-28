#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// MQ-2 Sensor
const int sensorPin = A0;

#define RL 10
#define m -0.263
#define b 0.42
#define Ro 20

void setup()
{
  Serial.begin(9600);

  Serial.println("MQ2 Warming Up...");
  delay(20000);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println("OLED Failed");
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop()
{
  float sensorValue = analogRead(sensorPin);

  float VRL = sensorValue * (5.0 / 1023.0);

  float Rs = ((5.0 * RL) / VRL) - RL;

  float ratio = Rs / Ro;

  float ppm = pow(10, ((log10(ratio) - b) / m));

  // Serial Monitor
  Serial.print("ADC: ");
  Serial.print(sensorValue);

  Serial.print("  PPM: ");
  Serial.println(ppm);

  // OLED
  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(0,0);
  display.println("MQ-2");

  display.setTextSize(1);
  display.setCursor(0,30);
  display.print("ADC : ");
  display.println(sensorValue);

  display.setCursor(0,45);
  display.print("PPM : ");
  display.print(ppm,1);

  display.display();

  delay(500);
}