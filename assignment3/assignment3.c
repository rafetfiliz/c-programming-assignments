#include <stdio.h> //for printf,fscanf,fopen and getc
#include <stdlib.h> //for free,EXIT_SUCCESS and EXIT_FAILURE

#define N_COLUMNS 4 //Number of candidates.

struct Candidate { //Struct to define candidates.
    char letter;
    int votes;
    float percent;
} candidate1, candidate2, candidate3, candidate4;

int row_number(char* filename) //Funcion that calculates the number of lines (number of districts) in the file.
{
    FILE* fp;
    fp = fopen(filename, "r");

    int count = 0;
    char c;

    for (c = getc(fp); c != EOF; c = getc(fp)) { //Calculate number of lines.
        if (c == '\n')
            count++;
    }

    return count;

    fclose(fp);
}

void read_file(char* filename, int** arr, int row_number) //Function that assigns integers from file to an array.
{
    FILE* fp;
    fp = fopen(filename, "r");
    for (int i = 0; i < row_number; i++) {
        for (int j = 0; j < N_COLUMNS; j++) {
            fscanf(fp, "%d", &arr[i][j]);
        }
    }

    fclose(fp);
}

void votes_and_percentages(int** arr, int row_number) //Function that calculates the number of votes and percentage of vote for each candidate.
{
    int sum;

    for (int i = 0; i < row_number; i++) {
        for (int j = 0; j < N_COLUMNS; j++) {
            if (j == 0) {
                candidate1.votes += arr[i][j];
            } else if (j == 1) {
                candidate2.votes += arr[i][j];
            } else if (j == 2) {
                candidate3.votes += arr[i][j];
            } else if (j == 3) {
                candidate4.votes += arr[i][j];
            }
        }
    }

    sum = candidate1.votes + candidate2.votes + candidate3.votes + candidate4.votes;

    candidate1.percent = (candidate1.votes * 100.0) / sum;
    candidate2.percent = (candidate2.votes * 100.0) / sum;
    candidate3.percent = (candidate3.votes * 100.0) / sum;
    candidate4.percent = (candidate4.votes * 100.0) / sum;
}

void decider() //Function that decides which candidate wins or which candidates are going to second round.
{

    if (candidate1.percent > 50.0) {
        printf("Winner: %c\n", candidate1.letter);

    } else if (candidate2.percent > 50.0) {
        printf("Winner: %c\n", candidate2.letter);

    } else if (candidate3.percent > 50.0) {
        printf("Winner: %c\n", candidate3.letter);

    } else if (candidate4.percent > 50.0) {
        printf("Winner: %c\n", candidate4.letter);

    }

    else if ((candidate1.percent <= 50.0) && (candidate2.percent <= 50.0) && (candidate3.percent <= 50.0) && (candidate4.percent <= 50.0)) { //To decide which candidates are going to second round.
        double largest;
        double second;
        char letter_of_largest;
        char letter_of_second;
        double percentages[4] = { candidate1.percent, candidate2.percent, candidate3.percent, candidate4.percent }; //Array that store percentages of votes of candidates.
        if (percentages[0] > percentages[1]) {
            largest = percentages[0];
            second = percentages[1];
        } else if (percentages[1] > percentages[0]) {
            largest = percentages[1];
            second = percentages[0];
        }
        for (int i = 0; i < 4; i++) {
            if (percentages[i] > largest) { //Find the largest percentage.
                largest = percentages[i];
                switch (i) {
                case 0:
                    letter_of_largest = 'A';
                    break;
                case 1:
                    letter_of_largest = 'B';
                    break;
                case 2:
                    letter_of_largest = 'C';
                    break;
                case 3:
                    letter_of_largest = 'D';
                    break;
                }
            } else if (second < percentages[i]) { //Find the smallest percentage.
                second = percentages[i];
                switch (i) {
                case 0:
                    letter_of_second = 'A';
                    break;
                case 1:
                    letter_of_second = 'B';
                    break;
                case 2:
                    letter_of_second = 'C';
                    break;
                case 3:
                    letter_of_second = 'D';
                    break;
                }
            }
        }

        printf("Second round: %c and %c\n", letter_of_largest, letter_of_second);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        return EXIT_FAILURE;
    }

    int n_rows = 0;

    n_rows = row_number(argv[1]); //Assign number of rows to n_rows.

    int** main_array; //Dynamic array of votes.
    main_array = malloc(sizeof(int*) * n_rows);
    for (int i = 0; i < n_rows; i++)
        main_array[i] = (int*)malloc(sizeof(int) * N_COLUMNS);

    read_file(argv[1], main_array, n_rows); //Assign integers from file to this dynamic array.

    candidate1.letter = 'A';
    candidate2.letter = 'B';
    candidate3.letter = 'C';
    candidate4.letter = 'D';

    votes_and_percentages(main_array, n_rows); //Calculate number of votes and percentages of votes of candidates.

    decider(); //Decide which candidate wins or which candidates are going to second round.

    for (int i = 0; i < n_rows; i++) {
        free(main_array[i]);
        main_array[i] = NULL;
    }

    free(main_array);
    main_array = NULL;

    return EXIT_SUCCESS;
}
