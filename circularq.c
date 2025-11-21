#include <stdio.h>
#include <stdlib.h>
int *queue;
int SIZE;
int front=-1,rear=-1;
int isFull(){
return (front==(rear+1)%SIZE);
}
int isEmpty(){
return(front==-1);
}
void enqueue(int value){
if (isFull()){
printf("Queue is full\n");
return;
}
if (isEmpty()){
front=rear=0;
}else{
rear=(rear+1)%SIZE;
}
queue[rear]=value;
printf("%d inserted into queue\n",value);
}

void dequeue(){
if(isEmpty()){
printf("Queue is empty\n");
return;
}
int deletedValue=queue[front];
if(front==rear){
front=rear=-1;
}else{
front=(front+1)%SIZE;
}
printf("%d deleted into queue\n",deletedValue);
}

void display(){
if(isEmpty()){
printf("Queue is empty\n");
return;
}
printf("Queue elements:\n");
int i=front;
while(1){
printf("%d",queue[i]);
if(i==rear)break;
i=(i+1)%SIZE;
}
}
int count(){
if(isEmpty()) return 0;
if(rear>=front)
	return rear-front+1;
	else
	return SIZE-front+rear+1;
	}
	
int main() {
    int choice, value;
            printf("Enter size of Q:\n");
                    scanf("%d", &SIZE);
        queue=(int*)malloc(SIZE* sizeof(int));
        if(!queue){
        printf("memory allocation failed\n");
        return 1;
        }
        printf("\n--- circular Q Menu ---\n");
        printf("1. enqueue\n2. dequeue\n3. display\n4. Count\n5. Exit\n");
    while (1) {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value : ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Total elements: %d\n", count());
                break;

            case 5:
                free(queue);
                break;

       
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
