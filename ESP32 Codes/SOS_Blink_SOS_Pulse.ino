const int buttonPin1 = 23;
int buttonState1 = 0;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(23, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(23), interrupcionBoton,
  FALLING);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);

 if(buttonState1 == HIGH) {
  analogWrite(5, 255);
  } else if (buttonState2 == LOW) { 
  analogWrite(5, 0);
  }

}

