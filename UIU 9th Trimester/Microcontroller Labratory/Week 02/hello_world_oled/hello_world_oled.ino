#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);
void setup() {
	if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
		Serial.println(F("SSD1306 allocation failed"));
		for (;;); // Don't proceed, loop forever
	}
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setTextSize(1);
	display.display();
	//display.clearDisplay();
}

void loop() {
	display.clearDisplay();
	display.setCursor(0, 12);
	display.println("Hello World!");
	display.display();
	delay(100);
}