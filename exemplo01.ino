// autor: Tiago Caldeira

void move_m(int md,int me){
 //Ordem para os motores
  digitalWrite(4,HIGH); 
  digitalWrite(7,HIGH);
  if( me < 0 ){ 
      digitalWrite(4,LOW);  
      me = 0 - me; 
      }
  analogWrite( 5, me);    
  if( md < 0 ){ 
      digitalWrite(7,LOW);  
      md = 0 - md; 
      }
  analogWrite( 6, md);    
}

void move_t(int md,int me,int t){
  //Ordem para os motores com tempo
  move_m(md,me);  
  delay(t);
  move_m(0,0);
}


void setup()  { 
  Serial.begin(9600);
  //Declarar Portas dos Motores
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);pinMode(5, OUTPUT);     
  pinMode(6, OUTPUT);pinMode(7, OUTPUT);     
} 

int medir(){
}

void loop(){
  int duration, distance;
  digitalWrite(2, HIGH);
  delayMicroseconds(1000);
  digitalWrite(2, LOW);
  duration = pulseIn(3, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
    move_m(100,100);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    if (distance > 30)
        move_m(100,100);
    else{
        move_m(100,-100);
    }
  }
  delay(100);
}
