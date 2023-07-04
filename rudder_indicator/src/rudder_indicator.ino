#include <Servo.h> // add servo library

#define A0 0            // Analog pin used to connect the potentiometer
#define D9 9            // Digital pin used to connect the servo
#define POT_MAX 1023    // Maximum value of the potentiometer
#define POT_MIN 0       // Minimum value of the potentiometer
#define SERVO_MAX 180   // Maximum value of the servo
#define SERVO_MIN 0     // Minimum value of the servo
#define MILLISECONDS 15 // Amount of time for the servo to update postion

// create servo object to control a servo
Servo needle_indicator;

int pot_pin = A0;
int pot_value = 0;
int servo_position = 0;

void setup()
{
    // Initialize the servo pin
    needle_indicator.attach(D9);
}

void loop()
{
    pot_value = analogRead(pot_pin);

    /* Assign 'servo_postion' by scaling 'pot_value' to a value between
     * SERVO_MIN and SERVO_MAX */
    servo_position = map(pot_value, POT_MIN, POT_MAX, SERVO_MIN, SERVO_MAX);

    // Set the servo position
    needle_indicator.write(servo_position);

    // Wait for servo to reach the new position
    delay(MILLISECONDS);
}