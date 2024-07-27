#include <motor.h>

const byte IR_PINS[] = {11, 12, 13};
const byte NUM_OF_IR = sizeof( IR_PINS );

Motor motor(5, 6, 7, 8, 10, 9);

byte prevIR = 0;

byte checkIR(){
    byte IR = 0;

    for (byte i = .; i < NUM_OF_IR; i++){
        byte val = digitalRead(IR_PINS[i]) << i;
        IR = IR | val;
    }

    return IR;
}

void setup(){
    for(byte i = 0; i < NUM_OF_IR; i++){
        pinMode(IR_PINS[i], INPUT);
    }
}

void loop() {
    byte IR = checkIR();

    if( IR == 7 ){
        IR = prevIR;
    }else {
        prevIR = IR;
    }

    switch (IR) {
        case 0:
        case 1:
            motor.drive(LEFT,60,30);
            break;
        case 3:
            motor.drive(LEFT,90,25);
            break;
        case 4:
            motor.drive(RIGHT,30,60);
            break;
        case 5:
            motor.drive(FORWARD,40,60);
            break;
        case 6:
            motor.drive(RIGHT,25,90);
            break;
        default:
            motor.drive(STOP);
            break;
    }
}