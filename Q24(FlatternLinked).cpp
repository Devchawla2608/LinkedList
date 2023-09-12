// Flattening a Linked List

// Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

// Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
// For more clarity have a look at the printList() function in the driver code.

Link -> https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

Node *flatten(Node *root)
{
    Node* head1 = root;
    Node* head2 = root->next;
    root = root->next;
    while(root != NULL){
        Node* head = NULL;
        Node* tail = NULL;
        while(head1 != NULL && head2 != NULL){
            if(head1->data < head2->data){
                Node* newNode = new Node(head1->data);
                if(head == NULL && tail ==NULL){
                    head = newNode;
                    tail = newNode;
                }else{
                    tail->bottom = newNode;
                    tail = tail->bottom;
                }
                head1 = head1->bottom;
            }else{
                Node* newNode = new Node(head2->data);
                if(head == NULL && tail == NULL){
                    head = newNode;
                    tail = newNode;
                }else{
                    tail->bottom = newNode;
                    tail = tail->bottom;
                }
                head2 = head2->bottom;
            }
        }
        while(head1 != NULL){
            Node* newNode = new Node(head1->data);
                if(head == NULL && tail ==NULL){
                    head = newNode;
                    tail = newNode;
                }else{
                    tail->bottom = newNode;
                    tail = tail->bottom;
                }
                head1 = head1->bottom;
        }
        while(head2 != NULL){
            Node* newNode = new Node(head2->data);
                if(head == NULL && tail ==NULL){
                    head = newNode;
                    tail = newNode;
                }else{
                    tail->bottom = newNode;
                    tail = tail->bottom;
                }
                head2 = head2->bottom;
        }
        root = root->next;
        head1 = head;
        head2 = root;
    }
    return head1;
}

// Time Complexity: O(N*M)
// Auxiliary Space: O(1)
