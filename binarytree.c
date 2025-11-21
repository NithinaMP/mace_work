#include<stdio.h>
#include<stdlib.h>
 struct Node{
 int data;
 struct Node *left,*right;
 };
 struct Queue{
 	int front,rear,size;
 	struct Node** arr;
 	};
 struct Node* createNode(int value){
 	struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
 	newNode->data=value;
 	newNode->left=newNode->right=NULL;
 	return newNode;
 }
 struct Queue* createQueue(int size)
