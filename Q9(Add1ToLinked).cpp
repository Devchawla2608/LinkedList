// Add 1 to a number represented as linked list

// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

// Link : https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

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

    
    
    Node* addOne(Node *head) 
    {
        head = reverseList(head);
        Node* temp = head;
        Node* pre;
        int carry = 1;
        while(head != NULL){
            int s = head->data + carry;
            carry = s/10;
            head->data = s%10;
            pre = head;
            head = head->next;
        }
        if(carry >0 && head == NULL){
            Node* newNode = new Node(carry);
            pre->next = newNode;
        }
        head = reverseList(temp);
        return head;
    }
};
Time Complexity: O(N)
Auxiliary Space: O(1)