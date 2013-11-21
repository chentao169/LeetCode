/*
Sort List  : http://oj.leetcode.com/problems/sort-list/
Sort a linked list in O(n log n) time using constant space complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(!head) return head;
        vector<ListNode *> *l1 = new vector<ListNode *>;
        vector<ListNode *> *l2 = new vector<ListNode *>;
        while(head){
            ListNode *tmp = head;
            head = head->next;
            tmp->next = NULL;
            l1->push_back(tmp);
        }
        
        while(l1->size() > 1){
            for(int i=0; i < l1->size()/2; i++)
                l2->push_back( merge( (*l1)[2*i], (*l1)[2*i+1] ) );
            
            if(l1->size()%2) l2->push_back( (*l1)[l1->size()-1] );
            swap(l1, l2);
            l2->clear();
        }
        ListNode *result = (*l1)[0];
        delete l1;
        delete l2;
        return result;
    }
    
    ListNode *merge(ListNode *l1, ListNode *l2){
         ListNode *h = NULL;
         ListNode **p = &h;
         while(l1 && l2) {
             if(l1->val < l2->val){
                *p = l1;
                l1 = l1->next;
             }else {
                *p = l2;
                l2 = l2->next;
             }
             p = &((*p)->next);
         }
         if(l1) *p = l1;
         else *p = l2;
         return h;
    }
};
