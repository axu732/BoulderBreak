#define _CRT_SECURE_NO_WARNINGS
#define CAVE_SIZE 10
#include <stdio.h>
#include <string.h>

void InitialiseStory(char* paragraph) {
	char sutory[2000] = "Welcome to the new Indiana Jones movie tie in game.\nThe budget for this game however was 0 so the dev team\n(one guy really) had to revert to coding on c and using\nascii characters to display the action. O are boulders,\n* are holes that can plugged up with boulders.\n# are walls. X is Indiana Jones. + are treasures. ";
	int i;
	
	for (i = 0; i < 2000; i++) {
		paragraph[i] = sutory[i];
	}
	
}



void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE]) {
    int i, j;
    for (i = 0; i < CAVE_SIZE; i++) {
        for (j = 0; j < CAVE_SIZE; j++) {

            if (cave[i][j] == 1 && j == CAVE_SIZE - 1) {
                printf("%c\n", (char)35);
            }

            if (cave[i][j] == 1 && j != CAVE_SIZE - 1) {
                printf("%c", (char)35);
            }
            if (cave[i][j] == 0 && j != CAVE_SIZE - 1) {
                printf("%c", (char)32);
            }
            if (cave[i][j] == 0 && j == CAVE_SIZE - 1) {
                printf("\n");
            }
            if (cave[i][j] == 'E' && j != CAVE_SIZE - 1) {
                printf("%c", (char)32);
            }
            if (cave[i][j] == 'E' && j == CAVE_SIZE - 1) {
                printf("\n");
            }
            if (cave[i][j] == 79 && j != CAVE_SIZE - 1) {
                printf("%c", (char)79);
            }
            if (cave[i][j] == 88 && j != CAVE_SIZE - 1) {
                printf("%c", (char)88);
            }
            if (cave[i][j] == 88 && j == CAVE_SIZE - 1) {
                printf("%c\n", (char)88);
            }
            if (cave[i][j] == 42 && j != CAVE_SIZE - 1) {
                printf("%c", (char)42);
            }
            if (cave[i][j] == 43 && j != CAVE_SIZE - 1) {
                printf("%c", (char)43);
            }

        }


    }
}

void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char* layout) {
    int i = 0;
    int j = 0;
    int stringcounter = 0;
    for (i = 0; i < CAVE_SIZE; i++) {
        for (j = 0; j < CAVE_SIZE; j++) {
            if (layout[stringcounter] == '0') {
                cave[i][j] = 0;

           }
            if (layout[stringcounter] == '1') {
                cave[i][j] = 1;
            }
            if (layout[stringcounter] == 'E') {
                cave[i][j] = layout[stringcounter];
            }
            stringcounter++;
        }
        
    }
    
}


int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE]) {
    int i = 0;
    int j = 0;
    for (i = 0; i < CAVE_SIZE; i++) {
        for (j = 0; j < CAVE_SIZE; j++) {

            if (cave[i][j] == 0 && j == 0) {
                return 0;
                /* Checks if a 0 is used instead of a exit character*/
            }
            if (cave[i][j] == 0 && j == 9) {
                return 0;
                /* Checks if a 0 is used instead of a exit character*/
            }
            if (cave[i][j] == 0 && i == 0) {
                return 0;
            }
            if (cave[i][j] == 0 && i == 9) {
                return 0;
            }
        }
    }

    return 1;
}
       


int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE]) {
    int i = 0;
    int j = 0;
    int exitcounter = 0;
    for (i = 0; i < CAVE_SIZE; i++) {
        for (j = 0; j < CAVE_SIZE; j++) {
            if (cave[i][j] == 'E') {
                exitcounter++;
            }
        }
    }
    if (exitcounter > 1) {
        return 0;
    }
    else if (exitcounter == 1) {
        return 1;
    }
    return 0;
}

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE]) {
    int i = 0;
    int j = 0;
    for (i = 0; i < CAVE_SIZE; i++) {
        for (j = 0; j < CAVE_SIZE; j++) {

            if (cave[i][j] == 'E' && j == 0 && i == 0) {
                return 0;
            }
            if (cave[i][j] == 'E' && j == 9 && i == 0) {
                return 0;
            }
            if (cave[i][j] == 'E' && j == 9 && i == 9) {
                return 0;
            }
            if (cave[i][j] == 'E' && j == 0 && i == 9) {
                return 0;
            }
            if (cave[i][j] == 'E' && j == 0 && i != 0) {
                return 1;
            }
            if (cave[i][j] == 'E' && j == 9 && i != 9) {
                return 1;
            }
          
            if (cave[i][j] == 'E' && j != 0 && i == 9) {
                return 1;
            }
            if (cave[i][j] == 'E' && j != 9 && i == 9) {
                return 1;
            }
            if (cave[i][j] == 'E' && j != 0 && i == 0) {
                return 1;
            }
            if (cave[i][j] == 'E' && j != 9 && i == 0) {
                return 1;
            }
        }

    }
    return 0;
}



