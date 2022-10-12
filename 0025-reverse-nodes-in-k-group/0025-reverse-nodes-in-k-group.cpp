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
    ListNode* reverse(ListNode* head,int k,ListNode* prev){
        ListNode* root = head;
        int node = k+1;
        ListNode* prev2;
        while(--node && head!=NULL){
            prev2=head;
            head = head->next;
        }
        if(node != 0) return root;
       
            node = k+1;
            ListNode* newHead = reverse(head,k,prev2);
            head = root;
            ListNode* nextNode = head;
            while(--node){
                nextNode = head->next;
                head->next = prev;
                prev = head;
                head = nextNode;
            }
            
            root->next = newHead;
            return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head,k,NULL);
    }
};