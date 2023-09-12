// Rotate Doubly linked list by N nodes

// Given a doubly-linked list, rotate the linked list counter-clockwise by N nodes. Here N is a given positive integer and is smaller than the count of nodes in linked list.

// Coding Ninjas Link : https://www.codingninjas.com/codestudio/problems/rotate-doubly-linked-list-by-n-nodes_920418?leftPanelTab=0

// Function to rotate doubly linked list by N nodes
Node* rotate(Node* head, int N)
  {
   // If we have to rotate by zero nodes, then return the head node as it is
   if(N==0) return head;
  
   // Creating a node to point the last node of the linked list
   Node* last_node = head;
   while(last_node->next != NULL)
     {
      last_node = last_node->next;
     }
     
   /*
          Join the first and last node by making the first node the next 
           of the last node and the last node as prev of the first node
   */
   last_node->next = head;
   head->prev = last_node;
  
   // Variable used to go to the Nth node
   int cnt=0;
   while(cnt < N)
     {
             head = head->next;
             last_node=last_node->next;
             cnt++;
     }
    
     /*
       Now head and last_node is pointing to the first and last node of
       the rotated inked, so now remove the link between head and last node
     */
     last_node->next=NULL;
     head->prev=NULL;
     
     // Finally, return the head node of the rotated linked list
     return head;
  }

//   Time Complexity: O(N)
//   Auxiliary Space: O(1)