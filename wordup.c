//Author: Ana Hernandez-Mejia
//Purpose: Project 10
//Date: 4/23/24

#include <stdio.h>
#define WORD "mystery.txt"
#define SIZE 5

void user_input(char array1[], int i);
int fouWord(char array1[], char array2[]);
void cap_let(char array1[], char array2[]);
void wron_let(char array1[], char array2[], char array3[]);


int main(){
	FILE *fp1;
	char word[SIZE], guess[SIZE], arrow[SIZE];
	int i;
	int numguess = 0;
	int wordFou = 0;
	
	fp1 = fopen(WORD, "r");
	if(fp1 == NULL){
		printf("Can't open file\n");
	return 0;
	}
	else{
		
		for(i = 0; i < SIZE; i++){
			fscanf(fp1, "%c", &word[i]);
		}
	}
	fclose(fp1);
	
	do{
		user_input(guess, numguess);
		wordFou = fouWord(guess, word);
		cap_let(guess, word);
		printf("%s", guess);
		printf("\n");
		
		wron_let(guess, word, arrow);

			
		numguess++;
	}while(wordFou != 1 && numguess < 6);
					
return 0;
}
void user_input(char array1[], int i){
	printf("GUESS %d! Enter your guess: ", i+1);
	scanf("%s", array1);
}

int fouWord(char array1[], char array2[]){
	for(int i = 0; i < SIZE; i++){
		if(array1[i] != array2[i]){
		return 0;
		}
	}
return 1;
}	

void cap_let(char array1[], char array2[]){
	for(int i = 0; i < SIZE; i++){
		if(array1[i] == array2[i]){
			array1[i] = array1[i] - 32;
		}
	}

	
}

void wron_let(char array1[], char array2[], char array3[]){
	int i, j, k;
	for(k = 0; k < SIZE; k++){
		array3[k] = ' ';
	}
	
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			if(array1[i] == array2[j]){
				array3[i] = '^';
			}
		}
	}
}	




	
	

