#include <Adafruit_NeoPixel.h>
#include <TimerOne.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            8

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      88

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int Resetpin =A5; // Digital pin for reset button
int StartStopPin = A4; //Digital pin for  
int pushbutton=0;
int State =0; // Inital state of the Start/Spot button
int lastState=0;

volatile int num =0;
volatile int watch =0;

int d;
int segment =d*21;

int r=119; // RGB values
int g=21;
int b=106;
void setup() 
{
  pixels.begin(); // This initializes the NeoPixel library.
  Timer1.initialize(10000);         // initialize timer1
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}

void Blank()
{
  for(int i=0;i<21;i++)
  {
    pixels.setPixelColor(i+segment,0,0,0); // Moderately bright green color.
  }
}
void One()
{
pixels.setPixelColor(3+segment,r,g,b); //Segment B
pixels.setPixelColor(4+segment,r,g,b); //Segment B
pixels.setPixelColor(5+segment,r,g,b); //Segment B
pixels.setPixelColor(6+segment,r,g,b); //Segment C
pixels.setPixelColor(7+segment,r,g,b); //Segment C
pixels.setPixelColor(8+segment,r,g,b); //Segment C
}
void Two()
{
pixels.setPixelColor(0+segment,r,g,b); //Segment A
pixels.setPixelColor(1+segment,r,g,b); //Segment A
pixels.setPixelColor(2+segment,r,g,b); //Segment A
pixels.setPixelColor(3+segment,r,g,b); //Segment B
pixels.setPixelColor(4+segment,r,g,b); //Segment B
pixels.setPixelColor(5+segment,r,g,b); //Segment B
pixels.setPixelColor(9+segment,r,g,b); //Segment D
pixels.setPixelColor(10+segment,r,g,b); //Segment D
pixels.setPixelColor(11+segment,r,g,b); //Segment D
pixels.setPixelColor(12+segment,r,g,b); //Segment E
pixels.setPixelColor(13+segment,r,g,b); //Segment E
pixels.setPixelColor(14+segment,r,g,b); //Segment E
pixels.setPixelColor(18+segment,r,g,b); //Segment G
pixels.setPixelColor(19+segment,r,g,b); //Segment G
pixels.setPixelColor(20+segment,r,g,b); //Segment G
}
void Three()
{
pixels.setPixelColor(0+segment,r,g,b); //Segment A
pixels.setPixelColor(1+segment,r,g,b); //Segment A
pixels.setPixelColor(2+segment,r,g,b); //Segment A
pixels.setPixelColor(3+segment,r,g,b); //Segment B
pixels.setPixelColor(4+segment,r,g,b); //Segment B
pixels.setPixelColor(5+segment,r,g,b); //Segment B
pixels.setPixelColor(6+segment,r,g,b); //Segment C
pixels.setPixelColor(7+segment,r,g,b); //Segment C
pixels.setPixelColor(8+segment,r,g,b); //Segment C
pixels.setPixelColor(9+segment,r,g,b); //Segment D
pixels.setPixelColor(10+segment,r,g,b); //Segment D
pixels.setPixelColor(11+segment,r,g,b); //Segment D
pixels.setPixelColor(18+segment,r,g,b); //Segment G
pixels.setPixelColor(19+segment,r,g,b); //Segment G
pixels.setPixelColor(20+segment,r,g,b); //Segment G
}

void Four()
{
pixels.setPixelColor(3+segment,r,g,b); //Segment B
pixels.setPixelColor(4+segment,r,g,b); //Segment B
pixels.setPixelColor(5+segment,r,g,b); //Segment B
pixels.setPixelColor(6+segment,r,g,b); //Segment C
pixels.setPixelColor(7+segment,r,g,b); //Segment C
pixels.setPixelColor(8+segment,r,g,b); //Segment C
pixels.setPixelColor(15+segment,r,g,b); //Segment F
pixels.setPixelColor(16+segment,r,g,b); //Segment F
pixels.setPixelColor(17+segment,r,g,b); //Segment F
pixels.setPixelColor(18+segment,r,g,b); //Segment G
pixels.setPixelColor(19+segment,r,g,b); //Segment G
pixels.setPixelColor(20+segment,r,g,b); //Segment G
}

