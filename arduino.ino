#include "SoftwareSerial.h"
SoftwareSerial serial_connection(12, 13);//Create a serial connection with TX and RX on these pins
#define BUFFER_SIZE 64//This will prevent buffer overruns.
#define AI1 5    //motor Right
#define AI2 4
#define PWM_A 10

#define BI1 6
#define BI2 7
#define PWM_B 11//motor left
char inData[BUFFER_SIZE];//This is a character buffer where the data sent by the python script will go.
char inChar=-1;//Initialie the first character as nothing
int count=0;//This is the number of lines sent in from the python script
int i=0;//Arduinos are not the most capable chips in the world so I just create the looping variable once



void setup() {
  // put your setup code here, to run once:
  pinMode(AI2, OUTPUT);
  pinMode(AI1, OUTPUT);
  pinMode(PWM_A, OUTPUT);
  pinMode(BI2, OUTPUT);
  pinMode(BI2, OUTPUT);
  pinMode(PWM_B, OUTPUT);

  Serial.begin(9600);//Initialize communications to the serial monitor in the Arduino IDE
  serial_connection.begin(9600);//Initialize communications with the bluetooth module
  serial_connection.println("Ready!!!");//Send something to just start comms. This will never be seen.
  Serial.println("Started");//Tell the serial monitor that the sketch has started.
}

void leftforward(int speed)
{
  digitalWrite(BI2, HIGH);
  digitalWrite(BI1, LOW);
  analogWrite(PWM_B, speed);
}
void leftbackward(int speed)
{
  digitalWrite(BI2,LOW);
  digitalWrite(BI1,HIGH);
  analogWrite(PWM_B,speed);
}
void rightforward(int speed)
{
  digitalWrite(AI2, HIGH);
  digitalWrite(AI1, LOW);
  analogWrite(PWM_A, speed);
}
void rightbackward(int speed)
{
  digitalWrite(AI2, LOW);
  digitalWrite(AI1, HIGH);
  analogWrite(10, speed);
}

void moveforward()
{
  rightforward(200);
  leftforward(200);  
}
void movebackward()
{
  rightbackward(200);
  leftbackward(200);
}
void rotateleft()
{
  stop_car();
  rightforward(100);
}
void rotateright()
{
  stop_car();
  leftforward(100);
}
void spin()
{
  leftbackward(100);
  rightforward(100);
  delay(4000);
}
void stop_car()
{
  digitalWrite(AI2, LOW);
  digitalWrite(AI1, LOW);
  analogWrite(PWM_A, 0);
  digitalWrite(BI2, LOW);
  digitalWrite(BI1, LOW);
  analogWrite(PWM_B, 0);
}
void loop()
{
  //This will prevent bufferoverrun errors
  byte byte_count=serial_connection.available();//This gets the number of bytes that were sent by the python script
  /*
  if(byte_count)//If there are any bytes then deal with them
  {
    Serial.println("byte_count: " + String(byte_count));
    inChar=serial_connection.read();
    Serial.println(String(inChar));
  }
  */
  if(byte_count)//If there are any bytes then deal with them
  {
    Serial.println("Incoming Data");//Signal to the monitor that something is happening
    int first_bytes=byte_count;//initialize the number of bytes that we might handle. 
    int remaining_bytes=0;//Initialize the bytes that we may have to burn off to prevent a buffer overrun
    if(first_bytes>=BUFFER_SIZE-1)//If the incoming byte count is more than our buffer...
    {
      remaining_bytes=byte_count-(BUFFER_SIZE-1);//Reduce the bytes that we plan on handleing to below the buffer size
    }
    for(i=0;i<first_bytes;i++)//Handle the number of incoming bytes
    {
      inChar=serial_connection.read();//Read one byte
      inData[i]=inChar;//Put it into a character string(array)
    }
    inData[i]='\0';//This ends the character array with a null character. This signals the end of a string
    if(String(inData)=="fwd_1s")
    {
      Serial.println("********* Start Motor Forward for 1 second *********");
      moveforward();
      delay(2000);
      stop_car();
    }
    else if(String(inData)=="left_1s")
    {
      Serial.println("********* Turning left for 1 second *********");
      rotateleft();
      delay(3600);
      stop_car();
    }
    else if(String(inData)=="180deg")
    {
      Serial.println("********* Turning 180 degrees *********");
      rotateleft();
      delay(7200);
      stop_car();
    }
    else if(String(inData)=="fwd_bit")
    {
      Serial.println("********* Start Motor Forward a bit *********");
      moveforward();
      delay(200);
      stop_car();
    }
    else if(String(inData)=="left_bit")
    {
      Serial.println("********* Turning left a bit *********");
      rotateleft();
      delay(180);
      stop_car();
    }
    
    for(i=0;i<remaining_bytes;i++)//This burns off any remaining bytes that the buffer can't handle.
    {
      inChar=serial_connection.read();
    }
    Serial.println(inData);//Print to the monitor what was detected
    serial_connection.println("Hello from Blue "+String(count));//Then send an incrmented string back to the python script
    count++;//Increment the line counter
  }
  delay(100);//Pause for a moment 
}
