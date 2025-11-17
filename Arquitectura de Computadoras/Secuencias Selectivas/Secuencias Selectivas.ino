const int buttonPin1 = 18;
const int buttonPin2 = 19;
const int buttonPin3 = 21;
int ledPin = 9; 
int brillo = 0; 
int paso = 5;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);

}

void loop() {

  int b1 = digitalRead(buttonPin1);
  int b2 = digitalRead(buttonPin2);
  int b3 = digitalRead(buttonPin3);


if (b1 == HIGH){
  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(500);
  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(500);
  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(500);
  
  analogWrite(5, 255);
  delay(1000);
  analogWrite(5, 0);
  delay(1000);
  analogWrite(5, 255);
  delay(1000);
  analogWrite(5, 0);
  delay(1000);
  analogWrite(5, 255);
  delay(1000);
  analogWrite(5, 0);
  delay(1000);

  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(500);
  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(500);
  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(3000);
}

if (b2 == HIGH){
  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(500);
  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(500);
  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(500);
  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(500);
  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(500);
  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(500);
  analogWrite(5, 255);
  delay(500);
  analogWrite(5, 0);
  delay(3000);
}

  if (b3 == HIGH){

  for (int i=0;i<=255;i++){
    analogWrite(5, i);
    delay(10);
  }
  
  for (int i=255;i>=0;i--){
    analogWrite(5, i);
    delay(10);
  }
  }

}
