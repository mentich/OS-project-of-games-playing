#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  
sem_t mutex; 
  
void* thread(void* arg) 
{
	int count =1;
     printf("****SNOWFLAKEM ENTERTAINMENT*****");
    //wait 
    sem_wait(&mutex); 
    printf("\nPLAYER ARE WAITING FOR ONLINE\n");
	//printf("\nSECOND  PLAYER ONLINE\n"); 
	//printf("\nTHIRD  PLAYER ONLINE\n"); 
  
    //critical section 
    sleep(4); 
    printf("\nFIRST PLAYER ONLINE\n");
    sleep(4);
      
    //signal 
    printf("\nSECOND PLAYER ONLINE\n");
	sleep(4); 
	printf("\nTHIRD PLAYER ONLINE\n"); 
	printf("Server Busy\n Players are currently playing \n No new Game can be Created.......\n Please Wait Players for previous Match to end\n");
	sleep(5);
	printf("Previous Match ending \n Announcing Result\n");
	printf("\nNew match start\n");
	if(true)
	{
		printf("Player %d Won",count);
		count++;
		if(count>4)
			{
				count =1;
			}
	}
    sem_post(&mutex); 
} 
  
  
int main() 
{ 
    sem_init(&mutex, 0, 1); 
    pthread_t t1,t2,t3; 
   // pthread_create(&t1,NULL,thread,NULL); 
    //sleep(2);
	//pthread_create(&t2,NULL,thread,NULL);
	sleep(2);  
    pthread_create(&t3,NULL,thread,NULL); 
    pthread_join(t1,NULL); 
    //pthread_join(t2,NULL); 
    //pthread_join(t3,NULL); 
    sem_destroy(&mutex); 
    return 0; 
} 
