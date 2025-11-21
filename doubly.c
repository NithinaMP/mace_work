#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL)
        head = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning.\n", value);
}

// Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL)
        head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at end.\n", value);
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL; // Only one node
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
}

// Display from beginning
void displayFromBeginning() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// Display from end
void displayFromEnd() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Count elements
void countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total nodes: %d\n", count);
}

// Main
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete from Beginning\n4. Delete from End\n");
        printf("5. Display from Beginning\n6. Display from End\n7. Count Nodes\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                displayFromBeginning();
                break;
            case 6:
                displayFromEnd();
                break;
            case 7:
                countNodes();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}



































// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node *prev;
//     struct Node *next;
// };

// struct Node *head = NULL;   

// struct Node* createNode(int value){
// 	struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
// 	if(!newNode){
// 	printf("Memory allocation failed");
// 	exit(0);
// 	}
// 	newNode->data=value;
// 	newNode->next=newNode->prev=NULL;
// 	return newNode;
// }



// void insertAtBeginning(int value){
// 	struct Node* newNode= createNode(value);
// 	if(head==NULL){
// 	 head=newNode;
// 	 }
// 	 else{
// 	 newNode->next=head;
// 	 head->prev=newNode;
// 	 head=newNode;
// 	 }
// 	 printf("%d inserted at beginning\n",value);
// }

	 
// void insertAtEnd(int value){
// 	struct Node* newNode=createNode(value);
// 	if(head==NULL){
// 	head=newNode;
// 	}
// 	else{
// 	struct Node *temp=head;
// 	while(temp->next != NULL){
// 	temp=temp->next;
// 	}
// 	temp->next=newNode;
// 	newNode->prev=temp;
// 	}
// 	printf("%d inserted to the end\n",value);
// }

// void deleteFromBeginning(){
// 	if(head==NULL){
// 	printf("List is empty\n");
// 	return;
// 	}else{
// 	struct Node *temp=head;
// 	head=head->next;
// 	if(head!=NULL){
// 	head->prev=NULL;
// 	}
// 	printf("%d deleted from the beginning\n",temp->data);
// 	free(temp);
// 	}
// }

// void deleteFromEnd(){
//  	if(head==NULL){
// 	printf("List is empty\n");
// 	return;
// 	}
// 	struct Node* temp=head;
// 	if(temp->next==NULL){
// 	head=NULL;
// 	printf("%d deleted from the end\n",temp->data);
// 	free(temp);
// 	return;
// 	}
// 	while(temp->next!=NULL){
// 	temp->prev->next=NULL;
// 	printf("%d deleted from the end\n",temp->data);
// 	free(temp);
// 	}
// }	

// // Delete from end
// /*void deleteFromEnd() {
//     if (head == NULL) {
//         printf("List is empty! Nothing to delete.\n");
//         return;
//     }
//     struct Node* temp = head;
//     if (temp->next == NULL) {  // only one node
//         head = NULL;
//         printf("%d deleted from end.\n", temp->data);
//         free(temp);
//         return;
//     }
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->prev->next = NULL;
//     printf("%d deleted from end.\n", temp->data);
//     free(temp);
// }

// */
// void traverseFromBeginning(){
// 	if(head==NULL){
// 	printf("List is empty\n");
// 	return;
// 	}
// 	struct Node *temp=head;
// 	printf("Traversel from the beginning\n");
// 	while(temp!=NULL){
// 	printf("%d\n",temp->data);
// 	temp=temp->next;
// }
// }

// void traversefromEnd(){
// 	if(head==NULL){
// 	printf("List is empty\n");
// 	return;
// 	}
// 	struct Node *temp=head;
// 	printf("Traverse from end\n");
// 	while(temp->next!=NULL){
// 	temp=temp->next;
// 	}
// 	while(temp!=NULL){
// 	printf("%d",temp->data);
// 	temp=temp->prev;
// }
// }
// void count(){
// 	int count=0;
// 	struct Node* temp = head;
// 	while(temp!=NULL){
// 	count++;
// 	temp=temp->next;

// 	}
// 		printf("Counted number is %d\n:",count);
// }



// int main(){
// int choice,value;
// printf("\n---doubly linked list---\n");
// printf("1.Insert At Beginning\n");
// printf("2.Insert At end\n");
// printf("3.Delete from Beginning\n");
// printf("4.Delete from end\n");
// printf("5.Traverse from Beginning\n");
// printf("6.Traverse from Beginning\n");
// printf("7.Count\n");
// while(1){
// printf("Enter a choice\n");
// scanf("%d",&choice);
// switch(choice){
// 	case 1:printf("Enter a value:\n");
// 		scanf("%d",&value);
// 		insertAtBeginning(value);break;
// 	case 2:printf("Enter a value:\n");
// 		scanf("%d",&value);
// 		insertAtEnd(value);break;
// 	case 3:deleteFromBeginning();break;
// 	case 4:deleteFromEnd();break;
// 	case 5:traverseFromBeginning();break;
// 	case 6:traversefromEnd();break;
// 	case 7:count();break;
// 	default:printf("Invalid choice\n");
// 	}
// 	}return 0;
	
// }





















/*
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at beginning.\n", value);
}

// Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at end.\n", value);
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("%d deleted from beginning.\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    if (temp->next == NULL) {  // only one node
        head = NULL;
        printf("%d deleted from end.\n", temp->data);
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    printf("%d deleted from end.\n", temp->data);
    free(temp);
}

// Traversal from beginning
void traverseFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Traversal from beginning: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Traversal from end
void traverseFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) { // reach last node
        temp = temp->next;
    }
    printf("Traversal from end: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Count elements
void countElements() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total elements in list = %d\n", count);
}

// Main function (menu-driven)
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Traverse from Beginning\n");
        printf("6. Traverse from End\n");
        printf("7. Count Elements\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                traverseFromBeginning();
                break;
            case 6:
                traverseFromEnd();
                break;
            case 7:
                countElements();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
*/
