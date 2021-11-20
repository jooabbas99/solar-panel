#define step_pin 3
#define dir_pin 2
#define MS1 5
#define MS2 4  
int dir;
int steps = 100;
//#include<AccelStepper.h>
//
//AccelStepper motor180(1,step_pin,dir_pin);
//long ta,tz;
//int move_end = 1;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
//  Serial.println("enter t dis a,z:");
// motor180.setMaxSpeed(500.0);
// motor180.setAcceleration(500.0);
// 
  pinMode(step_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  digitalWrite(step_pin, LOW);
  digitalWrite(dir_pin, LOW);
}

void loop() {
    digitalWrite(step_pin, HIGH);
    delay(1);
  digitalWrite(step_pin, LOW);
    delay(1);

}
