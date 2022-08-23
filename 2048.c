#include "2048.h"
#include "csv-handler.h"

#include <stdlib.h>
#include <math.h>

void setFieldValue(int row, int col, int value) {
	gameField[row][col] = value;
}

void wipeGameField() {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			setFieldValue(row, col, 0);
		}
	}
}

void generateGameField() {
	wipeGameField();
	srand(time(NULL));
	int row, col; // radek, sloupec
	for (row = 0; row < 4; row++) {
		for (col = 0; col < 4; col++) {
			setFieldValue(row, col, 0);
		}
	}
	row = rand() % 4 + 0;
	col = rand() % 4 + 0;
	setFieldValue(row, col, 1);
	return 0;
}

 
void printLineSeparator() {
	printf("+-------+-------+-------+-------+\n");
}

void printGameScreen() {
	for (int i = 0; i < 4; i++) {
		printLineSeparator();
		for (int j = 0; j < 4; j++) {
			if (gameField[i][j] > 0) {
				printf("| %5.0f ", pow(2, gameField[i][j]));
			}
			else {
				printf("|       ");
			}
		}
		printf("|\n");
	}
	printLineSeparator();
}

int getScore() {
	int score = 0;

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (gameField[row][col] > 1) {
				score = score + (pow(2, gameField[row][col] + 1) - 4);
			}
		}
	}
	return score;
}

// return 0 if user died = no move available
int stillAlive() {
	int possibleMoves = 0;

	//check available spaces, because filling them is definitely a move
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (gameField[row][col] == 0) {
				possibleMoves++;
			}
		}
	}

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 3; col++) {
			if (gameField[row][col] == gameField[row][col+1]) {
				possibleMoves++;
			}
		}
	}

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 4; col++) {
			if (gameField[row][col] == gameField[row+1][col]) {
				possibleMoves++;
			}
		}
	}

	return possibleMoves;
}

void addRandomTwo() {
	int row, col;
	int emptySpots = 0;

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (gameField[row][col] == 0) {
				emptySpots++;
			}
		}
	}

	if (emptySpots) {
		do {
			row = rand() % 4 + 0;
			col = rand() % 4 + 0;
		} while (gameField[row][col] != 0);
		setFieldValue(row, col, 1);
	}
}

void shiftInDirectionVodorovne(enum direction direction) {
	if (direction == left) { // posun cisla 
		for (int row = 0; row < 4; row++) {
			for (int col = 3; col > 0; col--) {
				if (gameField[row][col] > 0 && gameField[row][col - 1] == 0) {
					gameField[row][col - 1] = gameField[row][col];
					gameField[row][col] = 0;
				}
				for (int k = 3; k > 0; k--) {
					if (gameField[row][k] > 0 && gameField[row][k - 1] == 0) {
						gameField[row][k - 1] = gameField[row][k];
						gameField[row][k] = 0;
					}
				}
			}
		}
		for (int col = 1; col < 4; col++) {// najdi vsechny hodnoty na radku, secti exponent
			for (int row = 0; row < 4; row++) {
				if (gameField[row][col] > 0 && gameField[row][col - 1] == gameField[row][col]) {
					while (gameField[row][col - 1] == gameField[row][col]) {
						gameField[row][col - 1] += 1;
						gameField[row][col] = 0;
					}

				}
				else if (gameField[row][col] > 0 && gameField[row][col - 1] == 0 && gameField[row][col - 2] == gameField[row][col]) {
					while (gameField[row][col - 2] == gameField[row][col]) {
						gameField[row][col - 2] += 1;
						gameField[row][col] = 0;
					}

				}
				else if (gameField[row][col] > 0 && gameField[row][col - 1] == 0 && gameField[row][col - 2] == 0 && gameField[row][col - 3] == gameField[row][col]) {
					while (gameField[row][col - 3] == gameField[row][col]) {
						gameField[row][col - 3] += 1;
						gameField[row][col] = 0;
					}

				}
			}
		}
	}
	else if (direction == right) {
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 3; col++) {
				if (gameField[row][col] > 0 && gameField[row][col + 1] == 0) {
					gameField[row][col + 1] = gameField[row][col];
					gameField[row][col] = 0;
				}
				for (int k = 0; k < 3; k++) {
					if (gameField[row][k] > 0 && gameField[row][k + 1] == 0) {
						gameField[row][k + 1] = gameField[row][k];
						gameField[row][k] = 0;
					}
				}
			}
		}
		for (int row = 3; row > -1; row--) {
			for (int col = 0; col < 4; col++) {
				if (gameField[row][col] > 0 && gameField[row][col + 1] == gameField[row][col]) {
					while (gameField[row][col + 1] == gameField[row][col]) {
						gameField[row][col + 1] += 1;
						gameField[row][col] = 0;
					}

				}
				else if (gameField[row][col] > 0 && gameField[row][col + 1] == 0 && gameField[row][col + 2] == gameField[row][col]) {
					while (gameField[row][col + 2] == gameField[row][col]) {
						gameField[row][col + 2] += 1;
						gameField[row][col] = 0;
					}

				}
				else if (gameField[row][col] > 0 && gameField[row][col + 1] == 0 && gameField[row][col + 2] == 0 && gameField[row][col + 3] == gameField[row][col]) {
					while (gameField[row][col + 3] == gameField[row][col]) {
						gameField[row][col + 3] += 1;
						gameField[row][col] = 0;
					}

				}
			}
		}
	}
}

