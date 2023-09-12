// Multiply two linked lists

//    Given elements as nodes of the two linked lists. The task is to multiply these two linked lists, say L1 and L2. 

// Note: The output could be large take modulo 109+7.

// Link : https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1

   Node* reverseList(Node* head) {
       if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        Node* temp = head;
        Node* ans = reverseList(temp->next);
        Node* save = head->next;
        save->next = head;
        head->next = NULL;
        return ans;
    }
    

long long  multiplyTwoLists (Node* l1, Node* l2)
{

    Node* temp1 = l1;
    Node* temp2 = l2;
    long long int num1 = 0;
    long long int num2 = 0;
    while(temp1 !=NULL){
        num1 = (num1*10 + temp1->data)%1000000007;
        temp1 = temp1->next;
    }
    while(temp2 !=NULL){
        num2 = (num2*10 + temp2->data)%1000000007;
        temp2 = temp2->next;
    }
    long long int mul = num1*num2;
    mul %=1000000007;
    return mul;
}
Time Complexity: O(N+M)
Auxiliary Space: O(1)