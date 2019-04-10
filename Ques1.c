#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

struct process
{
	int id;
	int AT;
	int BT,BT1;
	int CT;
	int WT;
	int TAT;
	int flag;
	int check;
} p[3];
//declaring queue
int ready_queue[150];
int front=-1;
int rear=-1;
void insert(int index)  
{
	if (rear == 149)
        printf("Queue Overflow \n");
        else
        {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        rear = rear + 1;
        ready_queue[rear] =index;
        printf("Process entered readyQueue :%d\n",ready_queue[rear]);
        }
}
void qdelete()
{
	if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", ready_queue[front]);
        front = front + 1;
    }
}

int tq1=3;
int tq2=6;
float avgT=0;
float avgW=0;
int TotalWT=0;
int TotalTAT=0;

void firstIteration()
{
	int i=4,j,k;
	int time=0;
	insert(0);
	p[0].check=1;
	int n=ready_queue[rear];
	while(n!=-1)
	{
	if(p[n].BT >= tq1 && p[n].BT>0)
	{
            printf("Process at time %d is P%d\n",time,n);			        
	    p[n].BT=p[n].BT - tq1;
		time+=tq1;
		p[n].flag=1;   //counting number of times process execute
		for(k=n+1;k<4;k++) //placing in ready queue
		{
		if(p[k].AT<time && p[k].check==0)
		{
		insert(k);
		p[k].check++;
    	}
        }
        if(p[n].BT>0)
		insert(n);		
					   
	qdelete();
	n=ready_queue[front];
   }
   
   	if(p[0].flag==1)
   	if(p[1].flag==1)
   	if(p[2].flag==1)
   	if(p[3].flag==1)
   	{
   	break;	
   }
}
}

void secondIteration()
{
	int k;
	int n=ready_queue[front];
	while(n!=-1)
	{
	if(p[n].BT >= tq2 && p[n].BT>0)
	{
        printf("Process at time %d is P%d\n",time,n);			        
	    p[n].BT=p[n].BT - tq2;
		time+=tq2;
		p[n].flag=1;   //counting number of times process execute
		
        if(p[n].BT>0)
	insert(n);		
					   
	qdelete();
	n=ready_queue[front];
   }
   
   	if(p[0].flag==1)
   	if(p[1].flag==1)
   	if(p[2].flag==1)
   	if(p[3].flag==1)
   	{
   	break;	
   }
}
}

void SJF()
{
	int i;
	int j=4;
	int minBT=p[0].BT;
	int index;
	while(j!=0)
	{
	for(i=0;i<4;i++)
	{
	if(p[i].BT<minBT)
	{
	 index=i;
	}
	else if(p[index].BT == p[i].BT)
	{
		if(p[index].id>p[i].id)
		{
			index=i;
		}
	}
	}
	printf("Process at time %d is P%d",time,index);	
	time+=p[index].BT;
	 p[index].BT=0;
		if(p[index].BT==0)
		{
			printf("\t Process P%d completes at time: %d",index,time);
			p[index].CT=time;
			j--;
		}
	}
	
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
	
	//giving id to processes
	for(i=0;i<4;i++)
	{
		p[i].id=i;
	}
	
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
    
// round robin with Time quantum=3
	firstIteration();
	
//displaying the scenario after first iteration
	printf("Process Id\t\t\t Arrival_TIME\t\t\tBURST_time\t\t\tBURST_TIME_LEFT\n"); 
    for(i=0;i<4;i++)
    {
     printf("P%d\t\t\t\t %d\t\t\t\t %d\t\t\t\t %d\n",i,p[i].AT,p[i].BT1,p[i].BT); 
    }
	
// for each process changing flag value =0
  for(i=0;i<4;i++)
  {
  	p[i].flag=0;
   }
   
   //round robin with Time quantum=6
   secondIteration();
   
   //displaying the scenario after first iteration
	printf("Process Id\t\t\t Arrival_TIME\t\t\tBURST_time\t\t\tBURST_TIME_LEFT\n"); 
    for(i=0;i<4;i++)
    {
     printf("P%d\t\t\t\t %d\t\t\t\t %d\t\t\t\t %d\n",i,p[i].AT,p[i].BT1,p[i].BT); 
    }
    
    //shortest job first
    SJF();
	
    printf("Process Id\t\t\t Arrival_TIME\t\t\tBURST_time\t\t\tBURST_TIME_LEFT\n"); 
    for(i=0;i<4;i++)
    {
     printf("P%d\t\t\t\t %d\t\t\t\t %d\t\t\t\t %d\n",i,p[i].AT,p[i].BT1,p[i].BT); 
    }
   
	//calculating values for Total Waiting time
for(i=0;i<4;i++)
{
	//Total time taken=completion time-arrival time
	p[i].TAT=p[i].CT - p[i].AT;
	// waiting time= total time taken - burst time
	p[i].WT= p[i].TAT -p[i].BT1;
	
	TotalWT= TotalWT+p[i].WT;
	
}
 
//calculating values for turn around time
for(i=0;i<4;i++)
{
	TotalTAT= TotalTAT +p[i].TAT;
}

// displaying final scenario


printf ("\nProcess_ID.\tAT\tBT\tWT\tTAT\tCT\n"); 
for(i=0;i<3;i++)
{
printf ("%d\t %d\t %d\t %d\t %d\t %d\n",p[i].id,p[i].AT,p[i].BT,p[i].WT,p[i].TAT,p[i].CT); 
}
  
printf("\nTOTAL WAITING TIME:%d\n",TotalWT);
// average total waiting time
avgw=(float)TotalWT/3;   
printf("AVERAGE WAITING TIME:%f\n",avgw);
printf("TURN AROUND TIME:%d\n",TotalTAT);
float avgT=(float)TotalTAT/3;
printf("AVERAGE TURN AROUND TIME:%f\n",avgT);


}
