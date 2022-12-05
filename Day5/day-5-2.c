#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int MAX_STACK = 128;

char pop(char *stack);
void push(char *stack, char *topush);
void revstr(char *str);

int main()
{
	clock_t start, end;
        double cpu_time_used;
        start = clock();
        char *filename = "input_day5.txt";
        FILE *fp = fopen(filename, "r");


        if (fp == NULL)
        {
                printf("Error: could not open file %s", filename);
                return 1;
        }

	const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];
	
	char stack1[MAX_LENGTH] = "BVSNTCHQ";
	char stack2[MAX_LENGTH] = {"WDBG"};
	char stack3[MAX_LENGTH] = {"FWRTSQB"};
	char stack4[MAX_LENGTH] = {"LGWSZJDN"};
	char stack5[MAX_LENGTH] = {"MPDVF"};
	char stack6[MAX_LENGTH] = {"FWJ"};
	char stack7[MAX_LENGTH] = {"LNQBJV"};
	char stack8[MAX_LENGTH] = {"GTRCJQSN"};
	char stack9[MAX_LENGTH] = {"JSQCWDM"};

	char (*bigarr[9])[MAX_LENGTH];
	bigarr[0] = &stack1;
	bigarr[1] = &stack2;
	bigarr[2] = &stack3;
	bigarr[3] = &stack4;
	bigarr[4] = &stack5;
	bigarr[5] = &stack6;
	bigarr[6] = &stack7;
	bigarr[7] = &stack8;
	bigarr[8] = &stack9;


	int from;
	int to;
	int num;
	int i;

	char *curstring;

	char temp;

	char incrane[MAX_LENGTH] = "";

	while (fgets(buffer, MAX_LENGTH, fp)){
		if (buffer[0] != *"m")
			continue;
		memset(incrane,0,strlen(incrane));
		curstring = strtok(buffer, " ");
		num = atoi(strtok(NULL, " "));
		curstring = strtok(NULL, " ");
		from = atoi(strtok(NULL, " ")) - 1;		
		curstring = strtok(NULL, " ");
		to = atoi(strtok(NULL, " ")) - 1;

		for (i = 0; i < num; i++){
			temp = pop(*bigarr[from]);
			strncat(incrane, &temp, 1);
			
		
		}
		revstr(incrane);
		
		push(*bigarr[to], &incrane);
	
	}
	
	for (i = 0; i < 9; i++){
	
		printf("%s\n", *bigarr[i]);
	}
	end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Took %f seconds\n", cpu_time_used);

	return 0;
}

char pop(char *stack){
	char top = stack[strlen(stack)-1];
	stack[strlen(stack)-1] = '\0';
	
	return top;
}

void push(char *stack, char *topush){
	int i;	
	for (i = 0; i < strlen(topush); i++)
		strncat(stack, &topush[i], 1);
}

void revstr(char *str){
	int i, j;
	char temp;

	j = strlen(str)-1;
	i = 0;
	while(i<j){		
        	temp = str[j];
        	str[j] = str[i];
        	str[i] = temp;
		i++;
		j--;
    	}  
}


