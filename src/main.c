#include "project.h"
#include <math.h>

void pin_info(int direction, int curr_pin){
    int arr[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; ++i){
        if (i == curr_pin)
            arr[i] = 1;
        else
            arr[i] = 0;
    }
    if (direction == 1){
        A_Write(arr[0]);
        B_Write(arr[1]);
        C_Write(arr[2]);
        D_Write(arr[3]);
    }
    else{
        A_Write(arr[3]);
        B_Write(arr[2]);
        C_Write(arr[1]);
        D_Write(arr[0]);
    }
}


void forward_direction(int delay, double angle, int direction){
    int num_iter = round(512 * angle/360);
    for (int i = 0; i < num_iter; ++i){
        for (int j = 0; j < 4; ++j){
            pin_info(direction, j);
            CyDelay(delay);
        }
    }
}

int main(void)
{
    CyGlobalIntEnable;

    
    int delay;
    int direction = 1; //backwards (cw/ outer clockwise)
    
    float angle = 360.0; //desired angle turn in degrees;
    
    delay = 3;
    forward_direction(delay, angle, direction);
    direction = -1;
    CyDelay(1000);
    angle = 90.0;
    forward_direction(delay, angle, direction);
}
