// Segregate even and odd nodes in a Link List

// Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

// NOTE: Don't create a new linked list, instead rearrange the provided one.

// Link : https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

class Solution{
public:
    Node* divide(int N, Node *head){
        Node* evenHead = new Node(-1);
        Node* oddHead = new Node(-1);
        Node* evenTail = evenHead;
        Node* oddTail = oddHead;
        Node* temp =head;
        while(temp != NULL){
            if(temp->data %2 ==0){
                evenTail->next = temp;
                evenTail = evenTail->next;
            }else{
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
            temp = temp->next;
        }
        if(evenTail->data == -1 && oddTail->data == -1) return NULL;
        if(evenTail->data == -1) {oddTail->next = NULL ; return oddHead->next; }
        if(oddTail->data == -1) {evenTail->next = NULL ; return evenHead->next; }
        evenTail->next = oddHead->next;
        oddTail->next = NULL;
        return evenHead->next;
    }
};

// Time Complexity: O(N)
// Auxiliary Space: O(1)