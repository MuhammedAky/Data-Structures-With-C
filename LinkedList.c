#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to display the linked list
void display(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

// Function to find the middle element of the linked list and print it
void findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    if (head != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        printf("Middle Element Data: %d\n", slow->data);
    }
}

// Function to append a new node to the end of the linked list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Function to remove a node with a specific value from the linked list
void removeNode(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                // If the element to remove is the head, update the head to the next node.
                *head_ref = current->next;
            } else {
                // If not the head, update the previous node's next pointer to skip the current node.
                previous->next = current->next;
            }
            free(current); // Free the memory of the removed node.
            return; // Exit the loop after removal.
        }

        previous = current;
        current = current->next;
    }
}

// Function to calculate the length of the linked list
int getLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// Function to reverse the linked list in-place
void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int main() {
    struct Node* head = NULL;

    // Appending elements to the linked list
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    // Display the linked list
    printf("Linked List: ");
    display(head);

    printf("-------------------------\n");

    removeNode(&head, 10);

    append(&head, 35);
    append(&head, 40);
    append(&head, 50);

    // Display the linked list
    printf("Linked List: ");
    display(head);

    // Find and display the middle element
    findMiddle(head);

    // Calculate and display the length of the linked list
    int length = getLength(head);
    printf("Length of the linked list: %d\n", length);

    // Reverse the linked list in-place
    reverseList(&head);
    printf("Reversed Linked List: ");
    display(head);

    return 0;
}