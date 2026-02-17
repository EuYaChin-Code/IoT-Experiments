#include <Sleep_n0m1.h>

Sleep sleep;
unsigned long sleepTime;

const byte PIN_BOTON = 2;   // INT0
const byte PIN_LED   = 13;  // LED integrado

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

  // Botón a GND usando pullup interno
  pinMode(PIN_BOTON, INPUT_PULLUP);

}

void loop()
{
  Serial.println("Durmiendo hasta presionar el boton...");
  // Modo de máximo ahorro
  sleep.pwrDownMode();

  sleep.sleepPinInterrupt(PIN_BOTON, LOW);

  delay(30);
  while (digitalRead(PIN_BOTON) == LOW) {
  }
  delay(30);

  Serial.println("I Wake Up :)");
  Serial.println("Boton detectado -> LED ON");

  digitalWrite(PIN_LED, HIGH);
  delay(500);               
  digitalWrite(PIN_LED, LOW);

  Serial.println("LED OFF");


}
