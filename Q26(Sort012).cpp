// Given a linked list of 0s, 1s and 2s, sort it.
// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

// Link : https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* zeroHead = NULL;
        Node* zeroTail = NULL;
        Node* oneHead = NULL;
        Node* oneTail = NULL;
        Node* twoHead = NULL;
        Node* twoTail = NULL;
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == 0){
                if(zeroHead == NULL && zeroTail == NULL){
                    zeroHead = temp;
                    zeroTail = temp;
                }else{
                    zeroTail->next = temp;
                    zeroTail = zeroTail->next;
                }
            }else if(temp->data == 1){
                if(oneHead == NULL && oneTail == NULL){
                    oneHead = temp;
                    oneTail = temp;
                }else{
                    oneTail->next = temp;
                    oneTail = oneTail->next;
                }
            }else{
                if(twoHead == NULL && twoTail == NULL){
                    twoHead = temp;
                    twoTail = temp;
                }else{
                    twoTail->next = temp;
                    twoTail = twoTail->next;
                }
            }
            temp = temp->next;
        }
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        if(zeroTail != NULL){
            ansHead = zeroHead;
            ansTail = zeroTail;
        }
        if(oneTail != NULL){
            if(ansTail == NULL){
                ansHead = oneHead;
                ansTail = oneTail;
            }else{
                ansTail->next = oneHead;
                ansTail = oneTail;
            }
        }
        if(twoTail !=NULL){
            if(ansTail == NULL){
                ansHead = twoHead;
                ansTail = twoTail;
            }else{
                ansTail->next = twoHead;
                ansTail = twoTail;
            }
        }
        ansTail->next = NULL;
        return ansHead;
    }
};

// Time Complexity: O(N)
// Auxiliary Space: O(1)