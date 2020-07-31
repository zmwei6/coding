/*
 ============================================================================
 Name        : ctest38.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Binary Node
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y)	 (x) > (y) ? (y) : (x)

typedef struct node {
	int val;
	struct node *lp;
	struct node *rp;
} NODE_T;

void addNode(NODE_T *p, int lval, int rval)
{
	NODE_T *rnode, *lnode;

	/* create two nodes */
	rnode = (NODE_T *)malloc(sizeof(NODE_T));
	lnode = (NODE_T *)malloc(sizeof(NODE_T));
	rnode->val = rval;
	rnode->lp = NULL;
	rnode->rp = NULL;
	lnode->val = lval;
	lnode->lp = NULL;
	lnode->rp = NULL;

	p->val = MIN(lval, rval);
	p->lp = lnode;
	p->rp = rnode;
}

void deleteLastNode(NODE_T *p)
{
	NODE_T *lnode;
	lnode = p->lp;
	while(lnode)
	{
		if(lnode->lp == NULL && lnode->rp == NULL)
		{
		  free(lnode);
		  lnode = NULL;
		}
		else if(lnode->lp == NULL && lnode->rp != NULL)
		  lnode = lnode->rp;
		else if(lnode->lp != NULL && lnode->rp == NULL)
		  lnode = lnode->lp;
		else
		  lnode = lnode->lp;
	}
	lnode = p->rp;
	while(lnode)
	{
		if(lnode->lp == NULL && lnode->rp == NULL)
		{
		  free(lnode);
		  lnode = NULL;
		}
		else if(lnode->lp == NULL && lnode->rp != NULL)
		  lnode = lnode->rp;
		else if(lnode->lp != NULL && lnode->rp == NULL)
		  lnode = lnode->lp;
		else
		  lnode = lnode->rp;
	}
}

int main(void) {
	NODE_T *head, *cur;
	head = (NODE_T *)malloc(sizeof(NODE_T));
	head->val = 2;
	head->lp = NULL;
	head->rp = NULL;
	addNode(head, 2, 5);
	cur = head->rp;
	addNode(cur, 5, 7);
	cur = cur->rp;
	addNode(cur, 7, 8);
	while(head)
		deleteLastNode(head);

	return EXIT_SUCCESS;
}
