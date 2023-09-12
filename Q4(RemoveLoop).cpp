// Remove loop in Linked List

// Given a linked list of N nodes such that it may contain a loop.

// A loop here means that the last node of the link list is connected to the node at position X(1-based index). If the link list does not have any loop, X=0.

// Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

// Link : https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node* fast = head;
        Node* slow = head;
        while(slow != NULL && fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) break;
        }
        if(slow != fast) return ;
        slow = head;
        while(slow->next != fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == head){
            while(fast->next != slow){ fast = fast->next;}
            fast->next = NULL;
        }else{
            fast->next = NULL;
        }
        
    }
};

// Time Complexity: O(N)
// Auxiliary Space: O(1)