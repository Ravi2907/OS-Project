#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/types.h>
#define MAX_RESOURCES 5



int available_resources =MAX_RESOURCES;
void decrement_count()

{	printf("\ninitial value of resource %d",available_resources);
	available_resources-=1;
	printf("\nresouce under use %d",available_resources);
	
	sleep(5);
	
	available_resources+=1;
printf("\nresouce under after use%d",available_resources);

}



int main()
{       int n;
	
	while(1)
	{int ch;
		printf("\nGet Licence\n\n");
		printf("\nEnter Your Choice \n");
		printf("\n1.get your licence\n2.Exit System");
	
		
		scanf("%d",&ch);
		if(ch==1)
		{	
			if(available_resources>0)
			{
				pthread_t tid[10];
				int count;
				
				pthread_create(&tid[0],NULL,decrement_count,NULL);
                                pthread_create(&tid[1],NULL,decrement_count,NULL);

                    		pthread_join(tid[0],NULL);
				pthread_join(tid[1],NULL);

	
		
		scanf("%d",&ch);

				

			}
			else
			{
				printf("\nunavailabillity of requested no of lincences ,Please try aftr some time");
			}
		}	
		else if(ch==2)
		{
			return(0);
		}
	

	}



}
