/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;

        while(current != nullptr){
            ListNode* nextNode = current->next; // nextNode -> 1
            current->next = previous; // [0] -> nullptr
            previous = current; // previous -> [0]
            current = nextNode; // current, nextNode -> [1]
        }
        return previous;
    }
};
