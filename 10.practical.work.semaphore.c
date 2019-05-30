
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

typedef struct
{
char type;
// 0=fried chicken, 1=French fries
int amount;
// pieces or weight
char unit;
// 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void initfried_chicken(item *smt) {
	smt->type = 0;
	smt->amount = 0;
	smt->unit = 0;
}

void initFries(item *smt) {
    smt->type = 1;
    smt->amount = 0;
    smt->unit = 1;
}

void produce(item *i)
{
	sem_wait(&empty);
    while ((first + 1) % BUFFER_SIZE == last)
	{
        // do nothing -- no free buffer item
		return;
	}
	memcpy(&buffer[first], i, sizeof(item));
	i->amount += 1;
	first = (first + 1) % BUFFER_SIZE;
    sem_post(&full);
}

item *consume()
{
	sem_wait(&f);
    item *i = malloc(sizeof(item));
	while (first == last)
	{
        // do nothing -- nothing to consume
		printf("Nothing to consume!\n");
	}
	memcpy(i, &buffer[last], sizeof(item));
	i->amount -= 1;
	last = (last + 1) % BUFFER_SIZE;
    sem_post(&empty);
	return i;
}

int main()
{
	pthread_t tid;
	printf("My main goal is to blow up and act like I don't know nobody h\n");
	pthread_create(&tid, NULL, producerThread, NULL);
	pthread_create(&tid, NULL, consumerThread, NULL);
	pthread_join(tid, NULL);
    pthread_join(tid, NULL);
    pthread_exit(NULL);

}

void *producerThread(void* parameter) {
	item *fried_chicken, wing;
	fried_chicken = &wing;
	printf("3\n");
	initfried_chicken(fried_chicken);
    for (int i=0; i = 3; i = i + 1) 
    {
	produce(fried_chicken);
    }
	pthread_exit(NULL);
}

void *consumerThread(void* parameter) {
	printf("2\n");
	for (int i = 0; i = 2; i = i +1 )
    {
     consume();
	}
	pthread_exit(NULL);
}

sem_t empty, full;
pthread_mutex_t mutex;


pthread_t tid[2]; 
pthread_attr_t attr; 
