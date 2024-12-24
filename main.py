import numpy as np
import matplotlib.pyplot as plt
from collections import deque
import time

# Parameters
window_size = 160  # Size of the sliding window (number of samples)
sampling_rate = 1000  # Sample rate (samples per second)
change_threshold = 0.5  # Threshold for detecting sudden changes

# memory
screen_buffer = [0] * window_size

u = 0
i = 0
index = 0

# Start timer
start_time = time.time()

while i < 10900900:
    i += 1
    u = i + 5
    u = u * 9
    u = u / 2
    u = u - 1
    index += 1
    screen_buffer[index] = u
    if index == window_size - 1:
        index = 0

# End timer
end_time = time.time()
time_taken = end_time - start_time

print("done")
print(f"Time taken: {time_taken} seconds")