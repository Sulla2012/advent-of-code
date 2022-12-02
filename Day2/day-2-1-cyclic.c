#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int getscore(int opp, int me);


int main()
{
	clock_t start, end;
        double cpu_time_used;
        start = clock();
        char *filename = "day2_input.txt";
        FILE *fp = fopen(filename, "r");


        if (fp == NULL)
        {
                printf("Error: could not open file %s", filename);
                return 1;
        }

	int score = 0;

	int win_score = 0;
	int choice_score = 0;

	char *buf_p;

	const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];
	
	int my_throw;
	int op_throw;

	while (fgets(buffer, MAX_LENGTH, fp)){
		//printf("%s\n", buffer);
		op_throw = buffer[0]-65;
		my_throw = buffer[2]-88;
		//printf("%d\n", my_throw);
		win_score = getscore(op_throw, my_throw);
		
		//printf("%d\n", choice_score);
		score = score + win_score + my_throw; 
	}

	printf("%d\n", score);
	
	end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Took %f seconds\n", cpu_time_used);

	return 0;
}

int getscore(int op_throw, int my_throw){
	if (op_throw == my_throw)
		return 3;
	else if (((my_throw + 1) % 3) == op_throw % 3)
		return 0;
	else
		return 6;

}



