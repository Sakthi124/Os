#include <stdio.h> 

#include <stdlib.h> 

#include <limits.h> 

void sstf(int disk[], int n, int head) { 

int i, j, seek_time = 0; 

int visited[n]; 

// Initialize all as not visited

for (i = 0; i < n; i++) { 

visited[i] = 0; 

} 

printf("\nSSTF Scheduling:\n"); 

printf("Sequence of disk access:"); 

for (i = 0; i < n; i++) { 

int min_dist = INT_MAX; 

int min_index = -1; 

for (j = 0; j < n; j++) { 

if (!visited[j] && abs(disk[j] - head) < min_dist) { 

min_dist = abs(disk[j] - head); 

min_index = j; 

} 

} 

visited[min_index] = 1; 

printf(" %d", disk[min_index]); 

seek_time += min_dist; 

head = disk[min_index]; 

} 
printf("\nTotal Seek Time: %d\n", seek_time); 

} 

int main() { 

int disk[] = { 98, 183, 37, 122, 14, 124, 65, 67 }; 

int n = sizeof(disk) / sizeof(disk[0]); 

int head; 

printf("Enter the initial position of the disk head: "); 

scanf("%d", &head); 

sstf(disk, n, head); 

return 0; 

}
