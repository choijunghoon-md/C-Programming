import processing.serial.*;
Serial port;  // Create object from Serial class
int val;        // Data received from the serial port

int speed=3200;
int pulse=3200;
int return_pulse=-pulse;
int S_V=625;
int P_V=625;
int old_pulse=0;

void setup() 
{
  size(1400,700);
  smooth();
  String portName ;
  println(Serial.list());
  port = new Serial(this,"COM18",115200); 
  port.bufferUntil('\n');
}

void draw() {
  background(100);
  fill(0,26,51);
  rect(100,100,150,120);
  rect(300,100,150,120);
  rect(1050,500,120,120);
  rect(1200,500,140,120);
  rect(1125,300,120,120);
  rect(100,300,150,100);
  rect(100,500,150,100);
  fill(255);
  rect(1060,510,100,100);
  rect(1210,510,120,100);
  rect(1135,310,100,100);
  rect(110,110,130,100);
  rect(310,110,130,100);
  rect(110,310,130,80);
  rect(110,510,130,80);
  textSize(40);
  fill(0);
  rect(300,340,700,30);
  rect(300,540,700,30);
  text(speed,135,365);
  text(pulse,135,565);
  text("Stop",1147,370);
  text("Start",1069,570);
  text("Return",1215,570);
  textSize(30);
  text("Velocity\n   Mode",126,145);
  text("Position\n   Mode",326,145);
  fill(255);
  if((mouseX)>=305 && (mouseX)<=945 && (mouseY)>=340 && (mouseY)<=370 && (mousePressed)){
    S_V=mouseX;
    if(speed>=0){
      port.write(5);
      delay(10);
      port.write(speed/100);
      delay(10);
      port.write(speed%100);
      delay(10);
    }
    else{
      port.write(6);
      delay(10);
      port.write(-speed/100);
      delay(10);
      port.write(-speed%100);
      delay(10);
    }
  }
  if((S_V-625)>300){
    S_V=925;
  }
  else if((S_V-625)<-300){
    S_V=325;
  }
  speed=(S_V-625)*10;
  rect(S_V,345,50,20);
  if((mouseX)>=305 && (mouseX)<=945 && (mouseY)>=540 && (mouseY)<=570 && (mousePressed)){
    P_V=mouseX;
    if(pulse>=0){
      port.write(2);
      delay(10);
      port.write(pulse/100);
      delay(10);
      port.write(pulse%100);
      delay(10);
    }
    else{
    port.write(7);
    delay(10);
    port.write(-pulse/100);
    delay(10);
    port.write(-pulse%100);
    delay(10);
    }
  }
  pulse=(P_V-625)*10;
  rect(P_V,545,50,20);
  fill(255);
  text("SPEED",S_V-15,320);
  text("SPEED",130,290);
  text("POSITION",P_V-35,520);
  text("POSITION",110,490);
  if((mouseX)>100 && (mouseX)<250 && (mouseY)>100 && (mouseY)<220 && (mousePressed)){
    port.write(3);
    delay(10);
    port.write(0);
    delay(10);
    port.write(0);
    delay(10);
    }
if((mouseX)>300 && (mouseX)<450 && (mouseY)>100 && (mouseY)<220 && (mousePressed)){
    port.write(1);
    delay(10);
    port.write(0);
    delay(10);
    port.write(0);
    delay(10);
    }
if((mouseX)>1125 && (mouseX)<1245 && (mouseY)>300 && (mouseY)<420 && (mousePressed)){
    port.write(3);
    delay(10);
    port.write(0);
    delay(10);
    port.write(0);
    delay(10);
    }
if((mouseX)>1050 && (mouseX)<1170 && (mouseY)>500 && (mouseY)<620 && (mousePressed)){
    port.write(4);
    delay(10);
    port.write(0);
    delay(10);
    port.write(0);
    delay(10);
    old_pulse=pulse;
    }
 if((mouseX)>1200 && (mouseX)<1340 && (mouseY)>500 && (mouseY)<620 && (mousePressed)){
    if(old_pulse>=0){
      port.write(7);
      delay(10);
      port.write(old_pulse/100);
      delay(10);
      port.write(old_pulse%100);
      delay(10);
    }
    else{
      port.write(2);
      delay(10);
      port.write(-old_pulse/100);
      delay(10);
      port.write(-old_pulse%100);
      delay(10);
    }
  }
}
