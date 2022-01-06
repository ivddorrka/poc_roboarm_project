#include "project.h"

//void stop(int
void control_direction(int speed_percent, int direction, int num_servo) {
    uint8 pin_val = 0;
    if (direction == 0) {
        speed_percent = 100 - speed_percent;
        pin_val = 1;
    }
    
    if (num_servo == 1) {
        PWM_1_WriteCompare(speed_percent);
        Pin_pair01_Write(pin_val);
    }
    
    else if (num_servo == 2) {
        PWM_2_WriteCompare(speed_percent);
        Pin_pair02_Write(pin_val);
    }
    
    else if (num_servo == 3) {
        PWM_3_WriteCompare(speed_percent);
        Pin_pair03_Write(pin_val);
    }
    
    else if (num_servo == 4) {
        PWM_4_WriteCompare(speed_percent);
        Pin_pair04_Write(pin_val);
    }    
}

void move_servo(int time_to_work, int break_time, int speed, int direction,  int num_servo) {
    control_direction(30, direction, num_servo);
    CyDelay(10);
    
    control_direction(speed, direction, num_servo);
    CyDelay(time_to_work);

    control_direction(0, direction, num_servo);
    CyDelay(break_time);
    
}


int main(void)
{
    CyGlobalIntEnable; 
    
    PWM_1_Start();
    PWM_2_Start();
    PWM_3_Start();
    PWM_4_Start();


    for(;;)
    {

        
        move_servo(500, 1000, 20, 0, 1);
        move_servo(500, 1000, 20, 0, 2);
        move_servo(500, 1000, 20, 0, 3);
        move_servo(500, 1000, 20, 0, 4);


        move_servo(500, 1000, 20, 1, 1);
        move_servo(500, 1000, 20, 1, 2);
        move_servo(500, 1000, 20, 1, 3);
        move_servo(500, 1000, 20, 1, 4);


    }
}
