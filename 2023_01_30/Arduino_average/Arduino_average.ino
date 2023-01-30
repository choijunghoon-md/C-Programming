#include <NewPing.h>
#define MaxDistance  350

float old_average=0;
float new_average=0;

 void nomal_average_5data (float a,int K){
    new_average=(old_average*(K-1)/K)+(a/K);
    old_average=new_average ;
  }


NewPing R_sensor(48,49,MaxDistance);
  float R_Sonar_Error = 0.0;
  float R_Sonar_distance = 0.0;
  float R_Sonar_distance_old = 0.0;

NewPing L_sensor(52,53,MaxDistance);
  float L_Sonar_Error = 0.0;
  float L_Sonar_distance = 0.0;
  float L_Sonar_distance_old = 0.0;

NewPing F_sensor(50,51,MaxDistance);
  float F_Sonar_Error = 0.0;
  float F_Sonar_distance = 0.0;
  float F_Sonar_distance_old = 0.0;

void read_sonar_sensor(void){ //초음파센서 측정
    R_Sonar_distance = R_sensor.ping_cm()*10.0;
    L_Sonar_distance = L_sensor.ping_cm()*10.0;
    F_Sonar_distance = F_sensor.ping_cm()*10.0;
    if(R_Sonar_distance == 0){R_Sonar_distance = MaxDistance * 10.0;}
    if(L_Sonar_distance == 0){L_Sonar_distance = MaxDistance * 10.0;}
    if(F_Sonar_distance == 0){F_Sonar_distance = MaxDistance * 10.0;}
  }


void setup() {
 Serial.begin(115200);
}

float b=0;
int K=1;

void loop() {
  
  read_sonar_sensor();
  nomal_average_5data (L_Sonar_distance,K);
  K = K+1;
  Serial.println(new_average);
}
