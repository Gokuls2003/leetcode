class Solution {
public:
    Node* dfs(Node* node){
        if(node == NULL) return NULL;
        // WE try to go to last node
        Node* Child = dfs(node->child);
        Node* Next = dfs(node->next);
        // Case when we are at last node we return node
        if(Child == NULL && Next == NULL) return node;
        // If we are at somwhere middle return last node
        if(Child == NULL) return Next;
        // Concatnate child to next
            Node* temp = node->next;
            node->next = node->child;
            node->child = NULL;
            node->next->prev = node;
        // If there is no next return child
        if(Next == NULL) return Child;
        // Concate child before node->next
            Child->next = temp;
            temp->prev  = Child;
        // Return the last node
        return Next;
    }
    Node* flatten(Node* head) {
        Node* node = head;
        dfs(node);
        return head;
    }
};