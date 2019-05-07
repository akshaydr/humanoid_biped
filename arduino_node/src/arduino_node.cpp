#include<ros.h>
#include <std_msgs/String.h>
#include<Arduino.h>
#include"Encoder.h"

ros::NodeHandle nh;
std_msgs::String msg;
ros::Publisher enpub("encoderFeedback_raw", &msg);

Encoder m1(2, 3);
Encoder m2(19, 18);

char en_str[100];

void setup(){
  nh.initNode();
  nh.advertise(enpub);
}

void loop(){
  long motor1 = m1.read();
  long motor2 = m2.read();

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
