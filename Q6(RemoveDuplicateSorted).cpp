// Remove duplicate element from sorted Linked List

// Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
// Note: Try not to use extra space. The nodes are arranged in a sorted way.

// Gfg Link: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

Node *removeDuplicates(Node *head)
{
    if(head == NULL) return head;
    if(head ->next == NULL) return head;
    Node* pre = head;
    Node* fast = head->next;
    while(fast != NULL){
        if(fast->data == pre->data){
            Node* save = fast->next;
            pre->next = save;
            fast = save;
        }else{
            fast = fast->next;
            pre = pre->next;
        }
    }
    return head;
}

TIme Complexity: O(N)
Auxiliary Space: O(1)