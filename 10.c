#include<stdio.h>

#include<math.h>

void main() {

 int size, n, pgno, pagetable[3] = {5, 6, 7}, i, j, frameno;

 double ml;

 int ra = 0, ofs;



 printf("Enter process size (in KB of max 12KB): ");

 scanf("%d", &size);

 ml = size / 4;

 n = ceil(ml);

 printf("Total No. of pages: %d\n", n);

 printf("\nEnter relative address (in hexa): ");

 scanf("%x", &ra);

 pgno = ra / 1000;

 ofs = ra % 1000;

EX NO:10

IMPLEMENT THE PAGING TECHNIQUE USING C 

PROGRAM DATE:
54

 printf("Page no = %d\n", pgno);

 // Display page table

 printf("Page table:\n");

 for(i = 0; i < n; i++) {

 printf("%d[%d]\n", i, pagetable[i]);

 }

 frameno = pagetable[pgno];


 printf("\nPhysical address: %d%d\n", frameno, ofs);

}

