// Add two numbers represented by linked lists
// Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

// For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Link : https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

class Solution
{
    public:
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
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseList(first);
        second = reverseList(second);
        int s = 0;
        int c = 0;
        Node* newHead =  new Node(-1);
        Node* newTail = newHead;
            Node* newNode;
        while(first != NULL || second != NULL){
            s = c + (first!=NULL?first->data:0) + (second != NULL? second->data:0);
            s>=10? c = 1 : c = 0;
            newNode = new Node(s%10);
            newTail->next = newNode;
            newTail = newTail->next;
            if(first != NULL) first = first->next;
            if(second != NULL) second = second->next;
        }
        if(c!=0){
            newNode = new Node(c);
            newTail->next = newNode;
            newTail = newTail->next;
        }
        return reverseList(newHead->next);
    }
};

Time Complexity: O(N)
Auxiliary Space: O(1)