/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return head;
        }

        unordered_map<Node*, Node*> oldToCopy;

        Node* curr = head;

        while(curr != nullptr){
            oldToCopy[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while(curr != nullptr){
            Node* copyNode = oldToCopy[curr];
            copyNode->next = oldToCopy[curr->next];
            copyNode->random = oldToCopy[curr->random];

            curr = curr->next;
        }
        return oldToCopy[head];
    }
};
*/













class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldDeepCopy;

        if(head == nullptr){
            return head;
        }

        Node* curr = head;
        while(curr != nullptr){
            oldDeepCopy[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while(curr != nullptr){
            Node* newDeepCopy = oldDeepCopy[curr];
            newDeepCopy->next = oldDeepCopy[curr->next];
            newDeepCopy->random = oldDeepCopy[curr->random];

            curr = curr->next;
        }
        return oldDeepCopy[head];
    }
};
