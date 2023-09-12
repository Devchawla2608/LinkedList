// Nth node from end of linked list

// Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

// Link : https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

class Solution{
public:

    int noOfNodes(Node* head){
        int cnt = 0;
        while(head != NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }


    int getNthFromLast(Node *head, int n)
    {
        int no = noOfNodes(head);
        n = no-n+1;
        while(head != NULL && n!= 1){
            head = head->next;
            n--;
        }
        if(head == NULL) return -1;
        return head->data;
    }
};


// Time Complexity: O(N)
// Auxiliary Space: O(1)