#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

struct Student
{
int student_id;
int food_taken_time;
int waiting_time;
int arrival_time;
int completion_time;
int total_time_taken;
int ftk;
}s[3];

int totaltime=0;
int T=0;

int maxEatTime(int at) 
{ 
    int max = 0, i; 
    for (i = 0; i < 3; i++) { 
        if (s[i].arrival_time <= at) {
            if (s[i].food_taken_time > s[max].food_taken_time) 
                max = i; 
            else if(s[max].food_taken_time==s[i].food_taken_time)
            {
            	if(s[max].student_id>s[i].student_id)
            	max=i;
			}
        } 
} 
return max;
}
int execution() 
{ 
  
    int index; 
    int flag = 0; 
    int i = s[0].arrival_time; 
    while (1) { 
        if (i <= 3) { 
            index = maxEatTime(i); 
        } 
  
        else
            index = maxEatTime(3); 
        printf("Process executing at time : %d is P%d",totaltime,index);
  
        s[index].food_taken_time -= 1; 
        totaltime += 1; 
        i++; 
  
        if (s[index].food_taken_time == 0) { 
            s[index].completion_time = totaltime;
       printf("\tProcess P%d is completed at:%d",index,totaltime);
        } 
        printf("\n");
  
        // loop termination condition 
        if (totaltime == T) 
            break; 
    } 
} 
  

int main()
{
int i;
s[0].student_id=2132;
s[1].student_id=2102;
s[2].student_id=2453;

s[0].food_taken_time=2;
s[1].food_taken_time=4;
s[2].food_taken_time=8;		

//displaying initial state
printf ("STUDENT NO.\t\t\tStudent_id\t\t\t Arrival_TIME\t\t\tfood_taken_time\n"); 
for(i=0;i<3;i++)
{
printf ("S%d\t\t\t\t%d\t\t\t\t %d\t\t\t\t %d\n",i,s[i].student_id,s[i].arrival_time,s[i].food_taken_time); 
}
//backup for food_taken_time so that to print it in end
for(i=0;i<3;i++)
{
	s[i].ftk=s[i].food_taken_time;
}
//calculating total time T 
for(i=0;i<3;i++)
{
	T+=s[i].food_taken_time;
}

//spacing
printf("\n");

//executing processes
execution();
//calculating values for Total Waiting time
int Twt=0;
for(i=0;i<3;i++)
{
	//Total time taken=completion time-arrival time
	s[i].total_time_taken=s[i].completion_time - s[i].arrival_time;
	// waiting time= total time taken - burst time
	s[i].waiting_time= s[i].total_time_taken -s[i].ftk;
	
	Twt= Twt+s[i].waiting_time;
	
}
 
//calculating values for turn around time
int totalTAT=0;
for(i=0;i<3;i++)
{
	totalTAT= totalTAT +s[i].total_time_taken;
}

// displaying final scenario


printf ("\nSTUDENT NO.\tID\t AT\tFTT\tWT\tTAT\tCT\n"); 
for(i=0;i<3;i++)
{
printf ("S%d\t\t%d\t %d\t %d\t %d\t %d\t %d\n",i,s[i].student_id,s[i].arrival_time,s[i].ftk,s[i].waiting_time,s[i].total_time_taken,s[i].completion_time); 
}
  
printf("\nTOTAL WAITING TIME:%d\n",Twt);
// average total waiting time
float aTwt=(float)Twt/3;   
printf("AVERAGE WAITING TIME:%f\n",aTwt);
printf("TURN AROUND TIME:%d\n",totalTAT);
float atotalTAT=(float)totalTAT/3;
printf("AVERAGE TURN AROUND TIME:%f\n",atotalTAT);



}

