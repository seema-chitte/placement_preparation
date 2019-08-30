#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

// Data Structure to store a linked list node
struct Node
{
	int data;
	struct Node* next;
};

// Helper function to push a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;

	*head = newNode;
}

// Helper function to print given linked list
void printList(char *msg, struct Node* head)
{
	printf("%s", msg);
	while (head)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}

	printf("NULL\n");
}

// Recursive function to add a given digit to the linked list representing
// a number.
int add(struct Node *head, int digit)
{
	// base case: end of the linked list is reached
	if (head == NULL)
		return digit;

	// store carry returned by the recursive call of the next node
	int carry = add(head->next, digit);

	// optimization: terminate the recursion if carry is 0 at any point
	if (carry == 0)
		return;

	// get sum of the current node and the carry
	int sum = head->data + carry;

	head->data = sum % 10;	// update value of the current node
	return sum/10;			// return carry
}

// Function to add a single-digit number to a singly linked list 
// whose nodes represents digits of a number
void addDigit(struct Node** head, int digit)
{
	// Add given digit to the linked list using recursion
	int carry = add(*head, digit);

	// if there is any carry left, add a new node at the beginning of the list
	if (carry) {
		push(head, carry);
	}
}

// main function
int main(void)
{

	int arr[MAX_SIZE]; // Declare an array of MAX_SIZE
	    int i;

	   int n = sizeof(arr)/ sizeof(int);

	   
	   
	    /* Input array size */
	        printf("Enter size of array: ");
		    scanf("%d", &n);

		        /* Input elements in array */
		        printf("Enter %d elements in the array : ", n);
			    for(i=0; i<n; i++)
				        {
					scanf("%d", &arr[i]);
				 	}
	
	struct Node *head = NULL;
	for (int i = n - 1; i >= 0; i--)
		push(&head, arr[i]);

	int digit = 7;

	printList(" Original Linked List: ", head);
	addDigit(&head, digit);
	printList("Resultant Linked List: ", head);

	return 0;
}
