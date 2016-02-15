//Arbotix AX-12 Haptic Feedback demo code
//Andrew Bischoff



//import ax12 library to send DYNAMIXEL commands
#include <ax12.h>
#include <stdint.h>


#define base1 11
#define jointA1 12
#define jointB1 13
#define gripper1 14

#define base2 16
#define jointA2 17
#define jointB2 18
#define gripper2 19

void setup()
{
  
  //ax12SetRegister(51,0x3,11);//id set
  
  delay(100);//wait for servo to move
  ax12SetRegister(254,0x19,1);//led
  delay(10);
  ax12SetRegister(254,0x19,0);//led
  delay(10);
  ax12SetRegister(254,0x19,1);//led
  delay(10);
  ax12SetRegister(254,0x19,0);//led
  delay(10);
  
  
  
  ax12SetRegister2(254,0x06,100);//cw limit
  delay(10);
  ax12SetRegister2(254,0x08,1023-100);//ccw limit
  delay(10);
  ax12SetRegister2(254,0x20,0x06f);//move speed
  delay(10);
  

  ax12SetRegister(254,0x18,0);//torque enable
  delay(10);
  ax12SetRegister2(254,0x0e,0x3ff);//max torque
  delay(10);
  ax12SetRegister2(254,0x22,0x3ff);//torque limit
  delay(10);
  
  
  ax12SetRegister2(254,0x1e,1023/2);//move

  delay(1000);


 



  
  for(int i = 11; i <= 19; i++){
    
    //ax12SetRegister2(i,0x1e,1023/2-100);//move
    //delay(300);

    //ax12SetRegister2(i,0x1e,1023/2);//move
    //delay(300);

    //blink(i,2);
  }
  

  
  


  ax12SetRegister2(16,0x22,0x0);//torque limit
  delay(10);
  ax12SetRegister2(17,0x22,0x3F);//torque limit
  delay(10);
  ax12SetRegister2(18,0x22,0x3F);//torque limit
  delay(10);
  ax12SetRegister2(19,0x22,0x0);//torque limit
  delay(10);
  
  
  blink(254,10,50);

  


}

void loop(){

  
  copyPos(11,16);
  copyPos(12,17);
  copyPos(13,18);
  copyPos(14,19);
  
  
  

}



void copyPos(int to, int from){
  int pos;
  pos = ax12GetRegister(from,0x24,2);//present pos
  delay(1);
  ax12SetRegister2(to,0x1e,pos);//goal pos
  delay(1);
  
  
}








void blink(int id, int times){
  for(int i = 0; i < times; i++){
    ax12SetRegister(id,0x19,1);//led
    delay(100);
    ax12SetRegister(id,0x19,0);//led
    delay(100);
  }
}
void blink(int id, int times, int del){
  for(int i = 0; i < times; i++){
    ax12SetRegister(id,0x19,1);//led
    delay(del);
    ax12SetRegister(id,0x19,0);//led
    delay(del);
  }
}


