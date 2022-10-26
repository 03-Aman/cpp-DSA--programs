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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *curr = head;
        ListNode *nxt;
        ListNode *prev;
        while (curr && curr->next)
        {
            if (curr->val == curr->next->val) // check krenge ki curr se agla element same hai ya nahi
            {
                nxt = curr->next; //  pointer to store next node 
                while (nxt && curr->val == nxt->val) // jub tak nxt ki value alag nahi ho jaati nxt usse aage bdate raho
                    nxt = nxt->next;
                if (curr == head)   // checking ki list se start m hi toh duplicate value toh nahi
                {
                    curr = nxt;
                    head = curr;  // current ko hi head bna do
                }
                else
                {
                    prev->next = nxt;// previous ke next m next element store krdo yaani ki non duplicate value
                    curr = nxt;
                }
            }
            else
            {
                prev = curr;   // previous ko store krke current ko aage bdado
                curr = curr->next;
            }
        }
        return head;
    }
};