void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char* element){
    int i, j;
    if (row > CAVE_SIZE || col > CAVE_SIZE) {
        return;
    }
    
    if (cave[row][col] == 0 && cave[row][col] != 79 && strlen(element) == 7) {
        cave[row][col] = 79;
        /* Boulder */
    }
   
    if (cave[row][col] == 0 && cave[row][col] != 42 && strlen(element) == 4) {
        cave[row][col] = 42; 
        /* Hole */
    }
    if (cave[row][col] == 0 && cave[row][col] != 43 && strlen(element) == 8) {
        cave[row][col] = 43;
        /* Treasure */
    }

    for (i = 0; i < CAVE_SIZE; i++) {
        for (j = 0; j < CAVE_SIZE; j++) {
            if (cave[i][j] == 88)
                return;
        }
    }
    if (cave[row][col] == 0 && strlen(element) == 6) {
        cave[row][col] = 88;
        /*Player*/
    }

}

void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE]) {
    int temp[CAVE_SIZE][CAVE_SIZE];
    int i = 0;
    int j = 0;
    int x = 0;
    for (i = 0; i < CAVE_SIZE; i++) {
        for (j = 0; j < CAVE_SIZE; j++) {
            temp[j][i] = cave[i][j];
        }
    }

    for (i = 0; i < CAVE_SIZE; i++) {
        for (j = CAVE_SIZE - 1; j > -1; j--) {
            cave[i][x] = temp[i][j];
            x++;
        }
        x = 0;
    }
   
}

void BoulderMoveUp(int cave[CAVE_SIZE] [CAVE_SIZE], int row, int col) {
    while (cave[row - 1][col] != 79 && cave[row - 1][col] != 43 && cave[row -1 ][col] != 42 && cave[row -1 ][col] != 1) {
        cave[row][col] = 0;
        cave[row - 1][col] = 79;
        row--;

    }
    if (cave[row - 1][col] == 42) {
        cave[row - 1][col] = 0;
        cave[row][col] = 0;
    }

}
void BoulderMoveDown(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col) {
    while (cave[row + 1][col] != 79 && cave[row + 1][col] != 43 && cave[row + 1][col] != 42 && cave[row + 1][col] != 1) {
        cave[row][col] = 0;
        cave[row + 1][col] = 79;
        row++;

    }
    if (cave[row + 1][col] == 42) {
        cave[row + 1][col] = 0;
        cave[row][col] = 0;
    }

}

void BoulderMoveLeft(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col) {
    while (cave[row][col - 1] != 79 && cave[row][col - 1] != 43 && cave[row][col - 1] != 42 && cave[row][col - 1] != 1) {
        cave[row][col] = 0;
        cave[row][col - 1] = 79;
        col--;

    }
    if (cave[row][col - 1] == 42) {
        cave[row][col - 1] = 0;
        cave[row][col] = 0;
    }

}


void BoulderMoveRight(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col) {

    while (cave[row][col + 1] != 79 && cave[row][col + 1] != 43 && cave[row][col + 1] != 42 && cave[row][col + 1] != 1) {
        cave[row][col] = 0;
        cave[row][col + 1] = 79;
        col++;
      
    }
    if (cave[row][col + 1] == 42) {
        cave[row][col + 1] = 0;
        cave[row][col] = 0;
    }

}




