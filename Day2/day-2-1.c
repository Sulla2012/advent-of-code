#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int getscore(char opp, char me);
int choicescore(char me);

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
		//printf("%d\n", op_throw);
		win_score = getscore(op_throw, my_throw);
		choice_score = choicescore(my_throw);
		//printf("%d\n", choice_score);
		score = score + win_score + choice_score;
	}

	printf("%d\n", score);
	
	end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Took %f seconds\n", cpu_time_used);

	return 0;
}

int getscore(char op_throw, char my_throw){
	if (op_throw == 'A' && my_throw == 'X')
		return 3;
	else if (op_throw == 'A' && my_throw == 'Y')
		return 6;
	else if (op_throw == 'A' && my_throw == 'Z')
		return 0;
	else if (op_throw == 'B' && my_throw == 'X')
		return 0;
	else if (op_throw == 'B' && my_throw == 'Y')
		return 3;
	else if (op_throw == 'B' && my_throw == 'Z')
		return 6;
	else if (op_throw == 'C' && my_throw == 'X')
		return 6;
	else if (op_throw == 'C' && my_throw == 'Y')
		return 0;
	else if (op_throw == 'C' && my_throw == 'Z')
		return 3;
	else
		return -1;
}


int choicescore(char me){
	if (me == 'X')
		return 1;
	else if (me == 'Y')
		return 2;
	else if (me == 'Z')
		return 3;
	else
		return -1;
}
