/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 16 servos, one after the other

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!根据您的伺服系统，脉冲宽度最小值和最大值可能会有所不同，您希望这些值尽可能小/大，而不会触发最大范围的硬停止。 你必须根据需要调整它们，以配合你所拥有的舵机！
#define SERVOMIN  130 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)



void turn_angle(int which, float angle){
  float temp = 2.555 * angle + 160;
  pwm.setPWM(which, 0, temp);
}

float k;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates模拟舵机运行在〜60 Hz更新
  k = (SERVOMAX - SERVOMIN)/180;
  Serial.println("we can start");
  stand();
  delay(5000);
}

void stand(){
  turn_angle(0,105);turn_angle(4,25);turn_angle(8,40);
  turn_angle(1,60);turn_angle(5,125);turn_angle(9,130); 
  turn_angle(2,95);turn_angle(6,25);turn_angle(10,40);
  turn_angle(3,70);turn_angle(7,135);turn_angle(11,130);
  delay(200);
}
void go_1(){
  turn_angle(0,105);turn_angle(4,25);turn_angle(8,40);
  turn_angle(1,20);turn_angle(5,145);turn_angle(9,150); 
  turn_angle(2,95);turn_angle(6,25);turn_angle(10,40);
  turn_angle(3,90);turn_angle(7,115);turn_angle(11,95);
  delay(200);
}
void go_2(){
  turn_angle(0,105);turn_angle(4,25);turn_angle(8,40);
  turn_angle(1,80);turn_angle(5,105);turn_angle(9,90);
  turn_angle(2,95);turn_angle(6,25);turn_angle(10,40);
  turn_angle(3,30);turn_angle(7,145);turn_angle(11,148);
  delay(200);
}
void go_3(){
  turn_angle(0,150);turn_angle(4,15);turn_angle(8,30);
  turn_angle(1,60);turn_angle(5,125);turn_angle(9,130); 
  turn_angle(2,65);turn_angle(6,45);turn_angle(10,67);
  turn_angle(3,70);turn_angle(7,135);turn_angle(11,130);
  delay(200);
}
void go_4(){
  turn_angle(0,80);turn_angle(4,40);turn_angle(8,75);
  turn_angle(1,60);turn_angle(5,125);turn_angle(9,130); 
  turn_angle(2,150);turn_angle(6,15);turn_angle(10,20);
  turn_angle(3,70);turn_angle(7,135);turn_angle(11,130);
  delay(200);
}
void back_1(){
  turn_angle(0,105);turn_angle(4,25);turn_angle(8,40);
  turn_angle(1,80);turn_angle(5,105);turn_angle(9,90); 
  turn_angle(2,95);turn_angle(6,25);turn_angle(10,40);
  turn_angle(3,30);turn_angle(7,145);turn_angle(11,148);
  delay(200);
}
void back_2(){
  turn_angle(0,105);turn_angle(4,25);turn_angle(8,40);
  turn_angle(1,20);turn_angle(5,145);turn_angle(9,150); 
  turn_angle(2,95);turn_angle(6,25);turn_angle(10,40);
  turn_angle(3,90);turn_angle(7,115);turn_angle(11,95);
  delay(200);
}
void back_3(){
  turn_angle(0,80);turn_angle(4,40);turn_angle(8,75);
  turn_angle(1,60);turn_angle(5,125);turn_angle(9,130); 
  turn_angle(2,150);turn_angle(6,15);turn_angle(10,20);
  turn_angle(3,70);turn_angle(7,135);turn_angle(11,130);
  delay(200);
}
void back_4(){
  turn_angle(0,150);turn_angle(4,15);turn_angle(8,30);
  turn_angle(1,60);turn_angle(5,125);turn_angle(9,130); 
  turn_angle(2,75);turn_angle(6,45);turn_angle(10,77);
  turn_angle(3,70);turn_angle(7,135);turn_angle(11,130);
  delay(200);
}

void go(){
  go_1();
  stand();
  go_2();
  go_3();
  stand();
  go_4();  
}
void back(){
  back_1();
  stand();
  back_2();
  back_3();
  stand();
  back_4();
}
void loop() {
  back();
}


