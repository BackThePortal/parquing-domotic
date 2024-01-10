#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <stdlib.h>
#include <Arduino.h>

const int verm = 51,
  verd = 50,
  botoEntrada = 34,
  botoSortida = 35,
  servo = 13;
const int brunzidor = 9;
const int ultrTrig = 22;
const int ultrEcho = 7;
const int blau1 = 11;
const int blau2 = 10;

// Desactivar botons
const bool BOTONS = true;


bool passant = false;
unsigned long t = 0;

int d = 0;

unsigned int places = 3;

Servo servoMotor;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void motorLeds() {
  servoMotor.write(passant ? 20 : 125);
  
  digitalWrite(verm, !passant);
  digitalWrite(verd, passant);
}

void setup() {
  pinMode(verm, OUTPUT);
  pinMode(verd, OUTPUT);
  pinMode(botoSortida, INPUT);
  pinMode(botoEntrada, INPUT);
  pinMode(brunzidor, OUTPUT);
  pinMode(blau1, OUTPUT);
  pinMode(blau2, OUTPUT);
  pinMode(ultrTrig, OUTPUT);
  pinMode(ultrEcho, INPUT);

  
  lcd.init();
  lcd.backlight();

  lcd.print("Benvinguts");

  servoMotor.attach(13);
  
  digitalWrite(verm, HIGH);
  digitalWrite(verd, LOW);

  Serial.begin(9600);
}


void loop() {
  int sortida = digitalRead(botoSortida);
  

  // Enviar pulsació
  digitalWrite(ultrTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrTrig, LOW);

  // Calcular distància
  d = pulseIn(ultrEcho, HIGH) / 59;

  Serial.println(d);

  analogWrite(blau1, map(constrain(d, 5, 15), 5, 15, 1023, 0));
  analogWrite(blau2, map(constrain(d, 15, 50), 15, 50, 1023, 0));
  
  if ((d > 1 && d < 6) || digitalRead(botoEntrada) == HIGH) {
    t = millis();
    entrada = true;
  }

  if (millis() - t > 3000 && t != 0) {
    sortida = true;
    entrada = false;
  }


  if (entrada && !passant) {
    passant = true;
    tone(brunzidor, 3000, 700);
    motorLeds();
    --places;
    
  } else if (sortida && passant) {
    t = 0;
    passant = false;
    tone(brunzidor, 4000, 700);
    motorLeds();
    ++places;
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Lliures: ");
    lcd.print(places);
    
  }
  
  delay(100);
}
