// Reverse a linked list

// Given a linked list of N nodes. The task is to reverse this list.

// Link : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
      Node* first =NULL;
      Node* second = head;
      while(second != NULL){
         Node* temp = second ->next;
         if(temp == NULL) break;
         second->next = first;
         first = second;
         second = temp;
      }
      second ->next = first;
      return second;
    }
    
};

// Time Complexity: O(N)
// Auxiliary Space: O(1)