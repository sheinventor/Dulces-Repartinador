// Descripción del proyecto: Dispensador de dulces controlado por Arduino
// Conexiones: Buzzer en pin 4, botón en pin 2 y servomotor en pin 9

#include <Servo.h>
Servo polo;  // crea un objeto Servo
int buzzerPin = 4;
int pao = 2;  // Pin digital para el botón 
int beto; //Variable que permite guardar el estado del botón (activado o desactivado)


void setup() {
  polo.attach(9);  // asigna el pin 9 al servomotor
  polo.write(0);
  pinMode(pao, INPUT);
  Serial.begin(9600);  // Iniciar comunicación serial a 9600 baudios
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  beto= digitalRead(pao);
  if (beto==HIGH)
  {
  polo.write(0);  // mueve el servomotor a 0 grados
  delay(200);   
  Serial.println("Derecha");
  tone(buzzerPin, 440, 200); // La
  delay(200);
  tone(buzzerPin, 587, 200); // Re
  delay(200);

  }
  else 
  {  
  polo.write(90);  // mueve el servomotor a 90 grados
  delay(200);   
  Serial.println("IZQ");}
}


