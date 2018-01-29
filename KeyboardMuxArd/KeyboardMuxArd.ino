// Decode a 3 x 4 Keyboard

/*
 * ROW1 1 2 4
 * ROW2 4 5 6
 * ROW3 7 8 9
 * ROW4 * 0 #
 *      C C C
 *      1 2 3
 */

#define ROW1 9
#define ROW2 7
#define ROW3 12
#define ROW4 11
#define COLUMN1 10
#define COLUMN2 8
#define COLUMN3 6

void setup() {
  // put your setup code here, to run once:
  digitalWrite(COLUMN1, LOW);
  digitalWrite(COLUMN2, LOW);
  digitalWrite(COLUMN3, LOW);
  pinMode(ROW1, INPUT_PULLUP);
  pinMode(ROW2, INPUT_PULLUP);
  pinMode(ROW3, INPUT_PULLUP);
  pinMode(ROW4, INPUT_PULLUP);
  pinMode(COLUMN1, OUTPUT);
  pinMode(COLUMN2, OUTPUT);
  pinMode(COLUMN3, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int keyPress;
  keyPress = scanKeyboard();
  if (keyPress != -1){
    Serial.println(keyPress);
  }
}

int scanKeyboard(){
  digitalWrite(COLUMN1, HIGH);
  digitalWrite(COLUMN2, HIGH);
  digitalWrite(COLUMN3, HIGH);
  int i,j,k;
  k=-1;// No key press
  for (i=0;i<3;i++){
    if (i == 0){
      digitalWrite(COLUMN1, LOW);
      digitalWrite(COLUMN2, HIGH);
      digitalWrite(COLUMN3, HIGH);
    }
    if (i == 1){
      digitalWrite(COLUMN1, HIGH);
      digitalWrite(COLUMN2, LOW);
      digitalWrite(COLUMN3, HIGH);
    }
    if (i == 2){
      digitalWrite(COLUMN1, HIGH);
      digitalWrite(COLUMN2, HIGH);
      digitalWrite(COLUMN3, LOW);
    }
    j=i*10;
    if (digitalRead(ROW1) == LOW){
      k=j+1;  
    }
    if (digitalRead(ROW2) == LOW){
      k=j+2;  
    }
    if (digitalRead(ROW3) == LOW){
      k=j+3;  
    }
    if (digitalRead(ROW4) == LOW){
      k=j+4;  
    }
  }
  return(k);
}
