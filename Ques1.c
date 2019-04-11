#include<stdio.h>

//process body of process
struct process
{
	int id;
	int AT;
	int BT,BT1;
	int WT;
	int CT;
	int TAT;
	int check;   
	int flag;
}p[4];

void first_iteration();
void second_iteration();
int Index();
void SJF();


// declaring queue
int ready_queue[150];
int front=-1;
int rear=-1;
void insert(int index)  
{
	if (rear == 149)
        printf("Queue Overflow \n");
        else
        {
        if (front == -1)
        /*If queue is initially empty */
        front = 0;
        rear = rear + 1;
        ready_queue[rear] =index;
        printf("Process entered readyQueue: P%d\n",ready_queue[rear]);
        }
}
void qdelete()
{
	if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is: P%d\n", ready_queue[front]);
        front = front + 1;
    }
}

int time=0;
int tq1=3;
int tq2=6;
int TotalTIME=64;


int main()
{
	int TotalWT;
	int TotalTAT;
	float avgW;
	float avgT;
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
		p[i].flag=0;
		p[i].check=0;
	}
	
	// keeping a backup of burst time
	for(i=0;i<4;i++)
	{
		p[i].BT1=p[i].BT;
	}
	
	//displaying the initial state
	printf("Process Id\t Arrival_TIME\t BURST_time\n"); 
    for(i=0;i<4;i++)
    {
     printf("P%d\t\t %d\t\t %d\n",p[i].id,p[i].AT,p[i].BT); 
    }
    
    //round robin with timeQuantum 3
    first_iteration();
    
    //displaying the scenario after first iteration
	printf("Process Id\t\t\t Arrival_TIME\t\t\tBURST_time\t\t\tBURST_TIME_LEFT\n"); 
    for(i=0;i<4;i++)
    {
     printf("P%d\t\t\t\t %d\t\t\t\t %d\t\t\t\t %d\n",p[i].id,p[i].AT,p[i].BT1,p[i].BT); 
    }
    
    // for each process changing flag value =0 for second iteration
    for(i=0;i<4;i++)
    {
  	p[i].flag=0;
    }
    
    //round robin with timeQuantum 6
	second_iteration(); 
		
    //displaying the scenario after second iteration
	printf("Process Id\t\t\t Arrival_TIME\t\t\tBURST_time\t\t\tBURST_TIME_LEFT\n"); 
    for(i=0;i<4;i++)
    {
     printf("P%d\t\t\t\t %d\t\t\t\t %d\t\t\t\t %d\n",p[i].id,p[i].AT,p[i].BT1,p[i].BT); 
    }
    
    //shortest job first
    SJF();
    
    // calculating Waiting time and totaltime taken
    for(i=0;i<4;i++)
    {
    	p[i].TAT=p[i].CT-p[i].AT;
    	p[i].WT=p[i].TAT-p[i].BT1;
    	
    	TotalWT=TotalWT+p[i].WT;
    	TotalTAT=TotalTAT+p[i].TAT;
	}
	
	//displaying the final scenario after completion of all processes
    printf("Process Id\tArrival_TIME\tBURST_time\tCT\t\tWT\t\tTAT\n"); 
    for(i=0;i<4;i++)
    {
     printf("P%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",p[i].id,p[i].AT,p[i].BT1,p[i].CT,p[i].WT,p[i].TAT); 
    }
    
    // calculating average waiting time and average turn around time
    avgW=(float)(TotalWT/4);
    avgT=(float)(TotalTAT/4);
    printf("\nAVERAGE WAITING TIME : %f",avgW);
    printf("\nAVERAGE TURNAROUND TIME : %f",avgT);
    
}

void first_iteration()
{
	int i;
	insert(0);
	int n;
	n=ready_queue[rear];
	p[0].check=1;
	
	while(n!=-1)
	{
		if((p[n].BT>=tq1) && (p[n].BT>0))
		{
			printf("PROCESS EXECUTING AT TIME:%d is P%d\n",time,n);
			p[n].BT = p[n].BT-tq1;
			time=time+tq1;
			//counting no.of times process executes
			p[n].flag++;
			//adding processes to ready queue
			for(i=1;i<4;i++) // adding processes arriving while executing a process
			{
				if( (p[i].AT<time) && (p[i].check==0))
				{
					insert(i);
					p[i].check++;
				}
			}
			// inserting process if work is still left
			if(p[n].BT>0)
			{
				insert(n);
			}
			//deleting a process who have executing this time
			qdelete();
			n=ready_queue[front];			
		}
	 if(p[0].flag>=1)
	 if(p[1].flag>=1)
	 if(p[2].flag>=1)
	 if(p[3].flag>=1)
	 {
	 	break;
	 }
	}
}

void second_iteration()
{
	int i;
	int n=ready_queue[front];
	while(n!=-1)
	{
		if( (p[n].BT>= tq2)&&(p[n].BT>0) )
		{
        printf("Process at time %d is P%d\n",time,n);			        
	    p[n].BT=p[n].BT-tq2;
		time=time+tq2;
		p[n].flag++;   //counting number of times process execute
		
        if(p[n].BT>0)
        {
		   insert(n);
	    }
					   
	    qdelete();
     	n=ready_queue[front];
   }
   
   	if(p[0].flag>=1)
   	if(p[1].flag>=1)
   	if(p[2].flag>=1)
   	if(p[3].flag>=1)
   	{
   	  break;	
    }
    }
}

int Index()
{
   int i;
   int pos=0;
   int min = p[0].BT;
   for(i=0;i<4;i++)
    {
    	if(p[i].BT<min)
    	{
    		min=p[i].BT;
    		pos=i;
		}
    }
    	return pos;	
}


void SJF()
{
	int i=0;
	int minBT=p[0].BT;
	int index;
	while(1)
	{	
	    index=Index();            
		printf("Process at time %d is P%d\n",time,index);		
		p[index].BT=p[index].BT-1;
     	time=time+1;    	
    	if(p[index].BT==0)
		{
			printf("\tProcess P%d completes at time: %d\n",index,time);
			p[index].BT=16;
			p[index].CT=time;
		}
		if(time==TotalTIME)
		{
			break;
		}
	}
	
}
