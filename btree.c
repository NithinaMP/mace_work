#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Queue {
    int front, rear, size;
    struct Node** arr;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = size;
    // Fix: Allocate memory for the full queue size
    q->arr = (struct Node**)malloc(q->size * sizeof(struct Node*));
    if (q->arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* node = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return node;
}

// Corrected insert function using level-order traversal
struct Node* insert(struct Node* root, int value) {
    struct Node* newNode = createNode(value);
    if (root == NULL) {
        return newNode;
    }

    struct Queue* q = createQueue(100);
    enqueue(q, root);

    while (!isEmpty(q)) {
        struct Node* temp = dequeue(q);
        
        if (temp->left == NULL) {
            temp->left = newNode;
            free(q); // Free the queue memory
            return root;
        } else {
            enqueue(q, temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            free(q); // Free the queue memory
            return root;
        } else {
            enqueue(q, temp->right);
        }
    }
    return root;
}

// Corrected delete function
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return NULL;

    struct Queue* q = createQueue(100);
    enqueue(q, root);

    struct Node *target = NULL, *temp = NULL, *last = NULL;
    
    // Find the node to delete and the last node in the tree
    while (!isEmpty(q)) {
        temp = dequeue(q);
        if (temp->data == value) {
            target = temp;
        }
        if (temp->left) enqueue(q, temp->left);
        if (temp->right) enqueue(q, temp->right);
        last = temp;
    }

    if (target != NULL) {
        target->data = last->data;
        
        // Find the parent of the last node to remove it
        struct Queue* q2 = createQueue(100);
        enqueue(q2, root);
        while (!isEmpty(q2)) {
            temp = dequeue(q2);
            if (temp->left == last) {
                free(temp->left);
                temp->left = NULL;
                break;
            }
            if (temp->right == last) {
                free(temp->right);
                temp->right = NULL;
                break;
            }
            if (temp->left) enqueue(q2, temp->left);
            if (temp->right) enqueue(q2, temp->right);
        }
        free(q2);
    }
    
    // Free the original queue
    free(q);
    
    return root;
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    while (1) {
        printf("\n---Binary tree operations---");
        printf("\n1. Insert\n2. Delete\n3. Inorder traversal\n4. Preorder traversal\n5. Postorder traversal\n6. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert:\n");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to delete:\n");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Inorder traversal:\n");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder traversal:\n");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal:\n");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting....\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}








// #include<stdio.h>
// #include<stdlib.h>
// struct Node{
//  int data;
//  struct Node *left,*right;
//  };
// struct Queue{
// int front,rear,size;
// struct Node** arr;
// };
// struct Node* createNode(int value){
// 	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
// 	newNode->data=value;
// 	newNode->left=newNode->right=NULL;
// 	return newNode;
// }

// struct Queue* createQueue(int size){
// 	struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
// 	q->front= q->rear=-1;
// 	q->size=size;
// 	q->arr=(struct Node**)malloc(sizeof(struct Node*));
// 	return q;
// }
// int isEmpty(struct Queue* q){
// return q->front==-1;
// }
// void enqueue(struct Queue* q, struct Node* node){
// 	if ((q->rear+1)%q->size==q->front) return;
// 	if(isEmpty(q)) q->front=0;
// 	q->rear=(q->rear+1)%q->size;
// 	q->arr[q->rear] = node;
// }
// struct Node* dequeue(struct Queue* q){
// 	if(isEmpty(q)) return NULL;
// 	struct Node* node = q->arr[q->front];
// 	if(q->front == q->rear) q->front=q->rear=-1;
// 	else q->front = (q->front+1)%q->size;
// 	return node;
// }

// struct Node* insert(struct Node* root,int value){
// 	struct Node* newNode = createNode(value);
// 	if(root==NULL) return newNode;
// 	struct Queue* q= createQueue(100);
// 	enqueue(q,root);
	
// 	while(!isEmpty(q)){
// 	struct Node* temp=dequeue(q);
// 	if(temp->left ==NULL){
// 	temp->left=newNode;
// 	break;
// 	}else{
// 	enqueue(q,temp->left);
// 	}
// 	if(temp->right==NULL){
// 	temp->right=newNode;
// 	break;
// 	}else{
// 	enqueue(q,temp->right);
// 	}
// 	}return root;
// }

// struct Node* deleteNode(struct Node* root,int value){
// 	if(root==NULL) return NULL;
	
// 	struct Queue* q =createQueue(100);
// 	enqueue(q,root);
// 	struct Node *target =NULL,*temp,*last;
// 	while(!isEmpty(q)){
// 		temp=dequeue(q);
// 		if(temp->data == value) target=temp;
// 		if(temp->left) enqueue(q,temp->left);
// 		if(temp->right) enqueue(q, temp->right);
// 		last=temp;
// 	}
// 	if(target!= NULL){
// 	target->data= last->data;
// 	enqueue(q,root);
// 	while(!isEmpty(q)){
// 	temp=dequeue(q);
// 	if(temp->left){
// 	if(temp->left == last){
// 		free(temp->left);
// 		temp->left=NULL;
// 		break;
// }else enqueue(q,temp->left);
// }
// if(temp->right){
// 	if(temp->right == last){
// 	free(temp->right);
// 	temp->right=NULL;
// 	break;
// 	}else enqueue(q,temp->right);
// 	}
//     }
// }
// return root;
// }

// void inorder(struct Node* root){
// if(root !=NULL){
// inorder(root->left);
// printf("%d",root->data);
// inorder(root->right);
// }
// }

// void preorder(struct Node* root){
// if(root != NULL){
// printf("%d",root->data);
// preorder(root->left);
// preorder(root->right);
// }
// }

// void postorder(struct Node* root){
// if(root!=NULL){
// postorder(root->left);
// postorder(root->right);
// printf("%d",root->data);
// }
// }

// int main(){
// struct Node* root=NULL;
// int choice,value;
// while(1){
// printf("\n---Binary tree operations---");
// printf("\n1.Insert\n2.Delete\n3.Inorder traversal\n4.Preorder traversal\n5.Postorder traversal\n6.Exit");
// printf("\nEnter your choice:");
// scanf("%d",&choice);
// switch(choice){
// case 1: printf("Enter value to insert:\n");
// 	scanf("%d",&value);
// 	root=insert(root,value);
// 	break;
// case 2: printf("Enter value to delete:\n");
// 	scanf("%d",&value);
// 	root=deleteNode(root,value);
// 	break;
// case 3: printf("Inorder traversal:\n");
// 	inorder(root);
// 	break;
// case 4: printf("Preorder traversal:\n");
// 	preorder(root);
// 	break;
// case 5: printf("Postorder traversal:\n");
// 	postorder(root);
// 	break;
// case 6: printf("Exiting....\n");
// 	exit(0);
// default:printf("Invalid choice\n");
// }
// }return 0;
// }

