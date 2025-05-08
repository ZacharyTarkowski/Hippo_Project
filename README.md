# Hippo_Project

Project for my Mother, who is a teacher with a hippo themed classroom. The animation I will use is a hippo waving when the IR sensor is triggered, and sleeping when not triggered. Until I get the art for that, the placeholder is Crasher Wake from Pokemon.

Plays an idle animation until an IR sensor is triggered, then plays the active animation on a TFT screen.
"Animation" is a strong word, it rotates between a series of pictures.

Project uses an STM32 STM32F401CCU6 and ILI9341 TFT lcd with an IR sensor.

Lazy hack to not use the SD card is to run-length encode the images. Encoder is included, it should spit out a C array to pop into Hippo_Images.h

Credit to :
https://github.com/afiskon/stm32-ili9341 (draw_image doesnt work for me btw)
https://github.com/martnak/STM32-ILI9341 (draw image works but screen clear is significantly slower than TFT lib 1's)
