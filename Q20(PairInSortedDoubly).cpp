// Find pairs with given sum in doubly linked list

// https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

// Link ->  https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab


    Node* len(Node* head){
        if(head == NULL) return NULL;
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        return temp;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node* last = len(head);
        vector<pair<int , int>> ans;
        while(head != last && head ->prev != last){
            if(head->data + last->data < target) head = head->next;
            else if(head->data + last->data > target) last = last->prev;
            else {
                ans.push_back({head->data , last->data});
                head = head->next;
                last = last->prev;
            }
        }
        return ans;
    }

    Time Complexity 