const int ledPin = 12;          
const int interruptPin = 23;   
const int buttonPin1 = 18;     
const int buttonPin2 = 19;     
const int buttonPin3 = 21;      
bool lastState1 = LOW;
bool lastState2 = LOW;
bool lastState3 = LOW;
const unsigned long debounceMs = 35;
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;
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
int ledState = 0; // 0 o 255
volatile bool interruptToggleRequested = false; // La ISR pide alternar pausa/reanudar
bool paused = false;
unsigned long pauseStartMillis = 0;

void interrupcionBoton();

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT);       
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(interruptPin, INPUT_PULLUP);

  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(interruptPin), interrupcionBoton, FALLING);

  analogWrite(ledPin, 0);

  lastState1 = digitalRead(buttonPin1);
  lastState2 = digitalRead(buttonPin2);
  lastState3 = digitalRead(buttonPin3);
}

void loop() {
  unsigned long currentMillis = millis();

  if (interruptToggleRequested) {
    interruptToggleRequested = false;

    if (!paused) {
      paused = true;
      pauseStartMillis = currentMillis;
      Serial.println("Pausa activada: LED apagado visualmente.");
      analogWrite(ledPin, 0);
    } else {
      paused = false;
      unsigned long pauseDur = currentMillis - pauseStartMillis;

      if (secuenciaActiva == 1) previousMillis1 += pauseDur;
      if (secuenciaActiva == 2) previousMillis2 += pauseDur;
      if (fadeActive)           previousMillis3 += pauseDur;

      if (secuenciaActiva == 1 || secuenciaActiva == 2) {
        analogWrite(ledPin, ledState);
      } else if (fadeActive) {
        analogWrite(ledPin, fadeValue);
      } else {
        analogWrite(ledPin, 0);
      }

      Serial.println("Pausa desactivada: reanudando en el mismo punto.");
    }
  }

  bool raw1 = digitalRead(buttonPin1);
  bool raw2 = digitalRead(buttonPin2);
  bool raw3 = digitalRead(buttonPin3);

  bool b1 = lastState1;
  if (raw1 != lastState1 && (currentMillis - lastDebounceTime1) > debounceMs) {
    lastDebounceTime1 = currentMillis;
    b1 = raw1;
  }

  bool b2 = lastState2;
  if (raw2 != lastState2 && (currentMillis - lastDebounceTime2) > debounceMs) {
    lastDebounceTime2 = currentMillis;
    b2 = raw2;
  }

  bool b3 = lastState3;
  if (raw3 != lastState3 && (currentMillis - lastDebounceTime3) > debounceMs) {
    lastDebounceTime3 = currentMillis;
    b3 = raw3;
  }

  if (paused) {
    if (b1 == HIGH && lastState1 == LOW) {
      paused = false;
      Serial.println("Pausa desactivada por botón 1: iniciando secuencia 1.");
      secuenciaActiva = 1;
      step1 = 0;
      previousMillis1 = currentMillis;
      fadeActive = false;
      ledState = 0;
      analogWrite(ledPin, ledState);
    }

    if (b2 == HIGH && lastState2 == LOW) {
      paused = false;
      Serial.println("Pausa desactivada por botón 2: iniciando secuencia 2.");
      secuenciaActiva = 2;
      step2 = 0;
      previousMillis2 = currentMillis;
      fadeActive = false;
      ledState = 0;
      analogWrite(ledPin, ledState);
    }

    if (b3 == HIGH && lastState3 == LOW) {
      paused = false;
      Serial.println("Pausa desactivada por botón 3: iniciando fade.");
      fadeActive = true;
      fadeValue = 0;
      fadeDirection = 1;
      previousMillis3 = currentMillis;
      secuenciaActiva = 0;
      ledState = 0;
      analogWrite(ledPin, fadeValue);
    }

    lastState1 = b1;
    lastState2 = b2;
    lastState3 = b3;

    if (paused) {
      analogWrite(ledPin, 0);
      return;
    }
  }

  if (!paused) {
    if (b1 == HIGH && lastState1 == LOW) {
      secuenciaActiva = 1;
      step1 = 0;
      previousMillis1 = currentMillis;
      fadeActive = false;
      ledState = 0;
      Serial.println("Iniciando secuencia 1.");
    }

    if (b2 == HIGH && lastState2 == LOW) {
      secuenciaActiva = 2;
      step2 = 0;
      previousMillis2 = currentMillis;
      fadeActive = false;
      ledState = 0;
      Serial.println("Iniciando secuencia 2.");
    }

    if (b3 == HIGH && lastState3 == LOW && !fadeActive) {
      fadeActive = true;
      fadeValue = 0;
      fadeDirection = 1;
      previousMillis3 = currentMillis;
      secuenciaActiva = 0;
      ledState = 0;
      Serial.println("Iniciando fade.");
    }
  }

  lastState1 = b1;
  lastState2 = b2;
  lastState3 = b3;

  if (secuenciaActiva == 1) {
    if (currentMillis - previousMillis1 >= (unsigned long)tiempo1[step1]) {
      previousMillis1 = currentMillis;
      ledState = (ledState == 0) ? 255 : 0;
      analogWrite(ledPin, ledState);
      step1++;
      if (step1 >= secuenciaLength1) {
        secuenciaActiva = 0;
        analogWrite(ledPin, 0);
        ledState = 0;
        Serial.println("Secuencia 1 finalizada.");
      }
    }
  }

  if (secuenciaActiva == 2) {
    if (currentMillis - previousMillis2 >= (unsigned long)tiempo2[step2]) {
      previousMillis2 = currentMillis;
      ledState = (ledState == 0) ? 255 : 0;
      analogWrite(ledPin, ledState);
      step2++;
      if (step2 >= secuenciaLength2) {
        secuenciaActiva = 0;
        analogWrite(ledPin, 0);
        ledState = 0;
        Serial.println("Secuencia 2 finalizada.");
      }
    }
  }

  if (fadeActive) {
    if (currentMillis - previousMillis3 >= (unsigned long)fadeInterval) {
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
        Serial.println("Fade finalizado.");
      }
    }
  }
}

void interrupcionBoton() {
  interruptToggleRequested = true;
}
