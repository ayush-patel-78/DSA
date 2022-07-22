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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return head;
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* prev = head;
        ListNode* selected=start;
        bool check = false;
        if(head->val < x){
            selected = head;
            head=head->next;
        }
        // ListNode* after = head;
        ListNode* small;
        while(head!=NULL){
            // after = head->next;
            if(head->val < x){
                small = head;
                check = true;
            }
            if(check){
                ListNode* next_node = small->next;
                prev->next = next_node;
                small->next = selected->next;
                selected->next = small;
                selected = selected->next;
                check = false;
            }
            prev = head;
            head = head->next;
        }
        return start->next;
        
    }
};