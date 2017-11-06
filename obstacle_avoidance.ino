                                                                                 //OBSTACLE AVIODANCE

//THE BUTTONS
//b:To move bck(buttton connected to pin 3 enables the vehicle to move backward)
//f:To move frward
//l:To move left
//r:To move right;


#define trig 3
#define echo 4
#define motor11 7
#define motor12 2
#define motor21 10
#define motor22 11
#define ena1 8
#define ena2 13

float t=0,cm=0;
void setup() 
{
  Serial.begin(9600); 
  pinMode(trig,OUTPUT);//for trigger in ping
  pinMode(echo,INPUT);//for echo in ping
  
  pinMode(motor11,OUTPUT);//retrives 5v power for 1st motor frm this pin
  pinMode(motor12,OUTPUT);
  pinMode(ena1,OUTPUT);
  pinMode(motor21,OUTPUT);//retrives 5v power for 1st motor frm this pin
  pinMode(motor22,OUTPUT);
  pinMode(ena2,OUTPUT); 
}
void loop() 
{
  
  digitalWrite(ena1,HIGH);          //ACTIVATES MOTOR
  digitalWrite(ena2,HIGH);
  char a=0;
  digitalWrite(trig,LOW);
  delayMicroseconds(3);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  delayMicroseconds(3);
  t=pulseIn(echo,HIGH);
  cm=(t)/58; 
  if(cm<=10)
  {
       bck();
       pause();
       delay(10);
  }
  else if(cm>10)
  {
    while(!Serial.available());
    a=Serial.read(); 
    if(a=='b')
    {
       bck();
       pause();
    }
    else if(a=='f')
    {
        fwd();
        pause();
    }
    else if (a=='l')
    {
        left();
        pause();
    }
     
    else if(a=='r')
    {
         right();
         pause();
     
    }
  }  
  
}


void fwd(void)
{

         digitalWrite(motor11,HIGH);           //MOVES IN frWARD DIRECTION
         digitalWrite(motor12,LOW);
         digitalWrite(motor21,LOW);           
         digitalWrite(motor22,HIGH);
         
}

void bck(void)
{

         digitalWrite(motor11,LOW);          //MOVES IN bckWARD DIRECTION 
         digitalWrite(motor12,HIGH);
         digitalWrite(motor21,HIGH);
         digitalWrite(motor22,LOW);
         
 }
void left(void)
{
         digitalWrite(motor11,LOW);          //MOVES IN left DIRECTION 
         digitalWrite(motor12,HIGH);
         digitalWrite(motor21,LOW);
         digitalWrite(motor22,HIGH);

}

void right(void)
{
         digitalWrite(motor11,HIGH);           //MOVES IN RIGHT DIRECTION
         digitalWrite(motor12,LOW);
         digitalWrite(motor21,HIGH);           
         digitalWrite(motor22,LOW);
}

void pause(void)
{
         delay(100);
         digitalWrite(motor11,LOW);          
         digitalWrite(motor12,LOW);
         digitalWrite(motor21,LOW);
         digitalWrite(motor22,LOW);

}



