#include <ZMPT101B.h>// NOTE TO DEVS: add this library to your ide
#define acspin 34
#define zmptpin 32
#define sensitivity 500.0f
#define voltageCalibration 1.136

ZMPT101B voltageSensor(VOLTAGE_PIN, 50.0);// 50 Hz is my mains frequency, developers are advised to check their mains

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  voltageSensor.setSensitivity(sensitivity);
}

void loop() {
  float voltage = voltageSensor.getRmsVoltage() * voltageCalibration;
  int adc =  analogRead(acspin);
  float voltage = adc*3.3/4095; // converting adc value to voltage, when Vref = 5v vcc;
  float current = (voltage-2.5)/0.100 /* subtracting 2.5v offset,ie, when load is absent, a voltage of 2.5v is sent by acs712.
   we then divide it by sensitivity*/

  // filtering unstable values when load isn't connected
  if (abs(voltage) < 20.0) voltage = 0.0;
  if (abs(current) < 0.1) current = 0.0;
  
  Serial.print("Voltage:",voltage);
  Serial.print("Current:",current);
  Serial.print("Power:", voltage*current);
  /*coming soon: 
    1. scaling this power calcs to a month
    2. temperature and humidity calculation
    */
}
