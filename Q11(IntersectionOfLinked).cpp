// Intersection of two sorted Linked lists

// Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with its own memory the original lists should not be changed.
// Note: The linked list elements are not necessarily distinct.

// Link : https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

Node* findIntersection(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* start = NULL;
    Node* end = NULL;
    
    while(temp1 !=NULL && temp2 !=NULL){
        if(temp1->data == temp2->data){
            Node* newNode = new Node(temp1->data);
            if(start == NULL){
                start = newNode;
                end = newNode;
            }else{
                end->next = newNode;
                end = newNode;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else if(temp1 ->data > temp2 ->data){
            temp2 = temp2->next;
        }else{
            temp1 = temp1->next;
        }
    }
    return start;
}
Time Complexity: O(N)
Auxiliary Space: O(1)
