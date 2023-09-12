// Reverse a Doubly Linked List

// Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

// Link : https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

Node* reverseDLL(Node * head)
{
    if(head == NULL) return head;
    if(head->next == NULL) {
        return head;
    }
    Node* fast = head;
    while(fast->next != NULL) fast = fast->next;
    head = fast;
    head->next = head->prev;
    head->prev = NULL;
    Node* slow = head->next->prev;
    head->next->prev = head;
    head = head->next;
    while(slow != NULL){
        head->next = slow;
        Node* save = slow->prev;
        slow->prev = head;
        head = head->next;
        slow = save;
    }
    head->next = NULL;
    return fast;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)