void Five()
{
pixels.setPixelColor(0+segment,r,g,b); //Segment A
pixels.setPixelColor(1+segment,r,g,b); //Segment A
pixels.setPixelColor(2+segment,r,g,b); //Segment A
pixels.setPixelColor(6+segment,r,g,b); //Segment C
pixels.setPixelColor(7+segment,r,g,b); //Segment C
pixels.setPixelColor(8+segment,r,g,b); //Segment C
pixels.setPixelColor(9+segment,r,g,b); //Segment D
pixels.setPixelColor(10+segment,r,g,b); //Segment D
pixels.setPixelColor(11+segment,r,g,b); //Segment D
pixels.setPixelColor(15+segment,r,g,b); //Segment F
pixels.setPixelColor(16+segment,r,g,b); //Segment F
pixels.setPixelColor(17+segment,r,g,b); //Segment F
pixels.setPixelColor(18+segment,r,g,b); //Segment G
pixels.setPixelColor(19+segment,r,g,b); //Segment G
pixels.setPixelColor(20+segment,r,g,b); //Segment G
}
void Six()
{
pixels.setPixelColor(0+segment,r,g,b); //Segment A
pixels.setPixelColor(1+segment,r,g,b); //Segment A
pixels.setPixelColor(2+segment,r,g,b); //Segment A
pixels.setPixelColor(6+segment,r,g,b); //Segment C
pixels.setPixelColor(7+segment,r,g,b); //Segment C
pixels.setPixelColor(8+segment,r,g,b); //Segment C
pixels.setPixelColor(9+segment,r,g,b); //Segment D
pixels.setPixelColor(10+segment,r,g,b); //Segment D
pixels.setPixelColor(11+segment,r,g,b); //Segment D
pixels.setPixelColor(12+segment,r,g,b); //Segment E
pixels.setPixelColor(13+segment,r,g,b); //Segment E
pixels.setPixelColor(14+segment,r,g,b); //Segment E
pixels.setPixelColor(15+segment,r,g,b); //Segment F
pixels.setPixelColor(16+segment,r,g,b); //Segment F
pixels.setPixelColor(17+segment,r,g,b); //Segment F
pixels.setPixelColor(18+segment,r,g,b); //Segment G
pixels.setPixelColor(19+segment,r,g,b); //Segment G
pixels.setPixelColor(20+segment,r,g,b); //Segment G
}
void Seven()
{
pixels.setPixelColor(0+segment,r,g,b); //Segment A
pixels.setPixelColor(1+segment,r,g,b); //Segment A
pixels.setPixelColor(2+segment,r,g,b); //Segment A
pixels.setPixelColor(3+segment,r,g,b); //Segment B
pixels.setPixelColor(4+segment,r,g,b); //Segment B
pixels.setPixelColor(5+segment,r,g,b); //Segment B
pixels.setPixelColor(6+segment,r,g,b); //Segment C
pixels.setPixelColor(7+segment,r,g,b); //Segment C
pixels.setPixelColor(8+segment,r,g,b); //Segment C
}

void Eight()
{
pixels.setPixelColor(0+segment,r,g,b); //Segment A
pixels.setPixelColor(1+segment,r,g,b); //Segment A
pixels.setPixelColor(2+segment,r,g,b); //Segment A
pixels.setPixelColor(3+segment,r,g,b); //Segment B
pixels.setPixelColor(4+segment,r,g,b); //Segment B
pixels.setPixelColor(5+segment,r,g,b); //Segment B
pixels.setPixelColor(6+segment,r,g,b); //Segment C
pixels.setPixelColor(7+segment,r,g,b); //Segment C
pixels.setPixelColor(8+segment,r,g,b); //Segment C
pixels.setPixelColor(9+segment,r,g,b); //Segment D
pixels.setPixelColor(10+segment,r,g,b); //Segment D
pixels.setPixelColor(11+segment,r,g,b); //Segment D
pixels.setPixelColor(12+segment,r,g,b); //Segment E
pixels.setPixelColor(13+segment,r,g,b); //Segment E
pixels.setPixelColor(14+segment,r,g,b); //Segment E
pixels.setPixelColor(15+segment,r,g,b); //Segment F
pixels.setPixelColor(16+segment,r,g,b); //Segment F
pixels.setPixelColor(17+segment,r,g,b); //Segment F
pixels.setPixelColor(18+segment,r,g,b); //Segment G
pixels.setPixelColor(19+segment,r,g,b); //Segment G
pixels.setPixelColor(20+segment,r,g,b); //Segment G
}

