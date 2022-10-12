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
     ListNode* reverse(ListNode* head,ListNode* prev){
        ListNode* root = head;
        int node = 3;
        ListNode* prev2;
        while(--node && head!=NULL){
            prev2=head;
            head = head->next;
        }
        if(node != 0) return root;
       
            node = 3;
            ListNode* newHead = reverse(head,prev2);
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
    ListNode* swapPairs(ListNode* head) {
         return reverse(head,NULL);
    }
};