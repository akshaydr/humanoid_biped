#include<ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float64.h>
#include<Arduino.h>
#include"Encoder.h"

ros::NodeHandle nh;
std_msgs::String msg;
ros::Publisher enpub("encoderFeedback_raw", &msg);

Encoder m1(2, 3);
Encoder m2(19, 18);

const int dir1 = 6;
const int pwm1 = 7;
const int dir2 = 8;
const int pwm2 = 9;

char en_str[100];

void messageCb( const std_msgs::Float64& toggle_msg){
    if (toggle_msg.data == 10.0) {
      digitalWrite(dir1,HIGH) ;
      digitalWrite(dir2,HIGH) ;
      analogWrite(pwm1,200) ;
      analogWrite(pwm2,200) ;
    }
    else {
      digitalWrite(dir1,HIGH) ;
      digitalWrite(dir2,LOW) ;
      analogWrite(pwm1,0) ;
      analogWrite(pwm2,0) ;
    }
}

ros::Subscriber<std_msgs::Float64> drsub("base_drive", &messageCb );

void setup(){
  nh.initNode();

  pinMode(dir1, OUTPUT) ; 	//Logic pins are also set as output
  pinMode(pwm1, OUTPUT) ; 	//Logic pins are also set as output
  pinMode(dir2, OUTPUT) ;
  pinMode(pwm2, OUTPUT) ;

  nh.advertise(enpub);
  nh.subscribe(drsub);
}

void loop(){
  long motor1 = m1.read();
  long motor2 = m2.read();

  pinMode(dir1, OUTPUT) ; 	//Logic pins are also set as output
  pinMode(pwm1, OUTPUT) ; 	//Logic pins are also set as output
  pinMode(dir2, OUTPUT) ;
  pinMode(pwm2, OUTPUT) ;

  char m1[10];
  dtostrf(motor1, 6, 2, m1);

  char m2[10];
  dtostrf(motor2, 6, 2, m2);

  String s = String(m1) + "," + String(m2);

  s.toCharArray(en_str, 100);

  msg.data = en_str;

  enpub.publish(&msg);
  nh.spinOnce();
}
