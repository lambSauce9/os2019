#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define BufferSize 10 


int main()
{
	int option = 0;
	item *Turkey, t, *notTurkey, nt;
	Turkey = &t;
	notTurkey = &nt;
	printf("Turkey 1 or notTurkey 2 \n");
	while (true)
	{
		scanf("%d", &option);
		if (option == 1)
		{
			printf("Ottoman\n");
			initTurkey(Turkey);
			produce(Turkey);
			produce(Turkey);
			printf("Consuming...\n");
			Turkey = consume();
			break;
		}
		else if (option == 2)
		{
			printf("Remove kebab\n");
			initNotTurkey(notTurkey);
			produce(notTurkey);
			produce(notTurkey);
			printf("Consuming...\n");
			notTurkey = consume();
			break;
		}
		else
		{
			printf("1 or 2 no more Kebab\n");
		}
	}
	return 0;
}
typedef struct item{
   char type;
   int amount;
   char unit;
}item;

 item buffer[BufferSize] ;
 int first  = 0;
 int last = 0;

void initTurkey(item *Turkey){
   Turkey->type = 0;
   Turkey->amount = 0;
   Turkey->unit = 0;
}

void initNotTurkey(item *notTurkey){
   notTurkey->type = 1;
   notTurkey->amount = 0;
   notTurkey->unit = 1;
}
void produce(item *i)
{
	while ((first + 1) % BufferSize == last)
	{
		printf("There is no more space\n");
		return;
	}
	memcpy(&buffer[first], i, sizeof(item));
	i->amount += 1;
	first = (first + 1) % BufferSize;
	printf("First = %d\n", first);
    printf("Push one more to the buffer");

} 

item *consume()
{
	item *i = malloc(sizeof(item));
	while (first == last)
	{
		printf("Nothing to consume!\n");
	}
	memcpy(i, &buffer[last], sizeof(item));
	i->amount -= 1;
	last = (last + 1) % BufferSize;
	printf("Last = %d\n", last);
	printf("The consumer consumes the item");
    return i;

}
