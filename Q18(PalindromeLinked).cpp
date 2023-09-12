// Check if Linked List is Palindrome

// Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

// Link : https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    Node* reverseList(Node* head) {
       if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        Node* temp = head;
        Node* ans = reverseList(temp->next);
        Node* save = head->next;
        save->next = head;
        head->next = NULL;
        return ans;
    }
    
    bool isPalindrome(Node *head)
    {
       int num1 = 0;
       Node* temp = head;
        while(temp != NULL){
           num1 = num1*10 + temp->data;
           temp = temp->next;
        }
        Node* head2 = reverseList(head);
        int num2 = 0;
        temp = head2;
        while(temp != NULL){
           num2 = num2*10 + temp->data;
           temp = temp->next;
        }
        return num1 == num2;
    }
};

// Time Complexity: O(N)
// Auxiliary Space: O(1)