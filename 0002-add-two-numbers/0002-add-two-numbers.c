/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* a, struct ListNode* b) {
    struct ListNode* result = NULL;
    struct ListNode* prev = NULL;
    int carry = 0;
    while (a || b) {
        int sum = carry + (a ? a->val : 0) + (b ? b->val : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = sum;
        node->next = NULL;

        if (!result) result = node;
        else prev->next = node;
        prev = node;

        if (a) a = a->next;
        if (b) b = b->next;
    }
    if (carry > 0) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL;
        prev->next = node;
    }
    return result;
}