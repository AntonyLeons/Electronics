#include <Adafruit_NeoPixel.h>
#include <TimerOne.h>
#include <Wire.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            8

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      88

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int c;
int pos=0;
bool paused = false;

volatile long num = 0;
volatile long tseconds = 0;
volatile int hours = 0;
volatile int minutes = 0;
volatile int seconds = 0;
volatile int watch = 0;

int segment;

int r = 119; // RGB values
int g = 21;
int b = 106;
void setup()
{
  pixels.begin(); // This initializes the NeoPixel library.
  Timer1.initialize(10000);         // initialize timer1
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveIR); // register event
  Serial.begin(9600);
}

void receiveIR()
{
  c = Wire.read();
  switch (c)
  {
    case 93:
      num = 0;
      watch = num;
      dnum();
      break;
    case 253:
      if (paused == false)
      {
        Timer1.detachInterrupt();
        paused = true;
      }
      else {
        Timer1.attachInterrupt(callback);
        paused = false;
      }
      break;
    case 29:
      pos++;
      Serial.print(pos);
      Serial.print(".");
      if (hours < 10)
      {
        Serial.print("0");
      }
      Serial.print(hours);
      Serial.print(":");
      if (minutes < 10)
      {
        Serial.print("0");
      }
      Serial.print(minutes);
      Serial.print(".");
      if (seconds < 10)
      {
        Serial.print("0");
      }
      Serial.println(seconds);
      break;
    case 151: //off
      r = 0;
      g = 0;
      b = 0;
      pixels.show();
      break;
    case 207: //red
      r = 255;
      g = 0;
      b = 0;
      pixels.show();
      break;
    case 231: //green
      r = 0;
      g = 255;
      b = 0;
      pixels.show();
      break;
    case 133: //blue
      r = 0;
      g = 0;
      b = 255;
      pixels.show();
      break;
    case 239: //purple
      r = 119;
      g = 21;
      b = 106;
      pixels.show();
      break;
    case 199: //white
      r = 255;
      g = 255;
      b = 255;
      pixels.show();
      break;
    case 165: //cyan
      r = 0;
      g = 255;
      b = 255;
      pixels.show();
      break;
    case 79:
      r = rand() % 256;
      g = rand() % 256;
      b = rand() % 256;
      pixels.show();
      break;
    default:
      r = rand() % 256;
      g = rand() % 256;
      b = rand() % 256;
      pixels.show();
      break;
  }
}
void callback()
{
  num++;
  tseconds = num / 100;
  seconds = (tseconds % 60);
  minutes = (tseconds / 60) % 60;
  hours = tseconds / 3600;
  if (num < 6000)
  {
    watch = num;
    dnum();
  }
  if (minutes > 0 && hours == 0)
  {
    dmin();
  }
  if (hours > 0)
  {
    dhours();
    Serial.println(minutes);
  }
}
void dnum()
{
  pixels.clear();
  //decimal
  pixels.setPixelColor(84, pixels.Color(r, g, b));
  pixels.setPixelColor(87, pixels.Color(r, g, b));

  segment = 0;
  Picknumber((watch / 1000));

  segment = 21;
  Picknumber((watch % 1000) / 100);

  segment = 42;
  Picknumber((watch % 100) / 10);

  segment = 63;
  Picknumber((watch % 10));
  pixels.show();
}
void dmin()
{
  pixels.clear();
  //decimal
  pixels.setPixelColor(84, pixels.Color(r, g, b));
  pixels.setPixelColor(87, pixels.Color(r, g, b));

  segment = 0;
  Picknumber((minutes % 100 / 10));

  segment = 21;
  Picknumber((minutes % 10));

  segment = 42;
  Picknumber((seconds % 100) / 10);

  segment = 63;
  Picknumber((seconds % 10));
  pixels.show();
}
void dhours()
{
  pixels.clear();
  //decimal
  pixels.setPixelColor(84, pixels.Color(r, g, b));
  pixels.setPixelColor(87, pixels.Color(r, g, b));

  segment = 0;
  Picknumber((hours % 100 / 10));

  segment = 21;
  Picknumber((hours % 10));

  segment = 42;
  Picknumber((minutes % 100) / 10);

  segment = 63;
  Picknumber((minutes % 10));
  pixels.show();
}
void SegmentA()
{
  pixels.setPixelColor(0 + segment, r, g, b);
  pixels.setPixelColor(1 + segment, r, g, b);
  pixels.setPixelColor(2 + segment, r, g, b);
}
void SegmentB()
{
  pixels.setPixelColor(3 + segment, r, g, b);
  pixels.setPixelColor(4 + segment, r, g, b);
  pixels.setPixelColor(5 + segment, r, g, b);
}
void SegmentC()
{
  pixels.setPixelColor(6 + segment, r, g, b);
  pixels.setPixelColor(7 + segment, r, g, b);
  pixels.setPixelColor(8 + segment, r, g, b);
}
void SegmentD()
{
  pixels.setPixelColor(9 + segment, r, g, b);
  pixels.setPixelColor(10 + segment, r, g, b);
  pixels.setPixelColor(11 + segment, r, g, b);
}
void SegmentE()
{
  pixels.setPixelColor(12 + segment, r, g, b);
  pixels.setPixelColor(13 + segment, r, g, b);
  pixels.setPixelColor(14 + segment, r, g, b);
}
void SegmentF()
{
  pixels.setPixelColor(15 + segment, r, g, b);
  pixels.setPixelColor(16 + segment, r, g, b);
  pixels.setPixelColor(17 + segment, r, g, b);
}
void SegmentG()
{
  pixels.setPixelColor(18 + segment, r, g, b);
  pixels.setPixelColor(19 + segment, r, g, b);
  pixels.setPixelColor(20 + segment, r, g, b);
}
void One()
{
  SegmentB();
  SegmentC();
}
void Two()
{
  SegmentA();
  SegmentB();
  SegmentD();
  SegmentE();
  SegmentG();
}
void Three()
{
  SegmentA();
  SegmentB();
  SegmentC();
  SegmentD();
  SegmentG();
}
void Four()
{
  SegmentB();
  SegmentC();
  SegmentF();
  SegmentG();
}
void Five()
{
  SegmentA();
  SegmentC();
  SegmentD();
  SegmentF();
  SegmentG();
}
void Six()
{
  SegmentA();
  SegmentC();
  SegmentD();
  SegmentE();
  SegmentF();
  SegmentG();
}
void Seven()
{
  SegmentA();
  SegmentB();
  SegmentC();
}
void Eight()
{
  SegmentA();
  SegmentB();
  SegmentC();
  SegmentD();
  SegmentE();
  SegmentF();
  SegmentG();
}
void Nine()
{
  SegmentA();
  SegmentB();
  SegmentC();
  SegmentF();
  SegmentG();
}
void Zero()
{
  SegmentA();
  SegmentB();
  SegmentC();
  SegmentD();
  SegmentE();
  SegmentF();
}
void Picknumber (int x) // Cycles around 0,1,2,3,4,5,6,7,8 and 9
{
  switch (x)
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
void loop() {

}