#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

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
	while ((first + 1) % BUFFER_SIZE == last)
	{
        // do nothing -- no free buffer item
		return;
	}
	memcpy(&buffer[first], i, sizeof(item));
	i->amount += 1;
	first = (first + 1) % BUFFER_SIZE;
}

item *consume()
{
	item *i = malloc(sizeof(item));
	while (first == last)
	{
        // do nothing -- nothing to consume
		printf("Nothing to consume!\n");
	}
	memcpy(i, &buffer[last], sizeof(item));
	i->amount -= 1;
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

int main()
{
	int option = 0;
	item *fried_chicken, wing, *french, fries;
	fried_chicken = &wing;
	french = &fries;
	printf("fried_chicken: 1 or French fries: 2 \n");
	while (true)
	{
		/* code */
		scanf("%d", &option);
		if (option == 1)
		{
			printf("2 fried_chicken coming right up!\n");
			initfried_chicken(fried_chicken);
			produce(fried_chicken);
			produce(fried_chicken);
			fried_chicken = consume();
			break;
		}
		else 
		{
			printf("2 French Fries coming right up!\n");
			initFries(french);
			produce(french);
			produce(french);
			french = consume();
			break;
		}

	}
	return 0;
}


