// Autor: Tiago Caldeira
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

void loop(){
  Serial.print("Sensores de Luz (Portas A2 e A3)");
  Serial.print(analogRead(A2));
  Serial.print("\t");
  Serial.print(analogRead(A3));
  Serial.println(" ");
  //Accao:
  if( analogRead(A2) < 200 && analogRead(A3) < 240 )
    move_m(90,90); //90 90
  else if( analogRead(A2) > 200 )
    move_t(100,-180,50); //100 -180
  else if( analogRead(A3) > 240 )
    move_t(-180,100,50); //-180 100
  
}

//GREY   120  160
//BLACK  260  340
