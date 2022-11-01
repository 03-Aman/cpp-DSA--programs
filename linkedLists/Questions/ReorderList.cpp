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
//PROBLEM LINK: https://leetcode.com/problems/reorder-list/
// input: 1->2->3->4
// o/p: 1->4->2->3
// input: 1->2->3->4->5
// o/p: 1->5->2->4->3
class Solution {
    private:
    ListNode* getmid(ListNode* head){
        ListNode*slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        if(!head||!head->next)
            return head;
        ListNode* fwd=head->next;
         head->next=NULL;
        ListNode * reverseList=reverse(fwd);
        fwd->next=head;
        return reverseList;
       
        
    }
    ListNode* merge(ListNode* head,ListNode* Rhead){
        ListNode* dummyNode=new ListNode();
        ListNode* temp=dummyNode;
        while(head&&Rhead){
           temp->next=head;
            temp=temp->next;
            head=head->next;
            temp->next=Rhead;
             temp=temp->next;
            Rhead=Rhead->next;
          
        }
          while(head){
                temp->next=head;
                 head=head->next;
                temp=temp->next;
                
            }
            while(Rhead){
                temp->next=Rhead;
                Rhead=Rhead->next;
                temp=temp->next;
            }
        temp=dummyNode->next;
        delete dummyNode;
        return temp;
    }
public:
    
    void reorderList(ListNode* head) {
       ListNode* mid= getmid(head); // getting the middle of the list
        ListNode* Rhead=mid->next;  // storing the right half of the list 
      mid->next=NULL;// separating the two lists
        Rhead=reverse(Rhead);        // reversing the right half of the list
          head=merge(head,Rhead);
        
    }
};