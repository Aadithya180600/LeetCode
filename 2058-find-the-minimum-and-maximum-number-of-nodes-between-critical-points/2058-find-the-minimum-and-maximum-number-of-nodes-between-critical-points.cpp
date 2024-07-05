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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int min = 100001, max = 0;
        ListNode* temp = head;
        int t = 0;
        int c = 0;
        bool f = 0;
        while(temp->next->next != NULL){
            t = temp->val;
            temp = temp->next;
            if((temp->val > t and temp->val > temp->next->val) or (temp->val < t and temp->val < temp->next->val)){
                if(f){
                    if(min>c) {
                        min = c;
                    }
                    max+=c;
                }
                c=0;
                f=1;
            }
            c++;
        }
        if(min != 10001 and max != 0){
            return {min, max};
        }
        return {-1,-1};
    }
};