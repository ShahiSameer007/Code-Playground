#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int root;
	struct node *left;
	struct node *right;
}node;
node *newnode(int root){
	node *temp=(node*)malloc(sizeof(node));
	temp->root=root;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node *insert(node *p,node *nwnode){
	if(!p){
		printf("root %d\t inserted\n",nwnode->root);
		return nwnode;
	}
	if(nwnode->root>p->root){
		insert(p->right,nwnode);
		if(!(p->right))
		 p->right=nwnode;
	}
	else{
		insert(p->left,nwnode);
		if(!(p->left))
		 p->left=nwnode;
	}
	return p;
}
void search(node *p,int searchroot){
	if(!p){
		printf("No root found for value-%d\n",searchroot);
		return;
	}
	if(p->root==searchroot){
		printf("root %d\t found\n",searchroot);
	}
	else if(p->root<searchroot)
	 search(p->right,searchroot);
	else
	 search(p->left,searchroot); 
}
node *getinsuccessor(node *p){
	while(p->left!=NULL)
	 p=p->left;
	return p; 
}
node *deletion(node *p,int delroot){
	struct node *temp;
	if(!p){
		printf("Unable to delete no. such root exist\n");
		return p;
	}
	else if(delroot>p->root)
	  p->right=deletion(p->right,delroot);
	else if(delroot<p->root)
	  p->left=deletion(p->left,delroot);
	  else{
	  	if(p->left==NULL){
	  		temp=p->right;
	  		free(p);
	  		return temp;
		  }
	temp=getinsuccessor(p->right);
	p->root=temp->root;
	p->right=deletion(p->right,temp->root);
	}  
return p;
}
main(){
	node *root=NULL;
	root=insert(root,newnode(50));
	insert(root,newnode(80));
	insert(root,newnode(30));
	insert(root,newnode(40));
	insert(root,newnode(20));
	insert(root,newnode(100));
	search(root,50);
	search(root,10);
	node *newroot=deletion(root,50);
	if(newroot){
		printf("Succesfully deleted node. Now tree root node is- %d\t",newroot);
		}
		search(root,50);
	}
		
	
