#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for usleep 

void roll_animation(int sides, int count) {
    printf("Rolling %d D%d: ", count, sides);
    for (int i = 0; i < count; i++) {
        int result = (rand() % sides) + 1;
        printf("%d ", result);
        fflush(stdout);
        usleep(100000);  // Sleep for 100 milliseconds
    }
    printf("\n");
}

int roll_dice(int sides, int count) {
    roll_animation(sides, count);
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += (rand() % sides) + 1;
    }
    return total;
}

int main() {
    int dice_types[] = {20, 12, 8, 6, 4, 100};
    int dice_counts[6] = {0};
    int total_result = 0;

    srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        do {
            printf("How many D%d dice would you like to roll? (1-10): ", dice_types[i]);
            scanf("%d", &dice_counts[i]);
        } while (dice_counts[i] < 1 || dice_counts[i] > 10);
    }

    for (int i = 0; i < 6; i++) {
        total_result += roll_dice(dice_types[i], dice_counts[i]);
    }

    printf("Total result: %d\n", total_result);
    return 0;
}
