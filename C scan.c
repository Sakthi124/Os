#include <stdio.h>

#include <stdlib.h>

#define DISK_SIZE 200 // Total number of cylinders (0–199)

void cscan(int disk[], int n, int head) {

int seek_time = 0;

int i;

// Sort the disk requests

for (i = 0; i < n - 1; i++) {

for (int j = 0; j < n - i - 1; j++) {

if (disk[j] > disk[j + 1]) {

int temp = disk[j];

disk[j] = disk[j + 1];

disk[j + 1] = temp;

}}}

// Find the index of the first request greater than the head

int index = 0;

for (i = 0; i < n; i++) {

if (disk[i] > head) {

index = i;

break;

}}

printf("\nC-SCAN Scheduling:\n");

printf("Sequence of disk access: %d", head);

// Move toward the end

for (i = index; i < n; i++) {

printf(" %d", disk[i]);

seek_time += abs(disk[i] - head);
head = disk[i];

}

// Move to the end of the disk

if (head != DISK_SIZE - 1) {

seek_time += abs(DISK_SIZE - 1 - head);

head = 0; // Simulate jump from end to start

printf(" %d", DISK_SIZE - 1);

printf(" 0");

seek_time += DISK_SIZE - 1; // Jump from end (199) to 0

} else {

printf(" 0");

head = 0;

}

// Service the remaining requests from the beginning

for (i = 0; i < index; i++) {

printf(" %d", disk[i]);

seek_time += abs(disk[i] - head);

head = disk[i];

}

printf("\nTotal Seek Time: %d\n", seek_time);

}

int main() {

int disk[] = {98, 183, 37, 122, 14, 124, 65, 67};

int n = sizeof(disk) / sizeof(disk[0]);

int head;

printf("Enter the initial position of the disk head: ");

scanf("%d", &head);

cscan(disk, n, head);

return 0;

}
