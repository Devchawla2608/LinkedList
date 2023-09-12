//  Remove duplicates from an unsorted linked list

// Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.
  
//   Link : https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

    Node * removeDuplicates( Node *head) 
    {   
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        unordered_map<int , int> ourmap;
        Node* pre = NULL;
        Node* temp = head;
        while(temp != NULL){
            if(ourmap[temp->data] == 0){
                ourmap[temp->data]++;
                pre = temp;
                temp = temp->next;
            }else{
                Node* save = temp->next;
                pre->next = temp->next;
                temp = save;
            }
        }
        return head;
    }

    Time Complexity: O(N)
    Auxiliary Space: O(N)
