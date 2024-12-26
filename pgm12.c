#include<stdio.h>
#include<stdlib.h>
int empkey[20],hashindex,n,m,*ht,elecount=0;
void createhashtable()
{
ht=(int*)malloc(m*sizeof(int));
if(ht==NULL)
printf("MEMORY UNAVAILABLE!");
else
{
for(int i=0;i<m;i++)
{
ht[i]=-1;
}
}
}
void insertintohashtable(int key)
{
hashindex=key%m;
if(ht[hashindex]!=-1)
{
hashindex=(hashindex+1)%m;
}
ht[hashindex]=key;
elecount++;
}
void display()
{
int i;
if(elecount==0)
{
printf("HASH TABLE EMPTY\n");
}
for(i=0;i<m;i++)
{
printf("T[%d]-->%d\n",i,ht[i]);
}
}
void main()
{
int i;
printf("enter no of records: ");
scanf("%d",&n);
printf("enter hashtable size: ");
scanf("%d",&m);
printf("enter emp key values: \n");
for(i=0;i<n;i++)
{
scanf("%d",&empkey[i]);
}
createhashtable();
printf("inserting keys into hashtable:\n");
for(i=0;i<n;i++)
{
if(elecount==m)
{
printf("HASH TABLE FULL\n");
printf("cant insert %d key\n",empkey[i]);
break;
}
insertintohashtable(empkey[i]);
}
display();
}