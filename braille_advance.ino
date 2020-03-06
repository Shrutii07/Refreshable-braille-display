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
}  

void loop()
{
  for(int i = 0; i < sizeof(data); i++)
  {
    input=data[i];

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
          digitalWrite(7, HIGH);
          delay(1000);
//          digitalWrite(7, LOW);
          temp = 0;
        }
        else if(input>= '0' && input<='9')
        {
          //digits
          digitalWrite(3, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(6, HIGH);
          digitalWrite(7, HIGH);
          delay(1000);
//          digitalWrite(3, LOW);
//          digitalWrite(5, LOW);
//          digitalWrite(6, LOW);
//          digitalWrite(7, LOW);
        }
        for(int k=0;k<6 ;k++)
        {
          if( output[k] == 1 )
           {
            digitalWrite(k+2, HIGH);
           }
           else
           {
            digitalWrite(k+2, LOW);
           }
        }
       delay(5000);
//       for(int k=0;k<6 ;k++)
//        {
//          if(output[k] == 1)
//           {
//            digitalWrite(k+2, LOW);
//           }
//        }
       break;
      }
    }
  }
}
