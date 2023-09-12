// Check If Circular Linked List

// Given head, the head of a singly linked list, find if the linked list is circular or not. A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle. An empty linked list is considered as circular.

// Note: The linked list does not contains any inner loop

// Link https://practice.geeksforgeeks.org/problems/circular-linked-list/1

bool isCircular(Node *head)
{
    if(head == NULL) return true;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
             break;
       }
    }
    if(fast == NULL || fast->next == NULL){
        return false;
    }
    slow = head;
    while(slow ->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    if(slow == head) return true;
    return false;
}

Time Complexity : O(N)
Auxiliary Space: O(1)