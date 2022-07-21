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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = right;
        ListNode* start = head;
        ListNode* rightNode = head;
        while(count--){
            rightNode = head;
            head = head->next;
        }
        ListNode* last = head;
        head = start ;
        int left_count = left-1;
        ListNode* prev = NULL;
        while(left_count--){
            prev = head;
            head = head->next;
        }
        ListNode* left_index_minus_one = prev;
        ListNode* left_index = head;
        prev = head;
        head = head->next;
        while(head!=last && head!=NULL){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        left_index->next = last;
        if(left_index_minus_one != NULL){
            left_index_minus_one->next = prev;
        }
        if(left==1) return rightNode;
        return start;
        
        
    }
};