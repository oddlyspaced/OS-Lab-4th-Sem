#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node* next;
} *head = NULL;

void insert_node(int v) {
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->value = v;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
}

void create_queue(int size) {
	int i;
	for (i = 0;i < size; i++) {
		insert_node(-1);
	}
}

void print_queue(int size) {
	struct node* temp = head;
	int i;
	for (i = 0; i < size; i++) {
		if (temp->value == -1) {
			printf("X\t");
		}
		else {
			printf("%d\t", temp->value);
		}
		temp = temp->next;
	}
}

// 1 -> page fault
// 0 -> exists
int check_page_fault(int v, int size) {
	struct node* temp = head;
	int i;
	for (int i = 0; i < size; i++) {
		if (temp->value == v) {
			return 0;
		}
		temp = temp->next;
	}
	return 1;
}

int main() {
	int tot;
	printf("\nEnter total reference string size: ");
	scanf("%d", &tot);

	int pages[tot];
	printf("\nEnter pages: \n");
	int i;
	for (i = 0; i < tot; i++) {
		scanf("%d", &pages[i]);
	}

	int cap;
	printf("\nEnter capacity: ");
	scanf("%d", &cap);

	create_queue(cap);
	
	int faults = 0;

	for (i = 0; i < tot; i++) {
		print_queue(cap);
		if (check_page_fault(pages[i], cap) == 1) {
			faults += 1;
			insert_node(pages[i]);
			printf("\tFault Occured!");
		}
		printf("\n");
	}
	printf("\nTotal page faults: %d", faults);
	return 0;
}
