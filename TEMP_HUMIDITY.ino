#include <DHT.h>

#define DHTPIN 26      // Make sure you're using a valid GPIO
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();  // This is crucial!
}

void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print(temp);
  Serial.print("°C  ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000);
}
