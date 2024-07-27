#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_animation(int sides) {
    printf("Rolling a D%d: ", sides);
    for (int i = 0; i < 5; i++) {
        int result = (rand() % sides) + 1;
        printf("%d ", result);
        fflush(stdout);
        usleep(100000);  // Sleep for 100 milliseconds
    }
    printf("\n");
}

int roll_dice(int sides) {
    roll_animation(sides);
    return (rand() % sides) + 1;
}

int main() {
    int dice_types[] = {20, 12, 8, 6, 4, 100};
    int dice_counts[6] = {0};
    int total_result = 0;

    srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        printf("How many D%d dice would you like to roll? (0-6): ", dice_types[i]);
        scanf("%d", &dice_counts[i]);
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < dice_counts[i]; j++) {
            int result = roll_dice(dice_types[i]);
            total_result += result;
        }
    }

    printf("Total result: %d\n", total_result);
    return 0;
}
