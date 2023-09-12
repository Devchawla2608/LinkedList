    // Move Last Element to Front of a Linked List
    // You are given the head of a Linked List. You have to move the last element to the front of the Linked List and return the list.

// Link : https://practice.geeksforgeeks.org/problems/move-last-element-to-front-of-a-linked-list/1

    ListNode *moveToFront(ListNode *head){
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode* temp = head;
        while(temp->next != NULL && temp->next->next != NULL){
            temp = temp->next;
        }
        ListNode* save = temp->next;
        temp->next = NULL;
        save->next = head;
        return save;
    }

Time Complexity: O(N)
Auxiliary Space: O(1)