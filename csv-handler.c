#include "2048.h"
#include "csv-handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// funkce přidá zápis o dalším úspěšném řešení do leaderboard.csv
void insertIntoLeaderboard(char* username) {
	FILE* leaderboardFile;
	fopen_s(&leaderboardFile, "leaderboard.csv", "a");
	if (leaderboardFile != NULL) {
		fprintf_s(leaderboardFile, "%d, %s, \n", getScore(), username);
		fclose(leaderboardFile);
	}
	else {
		printf("Record could not be saved, leaderboard.csv may have gotten damaged.");
		system("pause");
	}
}

 // funkce, která načte leaderboard ze sobuoru

void printLeaderboard() {
	FILE* leaderboardFile;
	fopen_s(&leaderboardFile, "leaderboard.csv", "r");
	if (leaderboardFile != NULL) {
		int recordCount=1;

		// get amount of records
		for (char c = getc(leaderboardFile); c != EOF; c = getc(leaderboardFile)) {
			if (c == '\n') { // Increment count if this character is newline 
				recordCount = recordCount + 1;
			}
		}

		// reset file back to beginning
		fseek(leaderboardFile, 0L, SEEK_SET);

		if (recordCount) {
			// loads, saves into memory, sorts and prints all records. kind of voodoo magic, even for me. And I did write it. Geez. -MH @ 11pm

			// docasna promenna prvniho zaznamu
			struct lbRecord* prvniZaznam = NULL;

			// docasna promenna aktualniho zaznamu
			struct lbRecord* aktualniZaznam = NULL;

			for (int i = 0; i < recordCount-1; i++) {
				char nick[USERNAME_SIZE];
				int	score;

				fscanf_s(leaderboardFile, "%d, %127[^,], \n", &score, &nick, USERNAME_SIZE); // nacte jeden zaznam ze souboru

				// docasna promenna pro jednotlive pruchody
				struct lbRecord* novyZaznam;

				// naplneni noveho zaznamu informacemi
				novyZaznam = (struct lbRecord*)malloc(sizeof(struct lbRecord));
				strcpy_s(novyZaznam->username, USERNAME_SIZE, nick);
				novyZaznam->score = score;
				novyZaznam->dalsi = NULL;

				if (prvniZaznam == NULL) { //zahajeni zapisu
					prvniZaznam = novyZaznam;
				}
				else if (prvniZaznam->score < novyZaznam->score) { //vlozeni na zacatek
					novyZaznam->dalsi = prvniZaznam;
					prvniZaznam = novyZaznam;
				}
				else {

					aktualniZaznam = prvniZaznam;
					int notResolved = 1;

					while (notResolved) {
						if (aktualniZaznam->dalsi == NULL) // jsme na poslednim zaznamu
						{
							aktualniZaznam->dalsi = novyZaznam; // pridavame na konec
							notResolved = 0;
						}
						else if (novyZaznam->score > aktualniZaznam->dalsi->score)
						{
							novyZaznam->dalsi = aktualniZaznam->dalsi; // vlozime za aktualniZaznam
							aktualniZaznam->dalsi = novyZaznam;
							notResolved = 0;
						}
						aktualniZaznam = aktualniZaznam->dalsi; // posun na dalsi zaznam
					}
				}
			}

			fclose(leaderboardFile);

			// pokud mame v leaderboard mene nez 10 zaznamu, vytiskneme vsechny, jinak omezime pocet tistenych zaznamu na 10
			int maxI; 
			if (recordCount < 11) { 
				maxI = recordCount - 1; 
			}
			else {
				maxI = 10;
			}

			aktualniZaznam = prvniZaznam;
			if (aktualniZaznam != NULL) {
				printf(" Score | Nick \n-------+-----------------\n"); //pretty hlavicka tabulky
				for (int i = 0; i < maxI; i++) { //postupne tiskne jednotlive zaznamy.
					printf(" %5.0d | %s\n", aktualniZaznam->score, aktualniZaznam->username);
					aktualniZaznam = aktualniZaznam->dalsi;
				}
			}

			aktualniZaznam = prvniZaznam;

			for (int i = 0; i < recordCount-1; i++) {
				struct lbRecord* dalsi = aktualniZaznam->dalsi;
				free(aktualniZaznam);
				aktualniZaznam = dalsi;

			}
		}
		else printf("Zatim nemate zadne zaznamenane skore.\n\n");
	}
	else printf("Pri otevirani souboru s leaderboardem nastala necekana chyba.\nJe mozne, ze zatim nebylo zaznamenano zadne skore.\n\n");
}




// funkce navrací herní pole pro obnovení hry
void importGameField(){

	int tempGameField[4][4];

	FILE* gameFile;
	fopen_s(&gameFile, "game.csv", "r");

	wipeGameField();

	if (gameFile != NULL) {

		for (int i = 0; i < 4; i++) {
			fscanf_s(gameFile, "%d, %d, %d, %d, \n", &tempGameField[i][0], &tempGameField[i][1], &tempGameField[i][2], &tempGameField[i][3]);
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				//printf("%d \n",tempGameField[i][j]); // debug command xD
				setFieldValue(i, j, tempGameField[i][j]);
			}
		}

		fclose(gameFile);

	}
}

// funkce ukládá aktuální herní pole
void saveGameField() {
	printf("saveGameField not actually implemented\n"); // abychom na ni nezapomenuli :)

	FILE* gameFile;
	fopen_s(&gameFile, "game.csv", "w");

	if (gameFile != NULL) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				fprintf_s(gameFile, "%d, ", gameField[i][j]);
			}
			fprintf(gameFile, "\n");
		}
		fclose(gameFile);
	}
}