#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list */
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode listint_t;

/* Function to check if a linked list is a palindrome */
int is_palindrome(listint_t** head)
{
    if (*head == NULL) {
        /* An empty list is considered a palindrome */
        return 1;
    }

    /* Find the middle node of the linked list */
    listint_t* slow = *head;
    listint_t* fast = *head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse the second half of the linked list */
    listint_t* prev = NULL;
    listint_t* curr = slow;
    while (curr != NULL) {
        listint_t* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    /* Compare the first half of the linked list with the reversed second half */
    listint_t* p1 = *head;
    listint_t* p2 = prev;
    while (p2 != NULL) {
        if (p1->val != p2->val) {
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    /* If we reach this point, the linked list is a palindrome */
    return 1;
}
