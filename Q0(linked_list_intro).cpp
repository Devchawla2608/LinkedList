  #include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

Node * take_input(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

Node* insertNode(Node *head , int i ,int data){
    Node *newNode = new Node(data);
    Node *temp = head;
    int count = 0;
    if(i == 0){
        newNode->next = head;
        head = newNode;
          return head;
    }
    while(count< i-1 && temp !=NULL){
        temp = temp->next;
        count = count + 1;
    }
    
    if(temp!=NULL){
   newNode->next = temp->next;
    temp->next =  newNode;

}
  return head;
}

Node* insertNodeRecursivly(Node *head , int i ,int data){
    if(head == NULL){
        return head;
    }
    if(i == 0){
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *smallOutput =  insertNodeRecursivly(head->next , i - 1 , data);
    head->next = smallOutput;
    return head;
}


Node* deleteNode(Node *head , int i){
    Node *temp = head;
    int count = 0;

    if(i == 0){
       head = temp->next;
       delete temp;
       return head;
    }
    while(count< i-1 && temp !=NULL){
        temp = temp->next;
        count = count + 1;
    }
    
    if(temp!=NULL){
        Node *a = temp->next;
        Node *b = a->next;
        temp->next = b;
        delete a;
}else{
    cout<<"You are giving an invaild i"<<endl;
}
  return head;
}



Node* deleteNodeRecursivly(Node *head , int i){
   if(head == NULL){
        return head;
    }
    if(i == 0){
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *smallOutput =  deleteNodeRecursivly(head->next , i - 1);
    head->next = smallOutput;
    return head;
}

Pair reverseLLPair(Node* head){
    if(head == NULL || head->next == NULL){
        Pair p;
        p.head = head;
        p.tail = head;
        return p;
    }

    Pair smallOutput = reverseLLPair(head->next);

    
    smallOutput.tail->next = head;
    smallOutput.tail = head;
     head->next = NULL;
    
    Pair p1;
    p1.head = smallOutput.head;
    p1.tail = smallOutput.tail;
    return p1;
}


Node* reverseLL(Node* head){
    if(head == NULL || head->next == NULL){
        cout<<"Hii i am in if"<<endl;
        return head;
    }
    cout<<"I am No null"<<endl;
    Node *smallOutput = reverseLL(head->next);
         cout<<"Hii i am after smallOutput "<<endl;
    Node* temp = smallOutput;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallOutput;
}


Node* reverseLL2(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    cout<<"I am No null"<<endl;
    Node *smallOutput = reverseLL(head->next);

   Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallOutput;
}

void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){

    // Statically created 
    // Node n1(1);
    // Node *head = &n1;
    // Node n2(2);
    // n1.next = &n2

    // // Dynamically created 
    // Node *n3 = new Node(5);
    // Node * head = n3;
    // Node *n4 = new Node(6);
    // n3->next = n4


// creating 5 nodes and print them using function 
    // Node n1(1);
    // Node *head = &n1;
    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);
    // n1.next = &n2
    // n2.next = &n3
    // n3.next = &n4
    // n4.next = &n5;
    Node *head = take_input();
    int i , data;
    cin>>i;
    // cin>>data;
    // head = insertNodeRecursivly(head , i , data);
    //  print(head);
    // head = deleteNode(head , i);
    // print(head);
    
    head  = deleteNodeRecursivly(head , i);
    print(head);

    return 0;
}









Node* insertNode(Node *head , int i ,int data){
    if(i == 0){
        Node* newNode = new Node(data);
        newNode->next =head;
        head = newNode;
        return head;
    }
    Node* temp = head;
    Node *save = NULL;
    while(temp!= NULL){
        if(i-1 == 0){
            save = temp;
            break;
        }
temp = temp->next;
i--;
    }
        if(temp != NULL){
        Node* newNode = new Node(data);
        newNode->next = save->next;
        save->next = newNode;    
        }else{
            cout<<"You are giving a higher value of i"<<endl;
        }
        
    return head;
}

void deleteNode(Node *head , int i){
    if(i == 0){
        Node* newNode = NULL;
        newNode = head->next;
        delete head;
        return newNode

    }
    Node* temp = head;
    
    while(temp!= NULL){
        if(i-1 == 0){
            break;
        }
        temp = temp->next;
        i--;
    }
        if(temp!=NULL){
            Node* newNode = NULL;
            newNode = temp->next ;
            temp->next = newNode->next;
            delete newNode;
        }
   
    
    return head;
}
