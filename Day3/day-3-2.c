#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char matchthree(char first[], char second[], char third[]);
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
	
	char first[MAX_LENGTH];
	char second[MAX_LENGTH];
	char third[MAX_LENGTH];

	char match;

	int sum = 0;
	int j = 0;
	while (fgets(buffer, MAX_LENGTH, fp)){

		if (j % 3 == 0){
			
			j++;
			strncpy(first, buffer, strlen(buffer));
			
		}
		else if (j % 3 == 1){
			j++;
			strncpy(second, buffer, strlen(buffer));
		}

		else {
			j++;
			
			strncpy(third, buffer, strlen(buffer)); 
			
			match = matchthree(first, second, third);
		
			
			sum += valchar(&match);
			memset(first,0,strlen(first));
                	memset(second,0,strlen(second));
			memset(third, 0, strlen(third));
			
		}	

		
	}	
	printf("%d\n", sum);	
	end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Took %f seconds\n", cpu_time_used);

	return 0;
}


char matchthree(char first[], char second[], char third[]){
	int i, j, k;
	char *matchptr;
	
	for (i = 0; first[i] != '\0'; i++){
		
		for (j = 0; second[j] != '\0'; j++){
			
			if (first[i] == second[j]){
				
				for (k = 0; third[k] != '\0'; k++){
					if (second[j] == third[k]){
						return first[i];
					}
				}
			}
		}
	}
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
