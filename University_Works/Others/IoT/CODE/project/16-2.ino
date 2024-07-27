#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN A0
#define SS_PIN 10
#define SERVO_PIN 2

bool lockerSwitch = false;
Servo servo;

typedef struct data{
    byte uid[4];
    char *name;
} RFIDTag;

RFIDTag tags[] = {
    {{60,209,110,133},"Arduino"},
    {{212,211,192,97},"Raspberry Pi"},
    {{21,8,10,83},"Espruino"}
};

byte totalTags = sizeof(tags) / sizeof(RFIDTag);

MFRC522 mfrc522(SS_PIN,RST_PIN);

void locker(bool toggle){
    if(toggle){
        servo.write(90);
    } else {
        servo.write(0);
    }
    delay(15);
}

void setup(){
    Serial.begin(9600);
    Serial.println();
    Serial.print("size of RFIDTag:");
    Serial.println(sizeof(RFIDTag));
    Serial.print("size of tag:");
    Serial.println(sizeof(tags));
    Serial.println("RFID reader is ready");

    SPI.begin();
    mfrc522.PCD_Init();
    servo.attach(SERVO_PIN);
    locker(lockerSwitch);

}


void loop(){
    if(mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()){
        byte *id = mfrc522.uid.uidByte;
        byte idSize = mfrc522.uid.size;
        bool foundTag = false;

        for(byte i = 0; i< totalTags; i++){
            if(memcmp(tags[i].uid, id, idSize)==0){
                Serial.println(tags[i].name);
                foundTag = true;
                lockerSwitch = ! lockerSwitch;
                locker(lockerSwitch);
                break;
            }
        }

        if(!foundTag){
            Serial.println("Wrong card!");

            if(lockerSwitch){
                lockerSwitch = false;
                locker(lockerSwitch);
            }
        }

        mfrc522.PICC_HaltA();
    }

}









