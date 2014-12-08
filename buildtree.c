#include"library.h"
void frontandbacksplit(struct node *h,struct node **front,struct node **back)
{
                int c=1;
                *front=h;
                while(c!=2){
                        h=h->next;
                        c++;
                }
                *back=h->next;
                h->next=NULL;
}
int len(struct node *p)
{
        int count=0;
	p=p->next;
        struct node *current;
        for (current = p; current != NULL; current = current->next) {
                count++;
        }
        return count;
}
void treebuild(struct node *root,struct node *f)
{
	while(root->next!=NULL)
		root=root->next;
	struct node *new=malloc(sizeof(struct node));
	root->next=new;
	new->left=f;
	new->right=f->next;
	f->next=f->next->next=NULL;
	new->next=NULL;
	new->name="*";
	new->count=new->left->count+new->right->count;
}
struct node *tree(struct node *root)
{
	struct node *front=NULL;
	struct node *back=NULL;
	while(len(root)>1){
	InsertSort(&root);
	frontandbacksplit(root,&front,&back);
	root=back;
	treebuild(root,front);
	}
	InsertSort(&root);
	struct node *new=malloc(sizeof(struct node));
        new->left=root;
	new->right=root->next;
	root->next->next=NULL;
	new->count=new->left->count+new->right->count;
	new->name="*";
	new->next=NULL;
	return new;
}
