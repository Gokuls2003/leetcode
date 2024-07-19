/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int length(struct ListNode* head){
    int l = 0;
    struct ListNode* temp = head;

    while(temp != NULL){
        l++;
        temp = temp->next;
    }

    return l;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len = length(head);
    int del = len - n;

    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* temp = dummy;

    while (del > 0 && temp->next != NULL) {
        temp = temp->next;
        --del;
    }

    if (temp->next != NULL) {
        struct ListNode* toRemove = temp->next;
        temp->next = temp->next->next;
        free(toRemove);
    }

    return dummy->next;
}