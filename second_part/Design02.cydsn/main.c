/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
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

void move_servo(uint32 time_to_work, uint32 break_time, int speed, int direction,  int num_servo) {
    control_direction(30, direction, num_servo);
    CyDelay(10);
    
    control_direction(speed, direction, num_servo);
    CyDelay(time_to_work);
    
    control_direction(0, direction, num_servo);
    CyDelay(break_time);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    PWM_1_Start();
    PWM_2_Start();
    PWM_3_Start();
    PWM_4_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    //PWM_2_Start();
    
    //int cmp = 70;
      
    control_direction(30, 1, 1);
    control_direction(30, 1, 2);
    control_direction(30, 1, 3);
    control_direction(30, 1, 4);
    CyDelay(10);
    for(;;)
    {
       //Pin_Green_Write(Pin_SW2_Read());
       
        //move_servo(500, 500, 10, 1, 1);
        
        //move_servo(500, 500, 20, 0, 2);
        
        //move_servo(1000, 500, 30, 1, 3);
        
        //move_servo(2000, 500, 10, 0, 4);
        
        
        
        //move_servo(500, 500, 10, 0, 1);
        
        //move_servo(500, 500, 20, 1, 2);
        
        //move_servo(1000, 500, 30, 0, 3);
        
        //move_servo(2000, 500, 10, 1, 4);
        
    
    
        
        //PWM_1_WriteCompare(cmp);
        //Pin_1_Write(1);
        //Pin_2_Write(0);
        //CyDelay(3000);
      
      

        control_direction(20, 1, 1);
        control_direction(20, 1, 2);
        control_direction(20, 1, 3);
        control_direction(20, 1, 4);
        
        CyDelay(1000);
        
        control_direction(0, 1, 1);
        control_direction(0, 1, 2);
        control_direction(0, 1, 3);
        control_direction(0, 1, 4);
        
        CyDelay(3000);
          
        control_direction(30, 0, 1);
        control_direction(30, 0, 2);
        control_direction(30, 0, 3);
        control_direction(30, 0, 4);
        
        
        CyDelay(10);
        
        control_direction(20, 0, 1);
        control_direction(20, 0, 2);
        control_direction(20, 0, 3);
        control_direction(20, 0, 4);
        
        CyDelay(1000);
        
        control_direction(0, 0, 1);
        control_direction(0, 0, 2);
        control_direction(0, 0, 3);
        control_direction(0, 0, 4);
        
        CyDelay(5000);
        
        control_direction(30, 1, 1);
        control_direction(30, 1, 2);
        control_direction(30, 1, 3);
        control_direction(30, 1, 4);
        
        CyDelay(10);
        /*cmp = 70;*/
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
