#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  100 // this is the 'minimum' pulse length count (out of 4096) 0 degrees
#define SERVOMAX  350 // this is the 'maximum' pulse length count (out of 4096) 90 degrees
#define SERVOMID1  170 // adjustable middle angle
#define SERVOMID2  167
#define SERVOMID3  160
#define SERVOMID4  160
#define SERVOMID5  160 
#define SERVOMID6  180
#define SERVOMID7  180

#define dropServo 0
#define tiltServo1 1 // farthest servo
#define tiltServo2 2
#define tiltServo3 3
#define tiltServo4 4
#define tiltServo5 5
#define tiltServo6 6
#define tiltServo7 7

#define LED_PIN_1 9
#define LED_PIN_2 10
#define buttonPin 46

int currentState = 0;

void setup() {
  pwm.begin();
  pinMode(buttonPin, INPUT);  // set up button pin
  //pinMode(LED_PIN_1, OUTPUT); // set up LED pins
  //pinMode(LED_PIN_2, OUTPUT);
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pwm.setPWM(tiltServo1, 0, SERVOMID1); // Set Tilt servos to middle
  pwm.setPWM(tiltServo2, 0, SERVOMID2);
  pwm.setPWM(tiltServo3, 0, SERVOMID3);
  pwm.setPWM(tiltServo4, 0, SERVOMID4);
  pwm.setPWM(tiltServo5, 0, SERVOMID5);
  pwm.setPWM(tiltServo6, 0, SERVOMID6);
  pwm.setPWM(tiltServo7, 0, SERVOMID7);
  pwm.setPWM(dropServo, 0, SERVOMIN); // Set Drop servo to closed
  Serial.begin(9600); // start Serial Print
}


void loop() {
  delay(1);
  currentState = digitalRead(buttonPin);
  //digitalWrite(LED_PIN_1, LOW);
  //digitalWrite(LED_PIN_2, HIGH);
  pwm.setPWM(tiltServo1, 0, SERVOMID1);
  pwm.setPWM(tiltServo2, 0, SERVOMID2);
  pwm.setPWM(tiltServo3, 0, SERVOMID3);
  pwm.setPWM(tiltServo4, 0, SERVOMID4);
  pwm.setPWM(tiltServo5, 0, SERVOMID5);
  pwm.setPWM(tiltServo6, 0, SERVOMID6);
  pwm.setPWM(tiltServo7, 0, SERVOMID7);
  if(currentState == HIGH){ // clicked 
    Serial.println("clicked");
    //digitalWrite(LED_PIN_1, HIGH);
    //digitalWrite(LED_PIN_2, LOW);
    for (int i=0; i<6; i++) {
      // Set platform middle for read
      pwm.setPWM(tiltServo1, 0, SERVOMID1);
      pwm.setPWM(tiltServo2, 0, SERVOMID2);
      pwm.setPWM(tiltServo3, 0, SERVOMID3);
      pwm.setPWM(tiltServo4, 0, SERVOMID4);
      pwm.setPWM(tiltServo5, 0, SERVOMID5);
      pwm.setPWM(tiltServo6, 0, SERVOMID6);
      pwm.setPWM(tiltServo7, 0, SERVOMID7);
      delay(300); // was 500
      // Read and print IR sensor value
      int sensorValue1 = analogRead(A0); //
      int sensorValue2 = analogRead(A1);
      int sensorValue3 = analogRead(A2);
      int sensorValue4 = analogRead(A3);
      int sensorValue5 = analogRead(A13);
      int sensorValue6 = analogRead(A12);
      int sensorValue7 = analogRead(A11);
      // Print incoming values
      Serial.print("sensor1: ");
      Serial.println(sensorValue1);
      Serial.print("sensor2: ");      
      Serial.println(sensorValue2);
      Serial.print("sensor3: ");
      Serial.println(sensorValue3);
      Serial.print("sensor4: ");
      Serial.println(sensorValue4);
      Serial.print("sensor5: ");
      Serial.println(sensorValue5);
      Serial.print("sensor6: ");
      Serial.println(sensorValue6);
      Serial.print("sensor7: ");
      Serial.println(sensorValue7);
      //Serial.print("A3: ");
      //Serial.println(analogRead(A3));
      delay(300); // was 500
      // Tilt platform based on RED or BLACK piece
      if(sensorValue1 < 500){ // BLACK (did not reflect IR signal) 
        pwm.setPWM(tiltServo1, 0, SERVOMAX-10);
      }else{  // RED (reflected IR signal)
        pwm.setPWM(tiltServo1, 0, SERVOMIN-20);
      }
      if(sensorValue2 < 500){ // BLACK (did not reflect IR signal) 
        pwm.setPWM(tiltServo2, 0, SERVOMAX-10);
      }else{  // RED (reflected IR signal)
        pwm.setPWM(tiltServo2, 0, SERVOMIN-25);
      }
      if(sensorValue3 < 500){ // BLACK (did not reflect IR signal) 
        pwm.setPWM(tiltServo3, 0, SERVOMAX-10);
      }else{  // RED (reflected IR signal)
        pwm.setPWM(tiltServo3, 0, SERVOMIN-10);
      }
      if(sensorValue4 < 500){ // BLACK (did not reflect IR signal) 
        pwm.setPWM(tiltServo4, 0, SERVOMAX-20);
      }else{  // RED (reflected IR signal)
        pwm.setPWM(tiltServo4, 0, SERVOMIN-10);
      }
      if(sensorValue5 < 500){ // BLACK (did not reflect IR signal) 
        pwm.setPWM(tiltServo5, 0, SERVOMAX);
      }else{  // RED (reflected IR signal)
        pwm.setPWM(tiltServo5, 0, SERVOMIN-20);
      }
      if(sensorValue6 < 500){ // BLACK (did not reflect IR signal) 
        pwm.setPWM(tiltServo6, 0, SERVOMAX);
      }else{  // RED (reflected IR signal)
        pwm.setPWM(tiltServo6, 0, SERVOMIN-15);
      }
      if(sensorValue7 < 500){ // BLACK (did not reflect IR signal) 
        pwm.setPWM(tiltServo7, 0, SERVOMAX);
      }else{  // RED (reflected IR signal)
        pwm.setPWM(tiltServo7, 0, SERVOMIN+10);
      }
      delay(150);
      // Drop a single Row
      pwm.setPWM(dropServo, 0, SERVOMAX);
      delay(125); // drop speed
      pwm.setPWM(dropServo, 0, SERVOMIN);
      delay(500); // was 500 ms
    }
  }
}
