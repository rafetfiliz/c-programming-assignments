#include <stdio.h> //For scanf and printf
#include <stdlib.h> //For EXIT_SUCCESS

int main()
{
    int point1 = 0; /*Points of player 1 and player 2*/
    int point2 = 0; /*etc. 0, 1, 2, 3, 4... */
    int score1 = 0; /*Scores of player 1 and player 2*/
    int score2 = 0; /* etc. 0, 15, 30, 40 */
    int user_input; /*Input given by user */

    while ((point1 <= 3 && point2 <= 2) || (point2 <= 3 && point1 <= 2)) { //This while loop is tracking the winner of the game. But this loop contains points 0-0 to 4-2.
        printf("%d-%d\n", score1, score2); //So there are no deuce scores in this loop.
        printf("Point: ");
        scanf("%d", &user_input);

        if (user_input == 1) { //If user enters 1 as an input, then add 1 to point of player 1.
            point1++;
        }

        else if (user_input == 2) { //If user enters 2 as an input, then add 1 to point of player 2.
            point2++;
        }

        switch (point1) { //Change the score of player 1 due to point of player 1.
        case 0:
            score1 = 0;
            break;

        case 1:
            score1 = 15;
            break;

        case 2:
            score1 = 30;
            break;

        case 3:
            score1 = 40;
            break;
        }

        switch (point2) { //Change the score of player 2 due to point of player 2.
        case 0:
            score2 = 0;
            break;

        case 1:
            score2 = 15;
            break;

        case 2:
            score2 = 30;
            break;

        case 3:
            score2 = 40;
            break;
        }

        if ((point1 == 4 && point2 == 0) || (point1 == 4 && point2 == 1) || (point1 == 4 && point2 == 2)) { //Player 1 wins the game if points are 4-0, 4-1 and 4-2.
            printf("GAME: PLAYER 1\n");
            return EXIT_SUCCESS;
        }

        if ((point2 == 4 && point1 == 0) || (point2 == 4 && point1 == 1) || (point2 == 4 && point1 == 2)) { //Player 2 wins the game if points are 0-4, 1-4 and 2-4.
            printf("GAME: PLAYER 2\n");
            return EXIT_SUCCESS;
        }

        if (point1 == 3 && point2 == 3) { //If points are 3-3 then get out of this loop and enter next while loop.
            break;
        }
    }

    while ((point1 + point2 >= 6) && ((point1 - point2 == 0) || (point1 - point2 == 1) || (point1 - point2 == -1))) { //This while loop is tracking the winner of the game.
        if (point1 == point2) { //But this loop starts from 3-3 and ends when player 1 or player 2 wins the game.
            printf("DEUCE\n"); // If they have equal points then score of the game is Deuce.
        }
        if (point1 > point2) {
            printf("ADVANTAGE: PLAYER 1\n"); // If point of player 1 is bigger than point of player 2 then score of the game is Advantage player 1.
        }
        if (point1 < point2) {
            printf("ADVANTAGE: PLAYER 2\n"); // If point of player 2 is bigger than point of player 1 then score of the game is Advantage player 2.
        }

        printf("Point: ");
        scanf("%d", &user_input);

        if (user_input == 1) { //If user enters 1 as an input, then add 1 to point of player 1.
            point1++;
        }

        else if (user_input == 2) { //If user enters 2 as an input, then add 1 to point of player 2.
            point2++;
        }

        if (point1 - point2 == 2) { // If there are 2 points between player 1 and player 2; and player 1 has bigger point, then player 1 wins the game.
            printf("GAME: PLAYER 1\n");
            return EXIT_SUCCESS;
        }

        if (point2 - point1 == 2) { // If there are 2 points between player 1 and player 2; and player 2 has bigger point, then player 2 wins the game.
            printf("GAME: PLAYER 2\n");
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}
