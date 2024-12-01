#include "Hippo_Logic.h"


void run_idle_state()
{
    ILI9341_DrawImage(0, 0, 240, 320, (const uint16_t*)frame_8_delay_0_67s);
    HAL_Delay(125);
    ILI9341_DrawImage(0, 0, 240, 320, (const uint16_t*)frame_3_delay_0_22s);
    HAL_Delay(125);
    ILI9341_DrawImage(0, 0, 240, 320, (const uint16_t*)frame_0_delay_0_22s);
    HAL_Delay(500);

}


void run_active_state()
{
    ILI9341_DrawImage(0, 0, 240, 320, (const uint16_t*)frame_8_delay_0_67s);
    HAL_Delay(125);
    ILI9341_DrawImage(0, 0, 240, 320, (const uint16_t*)frame_3_delay_0_22s);
    HAL_Delay(125);
    ILI9341_DrawImage(0, 0, 240, 320, (const uint16_t*)frame_0_delay_0_22s);
    HAL_Delay(500);
}