#include "project.h"
#include "math.h"

int forward_direction(int delay, double angle){
    int num_iter = round(512 * angle/360);
    for (int i = 0; i <num_iter; ++i){
        A_Write(1);
        B_Write(0);
        C_Write(0);
        D_Write(0);
        CyDelay(delay);
        
        A_Write(0);
        B_Write(1);
        C_Write(0);
        D_Write(0);
        CyDelay(delay);        
        
        
                
        A_Write(0);
        B_Write(0);
        C_Write(1);
        D_Write(0);
        CyDelay(delay); 
        
                
        A_Write(0);
        B_Write(0);
        C_Write(0);
        D_Write(1);
        CyDelay(delay); 
    }
    return 0;
}

int backward_direction(int delay, double angle){
    int num_iter = round(512 * angle/360);
    for (int i = 0; i < num_iter; ++i){
        A_Write(0);
        B_Write(0);
        C_Write(0);
        D_Write(1);
        CyDelay(delay);
        
        A_Write(0);
        B_Write(0);
        C_Write(1);
        D_Write(0);
        CyDelay(delay);        
        
        
                
        A_Write(0);
        B_Write(1);
        C_Write(0);
        D_Write(0);
        CyDelay(delay); 
        
                
        A_Write(1);
        B_Write(0);
        C_Write(0);
        D_Write(0);
        CyDelay(delay); 
    }
    return 0;
}


int main(void)
{
    CyGlobalIntEnable;

    
    float velocity = 0.5; //desired motor speed in rpm
    int delay;
    int direction = -1; //backwards (cw/ outer clockwise)
    
    float angle = 90.0; //desired angle turn in degrees;
    
    delay = 3;
    forward_direction(delay, 90.0);
    CyDelay(1000);
    backward_direction(delay, 90.0);
}
