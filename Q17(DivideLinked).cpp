// Split a Circular Linked List into two halves


// Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

// Link : https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* slow = head;
    Node* fast = head->next;
    while(fast->next != slow){
        fast = fast->next;
    }
    Node* superFast = head;
    while( superFast != fast && superFast->next != fast){
        superFast = superFast->next->next;
        slow = slow->next;
    }
    if(superFast->next = fast) superFast = superFast->next;
    Node* mid1 = slow;
    Node* mid2 = slow->next;
    mid1->next = head;
    fast->next = mid2;
    *head1_ref = head;
    *head2_ref = mid2;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)
