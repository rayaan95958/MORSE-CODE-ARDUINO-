//IMPLIMENTATION IN ARDUINO

int out[100];
int j=0;

void setup()
{
    Serial.begin(9600);
    pinMode(2,OUTPUT);
    input();
    blink();
}

void loop() 
{
}

void input()
{
   Serial.println("Please enter your string: ");

  // Loop which waits for user to enter string in Serial Monitor
  while (Serial.available() == 0) {}

  String a = Serial.readString();
  a.trim();
  Serial.println(a);
  char buf[100];
  a.toCharArray(buf,a.length());
  converter(buf);   
}

 int morse(char ch)                      //Returns morse of the letter.
{  int arr[]={12,2111,2121,211,1,1121,221,1111,11,1222,212,1211,22,21,222,1221,2212,121,111,2,112,1112,122,2112,2122,2211};
   int n=(toUpperCase(ch))-65;
   return arr[n];
}

 int converter(char a[100]) //Converts string to number formatted morse.
{

    for (int i=0;i<strlen(a);i++)
    {
        if(a[i]==' ')
        {
            out[j]=4;
            j++;
        }
        else
        {
            out[j]=morse(a[i]);
            j++;
            out[j]=3;
            j++;
        }
    }
    
     for(int k=0; k<(j-1);k++)      //Displays the converted string.
    {
        Serial.print(out[k]);
    }
}

void blink()
{
      for(int i=0;i<(j-1);i++)
    {

 //Ex: 1122 TO 1,1,2,2, CONVERTER .SINCE IT IS PASSED THAT WAY.
 int ret=1;
 int num=out[i];
 while (out[i]/=10) 
 ret++;
 int dig=ret;
 int arr[dig];
 while (dig--) 
 {
 arr[dig]=num%10;
 num/=10;
 }

 for (int i=0;i<ret;i++)
   {
      if(arr[i]==1)
       {
        digitalWrite(2,HIGH);
        delay(500);
        digitalWrite(2,LOW);
        delay(1000);
       }
      else if(arr[i]==2)
       {
        digitalWrite(2,HIGH);
        delay(2000);
        digitalWrite(2,LOW);
        delay(1000);
       }
      else if(arr[i]==3)
      {
        delay(2000);
      }
      else if(arr[i]==4)
      {
        if(arr[i-1]==3)
        delay(4000);
        else
        delay(6000);
      }
    }
  }
}