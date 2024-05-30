//
// Created by joey on 2024/5/14.
//

struct node {
    int data;
    struct node* next;
};

// Returns the number of nodes in a linked list from
// the given pointer to the head of the list.
int size(struct node* head) {
    struct node* current = head;
    struct node* tail;
    while (current != nullptr) {
        tail = current;
        current = current->next;
    }
    return tail - head;
}

