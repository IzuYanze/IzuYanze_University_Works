const byte potPin = A0;
const byte ledPin = 11;
int potspeed = 0;
byte val = 0;

void setup(){
    pinMode(ledPin, OUTPUT);
}

void loop(){
    potspeed = analogRead(potPin);
    val = map(potPin, 0, 1023, 0, 255);
    analogWrite(ledPin, val);
}