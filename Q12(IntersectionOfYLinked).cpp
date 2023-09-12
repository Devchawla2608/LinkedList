// Intersection Point in Y Shaped Linked Lists

// Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

// Link  -  https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

int findLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;   
    }
    return count;
}

int intersectPoint(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    int l1 = findLength(head1);
    int l2 = findLength(head2);
    if(l1 > l2){
        int diff = l1-l2;
        while(diff != 0){
            temp1 = temp1->next;
            diff--;
        }
    }
    else if(l2 > l1){
        int diff = l2-l1;
        while(diff != 0){
            temp2 = temp2->next;
            diff--;
        }
    }
    while(temp1 != NULL && temp2 != NULL){
        if(temp1 == temp2){
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}

Time Complexity: O(N)
Auxiliary Space: O(1)