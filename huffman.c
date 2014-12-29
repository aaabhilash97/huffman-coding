#include"library.h"
struct node *addtree(struct node *root,char str)
{
	char *n=&str;
	n++;
	*n='\0';
	if (root==NULL){
		root=malloc(sizeof(struct node));
		root->name=malloc(2);
		strcpy(root->name,&str);
		root->count=1;
		root->next=NULL;
		root->left=NULL;
		root->right=NULL;
	}
	else if(strcmp(root->name,&str)==0)
		root->count+=1;
	else
		root->next=addtree(root->next,str);
	return root;
}
struct node *frequency(char *str)
{	struct node *root;
	root=NULL;
	while(*str!='\0'){
		root=addtree(root,*str);
		str+=1;
	}
	return root;

}
void *assigncodes(struct node *r,char *a,char *b)
{
	if(r!=NULL){
		r->patt=malloc(sizeof(char));
		strcpy(r->patt,b);
		strcat(r->patt,a);
		assigncodes(r->left,"0",r->patt);
		assigncodes(r->right,"1",r->patt);
	}
}			
char *find(struct node *r,char *s)
{
	char *f="";
	if(r!=NULL){
		if(strncmp(r->name,s,1)==0)
			return r->patt;
		f=find(r->left,s);
		if(strncmp(f,"",1)!=0)
			return f;
		f=find(r->right,s);
        	if(strncmp(f,"",1)!=0)
                	return f;
	}
	return f;
}
char *encode(char *s,struct node *root)
{
	char *output=malloc(sizeof(char));
	for(;*s!='\0';s++)
		strcat(output,find(root,s));
	return output;
}
char *decode(struct node *root,char *s)
{
	char o[strlen(s)];
	int i=0;
	struct node *c=root;
	for(;*s!='\0';s++){
		printf("%s\n",s);
		if(strncmp("0",s,1)==0){
			root=root->left;
			if(strcmp("*",root->name)!=0){
				o[i]=*(root->name);i++;
				root=c;}
		}
		else if(strncmp("1",s,1)==0){
			root=root->right;
                        if(strcmp("*",root->name)!=0){
					o[i]=*(root->name);i++;
                                root=c;}
		}
	}
	o[i]='\0';
	char *ret=malloc(sizeof(char));
	strcpy(ret,o);
	return ret;
}
main(int argc,char *argv[])
{
	char a[]="abbcccddddeeeeeffffffggggggghijklmnopqrstuvwxyfz";
	struct node *root=frequency(a);
	root=tree(root);
	assigncodes(root,"","");
	char b[11111];
	if(argc>1)
		strcpy(b,argv[1]);
	else{
		printf("give an input");
		scanf("%s",b);}
	char *e=encode(b,root);
	printf("encode data=  %s\n",e);
	char *d=decode(root,e);
	printf("decoded=  %s\n",d);	
	
}
