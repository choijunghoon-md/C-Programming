#include <NewPing.h>
NewPing sensor(52,53,350);
#define k 0.7

float Sonar_distance=0;

void read_sonar_sensor(void){ //초음파센서 측정
    Sonar_distance = sensor.ping_cm()*10.0;
    if(Sonar_distance == 0){Sonar_distance = 350 * 10.0;}
  }

float old_average=0;
float new_average=0;

 void nomal_average (float a,float K){
    new_average=(old_average*K)+(a*(1-K));
    old_average=new_average;
  } //  이때 K는 가급적 0.4이상 1미만으로 한다.

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  read_sonar_sensor();
  nomal_average(Sonar_distance,k);
  Serial.print(Sonar_distance);
  Serial.print(" ");
  Serial.println(new_average);
  delay(100);
}
