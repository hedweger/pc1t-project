#define USERNAME_SIZE 128

// definice jedné položky
struct lbRecord {
	int score;
	char username[USERNAME_SIZE];
	struct lbRecord* dalsi;
};

void printLeaderboard();

void insertIntoLeaderboard(char* username);

void importGameField();

void saveGameField();