#include <stdio.h>
#include <stdlib.h>

#include "2048.h"
#include "csv-handler.h"
#include "ascii-art.h"

void renderGameView() {
	system("cls");
	addRandomTwo();
	printGameScreen();
	printf("\nScore: %d \n\n", getScore());
	asciiPrintControls();
}

int step() {
	//get user input

	int userinput = 0;
	int inType = getch();
	if (inType == 224) {
		userinput = getch();
	}
	else {
		userinput = inType;
	}

	//move or save game
	int retVal = 1;

	switch (userinput) {
	case 75:
		shiftGameField(left);
		renderGameView();
		retVal = 1;
		break;
	case 77:
		shiftGameField(right);
		renderGameView();
		retVal = 1;
		break;
	case 72:
		shiftGameField(up);
		renderGameView();
		retVal = 1;
		break;
	case 80:
		shiftGameField(down);
		renderGameView();
		retVal = 1;
		break;
	case 's':
		saveGameField();
		retVal = 0;
		break;
	default:
		//printf("Unknown key: %d", userinput); //debug line
		break;
	}

	return retVal;
}

void startGame() {

	printGameScreen();
	printf("\nScore: %d \n\n", getScore());
	asciiPrintControls();

	while (stillAlive())
	{
		if (!step()) 
			break;
	}
	if (!stillAlive()) {
		asciiPrintDeath();
	
		printf_s("\nEnter the username for your entry in the leaderboard: ");
		char username[USERNAME_SIZE] = "";
		scanf_s("%s", &username, USERNAME_SIZE);

		insertIntoLeaderboard(username);
		
		system("cls");
	}
}

void newGame() {
	generateGameField();
	startGame();
}

void resumeGame() {
	importGameField();
	startGame();
}

int menu() {
	system("cls");
	printf("\n");

	asciiPrint2048();
	asciiPrintMenu();

	printf("\nEnter your choice: ");
	int uloha;
	scanf_s(" %d", &uloha);
	return uloha;
}

void main() 
{
	
	int loop = 1;  
	//dokud u�ivatel nerekne, ze chce skoncit, zobrazujeme menu
	while (loop != 0) {
		switch (menu()) {
			case 1: //spouští novou hru
				system("cls");
				newGame();
				break;
			case 2: //obnovuje rozehranou hru
				system("cls");
				resumeGame();
				break;
			case 3: //zobrazí leaderboad
				system("cls");
				asciiPrintLeaderboard();
				printLeaderboard();
				system("pause");
				system("cls");
				break;
			case 0: //ukončí hru
				loop = 0;
				break;
			default:
				printf("Unknown operation.");
				break;
		}
	}
	system("cls");
	printf("\nThanks for playing our game.\n\n");
	printf("Marek Havel, 230256\n");
	printf("Tommy Hadwiger, 230252\n\n"); // todo: doplnit VUTID
	system("pause");
}



