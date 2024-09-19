#include<stdio.h>
#include<stdlib.h>
struct day
{
char*day;
int*date;
char*activity;
};
struct day*create_calender();
void read_calender(struct day*calender);
void display_calender(struct day*calender);
void free_calender(struct day*calender);
int main()
{
struct day*calender=create_calender();
read_calender(calender);
display_calender(calender);
free_calender(calender);
return 0;
}
struct day*create_calender()
{
return(struct day*)malloc(7*sizeof(struct day));
}
void read_calender(struct day*calender)
{
for (int i=0;i<7;i++)
{
printf("enter the day %d \n",i+1);
scanf("%ms",&calender[i].day);
printf("enter the date for %s \n",calender[i].day);
scanf("%d",&calender[i].date);
printf("enter the activity for %s\n",calender[i].day);
scanf("%ms",&calender[i].activity);
}
}
void display_calender(struct day*calender)
{
printf("\n the activiy for the week wise\n");
for(int i=0;i<7;i++)
{
printf("day:%s,Date:%d,activity:%s \n",calender[i].day,calender[i].date,calender[i].activity);
}
}
void free_calender(struct day*calender)
{
for (int i=0;i<7;i++)
{
free(calender[i].day);
free(calender[i].activity);
}
free(calender);
}