void shiftInDirectionSvisle(enum direction direction) {
	// najdi vsechny nenulové hodnoty na řádku, sečti jejich exponenty a zobraz je vlevo nebo vprav
	if (direction == up) {
		for (int row = 3; row > 0; row--) {
			for (int col = 0; col < 4; col++) {
				if (gameField[row][col] > 0 && gameField[row - 1][col] == 0) {
					gameField[row - 1][col] = gameField[row][col];
					gameField[row][col] = 0;
				}
				for (int k = 3; k > 0; k--) {
					if (gameField[k][col] > 0 && gameField[k - 1][col] == 0) {
						gameField[k - 1][col] = gameField[k][col];
						gameField[k][col] = 0;
					}
				}
			}
		}
		for (int row = 1; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				if (gameField[row][col] > 0 && gameField[row - 1][col] == gameField[row][col]) {
					while (gameField[row - 1][col] == gameField[row][col]) {
						gameField[row - 1][col] += 1;
						gameField[row][col] = 0;
					}

				}
				else if (gameField[row][col] > 0 && gameField[row - 1][col] == 0 && gameField[row - 2][col] == gameField[row][col]) {
					while (gameField[row - 2][col] == gameField[row][col]) {
						gameField[row - 2][col] += 1;
						gameField[row][col] = 0;
					}

				}
				else if (gameField[row][col] > 0 && gameField[row - 1][col] == 0 && gameField[row - 2][col] == 0 && gameField[row - 3][col] == gameField[row][col]) {
					while (gameField[row - 3][col] == gameField[row][col]) {
						gameField[row - 3][col] += 1;
						gameField[row][col] = 0;
					}

				}
			}
		}
	}
	else if (direction == down) {
		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 4; col++) {
				if (gameField[row][col] > 0 && gameField[row + 1][col] == 0) {
					gameField[row + 1][col] = gameField[row][col];
					gameField[row][col] = 0;
				}
				for (int k = 0; k < 3; k++) {
					if (gameField[k][col] > 0 && gameField[k + 1][col] == 0) {
						gameField[k + 1][col] = gameField[k][col];
						gameField[k][col] = 0;
					}
				}
			}
		}
		for (int row = 3; row > -1; row--) {
			for (int col = 0; col < 4; col++) {
				if (gameField[row][col] > 0 && gameField[row + 1][col] == gameField[row][col]) {
					while (gameField[row + 1][col] == gameField[row][col]) {
						gameField[row + 1][col] += 1;
						gameField[row][col] = 0;
					}

				}
				else if (gameField[row][col] > 0 && gameField[row + 1][col] == 0 && gameField[row + 2][col] == gameField[row][col]) {
					while (gameField[row + 2][col] == gameField[row][col]) {
						gameField[row + 2][col] += 1;
						gameField[row][col] = 0;
					}

				}
				else if (gameField[row][col] > 0 && gameField[row + 1][col] == 0 && gameField[row + 2][col] == 0 && gameField[row + 3][col] == gameField[row][col]) {
					while (gameField[row + 3][col] == gameField[row][col]) {
						gameField[row + 3][col] += 1;
						gameField[row][col] = 0;
					}

				}
			}
		}
	}

}

void shiftGameField(enum direction direction) {
		switch (direction) {
		case up:
			shiftInDirectionSvisle(up);
			break;
		case down:
			shiftInDirectionSvisle(down);
			break;
		case left:
			shiftInDirectionVodorovne(left);
			break;
		case right:
			shiftInDirectionVodorovne(right);
			break;
		}
}






































