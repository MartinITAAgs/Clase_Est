
#include <Keypad.h>

const byte f = 3;
const byte c = 3;

byte filas[f] = {16, 17, 18};
byte columnas[c] = {19, 21, 23};

char keys[f][c] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};

char tablero[f][c] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
char jugador = 'X';
bool fin = false;

Keypad keypad = Keypad(makeKeymap(keys), filas, columnas, f, c);

void printtablero() {
  Serial.println("+———+———+———+");
  for (int i = 0; i < f; i++) {
    for (int j = 0; j < c; j++) {
      Serial.print("| ");
      Serial.print(tablero[i][j]);
      Serial.print(' ');
    }
    Serial.println("|");
    Serial.println("+———+———+———+");
  }
}

bool chequeo(char p) {
  for (int i = 0; i < 3; i++) {
    if (tablero[i][0]==p && tablero[i][1]==p && tablero[i][2]==p) return true;
    if (tablero[0][i]==p && tablero[1][i]==p && tablero[2][i]==p) return true;
  }
  if (tablero[0][0]==p && tablero[1][1]==p && tablero[2][2]==p) return true;
  if (tablero[0][2]==p && tablero[1][1]==p && tablero[2][0]==p) return true;
  return false;
}

void setup() {
  Serial.begin(115200);
  Serial.println("Tic Tac Toe");
  printtablero();
}

void loop() {
  char k = keypad.getKey();
  if (!k) return;

  if (fin) {
    Serial.println("Juego terminado. Reiniciando...");
    for (int i=0;i<3;i++) for(int j=0;j<3;j++) tablero[i][j]=' ';
    jugador='X'; fin=false;
    printtablero();
    return;
  }

  int pos = k - '1'; // convierte '1'..'9' en 0..8
  if (pos < 0 || pos > 8) return;

  int r = pos / 3;
  int c = pos % 3;

  if (tablero[r][c] != ' ') {
    Serial.println("Casilla ocupada");
    return;
  }

  tablero[r][c] = jugador;
  printtablero();

  if (chequeo(jugador)) {
    Serial.print("¡Gana ");
    Serial.print(jugador);
    Serial.println("!");
    fin = true;
    return;
  }

  jugador = (jugador == 'X') ? 'O' : 'X';
}
