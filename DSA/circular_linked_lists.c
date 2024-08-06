#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* insert_begin(struct node* last, int new_data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;

	if (last == NULL) {
		last = new_node;
		last->next = last;
	} else {
		new_node->next = last->next;
		last->next = new_node;
	}

	return (last);
}

struct node* delete_node(struct node* last, int key) {
	if (last == NULL)
		return (last);

	struct node *temp = last->next, *prev = last;

	while (temp->data != key && temp != last) {
		prev = temp;
		temp = temp->next;
	}

	if (temp->data != key)
		return (last);

	if (temp == last) {
		if (last->next == last)
			last = NULL;
		else {
			last = temp->next;
			prev->next = last;
		}
	} else
		prev->next = temp->next;

	free(temp);
	return (last);
}

void traverse(struct node* last) {
	struct node* p;

	if (last == NULL) {
		printf("list is empty.\n");
		return;
	}

	p = last->next;

	do {
		printf("%d -> ", p->data);
		p = p->next;
	} while (p != last->next);

	printf("...\n");
}

int main() {
	struct node* last = NULL;

	last = insert_begin(last, 10);
	last = insert_begin(last, 20);
	last = insert_begin(last, 30);
	last = insert_begin(last, 40);

	printf("circular linked list:\n");
	traverse(last);

	last = delete_node(last, 20);

	printf("after deletion of 20:\n");
	traverse(last);

	return (0);
}

