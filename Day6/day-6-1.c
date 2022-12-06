#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int isunique(char *str);

int main()
{
	clock_t start, end;
        double cpu_time_used;
        start = clock();
        char *filename = "input_day6.txt";
        FILE *fp = fopen(filename, "r");
	
        if (fp == NULL)
        {
                printf("Error: could not open file %s", filename);
                return 1;
        }

	const unsigned MAX_LENGTH = 1024;
        char buffer[MAX_LENGTH];
	
	int i;

	char buff[4];

	char fullstring[MAX_LENGTH*8] = "";

	while (fgets(buffer, MAX_LENGTH, fp)){
		strcat(fullstring, buffer);
	
		
	}

	strncpy(buff, fullstring, 14);

        for (i = 13; i < strlen(fullstring); i++){
        	if (isunique(buff)){
            		break;
        	}
		
        	buff[i % 14] = fullstring[i];
     
	}
	printf("%d\n", i);
	printf("%s\n", buff);
	printf("%c\n", fullstring[i]);

	end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Took %f seconds\n", cpu_time_used);

	return 0;
}

int isunique(char *str){
	char temp[1000] = "";
	int i;
	int j = 0;
	for (i = 0; i < strlen(str); i++){

		if (strchr(temp, str[i]) == NULL){
			temp[j] = str[i];
			j++;	
		}
	}
	printf("%d\n", strlen(temp));
	return (strlen(str) == strlen(temp));
}
