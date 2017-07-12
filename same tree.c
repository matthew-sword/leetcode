#include <stdio.h>

struct TreeNode
{
        int val;
         struct TreeNode *left;
         struct TreeNode *right;
};

int isSameTree(struct TreeNode* p, struct TreeNode* q);

int main() {
    struct TreeNode* root1 = NULL;
    struct TreeNode* root2 = NULL;
    int result = isSameTree(root1,root2);
    printf("%d",result);

    return 0;
}

int isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
      return 1;

    if (p && q)     //p q都非空
    {
        if (p->val != q->val)       //p q值不同
            return 0;
        else        //p q值相同
        {
            if (isSameTree(p->left,q->left) && isSameTree(p->right,q->right))
                return 1;
            else
                return 0;
        }
    }
    else        //p q结构不同
        return 0;
}