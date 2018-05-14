//-------------------------------------------------------
// Arduino Uno board
// Peeper on pin 4, PIR Sensor on Pin 7
// two 8x8 LED matrix with MAX7219 on Pin 12,10,11 for DIN,CLK,CS
// LedCOntrol Library hafe to be installed
//-------------------------------------------------------

#include "LedControl.h"

#define SUMMER 4    // Pin for Summer Output
#define SENSOR 7    // PIR pin Input
#define DELAY 500   // not in use...

LedControl lc = LedControl(12, 10, 11, 2); // Pins: DIN,CLK,CS, # of Display connected

// Put values in arrays
byte arrNull[] =
{
  B00111100, // 0
  B01111110,
  B01100110,
  B01101110,
  B01110110,
  B01100110,
  B01111110,
  B00111100

};

byte arrEins[] =
{
  B00011000,
  B00111000,
  B01111000,
  B00011000,
  B00011000,
  B00011000,
  B01111110,
  B01111110
};

byte arrZwei[] =
{
  B01111100,
  B01111110,
  B00000110,
  B00111110,
  B01111100,
  B01100000,
  B01111110,
  B01111110
};

byte arrDrei[] =
{
  B01111100,
  B01111110,
  B00000110,
  B00111110,
  B00111110,
  B00000110,
  B01111110,
  B01111100
};

byte arrVier[] =
{
  B01100110,
  B01100110,
  B01100110,
  B01111110,
  B01111110,
  B00000110,
  B00000110,
  B00000110
};

byte arrFuenf[] =
{
  B01111110,
  B01111110,
  B01100000,
  B01111100,
  B01111110,
  B00000110,
  B01111110,
  B01111100
};

byte arrSechs[] =
{
  B00111100,
  B01111110,
  B01100000,
  B01111100,
  B01111110,
  B01100110,
  B01111110,
  B00111100
};

byte arrSieben[] =
{
  B01111110,
  B01111110,
  B00000110,
  B00001110,
  B00001100,
  B00011100,
  B00011000,
  B00011000
};

byte arrAcht[] =
{
  B00111100,
  B01111110,
  B01100110,
  B00111100,
  B00111100,
  B01100110,
  B01111110,
  B00111100
};

byte arrNeun[] =
{
  B00111100,
  B01111110,
  B01100110,
  B01111110,
  B00111110,
  B00000110,
  B00000110,
  B00000110
};

void setup() {

  pinMode(SUMMER, OUTPUT); // PinMode for sound, digital on/off

  pinMode(SENSOR, INPUT); // PinMode for PIR SENSOR, digital on/off

  lc.shutdown(0, false); // Wake up displays
  lc.shutdown(1, false);
  lc.setIntensity(0, 5); // Set intensity levels, 0 is low, 15 high
  lc.setIntensity(1, 5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);

}
int score = 0;
bool checkDone = LOW;

void loop() {
  // put your main code here, to run repeatedly:
//  int score = 0;    // initalisierun der variablen evtl. vor die setup routine ?
//  bool pirState = false;
  val = digitalRead(SENSOR);  // read input value

  if (val == HIGH) {            // check if the input is HIGH
    if (checkDone == LOW) {
      Peep;   // Ton
      score++;
      showNum(score);   // show score
      checkDone = HIGH;
    }
  } else {
    if (checkDone == HIGH){
      checkDone = LOW;
    }
  }
  if (score >= 99)
  {
    score = 0;
  }
}

void peep() {
  // just a melodie for the peeper. Low active Peeper
  digitalWrite(SUMMER, LOW);
  delay(100);
  digitalWrite(SUMMER, HIGH);
  delay(50);
  digitalWrite(SUMMER, LOW);
  delay(100);
  digitalWrite(SUMMER, HIGH);
  delay(50);
  digitalWrite(SUMMER, LOW);
  delay(200);
  digitalWrite(SUMMER, HIGH);
  delay(100);

}

void showNum(int number)
{
  if (number < 10)
  {
    show(1, arrNull);
  }
  else if (number < 20)
  {
    show(1, arrEins);
  }
  else if (number < 30)
  {
    show(1, arrZwei);
  }
  else if (number < 40)
  {
    show(1, arrDrei);
  }
  else if (number < 50)
  {
    show(1, arrVier);
  }
  else if (number < 60)
  {
    show(1, arrFuenf);
  }
  else if (number < 70)
  {
    show(1, arrSechs);
  }
  else if (number < 80)
  {
    show(1, arrSieben);
  }
  else if (number < 90)
  {
    show(1, arrAcht);
  }
  else if (number < 100)
  {
    show(1, arrNeun);
  };

  int lowNum = number % 10;

  if (lowNum < 1)
  {
    show(0, arrNull);
  }
  else if (lowNum < 2)
  {
    show(0, arrEins);
  }
  else if (lowNum < 3)
  {
    show(0, arrZwei);
  }
  else if (lowNum < 4)
  {
    show(0, arrDrei);
  }
  else if (lowNum < 5)
  {
    show(0, arrVier);
  }
  else if (lowNum < 6)
  {
    show(0, arrFuenf);
  }
  else if (lowNum < 7)
  {
    show(0, arrSechs);
  }
  else if (lowNum < 8)
  {
    show(0, arrSieben);
  }
  else if (lowNum < 9)
  {
    show(0, arrAcht);
  }
  else if (lowNum < 10)
  {
    show(0, arrNeun);
  }

}
//  Take values in Arrays and Display them
void show(int pos, byte picture[])
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(pos, i, picture[i]);
  }
}
// ---------------------------------- old code ----------------
/*  Adafruit Methode

int score = 0;
int pirState = LOW;
int val = 0;

void loop(){
  val = digitalRead(inputPin);  // read input value

  if (val == HIGH) {            // check if the input is HIGH
    if (pirState == LOW) {
          score++
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH){
      pirState = LOW;
    }
  }
}

 */

/* My Methode

while(true){
  if(digitalRead(SENSOR) == HIGH & checkDone == LOW) // reading the data from the pir sensor
    {
    checkDone = true
    Peep;   // Ton
    score++;
    showNum(score);   // punkte anzeigen
    }

    else if (digitalRead(SENSOR) == LOW & checkDone == true)
    {
      checkDone = false
    }
    if (score >= 99)
    {
      score = 0;
    }
  }

 */
