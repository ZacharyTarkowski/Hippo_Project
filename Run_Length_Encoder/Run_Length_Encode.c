#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Core/Inc/Hippo_Images.h"

#define MAX_RLEN 50

/* Returns the Run Length Encoded string for the 
source string src */
char* encode(char* src)
{
	int rLen;
	char count[MAX_RLEN];
	int len = strlen(src);

	/* If all characters in the source string are different, 
	then size of destination string would be twice of input string.
	For example if the src is "abcd", then dest would be "a1b1c1d1"
	For other inputs, size would be less than twice. */
	char* dest = (char*)malloc(sizeof(char) * (len * 2 + 1));

	int i, j = 0, k;

	/* traverse the input string one by one */
	for (i = 0; i < len; i++) {

		/* Copy the first occurrence of the new character */
		dest[j++] = src[i];

		/* Count the number of occurrences of the new character */
		rLen = 1;
		while (i + 1 < len && src[i] == src[i + 1]) {
			rLen++;
			i++;
		}

		/* Store rLen in a character array count[] */
		sprintf(count, "%d", rLen);

		/* Copy the count[] to destination */
		for (k = 0; *(count + k); k++, j++) {
			dest[j] = count[k];
		}
	}

	/*terminate the destination string */
	dest[j] = '\0';
	return dest;
}

/*driver program to test above function */
int main(int argc, char **argv)
{
	// FILE *file;
    // file = fopen(argv[1], "r'");
    // char *content;
    // long file_size;
	
    // // Move the file pointer to the end to get the file size
    // fseek(file, 0, SEEK_END);
    // file_size = ftell(file);
    // rewind(file);

    // // Allocate memory to hold the contents of the file
    // content = (char *)malloc(file_size + 1); // +1 for null terminator

    // // Read the file content into the string
    // fread(content, 1, file_size, file);
    // content[file_size] = '\0'; // Null-terminate the string

    // // Print the file content
    // printf("File contents:\n%s\n", content);

    // char* res = encode(content);
    // printf("Encoded %s",res);

    // // Clean up
    // free(content);
    // fclose(file);
    // free(res);

	FILE *file;
    file = fopen("Output.txt", "rw'");
    char *content;

	char* res = encode(Crasher_Wake);


	free(res);

    return 0;
}
