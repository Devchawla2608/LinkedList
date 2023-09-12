// Merge Sort for Linked List
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
// Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

// Link : https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node * merge(Node* head1 , Node* head2){
        Node* newNode = new Node(-1);
        Node* newNodeHead = newNode;
        Node* temp1 = head1;
        Node* temp2 = head2;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->data< temp2->data){
                Node* nNode =  new Node(temp1->data);
                newNode->next = nNode;
                newNode = newNode->next;
                temp1 = temp1->next;
            }else{
                Node* nNode =  new Node(temp2->data);
                newNode->next = nNode;
                newNode = newNode->next;    
                temp2 = temp2->next;
            }
        }
        while(temp1 != NULL){
            Node* nNode =  new Node(temp1->data);
            newNode->next = nNode;
            newNode = newNode->next;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            Node* nNode =  new Node(temp2->data);
            newNode->next = nNode;
            newNode = newNode->next;
            temp2 = temp2->next;
        }
        return newNodeHead->next;
    }
    Node* midFind(Node* head){
        Node* fast = head;
        Node* slow = head;
        while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node* mergeSort(Node* head) {
        if(head->next == NULL || head == NULL) return head;
        Node* mid = midFind(head);
        Node* temp1 = head;
        Node* temp2 = mid->next;
        mid->next = NULL;
        Node* sol1 = mergeSort(temp1);
        Node* sol2 = mergeSort(temp2);
        Node* sol = merge(sol1 , sol2);
        return sol;
        return head;
    }
};

Time Complexity: O(NlogN)
Auxiliary Space: O(N)