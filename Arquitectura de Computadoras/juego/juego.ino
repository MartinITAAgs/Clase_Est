// Configuración de pines
const int botonPin1 = 17;  
const int botonPin2 = 5;
const int botonPin3 = 18;
const int botonPin4 = 19;
const int botonPin5 = 21;
const int botonPin6 = 22;
const int botonPin7 = 23;
const int ledPin1 = 12;
const int ledPin2 = 14;
const int ledPin3 = 27;
const int ledPin4 = 26;
const int ledPin5 = 25;
const int ledPin6 = 33;

int numrand = 0;
int chance = 3;

void setup() {
  pinMode(botonPin1, INPUT_PULLUP);
  pinMode(botonPin2, INPUT_PULLUP);
  pinMode(botonPin3, INPUT_PULLUP);
  pinMode(botonPin4, INPUT_PULLUP);
  pinMode(botonPin5, INPUT_PULLUP);
  pinMode(botonPin6, INPUT_PULLUP);
  pinMode(botonPin7, INPUT_PULLUP);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
    pinMode(ledPin6, OUTPUT);

  randomSeed(analogRead(32));
  numrand = random(6); // LED ganador inicial
}

void loop() {
  // Leer el estado de los botones
  int estadoBoton1 = digitalRead(botonPin1);
  int estadoBoton2 = digitalRead(botonPin2);
  int estadoBoton3 = digitalRead(botonPin3);
  int estadoBoton4 = digitalRead(botonPin4);
  int estadoBoton5 = digitalRead(botonPin5);
  int estadoBoton6 = digitalRead(botonPin6);
  int estadoBoton7 = digitalRead(botonPin7);

  // Botón de reinicio
  if (estadoBoton7 == HIGH) {
    numrand = random(6);
    chance = 3;
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    analogWrite(ledPin5, 0);
    analogWrite(ledPin6, 0);
    delay(300); // anti-rebote
  }

  // Si se acabaron las oportunidades → todos tenues
  if (chance == 0) {
    analogWrite(ledPin1, 10);
    analogWrite(ledPin2, 10);
    analogWrite(ledPin3, 10);
    analogWrite(ledPin4, 10);
    analogWrite(ledPin5, 10);
    analogWrite(ledPin6, 10);
    return; // salir del loop
  }

  // Botón 1
  if (estadoBoton6 == HIGH) {
    if (numrand == 0) {
      analogWrite(ledPin1, 255);
      delay(5000);
      chance = 0; // termina el juego
    } else {
      analogWrite(ledPin1, 10);
      chance--;
    }
    delay(300);
  }

  // Botón 2
  if (estadoBoton5 == HIGH) {
    if (numrand == 1) {
      analogWrite(ledPin2, 255);
      delay(5000);
      chance = 0;
    } else {
      analogWrite(ledPin2, 10);
      chance--;
    }
    delay(300);
  }

  // Botón 3
  if (estadoBoton4 == HIGH) {
    if (numrand == 2) {
      analogWrite(ledPin3, 255);
      delay(5000);
      chance = 0;
    } else {
      analogWrite(ledPin3, 10);
      chance--;
    }
    delay(300);
  }

  // Botón 4
  if (estadoBoton3 == HIGH) {
    if (numrand == 3) {
      analogWrite(ledPin4, 255);
      delay(5000);
      chance = 0;
    } else {
      analogWrite(ledPin4, 10);
      chance--;
    }
    delay(300);
  }

  // Botón 5
  if (estadoBoton2 == HIGH) {
    if (numrand == 4) {
      analogWrite(ledPin6, 255);
      delay(5000);
      chance = 0;
    } else {
      analogWrite(ledPin6, 10);
      chance--;
    }
    delay(300);
  }

  // Botón 6
  if (estadoBoton1 == HIGH) {
    if (numrand == 5) {
      analogWrite(ledPin5, 255);
      delay(5000);
      chance = 0;
    } else {
      analogWrite(ledPin5, 10);
      chance--;
    }
    delay(300);
  }
}
