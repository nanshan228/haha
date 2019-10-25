#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node {
	int data;
	struct Node* pNext;
}NODE, * PNODE;

typedef struct Stack {
	PNODE pTop;
	PNODE pButtom;
}STACK, * PSTACK;

void init(PSTACK);
void push(PSTACK pS, int val);
void traverse(PSTACK pS);
bool pop(PSTACK, int*);
void clear(PSTACK pS);

int main()
{
	STACK S;
	int val;

	init(&S);
	push(&S, 1);
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	traverse(&S);
	clear(&S);
	traverse(&S);

	if (pop(&S, &val)) {
		printf("��ջ��Ԫ���ǣ�%d\n", val);
	}
	else {
		printf("��ջʧ�ܣ�\n");
	}

	traverse(&S);

	return 0;
}

void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (pS->pTop == NULL) {
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	else {
		pS->pButtom = pS->pTop;
		pS->pButtom->pNext = NULL;
	}
}

void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL) {
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
	}
	else {
		pNew->data = val;
		pNew->pNext = pS->pTop;
		pS->pTop = pNew;
	}
}

void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;

	while (p->pNext != NULL) {
		printf("ջ��Ԫ���ǣ�%d", p->data);
		printf("\n");
		p = p->pNext;
	}
}

bool pop(PSTACK pS, int* pVal)
{
	if (pS->pTop == pS->pButtom) {
		return false;
	}
	else {
		PNODE p = (PNODE)malloc(sizeof(NODE));
		if (p == NULL) {
			printf("��̬�ڴ����ʧ�ܣ�\n");
			exit(-1);
		}
		else {
			p = pS->pTop;
			*pVal = p->data;
			pS->pTop = p->pNext;
			free(p);

			return true;
		}
	}
}

void clear(PSTACK pS)
{
	if (pS->pTop == pS->pButtom) {
		return;
	}
	else {
		PNODE p = pS->pTop;
		PNODE q = NULL;

		while (p != pS->pButtom) {
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pButtom;

	}
}

void test()
{
	printf("Hello world!");
	printf("Hello world!");
	printf("Hello world!");

	printf("Hello git!");
}




