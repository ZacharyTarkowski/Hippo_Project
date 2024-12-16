#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "Raw_Images.h"

#define rle_element uint16_t

rle_element test_vector[] = {0,0,0,0,0,1,1,1,1,1,2,2,2,2};

rle_element* encode(rle_element* image, int* len)
{
    int original_len = *len;
    rle_element* result = malloc(sizeof(rle_element) * (original_len*2 + 1));
    
    int i = 0; 
    int result_i = 0;;
    while(i<original_len)
    {
        rle_element current_element = image[i];
        rle_element curr_count = 0;
        
        while(image[i] == current_element)
        {
            curr_count++;
            i++;
        }
        
        result[result_i] = curr_count;
        result[result_i + 1] = current_element;
        result_i += 2;
    }
    
    *len = result_i;
    
    return result;
}

int main()
{

    int len = ( sizeof(frame_0_delay_0_22s) / sizeof(rle_element) );
    
    rle_element* result = encode(frame_0_delay_0_22s, &len);
    
    
    //temp printing output
    for(int i = 0; i<len; i++)
    {
        printf("%x ",result[i]);
    }
    //do file output here

	FILE *file;
    file = fopen("Output.txt", "wb");
	//fwrite(result, sizeof(rle_element), len, file);

	char buf[50];
	sprintf(buf,"Length is %d\n",len);
	fwrite(buf, sizeof(char), strlen(buf), file);

	for(int i = 0; i<len; i++)
    {
		sprintf(buf,"0x%04x,",result[i]);
        fwrite(buf, sizeof(char), strlen(buf), file);
    }
    
	fclose(file);
    free(result);
    return 0;
}