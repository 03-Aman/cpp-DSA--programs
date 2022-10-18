#include <bits/stdc++.h>
#include "creation.cpp"
using namespace std;
void zigZag(node *root)
{
    if (root == NULL)
        return;
    stack<node *> currLvl;
    stack<node *> nxtLvl;
    bool LeftToRight = true;
    currLvl.push(root);
    while (!currLvl.empty())
    {
        node *temp = currLvl.top();
        currLvl.pop();
        if (temp)
        {
            cout << temp->data << " ";
            if (LeftToRight)
            {
                if (temp->left)
                    nxtLvl.push(temp->left);
                if (temp->right)
                    nxtLvl.push(temp->right);
            }
            else
            {
                if (temp->right)
                    nxtLvl.push(temp->right);
                if (temp->left)
                    nxtLvl.push(temp->left);
            }
        }
        if (currLvl.empty())
        {
            LeftToRight = !LeftToRight;
            swap(currLvl, nxtLvl);
        }
    }
}
int main()
{
    node *root = NULL;
    create_tree(root);
    levelOrder(root);
    cout << endl;
    cout<<"The zig-zag traversal of the tree is: ";
    zigZag(root);
    return 0;
}