#include <SoftwareSerial.h>
int SENSOR_MH_A_PIN = A0;


void setup() {
  Serial.begin(115200);
  pinMode(7, OUTPUT); 
}

float readSensor()
{
  float reading = analogRead(SENSOR_MH_A_PIN);
  float voltage;
  voltage = map(reading, 0, 1023, 0, 5000); // chuyển thang đo 
  float tile = (voltage / 5000) * 100;  //
  return (100 - tile);
}

void sendData()
{
  Serial.print((int)readSensor());
  
}

void loop() {
  Serial.print("Độ ẩm đất hiện tại : ");
  Serial.print((int)readSensor());
  Serial.print("%");
  Serial.println();
  delay(1000);
  if (readSensor() < 40 ) // khi độ ẩm đất dưới 40% sẽ thực hiện tự động bơm nước
  {
    digitalWrite(7, HIGH);
  }
  else
  {
    digitalWrite(7, LOW);
  }
}
