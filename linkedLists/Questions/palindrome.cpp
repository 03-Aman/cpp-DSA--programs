#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    if (head == NULL)
        head = temp;
    else
    {
        temp->next=head;
        head = temp;
    }
}
void print(node *head)
{
    node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// Function To find the middle of the list
node* getMid(node* head ) {
        node* slow = head;
        node* fast = head -> next;
        
        while(fast != NULL && fast-> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
// reverse list function
node * reverse(node *&head){
    node * curr=head;
    node * prev=NULL;
    node * fwd=NULL;
    while(curr!=NULL){
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }
    return prev;
    }
bool isPalindrome(node * head){
    if(head==NULL|| head->next==NULL)
    return true;
    // getting the middle of the list
    node * middle=  getMid(head);
    // cout<<middle->data;
    // reversing the list from the element next to the middle element
    node * temp=middle->next;
    middle->next=reverse(temp);
    // comparing both halves
    node * head1=head;
    node * head2=middle->next;
    while (head2!=NULL)
    {
       if(head1->data!=head2->data)
       return false;
       head1=head1->next;
       head2=head2->next;
    }
     // setting the list as it was initially
    //  temp=middle->next;
    //  middle->next=reverse(temp);
     return true;
    
}
int main()
{
    node *head = NULL;
    int n;
    cout<<"Enter the number of element you wish to insert in the list: ";
   cin>>n;
   cout<<"Now enter the elements in the list : ";
   while (n--)
   {
    int ele;
    cin>>ele;
    insertAtHead(head,ele);
   }
   
   
    print(head);
    cout<<getMid(head);
    return 0;
}