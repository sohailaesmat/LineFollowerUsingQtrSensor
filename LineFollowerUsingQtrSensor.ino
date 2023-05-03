/**
 ******************************************************************************
 * @file           : LineFollowerUsingQtrSensor.ino
 * @author         : Sohaila Esmat
 * @brief          : LineFollowerUsingQtrSensor
 ******************************************************************************
 */


#include <QTRSensors.h>
QTRSensors qtr;

const uint8_t SensorCount = 6; // number of sensors (you can change the number of sensors you want to use)
uint16_t sensorValues[SensorCount];

void setup()
{
  delay (500);          //time before implement the program
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5}, SensorCount); // define the pins of QTR sensor and the number of analoge pins
  pinMode(3, OUTPUT);   // define the pins of Left motor leg1
  pinMode(6, OUTPUT);   // define the pins of Left motor leg2
  pinMode(10, OUTPUT);  // define the pins of Right motor leg1
  pinMode(11, OUTPUT);  // define the pins of Right motor leg2
  Serial.begin(9600);   // define Serial monitor
  
}


void loop()
{
  qtr.read(sensorValues); //read QTR sensor values
 
  // this loop for present the values of sensor usinf serial monitor
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    if(sensorValues[i]>=1000) // if the sensor read black
    {
      sensorValues[i]=1;
      Serial.print("B");
    }
    else if(sensorValues[i]<1000) // if the sensor read white
    {
      sensorValues[i]=0;
      Serial.print("W");
    }
    //Serial.print(sensorValues[i]); // if you want to see the values of the sensor remove "//"
    Serial.print('\t');
  }
  Serial.println(); //new line in serial monitor

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Straight Forward
  if(sensorValues[0]==0 && sensorValues[1]==0 && sensorValues[2]==1 && sensorValues[3]==1 && sensorValues[4]==0 && sensorValues[5]==0)
  {
    analogWrite(3,255);
    analogWrite(6,0);
    analogWrite(10,255);
    analogWrite(11,0);
  }
//forward but little bit Left
  else if(sensorValues[0]==0 && sensorValues[1]==0 && sensorValues[2]==0 && sensorValues[3]==1 && sensorValues[4]==0 && sensorValues[5]==0)
  {
    analogWrite(3,240);
    analogWrite(6,0);
    analogWrite(10,255);
    analogWrite(11,0);
  }
  //forward but little bit Right
  else if(sensorValues[0]==0 && sensorValues[1]==0 && sensorValues[2]==1 && sensorValues[3]==0 && sensorValues[4]==0 && sensorValues[5]==0)
  {
    analogWrite(3,255);
    analogWrite(6,0);
    analogWrite(10,240);
    analogWrite(11,0);
  }
  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  //Right with big curve (slow speed)
  else if(sensorValues[0]==0 && sensorValues[1]==0 && sensorValues[2]==0 && sensorValues[3]==1 && sensorValues[4]==1 && sensorValues[5]==0)
  {
    analogWrite(3,255);
    analogWrite(6,0);
    analogWrite(10,180);
    analogWrite(11,0);
  }
  //Right with medium curve (medium speed)
  else if(sensorValues[0]==0 && sensorValues[1]==0 && sensorValues[2]==0 && sensorValues[3]==0 && sensorValues[4]==1 && sensorValues[5]==0)
  {
    analogWrite(3,255);
    analogWrite(6,0);
    analogWrite(10,140);
    analogWrite(11,0);
  }
  //Right with small curve (fast speed)
  else if(sensorValues[0]==0 && sensorValues[1]==0 && sensorValues[2]==0 && sensorValues[3]==0 && sensorValues[4]==1 && sensorValues[5]==1)
  {
    analogWrite(3,255);
    analogWrite(6,0);
    analogWrite(10,30);
    analogWrite(11,0);
  }
  //Reverse Right_1
  else if(sensorValues[0]==0 && sensorValues[1]==0 && sensorValues[2]==1 && sensorValues[3]==1 && sensorValues[4]==1 && sensorValues[5]==1)
  {
    analogWrite(3,255);
    analogWrite(6,0);
    analogWrite(10,0);
    analogWrite(11,150);
  }
  //Reverse Right_2
  else if(sensorValues[0]==0 && sensorValues[1]==0 && sensorValues[2]==0 && sensorValues[3]==1 && sensorValues[4]==1 && sensorValues[5]==1)
  {
    analogWrite(3,255);
    analogWrite(6,0);
    analogWrite(10,0);
    analogWrite(11,150);
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  //Left with big curve (slow speed)
  else if(sensorValues[0]==0 && sensorValues[1]==1 && sensorValues[2]==1 && sensorValues[3]==0 && sensorValues[4]==0 && sensorValues[5]==0)
  {
   
    analogWrite(3,180);
    analogWrite(6,0);
    analogWrite(10,255);
    analogWrite(11,0);
  }
 //Left with medium curve (medium speed)
  else if(sensorValues[0]==0 && sensorValues[1]==1 && sensorValues[2]==0 && sensorValues[3]==0 && sensorValues[4]==0 && sensorValues[5]==0)
  {
   
    analogWrite(3,140);
    analogWrite(6,0);
    analogWrite(10,255);
    analogWrite(11,0);
  }
  //Left with small curve (fast speed)
  else if (sensorValues[0]==1 && sensorValues[1]==1 && sensorValues[2]==1 && sensorValues[3]==0 && sensorValues[4]==0 && sensorValues[5]==0)
  {
    analogWrite(3,30);
    analogWrite(6,0);
    analogWrite(10,255);
    analogWrite(11,0);
  }
  //Reverse Left_1
  else if (sensorValues[0]==1 && sensorValues[1]==1 && sensorValues[2]==0 && sensorValues[3]==0 && sensorValues[4]==0 && sensorValues[5]==0)
  {
    analogWrite(3,0);
    analogWrite(6,150);
    analogWrite(10,255);
    analogWrite(11,0);
  }
  //Reverse Left_2
  else if (sensorValues[0]==1 && sensorValues[1]==1 && sensorValues[2]==1 && sensorValues[3]==0 && sensorValues[4]==0 && sensorValues[5]==0)
  {
    analogWrite(3,0);
    analogWrite(6,150);
    analogWrite(10,255);
    analogWrite(11,0);
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
}
