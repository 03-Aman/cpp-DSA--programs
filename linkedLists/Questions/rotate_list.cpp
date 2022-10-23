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



/* input: 1->2->3
k=2;
rotate 1= 3->1->2
rotate 2= 2->3->1
output= 2->3->1
*/
class Solution {
      private:
     ListNode* solve(ListNode* head, int k){
         if(head==NULL||head->next==NULL)
            return head;
        else{
              ListNode* start=head;
          ListNode* curr=head;
          ListNode* prev=NULL;
        while(k){
            while(curr->next){
                prev=curr;
                curr=curr->next;
            }
            // last waali node k next m list ka head daal diya 
            curr->next=start;
            prev->next=NULL;
            start=curr;
            //setting prev as a null again to repeat the step
            prev=NULL;
            k--;
        }
                  
     
      return start; }
     }
public:
    ListNode* rotateRight(ListNode* head, int k) {
      ListNode* newHead=solve(head,k);
        return newHead;
        }
};