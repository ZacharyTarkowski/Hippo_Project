#include "Hippo_Logic.h"


void run_idle_state()
{
    ILI9341_Draw_Run_Length_Encoded_Image((const uint16_t*)Hippo_Asleep_1, sizeof(Hippo_Asleep_1)/sizeof(uint16_t) );
    HAL_Delay(250);
    ILI9341_Draw_Run_Length_Encoded_Image((const uint16_t*)Hippo_Asleep_2, sizeof(Hippo_Asleep_2)/sizeof(uint16_t) );
    HAL_Delay(250);
}

void run_active_state()
{
    ILI9341_Draw_Run_Length_Encoded_Image((const uint16_t*)Hippo_Awake_1, sizeof(Hippo_Awake_1)/sizeof(uint16_t) );
    HAL_Delay(125);
    ILI9341_Draw_Run_Length_Encoded_Image((const uint16_t*)Hippo_Awake_2, sizeof(Hippo_Awake_2)/sizeof(uint16_t) );
    HAL_Delay(125);
}