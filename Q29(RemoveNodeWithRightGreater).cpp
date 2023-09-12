// Delete nodes having greater value on right

// Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater. (Not just immediate Right , but entire List on the Right)

// Link : https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

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
    
    
    Node *compute(Node *head)
    {
        Node* temp = reverseList(head);
        Node* head1 = temp;
        Node* pre = head1;
        temp = temp->next;
        int mx = head1->data;
        while(temp != NULL){
            if(temp -> data < mx){
                pre->next = temp->next;
                temp = pre->next;
            }else {
                mx = temp->data;
                pre = temp;
                temp = temp->next;
            }
        }
        return reverseList(head1);
    }
    
};

// Time Complexity: O(N)
// Auxiliary Space: O(1)