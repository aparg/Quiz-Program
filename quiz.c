//This is a quiz app which gives random questions to a player and calculates the score!

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char playerName[20];
char* question(int);
char* answer(int);
void arrayShuffler();
int array[15];//array for question randomizing
void options();
void startGame();
void help();
void writeScore(int score);
void viewScore();



int main(){
	int i,j,qsnNum,score=0,temp;
	char again;	
	srand(time(0));
	system("cls");
	options();
	printf("Thank you for trying the game %s!\n",playerName);
	printf("Wanna play again?Enter Y!\n");
	printf("Enter any  other key to discontinue\n");
	scanf("%c",&again);
	if(toupper(again)=='Y'){
		system("cls");
		options();
	}
	else{
		exit(0);
	}
	return 0;
}

void options(){
	char a;
	printf("Please enter your name \n");
	scanf("%s",playerName);
	fflush(stdin);
	system("cls");
	printf("----------------------------------------------------------\n");
	printf("Enter S to start\n");
	printf("Enter H for help\n");
	printf("Enter C for scoreboard\n");
	printf("Enter Q to quit game\n");
	printf("----------------------------------------------------------\n");
	scanf("%c",&a);	
	fflush(stdin);
	system("cls");
	if(toupper(a)=='S'){
		startGame();
	}
	else if(toupper(a)=='H'){
		help();
	}
	else if(toupper(a)=='Q'){
		exit(0);
	}
	else if(toupper(a)=='C'){
		viewScore();
	}
}

void help(){
	printf("........................................................................\n");
	printf("#You have 15 random questions to answer.\n");
	printf("#Type your answer and press enter to get the next question.\n");
	printf("#You can press enter if you would like to skip the question and move on to the next one.\n");
	printf("#The answers are case insensitive.\n");
	printf("#After fifteen questions are answered, you will see your score.\n");
	
	printf("........................................................................\n");
	printf("Press any key to go back");
	getch();
	system("cls");
	options();
}

void startGame(){
	int i,j,qsnNum,score=0,temp;
	char userAns[20],correctAns[200];
	arrayShuffler();
	for(i=0;i<15;i++){
			j=0;
			qsnNum = array[i];
			printf("%d. %s \n",i+1,question(qsnNum));
			scanf("%[^\n]%*c",userAns);
			fflush(stdin);
			while (userAns[j]){
				temp=userAns[j];
				userAns[j]=toupper(temp);
				j++;
			}
	   		
			if(strcmp(userAns,answer(qsnNum))==0){
				score++;
			}
		}
	printf("***************************************************************************************************************\n");
	printf("\t\t\t\t\t\t\t Score: %d / 15\n",score);
	printf("***************************************************************************************************************\n");
	writeScore(score);
	getch();
	
}

char* question(int i){
	switch(i){
		case 0:
			return"In which country was Buddha born? ";
			break;
		case 1:
			return"Who was the father of Rana Prime Minister Mohan Shamsher?";
			break;
		case 2:
			return"When was the Sagarmatha National Park included in the world heritage sites?"	;
			break;
		case 3:
			return"What is the name of the the man who launched eBay back in 1995? 	";
			break;	
		case 4:
			return"Which email service is owned by Microsoft?";
			break;	
		case 5:
			return"How many molecules of oxygen does ozone have? ";
			break;
		case 6:
			return"Which company owns Bugatti, Lamborghini, Audi, Porsche, and Ducati? 	";
			break;	
		case 7:
			return"Who was Nepal's king in 1911-1955? ";
			break;
		case 8:
			return"Which year was Tribhuvan university established(in BS)?";
			break;	
		case 9:
			return"What kind of climate is taken to be the climate of the cold desert and the third pole? ";
			break;	
		case 10:
			return"How many seasons are there in Nepal according to the weather conditions? ";
			break;	
		case 11:
			return"What is the capital of New Zealand? ";
			break;	
		case 12:
			return"Who is the writer of \"Merchant of Venice\"? ";
			break;	
		case 13:
			return"The book \"Da Vinci Code\", was written by who? ";
			break;	
		case 14:
			return"What is a female donkey called? 	";
			break;	
		case 15:
			return"Which mammal has no vocal cords? ";
			break;	
		case 16:
			return"What is evidence in court, where a person tells everything they saw or know?	";
			break;	
		case 17:
			return"In which year World War I begin? ";
			break;	
		case 18:
			return"In which country was  Adolph Hitler born?";
			break;
		case 19:
			return"If there are 6 apples and you take away 4, how many do you have?";
			break;	
		case 20:
			return"Thor was the son of which God?";
			break;
		case 21:
			return"Which musical instrument has 47 strings and 7 pedals?";
			break;
		case 22:
			return"Which mountain is understood by \"Killer Mountain\"?";
			break;		
	}
}

char* answer(int i){
	switch(i){
		case 0:
			return"NEPAL";
			break;
		case 1:
			return"CHANDRA SHUMSHER";
			break;
		case 2:
			return"1979 AD";
			break;	
		case 3:
			return"URUGUAY";
			break;	
		case 4:
			return"HOTMAIL";
			break;	
		case 5:
			return"3";
			break;
		case 6:
			return"VOLKSWAGEN";
			break;	
		case 7:
			return"TRIBHUVAN";
			break;	
		case 8:
			return"1959";
			break;	
		case 9:
			return"TUNDRA";
			break;	
		case 10:
			return"6"	;
			break;
		case 11:
			return"WELLINGTON";
			break;
		case 12:
			return"WILLIAM SHAKESPEARE";
			break;	
		case 13:
			return"DAN BROWN";
			break;	
		case 14:
			return"JENNY";
			break;	
		case 15:
			return"GIRAFFE";
			break;	
		case 16:
			return"TESTIMONY";
			break;	
		case 17:
			return"1914";
			break;	
		case 18:
			return"AUSTRIA";
			break;
		case 19:
			return"4";
			break;
		case 20:
			return"ODIN";
			break;
		case 21:
			return"HARP";
			break;	
		case 22:
			return"MANASLU";
			break;			
	}
}

void arrayShuffler(){
	int i,randomIndex,temp;
	
	for (i = 0; i < 23; i++) {     // fill array
	    array[i] = i;
	}
	
	for (i = 0; i < 15; i++) {    // shuffle array
	    int temp = array[i];
	    int randomIndex = rand() % 23;
	    array[i] = array[randomIndex];
	    array[randomIndex] = temp;
	}
	
}

void viewScore(){
	FILE *fp;	
	fp=fopen("scoreboard.txt","r");
	char c;
	
	if (fp == NULL) { 
        printf("Cannot open file scoreboard\n"); 
        exit(0); 
    } 
		
	c = fgetc(fp); 
    while (c != EOF){ 
        printf ("%c", c); 
        c = fgetc(fp); 
    } 

	fclose(fp);
	printf("Press any key to go back");
	getch();
	system("cls");
	options();
}

void writeScore(int score){
	FILE *fp;	
	fp=fopen("scoreboard.txt","a");
	char c;
	
	if (fp == NULL) { 
        printf("Cannot open file scoreboard\n"); 
        exit(0); 
    } 

	fprintf(fp,"%s : %d\n",playerName,score);
	
	fclose(fp);
}
