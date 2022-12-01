#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
main()
{
	clock_t start, end;
        double cpu_time_used;
	start = clock();
	char *filename = "cals.txt";
    	FILE *fp = fopen(filename, "r");


        if (fp == NULL)
    	{
        	printf("Error: could not open file %s", filename);
        	return 1;
    	}

    	// read one character at a time and
    	// display it to the output

	int cur_sum = 0;
	int max = 0;
	int max_i = 0;

	int cur_i = 0;

	const unsigned MAX_LENGTH = 256;
   	char buffer[MAX_LENGTH];
	char* buf_p;
	while ((buf_p = fgets(buffer, MAX_LENGTH, fp))){
		//printf("Cur cal (correct) %s", buffer);
		//printf("cur cal (prev) %d\n", *buffer);
		//printf("Chars between: %d\n", strcmp(buffer, "\n"));
        	if (strcmp(buffer, "\n") == 3){
			
			//elves are 1 indexed so itterate index here
                        cur_i += 1;
			///printf("Elf %d has %d cals\n",cur_i, cur_sum);
                        if (cur_sum < max)
				cur_sum = 0;
                        else{
                                max_i = cur_i;
                                max = cur_sum;
                                cur_sum = 0;
                        }
		}

		else{
			
			cur_sum += atoi(buffer);
			//printf("Cur cal %d\n", atoi(buffer));
			//printf("Cur tot cal %d\n", cur_sum);
	
		}
	}
	// close the file
    	fclose(fp);
	printf("Max cals: %d\n", max);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Took %f seconds\n", cpu_time_used);
    	return 0;

}



