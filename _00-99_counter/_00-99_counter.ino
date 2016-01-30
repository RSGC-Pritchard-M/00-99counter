//Counts from 00-99 on duel 7 segment display
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;  
int secondData = 9;

byte charMap[] =  {B01111110, B00110000, B01101101, B01111001, B00110011, B01011011, B01011111, B01110000, B01111111, B01110011};
int numElements = sizeof(charMap);

void setup() {
  pinMode(secondData, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
 
}

void loop() {
  for (int f = 0; f < numElements; f++) {
    for (int s = 0; s < numElements; s++) {
      for (int t = 0; t < 50; t++) {
        digitalWrite(secondData, HIGH);
        shiftOut(dataPin, clockPin, MSBFIRST, charMap[s]);
        digitalWrite(latchPin, HIGH);
        digitalWrite(latchPin, LOW);
        delay(5);
        digitalWrite(secondData, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, charMap[f]);
        digitalWrite(latchPin, HIGH);
        digitalWrite(latchPin, LOW);
        delay(5);
      }
    }
  }
}
