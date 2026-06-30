class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL ;
        }
        unordered_map<Node* , Node*> m ;
        Node* newHead = new Node (head->val) ;
        Node* oldtemp = head->next ;
        Node* newtemp = newHead ;
        m[head] = newHead ;
        
        while(oldtemp != NULL) {
            Node* CopyNode = new Node(oldtemp->val) ;
            m[oldtemp] = CopyNode ;
            newtemp->next = CopyNode ;
            newtemp = newtemp->next ;
            oldtemp = oldtemp->next ;
        }
        newtemp = newHead ; 
        oldtemp = head ;
        while(oldtemp != NULL) {
            newtemp->random = m[oldtemp->random] ;
            newtemp = newtemp->next ;
            oldtemp = oldtemp->next ;
        }
        return newHead ;
    }
};