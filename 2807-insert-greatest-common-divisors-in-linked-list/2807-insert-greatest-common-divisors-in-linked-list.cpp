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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        while(node2 != NULL){
            int k = gcd(node1->val, node2->val);
            ListNode* temp = new ListNode(k);
            node1->next = temp;
            temp->next = node2;
            node1 = node2;
            node2 = node2->next;
        }
        return head;
    }
};