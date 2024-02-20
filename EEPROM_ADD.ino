#include <EEPROM.h>
void setup()
{
  Serial.begin(9600);
  Serial.println("value of a ");
 
int  a=EEPROM.read(0);
  Serial.println(a);

  Serial.println("enter the value of b");
  delay(2000);
 int b=Serial.parseInt();
  Serial.println(b);

 int x=a+b;
  Serial.println(x);
  
  }

 void loop ()
 {}
 
