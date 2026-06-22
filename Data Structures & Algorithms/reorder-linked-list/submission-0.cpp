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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        ListNode* previous = nullptr;
        ListNode* current = secondHalf;
        while(current != nullptr){
            ListNode* nextNode = current->next;
            current->next = previous;

            previous = current;
            current = nextNode;
        }

        secondHalf = previous;

        ListNode* firstHalf = head;

        while(secondHalf != nullptr){
            ListNode* firstNext = firstHalf->next;
            ListNode* secondNext = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = firstNext;

            firstHalf = firstNext;
            secondHalf = secondNext;
        }
    }
};
