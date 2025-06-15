# Arduino Keypad Calculator
This project uses an Arduino with a 4x4 keypad and an LCD to create a simple multiplication calculator game. The user is asked to solve a random multiplication problem, and the input is verified through the keypad. The results are displayed on the LCD.

## Components Used
 1. Arduino board (e.g., Uno, Nano)
 2. 4x4 Matrix Keypad
 3. 16x2 LCD Display with I2C interface
 4. Jumper wires and breadboard

## Wiring Diagram
 1.Keypad:
  Connect the rows and columns of the keypad to digital pins 2 to 9 on the Arduino.

 2. LCD Display:
  Connect the SDA and SCL pins of the LCD to the corresponding pins on the Arduino (A4 and A5 for Uno).

## Libraries Used
 1. Wire.h: For I2C communication with the LCD.
 2. LiquidCrystal_I2C.h: To interface with the LCD over I2C.
 3. Keypad.h: For handling keypad input.

## Features
 1. The LCD will display a multiplication question (e.g., "3 x 7").
 2. The user enters the answer using the keypad.
 3. Press # to submit the answer.
 4. If correct, the message "Correct Answer!" will be shown.
 5. If wrong, the correct answer will be displayed.
 6. Press * to clear the input and start over.
 7. The game generates a new random multiplication question after each attempt.

## Setup Instructions
 1. Install Libraries:
  Install LiquidCrystal_I2C and Keypad libraries through the Arduino Library Manager.
 2. Wiring the Components:
    Keypad:
      Rows to pins 2-5.
      Columns to pins 6-9.
    LCD:
      SDA to A4 and SCL to A5 (for Arduino Uno).
