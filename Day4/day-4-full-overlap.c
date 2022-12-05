#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	clock_t start, end;
        double cpu_time_used;
        start = clock();
        char *filename = "input_day4.txt";
        FILE *fp = fopen(filename, "r");


        if (fp == NULL)
        {
                printf("Error: could not open file %s", filename);
                return 1;
        }

	const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];

	char * lower1, * upper1;
	char * lower2, * upper2;

	int intlower1, intupper1;
	int intlower2, intupper2;

	int fulllow, fullupp;

	int sum = 0;
	
	while (fgets(buffer, MAX_LENGTH, fp)){
	

		lower1 = strtok(buffer, ",-");	
		upper1 = strtok(NULL, ",-");
		lower2 = strtok(NULL, ",-");
		upper2 = strtok(NULL, ",-");

		intlower1 = atoi(lower1);
		intupper1 = atoi(upper1);
		intlower2 = atoi(lower2);
		intupper2 = atoi(upper2);
	
		fulllow = (intlower1 > intlower2) ? intlower1 : intlower2;
		fullupp = (intupper1 > intupper2) ? intupper2 : intupper1;

		sum += (0 > (fullupp - fulllow + 1)) ? 0 : (fullupp - fulllow + 1);		
	
	}
	
	printf("%d\n", sum);
	
	end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Took %f seconds\n", cpu_time_used);

	return 0;
}

