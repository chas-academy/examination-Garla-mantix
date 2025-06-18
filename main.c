#include <stdio.h>
#include <string.h>
#include <ctype.h>

char name[5][11];
int scores[5][13];
double averages[5];

int get_data(int i);
double calculate_average(int scores[]);
void print_top_student(char name[]);
void print_below_average(double averages[], double overall_avg);

int main() {
    double highest = 0;
    int top_student = 0;
    double total_avg = 0;

    for (int i = 0; i < 5; i++) {
        if (get_data(i) != 0) {
            return 1;
        }

        double avg = calculate_average(scores[i]);
        averages[i] = avg;
        total_avg += avg;

        if (avg > highest) {
            highest = avg;
            top_student = i;
        }
    }

    double overall_avg = total_avg / 5;

    print_top_student(name[top_student]);
    print_below_average(averages, overall_avg);

    return 0;
}

// Function to get input from the user and validate that input
int get_data(int i) {
    int input = scanf("%10s %d %d %d %d %d %d %d %d %d %d %d %d %d",
        name[i], &scores[i][0], &scores[i][1], &scores[i][2], &scores[i][3], &scores[i][4],
        &scores[i][5], &scores[i][6], &scores[i][7], &scores[i][8], &scores[i][9],
        &scores[i][10], &scores[i][11], &scores[i][12]);

    // Validates length of input
    if (input != 14) {
        printf("Invalid input format. Please enter the name followed by 13 scores.\n");
        return 1;
    }

    // Validates name's length 
    int len = strlen(name[i]);
    if (len < 1 || len > 10) {
        printf("Name must be between 1 and 10 characters long.\n");
        return 1;
    }

    // Valudates name's characters
    for (int j = 0; name[i][j] != '\0'; j++) {
        if (!isalpha((unsigned char)name[i][j])) {
            printf("Name must only contain letters (a-z, A-Z).\n");
            return 1;
        }
    }

    // Validates scores
    for (int j = 0; j < 13; j++) {
        if (scores[i][j] < 0 || scores[i][j] > 10) {
            printf("All scores must be integers between 0 and 10.\n");
            return 1;
        }
    }

    // Capitalizes first letter of name
    name[i][0] = toupper((unsigned char)name[i][0]);


    return 0;
}

// Function to average score
double calculate_average(int scores[]) {
    int sum = 0;
    for (int j = 0; j < 13; j++) {
        sum += scores[j];
    }
    return (double)sum / 13;
}

// Function to print top student
void print_top_student(char name[]) {
    printf("%s\n", name);
}

// Function to print below average
void print_below_average(double averages[], double overall_avg) {
    for (int i = 0; i < 5; i++) {
        if (averages[i] < overall_avg) {
            printf("%s\n", name[i]);
        }
    }
}
