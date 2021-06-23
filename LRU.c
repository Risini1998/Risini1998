//19001215
//LRU using a Queue

#include<stdio.h>
#include<string.h>

int isfull(int *rear);
int isempty(int *front,int *rear);
void enqueue(char queue[],int *front,int *rear,char n);
char dequeue(char queue[],int *front,int *rear);
int LRU(int time[]);

int noframe;

void main()
{
	char queue[10], tempq[10], page[40]={'\0'};
	int front=-1, rear=-1, tfront=-1, trear=-1;
	int count = 0, e1, e2, i, j, pos, faults = 0;
	int time[10];
	printf("\n Enter no of initial page slots: ");
	scanf("%d", &noframe);
	
	printf("\n Enter reference string: ");
	scanf(" %[^\n]s",page);
    
	for(i = 0; page[i] != '\0'; i++)
	{
		if(page[i]==' ')
			continue;
				
    	e1 = e2 = 0;
    	
    	for(j = front; j <= rear && j != -1; j++)
		{
    		if(queue[j] == page[i])
			{
	    		count++;
	    		time[j] = count;
	   			e1 = e2 = 1;
	   			break;
   			}
    	}
    	
    	if(e1 == 0)
		{
			if(isfull(&rear)==0)
			{
	    		count++;
	    		faults++;
	   			enqueue(queue,&front,&rear,page[i]);
	   			j=rear;
	   			time[j] = count;
	   			e2 = 1;
	    	}	
    	}
    	
    	if(e2 == 0)
		{
    		pos = LRU(time);
    		count++;
    		faults++;
    		time[pos] = count;
    		
    		int val;
    		while(isempty(&front,&rear)==0)
    		{
    			if(front==pos)
    			{
    				enqueue(tempq,&tfront,&trear,page[i]);
    				val=dequeue(queue,&front,&rear);
				}
				else
				{
					val=dequeue(queue,&front,&rear);
					enqueue(tempq,&tfront,&trear,val);
				}
			}
			
			while(isempty(&tfront,&trear)==0)
			{
				val=dequeue(tempq,&tfront,&trear);
				enqueue(queue,&front,&rear,val);
			}
    		
    	}
    	
    	printf("\n\n   |");
    	for(j = front; j <= rear; j++)
		{
    		printf("  %c  |",queue[j]);
    	}
    	
    	for(j=0;j<noframe-rear;j++)
    	{
    		printf("      ");
		}
		printf("\t%d Page Faults up to now", faults);
	}
	
    printf("\n\n\n Total Page Faults = %d\n", faults);
}

int isfull(int *rear)
{
	if(*rear==noframe-1)
		return 1;
	else
		return 0;
}

int isempty(int *front,int *rear)
{
	if(*front== -1 || *front>*rear)
		return 1;
	else
		return 0;
}

void enqueue(char queue[],int *front,int *rear,char n)
{
	if(isfull(rear)==0)
	{
		if(*front==-1 && *rear==-1)
			*front=*rear=0;
		else
			(*rear)++;
		queue[*rear]=n;	
	}
}

char dequeue(char queue[],int *front,int *rear)
{
	if(isempty(front,rear)==0)
	{
		int val=queue[*front];
		(*front)++;
		if(*front>*rear)
			*front=*rear=-1;
		return val;
	}
}

int LRU(int time[])
{
	int i, minimum = time[0], pos = 0;
 
	for(i = 1; i < noframe; ++i)
	{
		if(time[i] < minimum)
		{
			minimum = time[i];
			pos = i;
		}
	}
	return pos;
}
