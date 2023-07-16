//Motor 1
int in1=8;
int in2=9;
int ena=5;
//Motor 2
int in3=10;
int in4=11;
int enb=6;
//senor
int R_S = 2; 
int L_S = 13; 

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

pinMode(ena,OUTPUT);
pinMode(enb,OUTPUT);

pinMode(L_S, INPUT);
pinMode(R_S, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
   analogWrite(ena,125);
   analogWrite(enb,125);

   if((digitalRead(L_S) == 1)&&(digitalRead(R_S) == 1))
{
  Stop();
  Serial.println("Stop");
  delay(100);
  forword(); 
}


else if ((digitalRead(L_S) == 0)&&(digitalRead(R_S) == 1)) 
{
  turnLeft();
  Serial.println("Left");
 
}

else if ((digitalRead(L_S) == 1)&&(digitalRead(R_S) == 0))
{
  turnRight();
  Serial.println("Right");

}

else 
{
   forword();
   Serial.println("Forward");
}


}

void forword(){
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

}


void turnRight(){
digitalWrite(in1, HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4, LOW);  
analogWrite(enb,150 );

}

void turnLeft(){
 
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(ena,150);

}

void Stop(){
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
delay(3000);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
//delay(50);
}
