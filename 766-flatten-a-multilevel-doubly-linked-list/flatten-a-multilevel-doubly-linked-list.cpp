class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return head;

        Node* curr = head;
        while(curr != NULL){
            Node* next = curr->next; 

            if(curr->child != NULL){
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                Node* temp = curr->next;
                while(temp->next != NULL){   
                    temp = temp->next;
                }

                temp->next = next;          
                if(next) next->prev = temp;
            }

            curr = next;  
        }
        return head;
    }
};
