#include <SoftwareSerial.h>
#include <Arduino.h>


SoftwareSerial BTserial(10, 11); // RX | TX
int ena = 7;
int motorPin1 = 6;
int motorPin2 = 5;
int motorPin3 = 4;
int motorPin4 = 3;
int enb = 2;
int motorSpeed1 = 0;
int motorSpeed2 = 0;
int horn = 8;
int frontlight=9;//Front Light to pin D9
int backlight=12;//Front Light to pin D12

void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(horn, OUTPUT);
  pinMode(frontlight, OUTPUT);
  pinMode(backlight, OUTPUT);

}

void loop() {
  if (BTserial.available() > 0) {
    char data = BTserial.read();
    Serial.write(data);
    if (data == 'F') {
      Serial.println("Moving Forward...");
      forward();
    }
    else if (data == 'B') {
      Serial.println("Moving Backward...");
      backward();
    }
    else if (data == 'R') {
      Serial.println("Turning Left...");
      left();
    }
    else if (data == 'L') {
      Serial.println("Turning Right...");
      right();
    }
    else if (data == 'S') {
      Serial.println("Stopping...");
      stop();
    }
    else if (data == 'I'){
      forwardleft();

    }
     else if (data == 'G'){
      forwardright();

    }
     else if (data == 'J'){
      backleft();

    }
     else if (data == 'H'){
      backright();

    }

    else if (data == 'V'){
      digitalWrite(horn, HIGH);

    }

    else if (data == 'v'){
      digitalWrite(horn, LOW);

    }

    else if (data == 'W'){
      digitalWrite(frontlight, HIGH);

    }

    else if (data == 'w'){
      digitalWrite(frontlight, LOW);

    }

    else if (data == 'U'){
      digitalWrite(backlight, HIGH);

    }

    else if (data == 'u'){
      digitalWrite(backlight, LOW);

    }

    
  }
}

void forward() {
  motorSpeed1 = 255;
  motorSpeed2 = 255;
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  analogWrite(ena, motorSpeed1);
  analogWrite(enb, motorSpeed1);
}

void backward() {
  motorSpeed1 = 255;
  motorSpeed2 = 255;
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  analogWrite(ena, motorSpeed1);
  analogWrite(enb, motorSpeed2);  
}

void forwardleft() {
  motorSpeed1 = 50;
  motorSpeed2 = 255;
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  analogWrite(ena, motorSpeed1);
  analogWrite(enb, motorSpeed2);
}

void forwardright() {
  motorSpeed1 = 255;
  motorSpeed2 = 50;
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  analogWrite(ena, motorSpeed1);
  analogWrite(enb, motorSpeed2);
}

void backleft() {
  motorSpeed1 = 50;
  motorSpeed2 = 255;
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  analogWrite(ena, motorSpeed1);
  analogWrite(enb, motorSpeed2);  
}

void backright() {
  motorSpeed1 = 255;
  motorSpeed2 = 50;
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  analogWrite(ena, motorSpeed1);
  analogWrite(enb, motorSpeed2);  
}

void left() {
  motorSpeed1 = 200;
  motorSpeed2 = 200;
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  analogWrite(ena, motorSpeed1);
  analogWrite(enb, motorSpeed2);
}

void right() {
  motorSpeed1 = 200;
  motorSpeed2 = 200;
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  analogWrite(ena, motorSpeed1);
  analogWrite(enb, motorSpeed2);
}

void stop() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  analogWrite(ena, 0);
  analogWrite(enb, 0);
}