void Nine()
{
pixels.setPixelColor(0+segment,r,g,b); //Segment A
pixels.setPixelColor(1+segment,r,g,b); //Segment A
pixels.setPixelColor(2+segment,r,g,b); //Segment A
pixels.setPixelColor(3+segment,r,g,b); //Segment B
pixels.setPixelColor(4+segment,r,g,b); //Segment B
pixels.setPixelColor(5+segment,r,g,b); //Segment B
pixels.setPixelColor(6+segment,r,g,b); //Segment C
pixels.setPixelColor(7+segment,r,g,b); //Segment C
pixels.setPixelColor(8+segment,r,g,b); //Segment C
pixels.setPixelColor(15+segment,r,g,b); //Segment F
pixels.setPixelColor(16+segment,r,g,b); //Segment F
pixels.setPixelColor(17+segment,r,g,b); //Segment F
pixels.setPixelColor(18+segment,r,g,b); //Segment G
pixels.setPixelColor(19+segment,r,g,b); //Segment G
pixels.setPixelColor(20+segment,r,g,b); //Segment G
}

void Zero()
{
pixels.setPixelColor(0+segment,r,g,b); //Segment A
pixels.setPixelColor(1+segment,r,g,b); //Segment A
pixels.setPixelColor(2+segment,r,g,b); //Segment A
pixels.setPixelColor(3+segment,r,g,b); //Segment B
pixels.setPixelColor(4+segment,r,g,b); //Segment B
pixels.setPixelColor(5+segment,r,g,b); //Segment B
pixels.setPixelColor(6+segment,r,g,b); //Segment C
pixels.setPixelColor(7+segment,r,g,b); //Segment C
pixels.setPixelColor(8+segment,r,g,b); //Segment C
pixels.setPixelColor(9+segment,r,g,b); //Segment D
pixels.setPixelColor(10+segment,r,g,b); //Segment D
pixels.setPixelColor(11+segment,r,g,b); //Segment D
pixels.setPixelColor(12+segment,r,g,b); //Segment E
pixels.setPixelColor(13+segment,r,g,b); //Segment E
pixels.setPixelColor(14+segment,r,g,b); //Segment E
pixels.setPixelColor(15+segment,r,g,b); //Segment F
pixels.setPixelColor(16+segment,r,g,b); //Segment F
pixels.setPixelColor(17+segment,r,g,b); //Segment F
}

void Picknumber (int x) // Cycles around 0,1,2,3,4,5,6,7,8 and 9
{
  switch(x)
  {
  default:
  Zero();
  break;
  case 1: 
  One();
  break;
  case 2: 
  Two();
  break;
  case 3:
  Three();
  break;
  case 4:
  Four();
  break;
  case 5:
  Five();
  break; 
  case 6:
  Six();
  break;
  case 7:
  Seven();
  break;
  case 8:
  Eight();
  break;
  case 9:
  Nine();
  break;
  }
}

void callback()
{
 {
State=digitalRead(A4); // Reads inputy of start stop button

if (State !=lastState) // if button is pressed and has a value >0
{ 
  if (State == LOW) 
  {
    pushbutton++; // Increase the amount of times pushed
   }
}
lastState = State; // reset the amount of times pushed
 }
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

void loop() {
  //decimal
    pixels.setPixelColor(84, pixels.Color(r,g,b)); 
    pixels.setPixelColor(87, pixels.Color(r,g,b)); 
  
  d=0;
  segment =d*21;
  Blank();
  Picknumber((watch/1000)); /// 4th segment 1000ths and counts
   
  d=1;
  segment =d*21;
  Blank();
  Picknumber((watch%1000)/100); /// 3th segment 100ths
  
  d=2;
  segment =d*21;
  Blank();
  Picknumber((watch%100)/10); /// 2nd segment 10ths

  d=3;
  segment =d*21;
  Blank();
  Picknumber((watch%10)); /// 1st segment 1000ths
  pixels.show(); // This sends the updated pixel color to the hardware.mamk
}