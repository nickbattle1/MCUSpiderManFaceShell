/* 
   ****************************************************
The program smoothly opens and closes the "eyelids" of the helmet
     individually, depending on the state
     sensors. If the switch is connected to the output
     switch_pin is open then both servos are controlled
     sensor connected to sensor1_pin. Otherwise,
     te, each servo is controlled by its own
     rubbish.
   
   ****************************************************
*/

#include <Servo.h>

// THE SETTINGS OF THE SKETCH THAT YOU CAN EDIT YOURSELF

const int switch_pin = 4; // switch outlet
const int sensor1_pin = 2; // input number connected to sensor №1
const int sensor2_pin = 3; // input number connected to sensor №2
const int servo1_pin = 8; // the output number for the servo drive №1
const int servo2_pin = 9; // the output number for the servo drive №2
const int servo_angle = 94; // the angle at which the servo will turn
const int rotate_time = 140; // Angle by which the servo will turn The delay time 
                             //in milliseconds the servos need to make a full turn 
                             //(the smaller, the more responsive and synchronous 
                             //the system is, but if you set it too low, the servos
                             // will not make a full angle turn in time).

                             

// ****************************************************

Servo servo1;
Servo servo2;
boolean servo1_cmd = true;
boolean servo2_cmd = true;
boolean servo1_direction = false;
boolean servo2_direction = false;
int switch_state;

void setup()
{
  pinMode(sensor1_pin, INPUT);
  pinMode(sensor2_pin, INPUT);
  pinMode(switch_pin, INPUT);
}

void loop()
{
  switch_state = digitalRead(switch_pin);
  
  if (switch_state == HIGH){
    if (digitalRead(sensor1_pin) == HIGH && servo1_cmd){
      
      servo1.attach(servo1_pin);
      servo2.attach(servo2_pin);
      delay(20); 
      
      if (servo1_direction){
        servo1.write(servo_angle);
        servo2.write(0);
        delay(20);
      }
      else{
        servo1.write(0);
        servo2.write(servo_angle);
        delay(20);
      }
       
      servo1_direction = !servo1_direction;
      servo1_cmd = false;
    }
  }
  else{
    if (digitalRead(sensor1_pin) == HIGH && servo1_cmd){
      
      servo1.attach(servo1_pin);
      delay(20); 
      
      if (servo1_direction){
        servo1.write(servo_angle);
        delay(20);
      }
      else{
        servo1.write(0);
        delay(20);
      }
       
      servo1_direction = !servo1_direction;
      servo1_cmd = false;
    }
  
    if (digitalRead(sensor2_pin) == HIGH && servo2_cmd){
      
      servo2.attach(servo2_pin);
      delay(20); 
      
      if (servo2_direction){
        servo2.write(servo_angle);
        delay(20);
      }
      else{
        servo2.write(0);
        delay(20);
      }
      
      servo2_direction = !servo2_direction;
      servo2_cmd = false;
    }
  }
  
  if (digitalRead(sensor1_pin) == LOW && !servo1_cmd){
    servo1_cmd = true;
    }
  if (digitalRead(sensor2_pin) == LOW && !servo2_cmd){
    servo2_cmd = true;
    }  
    
  delay(rotate_time);
  
  if (servo1.attached()){
    servo1.detach();
  }
  if (servo2.attached()){
    servo2.detach();
  }
}
