#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// LCD setup via I2C (make sure the address 0x27 is correct for your unit, or change it to 0x3F if necessary)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16x2 LCD

// 4x4 keypad setup
const byte ROWS = 4;  // 4 rows
const byte COLS = 4;  // 4 columns

// Key layout on the keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Row pins connected to D2–D5
byte rowPins[ROWS] = {2, 3, 4, 5};

// Column pins connected to D6–D9
byte colPins[COLS] = {6, 7, 8, 9};

// Create a Keypad object using the library
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Game variables
int operand1, operand2, correctAnswer;
String userInput = "";

void setup() {
  // Initialize the LCD and turn on the backlight
  lcd.init();
  lcd.backlight();

  // Initialize the random number generator
  randomSeed(analogRead(0));

  // Generate the first question
  generateQuestion();
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    // If '#' key is pressed, consider the input complete and check the answer
    if (key == '#') {
      int answer = userInput.toInt();
      lcd.clear();
      if (answer == correctAnswer) {
        lcd.print("Correct Answer!");
      } else {
        lcd.print("Wrong! Ans:");
        lcd.setCursor(0, 1);
        lcd.print(correctAnswer);
      }
      delay(2000);  // Delay to show the result for two seconds
      userInput = "";
      generateQuestion();
    }
    // If '*' key is pressed, clear the current input
    else if (key == '*') {
      userInput = "";
      lcd.clear();
      lcd.print("Enter Answer:");
    }
    // If a digit key is pressed, add it to the input string
    else if (isDigit(key)) {
      userInput += key;
      lcd.clear();
      lcd.print("Enter Answer:");
      lcd.setCursor(0, 1);
      lcd.print(userInput);
    }
    // You can add additional functions for keys A, B, C, D if needed
  }
}

// Function to generate a new multiplication question and display it on the LCD
void generateQuestion() {
  // Generate two random numbers from 1 to 9
  operand1 = random(1, 10);
  operand2 = random(1, 10);
  correctAnswer = operand1 * operand2;

  lcd.clear();
  lcd.print("Calc: ");
  lcd.print(operand1);
  lcd.print(" x ");
  lcd.print(operand2);

  // Display a message on the second row encouraging the user to enter the answer
  lcd.setCursor(0, 1);
  lcd.print("Enter Answer:");
}
