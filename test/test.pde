import processing.net.*;
int[] a ={0,0,0,0,0,0,0,0};
void setup() {
size(1000,700);
smooth();
}

void draw(){
  
  fill(0,26,51);
  rect(150,150,700,60);
  
   fill(255,26,51);
   rect(50,320,900,60);
   
   fill(0);
   rect(140,330,20,40);
   rect(240,330,20,40);
   rect(340,330,20,40);
   rect(440,330,20,40);
   rect(540,330,20,40);
   rect(640,330,20,40);
   rect(740,330,20,40);
   rect(840,330,20,40);
   ellipse(140,350,40,40);
   ellipse(160,350,40,40);
   ellipse(240,350,40,40);
   ellipse(260,350,40,40);
   ellipse(340,350,40,40);
   ellipse(360,350,40,40);
   ellipse(440,350,40,40);
   ellipse(460,350,40,40);
   ellipse(540,350,40,40);
   ellipse(560,350,40,40);
   ellipse(640,350,40,40);
   ellipse(660,350,40,40);
   ellipse(740,350,40,40);
   ellipse(760,350,40,40);
   ellipse(840,350,40,40);
   ellipse(860,350,40,40);

  fill(0,26,51);
  rect(150,500,700,60);
  
  fill(255);
  ellipse(200,180,40,40);
  ellipse(800,180,40,40);
  ellipse(286,180,40,40);
  ellipse(371,180,40,40);
  ellipse(457,180,40,40);
  ellipse(543,180,40,40);
  ellipse(628,180,40,40);
  ellipse(714,180,40,40);
  
  ellipse(200,530,40,40);
  ellipse(800,530,40,40);
  ellipse(286,530,40,40);
  ellipse(371,530,40,40);
  ellipse(457,530,40,40);
  ellipse(543,530,40,40);
  ellipse(628,530,40,40);
  ellipse(714,530,40,40);
  


for(int i=0; i<8; i++){
  if(a[i]==0){
    fill(255);
    ellipse(140+100*i,350,40,40);
  } else{
    fill(255);
    ellipse(160+100*i,350,40,40);
  }
}

for(int i=0; i<8; i++){
  if(a[i]==0){
    if((mouseX-140-100*i)*(mouseX-140-100*i)+(mouseY-350)*(mouseY-350)<=400){
      if(mousePressed){
        a[i]=1;
        delay(100);
      }
    }
  } else{
    if((mouseX-160-100*i)*(mouseX-160-100*i)+(mouseY-350)*(mouseY-350)<=400){
      if(mousePressed){
        a[i]=0;
        delay(100);
      }
    }
  }




}




if((mouseX-200)*(mouseX-200)+(mouseY-180)*(mouseY-180)<=400 || a[0]==1){
if(mousePressed || a[0]==1){
fill(255,0,0);
} else {
fill(255);
}
ellipse(200,530,40,40);
}

if((mouseX-800)*(mouseX-800)+(mouseY-180)*(mouseY-180)<=400 || a[7]==1){
if(mousePressed || a[7]==1){
fill(255,0,0);
} else {
fill(255);
}
ellipse(800,530,40,40);
}

if((mouseX-286)*(mouseX-286)+(mouseY-180)*(mouseY-180)<=400 || a[1]==1){
if(mousePressed || a[1]==1){
fill(255,0,0);
} else {
fill(255);
}
ellipse(286,530,40,40);
}

if((mouseX-371)*(mouseX-371)+(mouseY-180)*(mouseY-180)<=400 || a[2]==1){
if(mousePressed || a[2]==1){
fill(255,0,0);
} else {
fill(255);
}
ellipse(371,530,40,40);
}

if((mouseX-457)*(mouseX-457)+(mouseY-180)*(mouseY-180)<=400 || a[3]==1){
if(mousePressed || a[3]==1){
fill(255,0,0);
} else {
fill(255);
}
ellipse(457,530,40,40);
}

if((mouseX-543)*(mouseX-543)+(mouseY-180)*(mouseY-180)<=400 || a[4]==1){
if(mousePressed || a[4]==1){
fill(255,0,0);
} else {
fill(255);
}
ellipse(543,530,40,40);
}

if((mouseX-628)*(mouseX-628)+(mouseY-180)*(mouseY-180)<=400 || a[5]==1){
if(mousePressed || a[5]==1){
fill(255,0,0);
} else {
fill(255);
}
ellipse(628,530,40,40);
}

if((mouseX-714)*(mouseX-714)+(mouseY-180)*(mouseY-180)<=400 || a[6]==1){
if(mousePressed || a[6]==1){
fill(255,0,0);
} else {
fill(255);
}
ellipse(714,530,40,40);
}





}
