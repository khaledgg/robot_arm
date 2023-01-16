// See https://github.com/timhendriks93/blender-servo-animation/tree/9dbd7ba8f4b1bdbf2dc24b6be9421516f3150020 
#include <Servo.h> //servo library

Servo baseServo;  // create servo object to control a servo
const int baseServoPin = 3;
int pos = 0;    // variable to store the servo position

String PcCommand; 
String PcAction;
int PcValue;

void setup() {
    baseServo.attach(baseServoPin);  // attaches the servo on pin 3 to the servo object
    Serial.begin(115200);
}

void loop() {
    if (Serial.available()>0){
        PcCommand = Serial.readStringUntil('\n');
        // input data xxx-999
        PcAction = PcCommand.substring(0,3);
        Serial.print("PcAction is: ");
        Serial.println(PcAction);

        if (PcAction == "Sv1"){ //base motor
            PcValue = (PcCommand.substring(4)).toInt();
            Serial.print("PcValue is: ");
            Serial.println(PcValue);
            baseServo.write(PcValue);
        }
    }

}

void servoBackAndForth(){
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        baseServo.write(pos);    
        delay(15);                       
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        baseServo.write(pos);      
        delay(15);                       
    }
}