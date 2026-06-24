/*LINE FOLLOWER USING PWM*/
int a=0;
void setup() 
{
  // these four pins is for motor control:
  pinMode(3,OUTPUT);   //3,5,6,9,10,11 pins are pwm pins in arduino uno
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(2,INPUT); // reading the value from the IR sensor 
}

void loop() 
{
  // put your main code here, to run repeatedly:
  /*if(digitalRead(2))*/  // it is same like if( a == 1 )
  a = digitalRead(2);
  if( a == 0 )
  {
    analogWrite(3,150);
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(9,0);
  }
  else
  {
    analogWrite(3,0);
    analogWrite(5,0);
    analogWrite(6,150);
    analogWrite(9,0);
  }
}
