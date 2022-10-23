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
/*
input: 1->2->3->1>4
k=1
output:2->3->4
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int k) {
        if(head==NULL)
            return head;
         ListNode* curr=head;
         ListNode*prev=NULL;
        while(curr){
            if(curr->val==k){
                if(curr==head){
                    head=curr->next;
                    prev=curr;
                   
                    curr=curr->next;
             
                }
                else{

                    prev->next=curr->next;
                    curr=curr->next;
              
                    
                }
            }
            else{
                prev=curr;
                curr=curr->next;
            }
            
        }
   return head; }
};