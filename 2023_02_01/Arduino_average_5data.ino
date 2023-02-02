#include <NewPing.h>
#define MaxDistance  350

float R_old_average=0;
float R_new_average=0;
float L_old_average=0;
float L_new_average=0;
float F_old_average=0;
float F_new_average=0;
float R_data[5]={0,0,0,0,0};
float F_data[5]={0,0,0,0,0};
float L_data[5]={0,0,0,0,0};

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void read_sonar_sensor(void){ //초음파센서 측정
    R_Sonar_distance = R_sensor.ping_cm()*10.0;
    L_Sonar_distance = L_sensor.ping_cm()*10.0;
    F_Sonar_distance = F_sensor.ping_cm()*10.0;
    if(R_Sonar_distance == 0){R_Sonar_distance = MaxDistance * 10.0;}
    if(L_Sonar_distance == 0){L_Sonar_distance = MaxDistance * 10.0;}
    if(F_Sonar_distance == 0){F_Sonar_distance = MaxDistance * 10.0;}
  }

   void nomal_average_5data (void){
   for(int i=0; i<4; i++){
     F_data[i]=F_data[i+1];
     L_data[i]=L_data[i+1];
     R_data[i]=R_data[i+1];
   }
   F_data[4]=F_Sonar_distance;
   F_new_average=F_old_average+(F_data[4]-F_data[0])/5;
   F_old_average=F_new_average ;
   L_data[4]=L_Sonar_distance;
   L_new_average=L_old_average+(L_data[4]-L_data[0])/5;
   L_old_average=L_new_average ;
   R_data[4]=R_Sonar_distance;
   R_new_average=R_old_average+(R_data[4]-R_data[0])/5;
   R_old_average=R_new_average ;
  }

  void nomal_average (int K){
    F_new_average=(F_old_average*(K-1)/K)+(F_Sonar_distance/K);
    F_old_average=F_new_average ;
    R_new_average=(R_old_average*(K-1)/K)+(R_Sonar_distance/K);
    R_old_average=R_new_average ;
    L_new_average=(L_old_average*(K-1)/K)+(L_Sonar_distance/K);
    L_old_average=L_new_average ;
  }


 void setup() {
  
  for(int i=1; i<6; i++){
    read_sonar_sensor();
    nomal_average (i);
    F_data[5-i]=F_Sonar_distance;
    L_data[5-i]=L_Sonar_distance;
    R_data[5-i]=R_Sonar_distance;
    }
    Serial.begin(115200);
  
  }

void loop() {
  read_sonar_sensor();
  nomal_average_5data();
  Serial.print("정면 초음파 센서 : ");
  Serial.println(F_new_average);
  }

  
