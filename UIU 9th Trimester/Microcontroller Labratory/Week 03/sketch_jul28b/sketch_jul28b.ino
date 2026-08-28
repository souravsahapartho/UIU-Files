#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// =========================
// WiFi Credentials
// =========================
const char* ssid = "SoURaV";
const char* password = "Sourav0775";

// Google Apps Script Web App URL
const char* scriptURL = "https://script.google.com/macros/s/AKfycbxu8QIGeMMa2aWxwdETjrQ4dECGrpuF6PjZVao3JApWajcKqRhMgknmC93Cf2qBIn-JNQ/exec";

void setup() {
  Serial.begin(115200);

  dht.begin();
  delay(2000);

  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    String url = String(scriptURL) +
                 "?temp=" + String(temperature, 2) +
                 "&hum=" + String(humidity, 2);

    Serial.println(url);

    http.begin(url);

    int httpCode = http.GET();

    Serial.print("HTTP Response Code: ");
    Serial.println(httpCode);

    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
    }

    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }

  Serial.println("----------------------");

  delay(5000);
}