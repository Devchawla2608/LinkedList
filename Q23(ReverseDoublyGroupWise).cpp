// Reverse a doubly linked list in groups of given size

// Given a doubly linked list containing n nodes. The problem is to reverse every group of k nodes in the list.

// Link : https://practice.geeksforgeeks.org/problems/reverse-doubly-linked-list-in-groups-of-given-size/1

Node* revListInGroupOfGivenSize(Node* head, int k)
{
    Node *current = head;
    Node* next = NULL;
    Node* newHead = NULL;
    int count = 0;
     
    // reversing the current group of k
    // or less than k nodes by adding
    // them at the beginning of list
    // 'newHead'
    while (current != NULL && count < k)
    {
        next = current->next;
        push(&newHead, current);
        current = next;
        count++;
    }
     
    // if next group exists then making the desired
    // adjustments in the link
    if (next != NULL)
    {
        head->next = revListInGroupOfGivenSize(next, k);
        head->next->prev = head;
    }
     
    // pointer to the new head of the
    // reversed group
    // pointer to the new head should point to NULL, otherwise you won't be able to traverse list in reverse order using 'prev'
    newHead->prev = NULL;
    return newHead;
}
 
// Function to print nodes in a
// given doubly linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)