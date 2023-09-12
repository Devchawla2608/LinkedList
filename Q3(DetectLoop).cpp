// Detect Loop in linked list

// Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.

// Link : https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

    bool detectLoop(Node* head)
    {
        Node* temp = head;
        Node* prev = head;
        while(temp != NULL && temp->next !=NULL && prev != NULL){
            temp = temp->next->next;
            prev = prev->next;
            if(temp == prev) return true;
        }
        return false;
    }

    // Time Complexity: O(N)
    // Auxiliary Space: O(1)