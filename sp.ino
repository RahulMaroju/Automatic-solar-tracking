#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
short int rot;
/* rot Direction of rotation
 *  0   None
 *  1   Clockwise
 *  -1  Anti-clockwise
 */
int p;    // variable to store the servo position

short int find_rot (void);                                                                                                                                                                                                                                                                                                                                                                                                              

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  p=myservo.read();
}

void loop() {
  while (rot!=0)  {
    rot = find_rot();
    delay(1000);
  }
  rot = find_rot();
}

short int find_rot(void) {
  short int r;
  int x, y;
  x=analogRead(A0);
  if (p<180)  {
    p++;
  }
  myservo.write(p);
  y=analogRead(A0);
  if (y > x) { //Light of higher intensity is detected
    r=1;
  }
  else  {
    p--;
    if (p>0)  {
      p--;
    }
    myservo.write(p);
    y = analogRead(A0);
    if (y > x)  {
      r = -1;
    }
    else  {
      p++;
      r = 0;
    }
  }
  return r;
}

