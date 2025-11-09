#include <stdio.h>
#include <stdbool.h>

// Shared lock variable
volatile bool lock = 0;

void entry_section() {
    while (lock != 0 ) {
        // Busy waiting
    }
    lock = 1; // Acquire the lock
}

void exit_section() {
    lock = 0; // Release the lock
}

void critical_section(int process_id) {
    printf("Process %d is in the critical section\n", process_id);
    // Simulate critical section work
}

void process(int process_id) {
    entry_section();
    critical_section(process_id);
    exit_section();
}

int main() {
    // Example simulation for P1, P2
    process(1);
    process(2);
    return 0;
}
