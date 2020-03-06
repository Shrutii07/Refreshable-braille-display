
//Braille binary
int binary[63][6]={{0,0,0,0,0,0},{0,1,1,0,1,1},{0,0,0,1,0,0},{0,1,0,1,1,1},{1,1,1,0,0,1},{1,1,0,0,0,1},{1,1,1,0,1,1},{1,0,1,1,1,1},{0,1,1,1,1,1},{1,0,0,0,0,1},{0,1,0,0,1,1} ,{0,0,0,0,0,1} ,{0,0,0,0,1,1},{0,1,0,0,0,1},{0,1,0,0,1,0},
        {0,0,0,1,1,1},{0,0,1,0,0,0},{0,0,1,0,1,0},{0,0,1,1,0,0},{0,0,1,1,0,1},{0,0,1,0,0,1},{0,0,1,1,1,0},{0,0,1,1,1,1},{0,0,1,0,1,1},{0,0,0,1,1,0},{1,0,0,1,0,1},{0,0,0,1,0,1},{1,0,1,0,0,1},{1,1,1,1,1,1},{0,1,0,1,1,0},{1,1,0,1,0,1},
        {0,1,0,0,0,0},{1,0,0,0,0,0},{1,0,1,0,0,0},{1,1,0,0,0,0},{1,1,0,1,0,0},{1,0,0,1,0,0},{1,1,1,0,0,0},{1,1,1,1,0,0},{1,0,1,1,0,0},{0,1,1,0,0,0},{0,1,1,1,0,0},{1,0,0,0,1,0},{1,0,1,0,1,0},{1,1,0,0,1,0},{1,1,0,1,1,0},{1,0,0,1,1,0},{1,1,1,0,1,0},{1,1,1,1,1,0},{1,0,1,1,1,0},{0,1,1,0,1,0},{0,1,1,1,1,0},{1,0,0,0,1,1},{1,0,1,0,1,1},{0,1,1,1,0,1},{1,1,0,0,1,1},{1,1,0,1,1,1},{1,0,0,1,1,1},
        {0,1,1,0,0,1},{1,0,1,1,0,1},{1,1,1,1,0,1},{0,1,0,1,0,0},{0,1,0,1,0,1}};

//Ascii codes
char ascii[63]={' ', '!', '"', '#', '$', '%', '&', '(', ')', '*', '+', ',', '-', '.', '/', 
        '0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?',
        '@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
         '[','\\',']','^','_'};

char data[20] ="Hello ";  
char input;
int* output;
int capital_sign=0,numerical_sign=0;
int k=0;
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
    for (int j=0 ; j<sizeof(ascii); j++)
    {
      if(input == ascii[j])
      { 
        output=binary[j];
        if( input <=65 || input<91 )
        {
          //capital letters
          capital_sign = 1;
          
//          int cap_out[6] = {0,0,0,0,0,1};
        }
        else if(input <=97 || input<123)
        {
          //small letters 
          capital_sign =0;
         }
         else if(input<= 48 || input<57)
         {
            //digits
            numerical_sign=1;
//            int num_out[6]={0,1,0,1,1,1};
            
         }
         else
         {
          numerical_sign=0;
          capital_sign=0;
         }
         
         while(k<6)
         {
          if( capital_sign == 1)
          {
           digitalWrite(6, HIGH);
            delay(1000);
           
            k=0;
            capital_sign=0;
          
           
          }
          
          else if(capital_sign ==0 || numerical_sign ==0)
          {
           if(output[k] == 1)
           {
            digitalWrite(k+2, HIGH);
            k++;
           }
           else
           {
            digitalWrite(k+2, LOW);
            k++;
           } 
           }

           else if( numerical_sign == 1)
          {
            digitalWrite(2, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
           
       
            k=0;
            numerical_sign=0;
          }
          
        }
        delay(2000); 
        break;
      }
    }
  }
}
