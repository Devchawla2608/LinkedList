    // Middle of the Linked List
    
    // Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

// Link : https://leetcode.com/problems/middle-of-the-linked-list/

    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast !=NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    // Time Complexity: O(N)
    // Auxiliary Space: O(1)