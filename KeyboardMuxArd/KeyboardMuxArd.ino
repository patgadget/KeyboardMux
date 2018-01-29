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
  pinMode(ROW1, INPUT);
  pinMode(ROW2, INPUT);
  pinMode(ROW3, INPUT);
  pinMode(ROW4, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
