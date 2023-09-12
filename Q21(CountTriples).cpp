// Count Triplets

// Given a sorted linked list of distinct nodes (no two nodes have the same data) and an integer X. Count distinct triplets in the list that sum up to given integer X.
// Note: The Linked List is sorted in decending order.

// Link : https://practice.geeksforgeeks.org/problems/count-triplets-in-a-sorted-doubly-linked-list/1

int countTriplets(struct Node* head, int x) 
{ 
    Node* temp1 = head;
    unordered_map<int , int> ourmap;
    while(temp1 !=NULL){
        ourmap[temp1->data]++;
        temp1 = temp1->next;
    }
    temp1 = head;
    int count = 0;
    Node* temp2 = NULL;
    while(temp1 !=NULL){
        temp2 = temp1->next;
        while(temp2 !=NULL){
            int sum = temp1->data + temp2->data;
            if(ourmap.count(x - sum)>0 && (x-sum != temp1->data) && (x- sum != temp2->data)){
                // cout<<"This "<<temp1->data<<" "<<temp2->data<<" "<<x-sum<<endl;
                count++;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return count/3;
} 

Time Complexity: O(N^2)
Auxiliary Space: O(N)