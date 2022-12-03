#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char firstmatch(char first[], char second[]);
int valchar(char match[]);

int main()
{
	clock_t start, end;
        double cpu_time_used;
        start = clock();
        char *filename = "input_day3.txt";
        FILE *fp = fopen(filename, "r");


        if (fp == NULL)
        {
                printf("Error: could not open file %s", filename);
                return 1;
        }

	const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];
	
	char first[MAX_LENGTH/2];
	char second[MAX_LENGTH/2];

	char match;

	int sum = 0;

	while (fgets(buffer, MAX_LENGTH, fp)){
		memset(first,0,strlen(first));
                memset(second,0,strlen(second));
		size_t half_length = strlen(buffer)/2;	
	
		strncpy(first, buffer, half_length);
		strncpy(second, &buffer[half_length], half_length);
		//printf("%s\n", first);	
		//printf("%s\n", second);
		match = firstmatch(first, second);
		//printf("%c\n", match);	
		//printf("%i\n", valchar(&match));
		sum += valchar(&match);
		//if (valchar(&match) == -1)
		//	break;
		
	}	
	printf("%d\n", sum);	
	end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Took %f seconds\n", cpu_time_used);

	return 0;
}

char firstmatch(char first[], char second[]){
	int i, j;
	for (i = 0; first[i] != '\0'; i++){
		for (j = 0; second[j] != '\0'; j++){
		       if (first[i] == second[j])
			       return first[i];
		}
	}
	printf("Hmmmm");
	return '\0';
}


int valchar(char match[]){
	if (64< *match && *match < 91)
		return *match - 38;
	else if (96 < *match && *match < 123)
		return *match - 96;
	else
		return -1;
}
