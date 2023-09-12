// Quick Sort on Linked List

// Sort the given Linked List using quicksort. which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

// Input:
// In this problem, method takes 1 argument: address of the head of the linked list. The function should not read any input from stdin/console.
// The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
// There are multiple test cases. For each test case, this method will be called individually.

// Output:
// Set *headRef to head of resultant linked list.

Link : https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1

node* partion(node* head , node* tail){
    node* pivot = head;
    node* cur = head->next ; 
    node* prev = head;
    while(cur != tail->next){
        if(pivot ->data > cur->data){
            swap(prev->next->data , cur->data);
            prev = prev->next;
        }
        cur = cur->next;
    }
    swap(prev->data , pivot->data);
    return prev;
}

void solveSort(node* head , node* tail){
    if(head == NULL || tail == NULL || head == tail) return;
    node * pivot = partion(head , tail);
    solveSort(head , pivot);
    solveSort(pivot->next , tail);
}

node* getTail(node*head){
    if(head == NULL || head->next == NULL) return head;
    node* temp = head;
    while(temp != NULL && temp->next != NULL) temp = temp->next;
    return temp;
}


void quickSort(struct node **headRef) {
    node* head = *headRef;
    if(head == NULL || head->next == NULL) return;
    node* tail = getTail(head);
    solveSort(head , tail);
}

// Time Complexity: O(N^2)
// Auxiliary Space: O(1)