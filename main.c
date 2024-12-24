#include <stdio.h>
#include <windows.h>

#define WINDOW_SIZE 160  // Size of the sliding window 
#define TARGET_CALLS 1000000  // Number of calls to measure

int screen_buffer[WINDOW_SIZE] = {0};
volatile long call_count = 0;

void CALLBACK high_frequency_function(PVOID lpParameter, BOOLEAN TimerOrWaitFired) {
    // Simple operation to keep the function lightweight
    screen_buffer[0]++;
    InterlockedIncrement(&call_count);
}

int main() {
    HANDLE hTimer = NULL;
    LARGE_INTEGER liDueTime;
    liDueTime.QuadPart = -1; // Start immediately

    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);

    // Create a high-resolution timer
    if (!CreateTimerQueueTimer(&hTimer, NULL, (WAITORTIMERCALLBACK)high_frequency_function, NULL, 0, 1, WT_EXECUTEINTIMERTHREAD)) {
        printf("CreateTimerQueueTimer failed (%d)\n", GetLastError());
        return 1;
    }

    // Measure the time taken for TARGET_CALLS calls
    QueryPerformanceCounter(&start);
    while (call_count < TARGET_CALLS) {
        // Do nothing, just wait for the timer callback to be called
    }
    QueryPerformanceCounter(&end);

    // Calculate the elapsed time in seconds
    double elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Time taken for %d calls: %f seconds\n", TARGET_CALLS, elapsed_time);

    // Clean up the timer
    DeleteTimerQueueTimer(NULL, hTimer, NULL);

    return 0;
}f