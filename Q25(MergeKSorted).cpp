// Merge K sorted linked lists
// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

// Link -> https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* solve(Node* temp1 , Node* temp2){
        Node* root = new Node(-1);
        Node* temp = root;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->data<temp2->data){
                root->next = temp1;
                root = root->next;
                temp1 = temp1->next;
            }else{
                root->next = temp2;
                root = root->next;
                temp2 = temp2->next;
            }
        }
        while(temp1!= NULL){ root->next = temp1; temp1 = temp1->next; root = root->next;}
        while(temp2!= NULL){ root->next = temp2; temp2 = temp2->next;root = root->next;}
        return temp->next;
    }
    
    Node * mergeKLists(Node *arr[], int k)
    {
        Node* temp1 = arr[0];
        for(int i = 1;i<k ; i++){
            Node* temp2 = arr[i];
            Node* store = solve(temp1 , temp2);
            temp1 = store;
        }
        return temp1;
    }
};

// Time Complexity: O(N*K)
// Auxiliary Space: O(1)