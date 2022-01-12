#include "project.h"


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

void stop_servo(int num) {
    if (num == 1) {
        PWM_1_Stop();
    }
    else if (num == 2) {
        PWM_2_Stop();
    }
    else if (num == 3) {
        PWM_3_Stop();
    }
    else {
        PWM_4_Stop();
    }
        
}


void start_servo(int num) {
    if (num == 1) {
        PWM_1_Start();
    }
    else if (num == 2) {
        PWM_2_Start();
    }
    else if (num == 3) {
        PWM_3_Start();
    }
    else {
        PWM_4_Start();
    }
        
}

void move_servo(int time_to_work, int break_time, int speed, int direction,  int num_servo) {
    start_servo(num_servo);
    //PWM_3_Start();
    control_direction(30, direction, num_servo);
    //control_direction(30, direction, num_servo - 1);
    CyDelay(10);
    
    control_direction(speed, direction, num_servo);
    //control_direction(speed, direction, num_servo - 1);
    CyDelay(time_to_work);

    control_direction(0, direction, num_servo);
    //control_direction(0, direction, num_servo - 1);
    CyDelay(break_time);
    //PWM_2_Stop();
    //PWM_3_Stop();
    stop_servo(num_servo);
    
}


void move(int speed[], int direction[], int time_to_work, int time_break) {
    for (int i = 1; i <= 4; i++) {
        start_servo(i);
       }

    for (int i = 0; i < 4; i++) {
        control_direction(30, direction[i], i + 1);
       }
    CyDelay(10);
    
    for (int i = 0; i < 4; i++) {
        control_direction(speed[i], direction[i], i + 1);
       }
    CyDelay(time_to_work);
    
    for (int i = 0; i < 4; i++) {
        control_direction(0, direction[i], i + 1);
       }
    CyDelay(time_break);
    
    for (int i = 1; i <= 4; i++) {
        stop_servo(i);
       }
    
}

void algo() {
    int speed[] = {20, 20, 20, 20};
    int direction_forward[] = {0, 0, 0, 0};
    int direction_backward[] = {1, 1, 1, 1};
    
    move(speed, direction_forward, 3000, 1000);
    CyDelay(100);

    for (int i = 1; i < 4; i++) {
        speed[i] = 0;
    }
    move(speed, direction_backward, 3000, 2000);
    CyDelay(100);
    
    speed[0] = 0;
    for (int i = 1; i < 4; i++) {
        speed[i] = 20;
    }
    move(speed, direction_backward, 2500, 1000);
    CyDelay(100);
    
    for (int i = 1; i < 4; i++) {
        speed[i] = 0;
    }
    speed[0] = 20;
    move(speed, direction_forward, 2000, 2000);
    CyDelay(100);
    speed[0] = 0;
    
    for (int i = 1; i < 4; i++) {
        speed[i] = 20;
    }
    move(speed, direction_forward, 2500, 1000);
    CyDelay(100);
    speed[0] = 20;
    move(speed, direction_backward, 3000, 1000);
    CyDelay(100);
    
    
    
    
}


int main(void)
{
    CyGlobalIntEnable; 
    
    int speed[] = {20, 20, 20, 20};
    int direction_forward[] = {0, 0, 0, 0};
    int direction_backward[] = {1, 1, 1, 1};

    for(;;)
    {
        algo();
        
        /*
        move(speed, direction_forward, 3000, 1000);
        CyDelay(1000);
        //speed = {20, 0, 0, 0};
        move_servo(3000, 1000, 20, 1, 1);
        CyDelay(1000);
        
        //speed[0] = 0;
        //move(speed, direction_backward, 2000, 1000);
        //CyDelay(1000);
        //move_servo(1000, 1000, 20, 0, 1);
        //CyDelay(1000);
        //move(speed, direction_backward, 2000, 1000);
        //CyDelay(1000);
        //speed[0] = 20;
        move(speed, direction_backward, 5000, 1000);
        CyDelay(1000);*/
        
        //algo();
        
        /*
        move(speed, direction_forward, 3000, 2000);
        speed[1] = 0;
        speed[2] = 0;
        speed[3] = 0;
        CyDelay(100);
        
        move(speed, direction_backward, 3000, 2000);
        CyDelay(100);
        move(speed, direction_forward, 3000, 2000);
        CyDelay(100);
        
        speed[1] = 20;
        speed[2] = 20;
        speed[3] = 20;
        CyDelay(100);
        
        move(speed, direction_backward, 4000, 2000);
        CyDelay(100);
        */
        
        //move(speed, direction_backward, 4000, 2000);
     
        
        //move_servo(500, 1000, 20, 1, 4); // close the hand

    }

}
