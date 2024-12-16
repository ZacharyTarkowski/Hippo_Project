#include "Hippo_Logic.h"


void run_idle_state()
{
    ILI9341_Draw_Run_Length_Encoded_Image((const uint16_t*)encoded_wake1, sizeof(encoded_wake1)/sizeof(uint16_t) );
    HAL_Delay(250);
    ILI9341_Draw_Run_Length_Encoded_Image((const uint16_t*)encoded_wake1, sizeof(encoded_wake1)/sizeof(uint16_t) );
    HAL_Delay(250);
}

void run_active_state()
{
    ILI9341_Draw_Run_Length_Encoded_Image((const uint16_t*)encoded_wake1, sizeof(encoded_wake1)/sizeof(uint16_t) );
    HAL_Delay(250);
    ILI9341_Draw_Run_Length_Encoded_Image((const uint16_t*)encoded_wake2, sizeof(encoded_wake2)/sizeof(uint16_t) );
    HAL_Delay(250);
}