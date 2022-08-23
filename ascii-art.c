#include <stdio.h>
#include <windows.h>   // barvičky :3

#define ORIGINALNI 15
#define TMAVECYANOVA 3
#define SVETLEMODRA 9
#define SVETLEZELENA 10
#define RUDA 4
#define SEDA 8 // sspbrno.cz henlo

void asciiPrint2048() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, SVETLEZELENA);

	printf("    2222222222222          000000000             444444444        888888888     \n");
	printf("  22:::::::::::::22      00:::::::::00          4::::::::4      88:::::::::88   \n");
	printf(" 2::::::222222:::::2   00:::::::::::::00       4:::::::::4    88:::::::::::::88 \n");
	printf(" 2222222     2:::::2  0:::::::000:::::::0     4::::44::::4   8::::::88888::::::8\n");
	printf("             2:::::2  0::::::0   0::::::0    4::::4 4::::4   8:::::8     8:::::8\n");
	printf("             2:::::2  0:::::0     0:::::0   4::::4  4::::4   8:::::8     8:::::8\n");
	printf("          2222::::2   0:::::0     0:::::0  4::::4   4::::4    8:::::88888:::::8 \n");
	printf("     22222::::::22    0:::::0     0:::::0 4::::444444::::444   8:::::::::::::8  \n");
	printf("   22::::::::222      0:::::0     0:::::0 4::::::::::::::::4  8:::::88888:::::8 \n");
	printf("  2:::::22222         0:::::0     0:::::0 4444444444:::::444 8:::::8     8:::::8\n");
	printf(" 2:::::2              0:::::0     0:::::0           4::::4   8:::::8     8:::::8\n");
	printf(" 2:::::2              0::::::0   0::::::0           4::::4   8:::::8     8:::::8\n");
	printf(" 2:::::2       222222 0:::::::000:::::::0           4::::4   8::::::88888::::::8\n");
	printf(" 2::::::2222222:::::2  00:::::::::::::00          44::::::44  88:::::::::::::88 \n");
	printf(" 2::::::::::::::::::2    00:::::::::00            4::::::::4    88:::::::::88   \n");
	printf(" 22222222222222222222      000000000              4444444444      888888888     \n");

	SetConsoleTextAttribute(hConsole, ORIGINALNI);
}

void asciiPrintMenu() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	printf("\n\n Press the following button to: \n\n");

	SetConsoleTextAttribute(hConsole, SVETLEZELENA);
	printf(" 1");
	SetConsoleTextAttribute(hConsole, SEDA);
	printf(" | ");
	SetConsoleTextAttribute(hConsole, SVETLEMODRA);
	printf("Start new game\n");

	SetConsoleTextAttribute(hConsole, SVETLEZELENA);
	printf(" 2");
	SetConsoleTextAttribute(hConsole, SEDA);
	printf(" | ");
	SetConsoleTextAttribute(hConsole, SVETLEMODRA);
	printf("Resume previous game\n");
	

	SetConsoleTextAttribute(hConsole, SVETLEZELENA);
	printf(" 3");
	SetConsoleTextAttribute(hConsole, SEDA);
	printf(" | ");
	SetConsoleTextAttribute(hConsole, SVETLEMODRA);
	printf("Leaderboard\n");

	SetConsoleTextAttribute(hConsole, SVETLEZELENA);
	printf(" 0");
	SetConsoleTextAttribute(hConsole, SEDA);
	printf(" | ");
	SetConsoleTextAttribute(hConsole, SVETLEMODRA);
	printf("Exit\n");

	SetConsoleTextAttribute(hConsole, ORIGINALNI);
}

void asciiPrintDeath() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, RUDA);

	printf("\n  ______    ______   __       __  ________         ______   __     __  ________  _______  \n");
	printf(" /      \\  /      \\ |  \\     /  \\|        \\       /      \\ |  \\   |  \\|        \\|       \\ \n");
	printf("|  $$$$$$\\|  $$$$$$\\| $$\\   /  $$| $$$$$$$$      |  $$$$$$\\| $$   | $$| $$$$$$$$| $$$$$$$\\ \n");
	printf("| $$ __\\$$| $$__| $$| $$$\\ /  $$$| $$__          | $$  | $$| $$   | $$| $$__    | $$__| $$ \n");
	printf("| $$|    \\| $$    $$| $$$$\\  $$$$| $$  \\         | $$  | $$ \\$$\\ /  $$| $$  \\   | $$    $$\n");
	printf("| $$ \\$$$$| $$$$$$$$| $$\\$$ $$ $$| $$$$$         | $$  | $$  \\$$\\  $$ | $$$$$   | $$$$$$$\\ \n");
	printf("| $$__| $$| $$  | $$| $$ \\$$$| $$| $$_____       | $$__/ $$   \\$$ $$  | $$_____ | $$  | $$\n");
	printf(" \\$$    $$| $$  | $$| $$  \\$ | $$| $$     \\       \\$$    $$    \\$$$   | $$     \\| $$  | $$\n");
	printf("  \\$$$$$$  \\$$   \\$$ \\$$      \\$$ \\$$$$$$$$        \\$$$$$$      \\$     \\$$$$$$$$ \\$$   \\$$\n");

	SetConsoleTextAttribute(hConsole, ORIGINALNI);
}

void asciiPrintLeaderboard() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, TMAVECYANOVA);

	printf("#                                                                             \n");
	printf("#       ######   ##   #####  ###### #####  #####   ####    ##   #####  #####  \n");
	printf("#       #       #  #  #    # #      #    # #    # #    #  #  #  #    # #    # \n");
	printf("#       #####  #    # #    # #####  #    # #####  #    # #    # #    # #    # \n");
	printf("#       #      ###### #    # #      #####  #    # #    # ###### #####  #    # \n");
	printf("#       #      #    # #    # #      #   #  #    # #    # #    # #   #  #    # \n");
	printf("####### ###### #    # #####  ###### #    # #####   ####  #    # #    # #####\n\n");

	SetConsoleTextAttribute(hConsole, ORIGINALNI);
}

void asciiPrintControls() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, SEDA);

	printf("       +---+\n");
	printf("       | ^ |\n");
	printf("   +---+---+---+          +---+\n");
	printf("   | < | V | > |          | s |\n");
	printf("   +---+---+---+          +---+\n");
	printf("   game controls        save game\n");

	SetConsoleTextAttribute(hConsole, ORIGINALNI);
}
