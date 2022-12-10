#include <Servo.h>
Servo miniservo;
int safety = 0;
int position = 0;
int servo_dir = 0;
int button_state = 0;

void setup()
{
  pinMode(5, INPUT);
  miniservo.attach(3, 500, 2500);
}

void loop()
{
  button_state = digitalRead(5);
  if (safety == 0)
  { // if safety is eqaul to 0
    if (button_state == HIGH)
    {
      safety = 1;
      delay(2000);
    }
  }
  else
  { // if safety is equal to 1
    if (button_state == HIGH)
    {
      safety = 0;
      delay(2000);
    }
    if (servo_dir == 0)
    {
      position += 1;
    }
    else
    {
      position -= 1;
    }
  }
  if (position == 0)
  {
    servo_dir = 0;
  }
  else if (position == 180)
  {
    servo_dir = 1;
  }
  miniservo.write(position);
  delay(60);
}