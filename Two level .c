#include<stdio.h>

struct st

{

char dname[20],sdname[20][20],fname[20][20][20];

int ds,sds[20];

}dir[20];

int main()

{

int i,j,k,n;

printf("Enter number of master file directories :");

scanf("%d",&n);

for(i=0;i<n;i++)

{

printf("Enter Name of directory %d",i+1);

122;

scanf("%s",dir[i].dname);

printf("Enter number of user file directories :");

scanf("%d",&dir[i].ds);

for(j=0;j<dir[i].ds;j++)

{

printf("Enter user file directory name and size");

scanf("%s",dir[i].sdname[j]);

scanf("%d",&dir[i].sds[j]);

for(k=0;k<dir[i].sds[j];k++)

{

printf("Enter file name :");

scanf("%s",dir[i].fname[j][k]);

}

}

}

printf("\n Master dir name\tsize\t sub dir name\t size\t files\n");

printf("\n****************************************\n");

for(i=0;i<n;i++)

{

printf("%s\t\t%d",dir[i].dname,dir[i].ds);

for(j=0;j<dir[i].ds;j++)

{

printf("\t%s\t\t%d\t",dir[i].sdname[j],dir[i].sds[j]);
73

for(k=0;k<dir[i].sds[j];k++)

printf("%s\t",dir[i].fname[j][k]);

printf("\n\t\t");

}

printf("\n");

}

}
