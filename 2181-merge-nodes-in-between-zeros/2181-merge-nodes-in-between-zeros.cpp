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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* current = head;
        int sum = 0;
        while(current->next != NULL){
            current = current -> next;
            temp->next = current;
        while(current->next->val != 0){
            current = current->next;
            current->val += temp->next->val;
            temp->next = current;
        }
        temp = temp->next;
        current = current->next;
        }
        temp->next = NULL;
        return head->next;
    }
};