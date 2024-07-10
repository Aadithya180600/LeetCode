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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        map<int, int> m;
        ListNode* temp = head;
        while(temp!=NULL){
            m[temp->val]++;
            temp = temp->next;
        }
        temp = head;
        ListNode* prev = NULL;
        // while(temp != NULL){
        //     cout<<temp->val<<" ";
        //     temp = temp->next;
        // }
        while(temp != NULL){
            // cout<<temp->val<<" ";
            if(m[temp->val] == 1){
                prev = temp;
                temp = temp->next;
                break;
            }
            temp = temp->next;
        }
        if(prev == NULL) {
            return NULL;
        }
        else head = prev;
        while(temp != NULL){
            if(m[temp->val] == 1){
                prev->next = temp;
                prev = temp;
            }
            temp = temp->next;
        }
        prev->next = NULL;

        return head;
    }
};