#include <stdio.h>

#include <stdlib.h>

void look(int arr[], int n, int head, int direction) {

int seek_time = 0;

int i;

for (i = 0; i < n - 1; i++) {

for (int j = 0; j < n - i - 1; j++) {

if (arr[j] > arr[j + 1]) {

int temp = arr[j];

arr[j] = arr[j + 1];

arr[j + 1] = temp;

}}}

int* left = (int*)malloc(n * sizeof(int));

int* right = (int*)malloc(n * sizeof(int));

int l = 0, r = 0;

for (i = 0; i < n; i++) {

if (arr[i] < head)

left[l++] = arr[i];

else

right[r++] = arr[i];

}

printf("\nLOOK Scheduling (Direction: %s):\n", direction ? "Right" : "Left");

printf("Sequence of disk access: %d", head);

if (direction) {

for (i = 0; i < r; i++) {

printf(" %d", right[i]);

seek_time += abs(head - right[i]);

head = right[i];

}

for (i = l - 1; i >= 0; i--) {

printf(" %d", left[i]);

seek_time += abs(head - left[i]);
head = left[i];

}} else {

for (i = l - 1; i >= 0; i--) {

printf(" %d", left[i]);

seek_time += abs(head - left[i]);

head = left[i];

}

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

int disk1[n], disk2[n];

for (int i = 0; i < n; i++) {

disk1[i] = disk[i];

disk2[i] = disk[i];

}

look(disk1, n, head, 1); // Right

look(disk2, n, head, 0); // Left

return 0;

}

 
