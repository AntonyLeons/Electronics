#include <TimerOne.h>
#include <StivSeg.h>
int Resetpin =A5; // Digital pin for reset button
int StartStopPin = A4; //Digital pin for  
int pushbutton=0;
int State =0; // Inital state of the Start/Spot button
int lastState=0;
volatile int num =0;
volatile int watch =0;
int numDigits = 4;
int digitPins[4] = {2, 3, 4, 5};
int segPins[8] = {11, 13, 7, 10, 9, 12, 6, 8}; //A-G and DP
bool isComCathode = true;
StivSeg disp(4, digitPins, segPins, isComCathode);
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(Resetpin, INPUT);
  pinMode(StartStopPin, INPUT);
  Timer1.initialize(10000);         // initialize timer1
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}
 
void callback()
{
  
State=digitalRead(A4); // Reads inputy of start stop button

if (State !=lastState) // if button is pressed and has a value >0
{ 
  if (State == LOW) // if state is high
  {
    pushbutton++; // Increase the amount of times pushed
   }
}
lastState = State; // reset the amount of times pushed
 
 if (pushbutton %2 !=1) // fiqures out what state the button is in
 {
    if(num<6000)
    {
    num++;
    watch=num;
    }
    else
  {               ///reset at 60
    num=0;
    watch=num;
  }
 }
   if(digitalRead(A5)== LOW) /// reset button
  {
     num=0;
    watch=num;
  }
}
 
void loop()
{
  disp.writeInt(watch);
}