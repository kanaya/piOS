#include <OneWire.h>
#include <DallasTemperature.h>

const int THS = A5;
const int SENSOR_RES = 9;
  
OneWire oneWireDev(THS);
DallasTemperature ths(&oneWireDev);
  
void setup(void) {
  Serial.begin(9600);
  ths.begin();
  ths.setResolution(SENSOR_RES);
}
  
void loop(void) {
  ths.requestTemperatures();
  float th = ths.getTempCByIndex(0);
  Serial.println(th);
  delay(500);
}
