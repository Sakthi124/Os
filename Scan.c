#include <stdio.h>

#include <stdlib.h>

#define DISK_SIZE 200 // Assume disk size for SCAN boundary

void scan(int arr[], int n, int head, int direction) {

int seek_time = 0;

int size = DISK_SIZE;

int i;

int* left = (int*)malloc(n * sizeof(int));

int* right = (int*)malloc(n * sizeof(int));

int l = 0, r = 0;

// Separate requests to left and right of head

for (i = 0; i < n; i++) {

if (arr[i] < head)

left[l++] = arr[i];

else

right[r++] = arr[i];

}

// Sort both halves

for (i = 0; i < l - 1; i++) {

for (int j = 0; j < l - i - 1; j++) {

if (left[j] > left[j + 1]) {

int temp = left[j];

left[j] = left[j + 1];
left[j + 1] = temp;

}}}

for (i = 0; i < r - 1; i++) {

for (int j = 0; j < r - i - 1; j++) {

if (right[j] > right[j + 1]) {

int temp = right[j];

right[j] = right[j + 1];

right[j + 1] = temp;

}}}

printf("\nSCAN Scheduling (Direction: %s):\n", direction == 1 ? "Right" : "Left");

printf("Sequence of disk access: %d", head);

if (direction == 1) {

// Moving toward higher cylinders

for (i = 0; i < r; i++) {

printf(" %d", right[i]);

seek_time += abs(head - right[i]);

head = right[i];

}

// Go to end

if (head != size - 1) {

seek_time += abs(head - (size - 1));

head = size - 1;

}

// Reverse direction

for (i = l - 1; i >= 0; i--) {

printf(" %d", left[i]);

seek_time += abs(head - left[i])
head = left[i];

}

} else {

// Moving toward lower cylinders

for (i = l - 1; i >= 0; i--) {

printf(" %d", left[i]);

seek_time += abs(head - left[i]);

head = left[i];

}

// Go to beginning

if (head != 0) {

seek_time += abs(head - 0);

head = 0;

}

// Reverse direction

for (i = 0; i < r; i++) {

printf(" %d", right[i]);

seek_time += abs(head - right[i]);

head = right[i];

}}

printf("\nTotal Seek Time: %d\n", seek_time);

free(left);

free(right);

}

int main() {
int disk[] = {98, 183, 37, 122, 14, 124, 65, 67};

int n = sizeof(disk) / sizeof(disk[0]);

int head;

printf("Enter the initial position of the disk head: ");

scanf("%d", &head);

scan(disk, n, head, 1); // Moving toward higher numbers (right)

scan(disk, n, head, 0); // Moving toward lower numbers (left)

return 0;

}
