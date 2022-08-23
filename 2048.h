
// uložení herního pole
int gameField[4][4];

enum direction {up,down,left,right};

void generateGameField();

void wipeGameField();

int stillAlive();

int getScore();

void setFieldValue(int row, int col, int value);

void printGameScreen();

void shiftGameField(enum direction direction);