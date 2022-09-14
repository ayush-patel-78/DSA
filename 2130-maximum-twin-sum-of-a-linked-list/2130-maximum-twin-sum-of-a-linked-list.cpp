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
    int pairSum(ListNode* head) {
          int nodes = 0;
          ListNode* temp = head;
          while(temp!=NULL){
              nodes++;
              temp = temp->next;
          }
        int count = 0;
        ListNode* curr = head;
          while(count != nodes/2){
              curr = curr->next;
              count++;
          }
        ListNode* next_node=NULL;
        ListNode* prev = NULL;
        while(curr!=NULL){
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        int maximum_ans = 0;
        while(head != NULL && prev !=NULL){
            if(head->val + prev->val > maximum_ans) maximum_ans = head->val + prev->val;
            head = head->next;
            prev = prev->next;
        }
        return maximum_ans;
    }
};