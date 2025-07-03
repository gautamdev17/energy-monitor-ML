#include <Wire.h>
#include <ZMPT101B.h>
#include <EmonLib.h>  // For current sensing only

// ---------------------- Voltage Sensor (ZMPT101B) ----------------------
#define VOLTAGE_PIN 34
#define SENSITIVITY 500.0f
#define VOLTAGE_CALIBRATION 1.136
#define VOLTAGE_THRESHOLD 20.0

ZMPT101B voltageSensor(VOLTAGE_PIN, 50.0);

// ---------------------- Current Sensor (SCT-013-000 via voltage divider) -------------------
#define CURRENT_PIN 32
#define CURRENT_CALIBRATION 60.6  // Tune this based on real load

EnergyMonitor emon;  // Only for current

// ---------------------- Setup ----------------------
void setup() {
  Serial.begin(115200);
  voltageSensor.setSensitivity(SENSITIVITY);

  // Only current is being sensed via EmonLib
  emon.current(CURRENT_PIN, CURRENT_CALIBRATION);
}

// ---------------------- Get Filtered Voltage ----------------------
float getFilteredVoltage() {
  float sum = 0;
  const int samples = 20;

  for (int i = 0; i < samples; i++) {
    sum += voltageSensor.getRmsVoltage() * VOLTAGE_CALIBRATION;
    delay(10);
  }

  float avgVoltage = sum / samples;
  return (avgVoltage < VOLTAGE_THRESHOLD) ? 0.0 : avgVoltage;
}

// ---------------------- Get Current ----------------------
float getCurrent() {
  emon.calcVI(20, 2000);  // 20 cycles or 2s timeout
  float current = emon.Irms;

  return (current < 0.05) ? 0.0 : current;  // Clamp ghost readings
}

// ---------------------- Main Loop ----------------------
void loop() {
  float voltage = getFilteredVoltage();
  float current = getCurrent();
  float apparentPower = voltage * current;

  // --------- Display ---------
  Serial.print("Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V\t");

  Serial.print("Current: ");
  Serial.print(current, 3);
  Serial.print(" A\t");

  Serial.print("Apparent Power: ");
  Serial.print(apparentPower, 2);
  Serial.println(" W");

  delay(500);
}
