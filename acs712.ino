void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  int adc =  analogRead(34);
  float voltage = adc*5/4096; // converting adc value to voltage, when Vref = 5v vcc;
  float current = (voltage-2.5)/0.100 /* subtracting 2.5v offset,ie, when load is absent, a voltage of 2.5v is sent by acs712.
   we then divide it by sensitivity*/
  Serial.println()
}