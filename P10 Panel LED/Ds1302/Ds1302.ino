#include <virtuabotixRTC.h>   
virtuabotixRTC myRTC(A2, A3, A4); // CLK, DAT, RST
String dayOfTheWeek = "   ";
int x =0;
void setup()  
{      
  Serial.begin(9600);
  //myRTC.setDS1302Time(0, 33, 0, 3, 10, 3, 2020);// seconds, minutes, hours, day of the week, day of the month, month, year
}

void loop()  
{                                                    
  myRTC.updateTime();                                                                                    
  Serial.print("Current Date / Time: ");                                                                 
  Serial.print(myRTC.dayofmonth);                                                                        
  Serial.print("/");                                                                                     
  Serial.print(myRTC.month);                                                                             
  Serial.print("/");                                                                                    
  Serial.print(myRTC.year);                                                                              
  Serial.print("  ");                                                                                   
  Serial.print(myRTC.hours);                                                                            
  Serial.print(":");                                                                                    
  Serial.print(myRTC.minutes);                                                                           
  Serial.print(":");                                                                                     
  Serial.println(myRTC.seconds);   
  int x = myRTC.dayofweek;                                      

      switch (x) 
      {
      case 1:
             dayOfTheWeek = "SUN";
        break;
      case 2:
             dayOfTheWeek = "MON";
        break;
      case 3:
             dayOfTheWeek = "TUE";
        break;
      case 4:
             dayOfTheWeek = "WED";
        break;
      case 5:
             dayOfTheWeek = "THU";
        break;
      case 6:
             dayOfTheWeek = "FRI";
        break;
      case 7:
             dayOfTheWeek = "SAT";
        break;
      default:
        Serial.println(" ");       
       }
        Serial.println(dayOfTheWeek);     
        delay(1000);                                                                       
}                                                                                                         
  
