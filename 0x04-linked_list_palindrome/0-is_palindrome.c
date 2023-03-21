#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list */
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode listint_t;

/* Function to create a new node with given data */
listint_t* new_node(int data)
{
    listint_t* node = (listint_t*) malloc(sizeof(listint_t));
    node->val = data;
    node->next = NULL;
    return node;
}

/* Function to reverse a linked list */
listint_t* reverse_list(listint_t* head)
{
    listint_t *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/* Function to check if a linked list is a palindrome */
int is_palindrome(listint_t** head)
{
    listint_t *slow = *head, *fast = *head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != NULL) {
        slow = slow->next;
    }

    slow = reverse_list(slow);
    fast = *head;

    while (slow != NULL) {
        if (fast->val != slow->val) {
            return 0;
        }
        fast = fast->next;
        slow = slow->next;
    }

    return 1;
}