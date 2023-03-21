#ifndef PALINDROME_H
#define PALINDROME_H

/* Definition for singly-linked list */
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode listint_t;

/* Function to check if a linked list is a palindrome */
int is_palindrome(listint_t** head);

#endif /* PALINDROME_H */