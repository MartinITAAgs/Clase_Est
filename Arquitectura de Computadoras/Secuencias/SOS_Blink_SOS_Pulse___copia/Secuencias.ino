int ledPin = 9; 
int brillo = 0; 
int paso = 5;

void setup() {
  pinMode(5, OUTPUT);
}

void loop() {
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

  for (int i=0;i<=255;i++){
    analogWrite(5, i);
    delay(10);
  }
  
  for (int i=255;i>=0;i--){
    analogWrite(5, i);
    delay(10);
  }

}
