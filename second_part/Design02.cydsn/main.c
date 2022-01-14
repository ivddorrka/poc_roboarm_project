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
    control_direction(30, direction, num_servo);
    CyDelay(10);
    
    control_direction(speed, direction, num_servo);
    CyDelay(time_to_work);

    control_direction(0, direction, num_servo);
    
    CyDelay(break_time);
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

void algo_oreo() {
    int speed[] = {25, 27, 27, 50};
    int direction_forward[] = {0, 0, 0, 0};
    int direction_backward[] = {1, 1, 1, 1};
    
    move(speed, direction_forward, 3000, 2000);
    CyDelay(100);
    
    
    
    // capture
    for (int i = 1; i < 4; i++) {
        speed[i] = 0;
    }
    
    move(speed, direction_backward, 2000, 2000);
    CyDelay(100);
    
    //get up
    speed[0] = 0;
    for (int i = 1; i < 3; i++) {
        speed[i] = 50;
    } 
    speed[3] = 60;
    
    move(speed, direction_backward, 500, 100);
    CyDelay(100);
    
    
    for (int i = 1; i < 3; i++) {
        speed[i] = 20;
    } 
    
    move(speed, direction_backward, 1500, 100);
    CyDelay(100);
    
    //down to the cup
    
    speed[3] = 0;
    
    move(speed, direction_forward, 2000, 2000);
    CyDelay(100);
    
    // get up
    speed[3] = 20;
    for (int i = 1; i < 3; i++) {
        speed[i] = 50;
    } 
    
    move(speed, direction_backward, 500, 100);
    CyDelay(100);
    
    for (int i = 1; i < 3; i++) {
        speed[i] = 20;
    }
    speed[3] = 40;
    
    
    move(speed, direction_backward, 2500, 2000);
    CyDelay(100);
    
    //bow
    speed[3] = 0;
    move(speed, direction_forward, 500, 2000);
    CyDelay(100);
    
    
    //feed
    for (int i = 1; i < 4; i++) {
        speed[i] = 0;
    }
    speed[0] = 25;
   
    move(speed, direction_forward, 2000, 2000);
    CyDelay(100);

    
    //stop
    speed[0] = 0;
    
    
    move(speed, direction_forward, 100, 20000);
    CyDelay(100);
}

void algo_jengu() {
    
    int speed[] = {20, 60, 0, 35};
    int direction_forward[] = {0, 0, 0, 0};
    int direction_backward[] = {1, 1, 1, 1};
    
    
    //bow down
    move(speed, direction_forward, 3000, 2000);
    CyDelay(100);
    
    speed[1] = 50;
    speed[0] = 30;

    speed[3] = 0;
    move(speed, direction_backward, 1500, 2000);
    CyDelay(100);
    
    
    speed[1] = 0;
    speed[0] = 0;
    speed[3] = 50;
    
    move(speed, direction_forward, 2000, 2000);
    CyDelay(100);
    
    for (int i = 0; i < 4; i++) {
        speed[i] = 0;
    }
    
    move(speed, direction_forward, 100, 20000);
    CyDelay(100);
    
    
}


CY_ISR( Pin_SW2_Handler){
    


    algo_oreo();
           
    
    Pin_SW2_ClearInterrupt();
    
}


int main(void)
{
    CyGlobalIntEnable; 

    Pin_SW2_int_StartEx( Pin_SW2_Handler );
    
    for(;;)
    {
        
    }
    
    

}
