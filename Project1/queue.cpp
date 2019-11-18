#include <stdio.h>
#include <malloc.h>
#include <windows.h>

typedef struct Queue {
	int* pBase;
	int front;
	int rear;
}QUEUE;

void init(QUEUE* pQ);
bool full_queue(QUEUE* pQ);
bool en_queue(QUEUE* pQ, int val);
void traverse_queue(QUEUE* pQ);
bool empty_queue(QUEUE* pQ);
bool out_queue(QUEUE* pQ, int* val);

int main2(void)
{
	QUEUE Q;
	int val;

	init(&Q);

	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);

	traverse_queue(&Q);

	if (out_queue(&Q, &val)) {
		printf("出队成功，出队元素：%d\n", val);
	}
	else
		printf("出队失败\n");

	traverse_queue(&Q);

	system("pause");
	return 0;
}

void init(QUEUE* pQ)
{
	pQ->pBase = (int*)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;
}

bool full_queue(QUEUE* pQ)
{
	if (pQ->front == (pQ->rear + 1) % 6)
		return true;
	else
		return false;
}

bool en_queue(QUEUE* pQ, int val)
{
	if (full_queue(pQ)) 
		return false;
	
	else {
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;

		return true;
	}

}

void traverse_queue(QUEUE* pQ)
{
	int i = pQ->front;

	while (i != pQ->rear) {
		printf(" %d ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");
}

bool empty_queue(QUEUE* pQ)
{
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}

bool out_queue(QUEUE* pQ, int* val)
{
	if (empty_queue(pQ))
		return false;

	else {
		*val = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;
		
		return true;
	}
}