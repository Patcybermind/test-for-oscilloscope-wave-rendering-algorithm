#include <stdio.h>
#include <time.h>

#define WINDOW_SIZE 160  // Size of the sliding window (number of samples)

int main() {
    // Parameters
    int window_size = WINDOW_SIZE;  // Size of the sliding window (number of samples)
    int sampling_rate = 1000;  // Sample rate (samples per second)
    float change_threshold = 0.5;  // Threshold for detecting sudden changes

    // memory
    float screen_buffer[WINDOW_SIZE] = {0};

    int u = 0;
    int i = 0;
    int index = 0;

    // Start timer
    clock_t start_time = clock();

    while (i < 10900900) {
        i += 1;
        u = i + 5;
        u = u * 9;
        u = u / 2;
        u = u - 1;
        index += 1;
        screen_buffer[index] = u;
        if (index == window_size - 1) {
            index = 0;
        }
    }

    // End timer
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("done\n");
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}