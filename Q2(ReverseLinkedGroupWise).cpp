// Reverse a Linked List in groups of given size

// Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

// Link : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        node* nex;
        node* prev = NULL;
        int c = 0;
        node* cur = head;
        while(cur != NULL and c<k){
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
            c++;
        }
        if(nex != NULL){
            head->next = reverse(nex , k);
        }
        return prev;
    }
};

// Time Complexity: O(N)
// Auxiliary Space: O(1)