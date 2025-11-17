const int ledPin = 12;
const int interruptPin = 23;
volatile bool interrupt = false;

const int buttonPin1 = 18;
const int buttonPin2 = 19;
const int buttonPin3 = 21;

bool lastState1 = LOW;
bool lastState2 = LOW;
bool lastState3 = LOW;

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

int step1 = 0;
int step2 = 0;
int secuenciaActiva = 0;

int tiempo1[] = {500,500,500,500,500,500,1000,1000,1000,1000,1000,1000,500,500,500,500,500,500};
int tiempo2[] = {500,500,500,500,500,500,500,500,500,500,500,500,500,500};
int secuenciaLength1 = sizeof(tiempo1) / sizeof(tiempo1[0]);
int secuenciaLength2 = sizeof(tiempo2) / sizeof(tiempo2[0]);
int fadeValue = 0;
int fadeDirection = 1;
const int fadeInterval = 10;
bool fadeActive = false;
int ledState = 0; 

void interrupcionBoton();

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(interruptPin), interrupcionBoton, FALLING);
}

void loop() {
  if (interrupt) {
    analogWrite(ledPin, 0);
    Serial.println("Interrupción activada: LED apagado");
    interrupt = false;
    secuenciaActiva = 0;
    fadeActive = false;
    step1 = 0;
    step2 = 0;
    fadeValue = 0;
    ledState = 0;
  }

  bool b1 = digitalRead(buttonPin1);
  bool b2 = digitalRead(buttonPin2);
  bool b3 = digitalRead(buttonPin3);
  unsigned long currentMillis = millis();

  if (b1 == HIGH && lastState1 == LOW) {
    secuenciaActiva = 1;
    step1 = 0;
    previousMillis1 = currentMillis;
    fadeActive = false;
    ledState = 0;
  }

  if (b2 == HIGH && lastState2 == LOW) {
    secuenciaActiva = 2;
    step2 = 0;
    previousMillis2 = currentMillis;
    fadeActive = false;
    ledState = 0;
  }

  if (b3 == HIGH && !fadeActive) {
    fadeActive = true;
    fadeValue = 0;
    fadeDirection = 1;
    previousMillis3 = currentMillis;
    secuenciaActiva = 0; 
  }

  lastState1 = b1;
  lastState2 = b2;
  lastState3 = b3;


  if (secuenciaActiva == 1) {
    if (currentMillis - previousMillis1 >= tiempo1[step1]) {
      previousMillis1 = currentMillis;
      ledState = (ledState == 0) ? 255 : 0; 
      analogWrite(ledPin, ledState);
      step1++;
      if (step1 >= secuenciaLength1) {
        secuenciaActiva = 0;
        analogWrite(ledPin, 0);
        ledState = 0;
      }
    }
  }

  if (secuenciaActiva == 2) {
    if (currentMillis - previousMillis2 >= tiempo2[step2]) {
      previousMillis2 = currentMillis;
      ledState = (ledState == 0) ? 255 : 0;
      analogWrite(ledPin, ledState);
      step2++;
      if (step2 >= secuenciaLength2) {
        secuenciaActiva = 0;
        analogWrite(ledPin, 0);
        ledState = 0;
      }
    }
  }

  if (fadeActive) {
    if (currentMillis - previousMillis3 >= fadeInterval) {
      previousMillis3 = currentMillis;
      analogWrite(ledPin, fadeValue);
      fadeValue += fadeDirection * 5;

      if (fadeValue >= 255) {
        fadeValue = 255;
        fadeDirection = -1;
      } else if (fadeValue <= 0) {
        fadeValue = 0;
        fadeActive = false;
        analogWrite(ledPin, 0);
      }
    }
  }
}

void interrupcionBoton() {
  interrupt = true;
}