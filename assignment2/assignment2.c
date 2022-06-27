#include <stdio.h> // for scanf and printf
#include <stdlib.h> // for EXIT_SUCCESS

#define MAX_ROWS 100 // maximum number of rows
#define MAX_LENGTH_OF_ROW 30 // maximum length of row (aisles included)
#define MAX_AISLES 5 // maximum number of aisles

int main()
{
    int num_rows;
    int seat_per_row;
    int num_aisles;
    int location_aisle1;
    int location_aisle2;
    int location_aisle3;
    int location_aisle4;
    int location_aisle5;
    int k = 0;
    char layout[MAX_ROWS][MAX_LENGTH_OF_ROW]; // array of seats and aisles
    char letters[20] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' }; // letters for columns
    int num_people;

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_LENGTH_OF_ROW; j++) {
            layout[i][j] = '-'; // all elements in the array are '-'
        }
    }

    printf("Number of rows: ");
    scanf("%d", &num_rows); // take number of rows from the user
    printf("Number of seats per row: ");
    scanf("%d", &seat_per_row); // take number of seats per row from the user
    printf("Number of aisles: ");
    scanf("%d", &num_aisles); // take number of aisles from the user

    switch (num_aisles) {
    case 1:
        printf("Add aisle 1 after seat: ");
        scanf("%d", &location_aisle1);
        for (int i = 0; i < num_rows + 1; i++) {
            layout[i][location_aisle1] = '|';
            layout[i][location_aisle1 + 1] = '|'; // turn seats (- -) into aisles (| |)
        }

        break;
    case 2:
        printf("Add aisle 1 after seat: ");
        scanf("%d", &location_aisle1);
        printf("Add aisle 2 after seat: ");
        scanf("%d", &location_aisle2);
        for (int i = 0; i < num_rows + 1; i++) {
            layout[i][location_aisle1] = '|';
            layout[i][location_aisle1 + 1] = '|';
            layout[i][location_aisle2 + 2] = '|';
            layout[i][location_aisle2 + 3] = '|';
        }
        break;
    case 3:
        printf("Add aisle 1 after seat: ");
        scanf("%d", &location_aisle1);
        printf("Add aisle 2 after seat: ");
        scanf("%d", &location_aisle2);
        printf("Add aisle 3 after seat: ");
        scanf("%d", &location_aisle3);
        for (int i = 0; i < num_rows + 1; i++) {
            layout[i][location_aisle1] = '|';
            layout[i][location_aisle1 + 1] = '|';
            layout[i][location_aisle2 + 2] = '|';
            layout[i][location_aisle2 + 3] = '|';
            layout[i][location_aisle3 + 4] = '|';
            layout[i][location_aisle3 + 5] = '|';
        }
        break;
    case 4:
        printf("Add aisle 1 after seat: ");
        scanf("%d", &location_aisle1);
        printf("Add aisle 2 after seat: ");
        scanf("%d", &location_aisle2);
        printf("Add aisle 3 after seat: ");
        scanf("%d", &location_aisle3);
        printf("Add aisle 4 after seat: ");
        scanf("%d", &location_aisle4);
        for (int i = 0; i < num_rows + 1; i++) {
            layout[i][location_aisle1] = '|';
            layout[i][location_aisle1 + 1] = '|';
            layout[i][location_aisle2 + 2] = '|';
            layout[i][location_aisle2 + 3] = '|';
            layout[i][location_aisle3 + 4] = '|';
            layout[i][location_aisle3 + 5] = '|';
            layout[i][location_aisle4 + 6] = '|';
            layout[i][location_aisle4 + 7] = '|';
        }
        break;
    case 5:
        printf("Add aisle 1 after seat: ");
        scanf("%d", &location_aisle1);
        printf("Add aisle 2 after seat: ");
        scanf("%d", &location_aisle2);
        printf("Add aisle 3 after seat: ");
        scanf("%d", &location_aisle3);
        printf("Add aisle 4 after seat: ");
        scanf("%d", &location_aisle4);
        printf("Add aisle 5 after seat: ");
        scanf("%d", &location_aisle5);
        for (int i = 0; i < num_rows + 1; i++) {
            layout[i][location_aisle1] = '|';
            layout[i][location_aisle1 + 1] = '|';
            layout[i][location_aisle2 + 2] = '|';
            layout[i][location_aisle2 + 3] = '|';
            layout[i][location_aisle3 + 4] = '|';
            layout[i][location_aisle3 + 5] = '|';
            layout[i][location_aisle4 + 6] = '|';
            layout[i][location_aisle4 + 7] = '|';
            layout[i][location_aisle5 + 8] = '|';
            layout[i][location_aisle5 + 9] = '|';
        }
        break;
    }

    for (int j = 0; j < MAX_LENGTH_OF_ROW; j++) {
        if (layout[0][j] != '|') {
            layout[0][j] = letters[k]; // print letters of columns
            k++;
        }
    }

    for (int i = 0; i < num_rows + 1; i++) {
        for (int j = 0; j < seat_per_row + num_aisles * 2; j++) {
            if (i == 0 && j == 0) {
                printf("   ");
            }

            else if (i < 10 && i > 0 && j == 0) {
                printf("%d  ", i); // print number of each row (from 1 to 9)
            }

            else if (i >= 10 && j == 0) // print number of each row (from 10 to 99)
            {
                printf("%d ", i);
            }

            printf(" %c", layout[i][j]); // print the layout
        }
        printf("\n");
    }

    printf("The number of people in the reservation\n (0: print current reservations, -1: exit): ");
    scanf("%d", &num_people);

    for (int j = 0; j < num_people; j++) // this loop is for the first reservation
    {
        if (layout[1][j] == '|') {
            j += 2;
            num_people += 2;
        }

        layout[1][j] = '+';
    }

    while (num_people != -1) {

        for (int i = 0; i < num_rows + 1; i++) {
            for (int j = 0; j < seat_per_row + num_aisles * 2; j++) {
                if (i == 0 && j == 0) {
                    printf("   ");
                }

                else if (i < 10 && i > 0 && j == 0) {
                    printf("%d  ", i);
                }

                else if (i >= 10 && j == 0) {
                    printf("%d ", i);
                }

                printf(" %c", layout[i][j]);
            }
            printf("\n");
        }

        printf("The number of people in the reservation\n (0: print current reservations, -1: exit): ");
        scanf("%d", &num_people);
    }

    return EXIT_SUCCESS;
}
