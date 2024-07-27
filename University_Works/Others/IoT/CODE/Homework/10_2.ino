byte ledPin = 11;

void setup(){
    pinMode(ledPin, OUTPUT);
    randomSeed(analogRead(A5));
}

void loop(){
    analogWrite(ledPin, random(135)+120);
    delay(random(200));
}