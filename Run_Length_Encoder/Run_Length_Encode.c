#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
//#include "Raw_Images.h"

#include "hippo_asleep_unfinished.h"
#include "hippo_awake_unfinished.h"

#define rle_element uint16_t
#define image_name Untitled_Artwork

#define GET_VARIABLE_NAME(Variable) (#Variable)
#define OUTPUT_HEADER "HIPPO_IMAGES_H"

rle_element test_vector[] = {0,0,0,0,0,1,1,1,1,1,2,2,2,2};
char buf[50];

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

void write_and_encode(FILE *file, rle_element* image_buf, char* name, int bufsize)
{
	int len = ( bufsize / sizeof(rle_element) );
    
    rle_element* result = encode(image_buf, &len);
	
	
	
	sprintf(buf,"static const uint16_t %s[] = { \n",name);
	fwrite(buf, sizeof(char), strlen(buf), file);
	
	
	
	for(int i = 0; i<len; i++)
    {
		sprintf(buf,"0x%04x,",result[i]);
        fwrite(buf, sizeof(char), strlen(buf), file);
    }
	
	sprintf(buf,"\n}; \n");
	fwrite(buf, sizeof(char), strlen(buf), file);
	
	free(result);
}

int main()
{

	FILE *file;
    file = fopen("Output.txt", "wb");
	
	sprintf(buf,"#ifndef %s \n#define %s \n#include <stdint.h>\n", OUTPUT_HEADER , OUTPUT_HEADER);
	fwrite(buf, sizeof(char), strlen(buf), file);

	write_and_encode(file, hippo_awake_unfinished, "hippo_awake_unfinished", sizeof(hippo_awake_unfinished));
	write_and_encode(file, hippo_asleep_unfinished, "hippo_asleep_unfinished", sizeof(hippo_asleep_unfinished));	

	sprintf(buf,"#endif \n");
	fwrite(buf, sizeof(char), strlen(buf), file);
    
	fclose(file);
	
	printf("Done\n");

    return 0;
}