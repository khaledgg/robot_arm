// Following https://www.youtube.com/watch?v=CypV9pPTCXo 

String CommandFromPC;
const int trigPin = 2;
const int echoPin = 3;
float duration, distance;

void setup(){
    Serial.begin(115200);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop(){
    if (Serial.available() > 0){ // If data showing up on port
        CommandFromPC = Serial.readStringUntil('\n');
        if (CommandFromPC == "Hello Arduino"){
            Serial.println("Hear ya Loud and clear");
            delay(1000);
        }else if (CommandFromPC == "Get Distance"){
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);

            duration = pulseIn(echoPin, HIGH);
            distance = (duration*.0343)/2;
            Serial.println(distance);
        }
    }
}