int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move) {
    int i, j; 
    int rowpos1 = 0;
    int colpos1 = 0;
    for (i = 0; i < CAVE_SIZE; i++) {
        for (j = 0; j < CAVE_SIZE; j++) {
            if (cave[i][j] == 88) {
                rowpos1 = i;
                colpos1 = j;
            }
        }
    }
    /*Empty Space*/
    if (move == 'd' && cave[rowpos1][colpos1 + 1] == 0) {
        cave[rowpos1][colpos1] = 0;
        cave[rowpos1][colpos1 + 1] = 88;
        return 0;
    }
    if (move == 's' && cave[rowpos1 + 1][colpos1] == 0) {
        cave[rowpos1][colpos1] = 0;
        cave[rowpos1 + 1][colpos1] = 88;
        return 0;
    }
    if (move == 'a' && cave[rowpos1][colpos1 - 1] == 0) {
        cave[rowpos1][colpos1] = 0;
        cave[rowpos1][colpos1 - 1] = 88;
        return 0;
    }
    if (move == 'w' && cave[rowpos1 - 1][colpos1] == 0) {
        cave[rowpos1][colpos1] = 0;
        cave[rowpos1-1][colpos1] = 88;
        return 0;
    }

    /*Hole*/
    if (move == 'd' && cave[rowpos1][colpos1 + 1] == 42) {
        cave[rowpos1][colpos1] = 0;
        return 1;
    }
    if (move == 's' && cave[rowpos1 + 1][colpos1] == 42) {
        cave[rowpos1][colpos1] = 0;
        return 1;
    }
    if (move == 'a' && cave[rowpos1][colpos1 - 1] == 42) {
        cave[rowpos1][colpos1] = 0;
        return 1;
    }
    if (move == 'w' && cave[rowpos1-1][colpos1] == 42) {
        cave[rowpos1][colpos1] = 0;
        return 1;
    }

    /*boulder*/
    if (move == 'd' && cave[rowpos1][colpos1 + 1] == 79) {
        BoulderMoveRight(cave, rowpos1, colpos1 + 1 );
        return 0;
    }
    if (move == 's' && cave[rowpos1 + 1][colpos1] == 79) {
        BoulderMoveDown(cave, rowpos1 + 1, colpos1);
        return 0;
    }
    if (move == 'a' && cave[rowpos1][colpos1 - 1] == 79) {
        BoulderMoveLeft(cave, rowpos1, colpos1 - 1);
        return 0;
    }
    if (move == 'w' && cave[rowpos1 - 1][colpos1] == 79) {
        BoulderMoveUp(cave, rowpos1 - 1, colpos1);
        return 0;
       
    }

    /*exit*/
    if (move == 'd' && cave[rowpos1][colpos1 + 1] == 'E') {
        cave[rowpos1][colpos1] = 0;
        cave[rowpos1][colpos1 + 1] = 88;
        return 2;
    }
    if (move == 's' && cave[rowpos1 + 1][colpos1] == 'E') {
        cave[rowpos1][colpos1] = 0;
        cave[rowpos1 + 1][colpos1] = 88;
        return 2;
    }
    if (move == 'a' && cave[rowpos1][colpos1 - 1] == 'E') {
        cave[rowpos1][colpos1] = 0;
        cave[rowpos1][colpos1 - 1] = 88;
        return 2;
    }
    if (move == 'w' && cave[rowpos1 - 1][colpos1] == 'E') {
        cave[rowpos1][colpos1] = 0;
        cave[rowpos1 - 1][colpos1] = 88;
        return 2;
    }
    /* treasure portion*/
    if (move == 'd' && cave[rowpos1][colpos1 + 1] == 43) {
        cave[rowpos1][colpos1] = 0;
        cave[rowpos1][colpos1 + 1] = 88;
        
        return 0;
    }
    if (move == 's' && cave[rowpos1 + 1][colpos1] == 43) {
        cave[rowpos1][colpos1] = 0;
        cave[rowpos1 + 1][colpos1] = 88;
      
        return 0;
    }
    if (move == 'a' && cave[rowpos1][colpos1 - 1] == 43) {
        cave[rowpos1][colpos1] = 0;
        cave[rowpos1][colpos1 - 1] = 88;
       
        return 0;
    }
    if (move == 'w' && cave[rowpos1 - 1][colpos1] == 43) {
        cave[rowpos1][colpos1] = 0;
        cave[rowpos1 - 1][colpos1] = 88;
    
        return 0;
    }

    return 0;
}

char GetMove(void)
{
    char move;
    printf("\nEnter move: ");
    scanf("%c", &move);
    // Ignore any characters that are invalid
    while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
        scanf("%c", &move);
    }
    return move;
}

/* The Boulder Break simulation */
int main(void)
{
    char story[2000];
    char layout[200] = "1111111111111000001111000000111000000001100000000E10010000011100000011111000001111111001111111111111";
    int cave[CAVE_SIZE][CAVE_SIZE] = { 0 };
    int gameOver = 0;

    InitialiseStory(story);
    InitialiseCave(cave, layout);
    AddItem(cave, 2, 4, "boulder");
    AddItem(cave, 5, 6, "boulder");
    AddItem(cave, 4, 8, "hole");
    AddItem(cave, 1, 4, "treasure");
    AddItem(cave, 4, 5, "player");

    printf("ENGGEN131 - C Project 2022\n");
    printf("                          ... presents ...\n");
    printf("______   _____  _     _        ______  _______  ______\n");
    printf("|_____] |     | |     | |      |     \\ |______ |_____/\n");
    printf("|_____] |_____| |_____| |_____ |_____/ |______ |    \\_\n");
    printf("______   ______ _______ _______ _     _\n");
    printf("|_____] |_____/ |______ |_____| |____/ \n");
    printf("|_____] |    \\_ |______ |     | |    \\_\n");
    printf("\n");
    printf("%s\n", story);
    printf("\nMove the player (X) using the keys 'w', 'a', 's', 'd'\n");
    printf("Good luck!\n\n\n");

    /* Main game loop */
    PrintCave(cave);
    while (!gameOver) {
        gameOver = MakeMove(cave, GetMove());
        PrintCave(cave);
        if (gameOver == 1) {
            printf("\n\nGAME OVER!! \nYou died!\n\n");
        }
        else if (gameOver == 2) {
            printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
        }
    }

    return 0;
}
