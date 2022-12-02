#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int getscore(char me);
int choicescore(char my_throw, char opp_throw);

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
	
	char my_throw;
	char op_throw;

	while (fgets(buffer, MAX_LENGTH, fp)){
		//printf("%s\n", buffer);
		op_throw = buffer[0];
		my_throw = buffer[2];
		win_score = getscore(my_throw);
		choice_score = choicescore(my_throw, op_throw);
		//printf("%d\n", choice_score);
		score = score + win_score + choice_score;
	}

	printf("%d\n", score);
	
	end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Took %f seconds\n", cpu_time_used);

	return 0;
}

int getscore(char my_throw){
	if (my_throw == 'X')
		return 0;
	else if (my_throw == 'Y')
		return 3;
	else if (my_throw == 'Z')
		return 6;
	else 
		return -1;
}


int choicescore(char my_throw, char op_throw){
	if (op_throw == 'A' && my_throw == 'X')
                return 3;
        else if (op_throw == 'A' && my_throw == 'Y')
                return 1;
        else if (op_throw == 'A' && my_throw == 'Z')
                return 2;
        else if (op_throw == 'B' && my_throw == 'X')
                return 1;
        else if (op_throw == 'B' && my_throw == 'Y')
                return 2;
        else if (op_throw == 'B' && my_throw == 'Z')
                return 3;
        else if (op_throw == 'C' && my_throw == 'X')
                return 2;
        else if (op_throw == 'C' && my_throw == 'Y')
                return 3;
        else if (op_throw == 'C' && my_throw == 'Z')
                return 1;
        else
                return -1;	
}
