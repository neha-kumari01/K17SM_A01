#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

struct process
{
	int AT;
	int BT,BT1;
	int WT;
	int CT;	
	int flag;
} p[3];

int tq1=3;
int tq2=6;
float avgT=0;
float avgW=0;
int TotalWT=0;
int TotalTAT=0;

void firstIteration()
{
	int i=4,j;
	int time=0;
    for(time=0,j=0;i!=0;)
			
		if(p[i].BT >= tq1 && p[i].BT>0)
		{
		        printf("Process at time %d is P%d\n",time,i);
				p[i].BT=p[i].BT - tq1;
				time+=tq1;
				for(j=1;j<4;j++)
				{
					p[j].AT<time;
					insertQueue(j);					
				}
				deleteQueue(i)
	     	}
	insertQueue();
	
	deleteQueue();
	
	
}

int main()
{
	int i;
	// giving value of arrival time
	p[0].AT=0;
	p[1].AT=2;
	p[2].AT=4;
	p[3].AT=13;
	
	// giving value of BT time
	
	p[0].BT=18;
	p[1].BT=23;
	p[2].BT=13;
	p[3].BT=10;
	
	// keeping a backup of burst time
	for(i=0;i<4;i++)
	{
		p[i].BT1=p[i].BT;
	}
	
	printf("Process Id\t\t\t Arrival_TIME\t\t\tBURST_time\n"); 
    for(i=0;i<4;i++)
    {
     printf("P%d\t\t\t\t %d\t\t\t\t %d\n",i,p[i].AT,p[i].BT); 
    }
	firstIteration();
		
}
