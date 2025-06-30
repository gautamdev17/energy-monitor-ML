const int sensorIn = 34;      // ESP32 ADC pin connected to ACS712 OUT
int mVperAmp = 100;           // 20A module = 100mV per Amp
int Watt = 0;
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);   // ESP32 ADC is 0-4095 (12-bit)
  Serial.println("ACS712 current sensor (20A)");
}

void loop() {
  Serial.println("");

  Voltage = getVPP();                         // Peak-to-peak voltage
  VRMS = (Voltage / 2.0) * 0.707;             // Convert peak to RMS
  AmpsRMS = (VRMS * 1000) / mVperAmp;         // Convert mV to Amps

  Serial.print(AmpsRMS);
  Serial.print(" Amps RMS  ---  ");

  Watt = (AmpsRMS * 240 / 1.3);               // Rough power estimate
  Serial.print(Watt);
  Serial.println(" W");
}

float getVPP() {
  float result;
  int readValue;
  int maxValue = 0;
  int minValue = 4095;

  uint32_t start_time = millis();
  while ((millis() - start_time) < 1000) {    // Sample for 1 second
    readValue = analogRead(sensorIn);
    if (readValue > maxValue) maxValue = readValue;
    if (readValue < minValue) minValue = readValue;
  }

  result = ((maxValue - minValue) * 3.3) / 4095.0;  // Convert ADC diff to voltage
  return result;
}
