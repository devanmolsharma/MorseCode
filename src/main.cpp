#include <Arduino.h>

struct Digit
{
  char digit;
  int delays[6];
};

Digit morseCodes[] = {
    {'A', {1, 3}},
    {'B', {3, 1, 1, 1}},
    {'C', {3, 1, 3, 1}},
    {'D', {3, 1, 1}},
    {'E', {1}},
    {'F', {1, 1, 3, 1}},
    {'G', {3, 3, 1}},
    {'H', {1, 1, 1, 1}},
    {'I', {1, 1}},
    {'J', {1, 3, 3, 3}},
    {'K', {3, 1, 3}},
    {'L', {1, 3, 1, 1}},
    {'M', {3, 3}},
    {'N', {3, 1}},
    {'O', {3, 3, 3}},
    {'P', {1, 3, 3, 1}},
    {'Q', {3, 3, 1, 3}},
    {'R', {1, 3, 1}},
    {'S', {1, 1, 1}},
    {'T', {3}},
    {'U', {1, 1, 3}},
    {'V', {1, 1, 1, 3}},
    {'W', {1, 3, 3}},
    {'X', {3, 1, 1, 3}},
    {'Y', {3, 1, 3, 3}},
    {'Z', {3, 3, 1, 1}},
    {'0', {3, 3, 3, 3, 3}},
    {'1', {1, 3, 3, 3, 3}},
    {'2', {1, 1, 3, 3, 3}},
    {'3', {1, 1, 1, 3, 3}},
    {'4', {1, 1, 1, 1, 3}},
    {'5', {1, 1, 1, 1, 1}},
    {'6', {3, 1, 1, 1, 1}},
    {'7', {3, 3, 1, 1, 1}},
    {'8', {3, 3, 3, 1, 1}},
    {'9', {3, 3, 3, 3, 1}},
    {',', {1, 3, 1, 3, 1, 3}},
    {'.', {3, 3, 1, 1, 3, 3}},
    {'?', {1, 1, 3, 3, 1, 1}},
    {'!', {3, 1, 3, 1, 3, 3}}};

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  Serial.print("What to convert to mourse code?\n");
}

void showCode(char c)
{
  for (Digit d : morseCodes)
  {
    if (d.digit == c)
    {
      for (int i = 0; i < 6; i++)
      {
        int delayTime = d.delays[i];
        if (delayTime == 0)
        {
          break;
        }
        digitalWrite(4, HIGH);
        delay(delayTime * 1000);
        digitalWrite(4, LOW);
        delay(200);
      }
    }
  }
}

void loop()
{
  if (Serial.available() > 0)
  {
    delay(3000);
    String digits = Serial.readString();
    Serial.print("Converting: ");
    Serial.println(digits);

    for (char d : digits)
    {
      showCode(d);
      delay(1000);
    }
    Serial.print("What to convert to mourse code?\n");
  }
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}