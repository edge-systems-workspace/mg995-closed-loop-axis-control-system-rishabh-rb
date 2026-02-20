/**
* @file main.ino
 * @brief MG995 Closed-Loop Axis Control System
 * @author YOUR_NAME
 * @date 2026-02-20
 *
 * @details
 * Implements PWM-based closed-loop control for MG995 servo motor.
 * Accepts angle input via Serial Monitor and validates range (0–180).
 */

#include <Servo.h>
#include <Arduino.h>

// TODO 1: Create Servo object
Servo axisServo;

// TODO 2: Define PWM pin (Use pin 9)
const int SERVO_PIN = 9;

// TODO 3: Create variable to store servo angle
int targetAngle = 0;

void setup() {

    // TODO 4: Initialize Serial communication (9600 baud)
    Serial.begin(9600);

    // TODO 5: Attach servo to PWM pin
    axisServo.attach(SERVO_PIN);

    // TODO 6: Print system initialization message
    Serial.println("=================================");
    Serial.println(" MG995 Axis Control System Ready ");
    Serial.println(" Enter angle between 0 and 180°  ");
    Serial.println("=================================");
}

void loop() {

    // TODO 7: Check if Serial data is available
    if (Serial.available() > 0) {

        // TODO 8: Read integer angle input from Serial
        targetAngle = Serial.parseInt();

        // Clear any remaining characters in buffer
        while (Serial.available() > 0) {
            Serial.read();
        }

        // TODO 9: Validate angle range (0–180)
        if (targetAngle >= 0 && targetAngle <= 180) {

            // Move servo to target angle
            axisServo.write(targetAngle);

            // TODO 10: Print confirmation message
            Serial.print("Servo moved to: ");
            Serial.print(targetAngle);
            Serial.println(" degrees");

        } else {

            Serial.println("Error: Invalid angle! Enter value between 0 and 180.");
        }
    }
}