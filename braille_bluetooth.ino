#include <Servo.h>

//Braille binary
int binary[63][6]={{0,0,0,0,0,0},{0,1,1,0,1,1},{0,0,0,1,0,0},{0,1,0,1,1,1},{1,1,1,0,0,1},{1,1,0,0,0,1},{1,1,1,0,1,1},{1,0,1,1,1,1},{0,1,1,1,1,1},{1,0,0,0,0,1},{0,1,0,0,1,1} ,{0,0,0,0,0,1} ,{0,0,0,0,1,1},{0,1,0,0,0,1},{0,1,0,0,1,0},
        {0,0,0,1,1,1},{0,0,1,0,0,0},{0,0,1,0,1,0},{0,0,1,1,0,0},{0,0,1,1,0,1},{0,0,1,0,0,1},{0,0,1,1,1,0},{0,0,1,1,1,1},{0,0,1,0,1,1},{0,0,0,1,1,0},{1,0,0,1,0,1},{0,0,0,1,0,1},{1,0,1,0,0,1},{1,1,1,1,1,1},{0,1,0,1,1,0},{1,1,0,1,0,1},
        {0,1,0,0,0,0},{1,0,0,0,0,0},{1,0,1,0,0,0},{1,1,0,0,0,0},{1,1,0,1,0,0},{1,0,0,1,0,0},{1,1,1,0,0,0},{1,1,1,1,0,0},{1,0,1,1,0,0},{0,1,1,0,0,0},{0,1,1,1,0,0},{1,0,0,0,1,0},{1,0,1,0,1,0},{1,1,0,0,1,0},{1,1,0,1,1,0},{1,0,0,1,1,0},{1,1,1,0,1,0},{1,1,1,1,1,0},{1,0,1,1,1,0},{0,1,1,0,1,0},{0,1,1,1,1,0},{1,0,0,0,1,1},{1,0,1,0,1,1},{0,1,1,1,0,1},{1,1,0,0,1,1},{1,1,0,1,1,1},{1,0,0,1,1,1},
        {0,1,1,0,0,1},{1,0,1,1,0,1},{1,1,1,1,0,1},{0,1,0,1,0,0},{0,1,0,1,0,1}};

//Ascii codes
char ascii[63]={' ', '!', '"', '#', '$', '%', '&', '(', ')', '*', '+', ',', '-', '.', '/', 
        '0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?',
        '@','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
         '[','\\',']','^','_'};

Servo servo1, servo2, servo3, servo4, servo5, servo6;

int Received;
char data[11] ="Hello 01";  
char input;
int* output;
int temp =0;
void setup() 
{  
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);  
    pinMode(4, OUTPUT);  
    pinMode(5, OUTPUT);  
    pinMode(6, OUTPUT);  
    pinMode(7, OUTPUT);  
    Serial.begin(9600); 
    
    servo1.attach(3);
    servo2.attach(5);
    servo3.attach(6);
    servo4.attach(9);
    servo5.attach(10);
    servo6.attach(11);
}  

void servo_disp(int* output)
{
   if( output[0] == 1 )
   {
    servo1.write(0);
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    servo1.write(45);
//    digitalWrite(k+2, LOW);
   }
    if( output[1] == 1 )
   {
    servo2.write(0);
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    servo2.write(45);
//    digitalWrite(k+2, LOW);
   }
    if( output[2] == 1 )
   {
    servo3.write(0);
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    servo3.write(45);
//    digitalWrite(k+2, LOW);
   }
    if( output[3] == 1 )
   {
    servo4.write(0);
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    servo4.write(45);
//    digitalWrite(k+2, LOW);
   }
    if( output[4] == 1 )
   {
    servo5.write(0);
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    servo5.write(45);
//    digitalWrite(k+2, LOW);
   }
    if( output[5] == 1 )
   {
    servo6.write(0);
//    digitalWrite(k+2, HIGH);
   }
   else
   {
    servo6.write(45);
//    digitalWrite(k+2, LOW);
   }

}

void loop()
{ 
  if (Serial.available() > 0)
  {
    while(Serial.available() > 0)
    {
      Serial.print("I am reading...\n");
      Received = Serial.read();
      Serial.print(Received);
      Serial.print(": ");
      Serial.print((char)Received);
      Serial.print("\n");
      input= (char)Received;
  
              if( input >=65 and input<91 )
          {
            //capital letters
            temp = 1;
             input += 'a' -'A' ;
          }
      
      for (int j=0 ; j<sizeof(ascii); j++)
      {
     
        if(input == ascii[j])
      {
        output=binary[j];
        if( temp == 1 )
        {
          //capital letters
          servo1.write(45);
          servo2.write(45);
          servo3.write(45);
          servo4.write(45);
          servo5.write(45);
          servo6.write(0);              // tell servo to go to position in variable 'pos'
          delay(5000);
//          servo6.write(1);
          temp = 0;
        }
        else if(input>= '0' && input<='9')
        {
          //digits
          servo1.write(45);
          servo2.write(0);
          servo3.write(45);
          servo4.write(0);
          servo5.write(0);
          servo6.write(0);
          delay(5000);
//          servo2.write(1);
//          servo4.write(1);
//          servo5.write(1);
//          servo6.write(1);

        }
         servo_disp(output);
         delay(5000);
         break;
        }
      }
    }
  }
  else
  {
    Serial.print(Serial.available());
    int zero[6] = {0, 0, 0, 0, 0, 0};
    servo_disp(zero);
    delay(3000);
  }
}
