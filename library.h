#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
struct node{
        char *name;
        int count;
	char *patt;
        struct node *next;
	struct node *left;
	struct node *right;
        };
void frontandbacksplit(struct node *h,struct node **front,struct node **back);
void treebuild(struct node *root,struct node *f);
int len(struct node *p);
struct node *tree(struct node *root);
void SortedInsert(struct node** headRef, struct node* newNode);
void InsertSort(struct node** headRef);
