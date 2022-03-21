# include<iostream>
# include<string.h>
# include<string>
using namespace std;
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;

}BiTNode,*BiTree;
void rebuildTree(char *midorder, char *preorder, int length,BiTree *T)
{
    if(length == 0)
    {
        *T=NULL;
        return;
    }
    *T =(BiTree)malloc(sizeof(BiTNode));
    (*T)->data = *preorder;
    int root = 0;
    for(;root < length; root++)
    {
        if(midorder[root] == *preorder)  //找到在mid_order中当前根结点的位置
        break;
    }
    rebuildTree(midorder, preorder +1, root,&(*T)->lchild);  //左子树
    rebuildTree(midorder + root + 1, preorder + root + 1, length - (root + 1),&(*T)->rchild);  //右子树
}
void postorder(BiTree T)
{
    if(T==NULL)
    return;
    postorder(T->lchild);
    postorder(T->rchild);
    cout<<T->data;
}
int main()
{
    char pre_order[100];
    char mid_order[100];
    cin>>pre_order;
    cin>>mid_order;
    BiTree T=NULL;
    rebuildTree(mid_order,pre_order,strlen(mid_order),&T);
    postorder(T);
    cout<<endl;
    return 0;
}