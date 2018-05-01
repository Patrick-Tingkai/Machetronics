

int xPin=A0;
int yPin=A1;

int out1=8;     
int out2=9;     
int out3=10;    
int out4=11;    

void setup(){
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);
  pinMode(13,OUTPUT);
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
  Serial.begin(9600);
}


void loop() 
{
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
  int xval=analogRead(xPin);
  Serial.print("xval = ");
  Serial.print(xval);
  //delay(300);
  int yval=analogRead(yPin);
  Serial.print(" /t yval = ");
  Serial.println(yval);
  //delay(300);

  if ((xval>315 && xval<345) && (yval>315 && yval<345)) //stop
  {
    digitalWrite(out1,LOW);  
    digitalWrite(out2,LOW);   
    digitalWrite(out3,LOW);   
    digitalWrite(out4,LOW);
    Serial.println("stop");
  } 

  else 
  { 
    if ((xval>240 && xval<290) && (yval>315 && yval<345)) //forward
   {
     digitalWrite(out1,HIGH);  
     digitalWrite(out2,LOW);   
     digitalWrite(out3,HIGH);  
     digitalWrite(out4,LOW);
     Serial.println("forward"); 
    }
    if ((xval>350 && xval<400) && (yval>315 && yval<345)) //backward
  {
   digitalWrite(out1,LOW);   
   digitalWrite(out2,HIGH);  
   digitalWrite(out3,LOW);   
   digitalWrite(out4,HIGH);
   Serial.println("backward");   
    }   

    if ((xval>315 && xval<345) && (yval>260 && yval<300)) //left
    {
      digitalWrite(out1,HIGH);  
      digitalWrite(out2,LOW);   
      digitalWrite(out3,LOW);   
      digitalWrite(out4,LOW);
      Serial.println("left");
     }


    if ((xval>315 && xval<345) && (yval>350 && yval<400))//right
    {
      digitalWrite(out1,LOW);  
      digitalWrite(out2,LOW);   
      digitalWrite(out3,HIGH);   
      digitalWrite(out4,LOW);
      Serial.println("right");
    }
  }
}