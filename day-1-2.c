#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main()
{
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
	int second = 0;
	int third = 0;

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
			printf("Elf %d has %d cals\n",cur_i, cur_sum);
                        if (cur_sum < third){
				cur_sum = 0;
			}
			else if(third <= cur_sum && cur_sum < second){
				third = cur_sum;
				cur_sum = 0;
			}
			else if (second <= cur_sum && cur_sum < max){
				third = second;
				second = cur_sum;
				cur_sum = 0;
			}
                        else if (max <= cur_sum){
                                third = second;
				second = max;
                                max = cur_sum;
                                cur_sum = 0;
                        }
			else{
				printf("You shouldn't be here...");
			}
		}

		else{
			
			cur_sum += atoi(buffer);
			printf("Cur cal %d\n", atoi(buffer));
			printf("Cur tot cal %d\n", cur_sum);
	
		}
	}
	// close the file
    	fclose(fp);
	printf("Max cals: %d\n", max);
	printf("Second cals: %d\n", second);
	printf("Third cals: %d\n", third);
	printf("Sum : %d\n", max+second+third);
    	return 0;

}



