<<<<<<< HEAD
#include "SeqQueue.c"
#include "BinTree.h"
=======
#include "BinTree.h"
#include "SeqQueue.c"
#include "SeqStack.c"
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
void TreeInit(TreeNode** root)
{
    assert(root);
    assert(*root);
    *root = NULL;
}
void PreOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    printf("%c ",root->data);
<<<<<<< HEAD
    PostOrder(root->lchild);
    PostOrder(root->rchild);
=======
    PreOrder(root->lchild);
    PreOrder(root->rchild);
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
}
void InOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    InOrder(root->lchild);
    printf("%c ",root->data);
    InOrder(root->rchild);
}

void PostOrder(TreeNode* root)
{
  if(root == NULL)
    return;
  PostOrder(root->lchild);
  PostOrder(root->rchild);
  printf("%c ",root->data);
}

void LevelOrder(TreeNode* root)
{
    //层序遍历
    assert(root);
    SeqQueue s;
    SeqQueueInit(&s);
    TreeNode *cur = root;
    SeqQueuePush(&s,cur);
    SeqQueueType tmp;
    while(SeqQueueFront(&s,&tmp))
    {
        printf("%c ",cur->data);
        if(cur->lchild != NULL)
            SeqQueuePush(&s,cur->lchild);
        if(cur->rchild != NULL)
            SeqQueuePush(&s,cur->rchild);
        SeqQueuePop(&s);
        SeqQueueType value;
        SeqQueueFront(&s,&value);
        cur = value; 
    }
  //使用队列。
  //将当前元素入队列，访问队列的首元素，将其左节点与右结点依次入队列
  //将首元素出队列，再执行上一步，直到队列中无元素。
}

// @brief 根据先序遍历结果(带有空节点标记), 
// 构造一棵树 
// @param array[] 先序遍历的结果 
// @param size 数组中元素个数 
// @param null_node 数组中空节点的特殊标记. 
TreeNode *CreateNode(TreeNodeType data)
{
  TreeNode *ret = (TreeNode*)malloc(sizeof(TreeNode));
  ret->rchild = NULL;
  ret->lchild = NULL;
  ret->data = data;
  return ret;
}
TreeNode* _TreeCreate(TreeNodeType array[],size_t size,size_t* index,TreeNodeType null_node)
{
  if(array[*index] == null_node)
    return NULL;
<<<<<<< HEAD
=======
  if(size == 0)
      return NULL;
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
  else
  {
    TreeNode *root = CreateNode(array[*index]);
    (*index)++;
    root->lchild = _TreeCreate(array,size-1,index,null_node);
    (*index)++;
    root->rchild = _TreeCreate(array,size-1,index,null_node);
    return root;
  }
}
TreeNode* TreeCreate(TreeNodeType array[], size_t size, TreeNodeType null_node)
{
  assert(array);
  size_t index = 0;
  return _TreeCreate(array,size,&index,null_node);
}
void DestroyNode(TreeNode *tmp)
{
    assert(tmp);
    free(tmp);
    tmp = NULL;
}
void _TreeDestroy(TreeNode *root)
{
    if(root == NULL)
        return;
    _TreeDestroy(root->lchild);
    _TreeDestroy(root->rchild);
    DestroyNode(root);
}
void TreeDestroy(TreeNode** root)
{
    assert(root);
    assert(*root);
    _TreeDestroy(*root);
    *root = NULL;
    root = NULL;
}

TreeNode* TreeClone(TreeNode* root)
{
    if(root == NULL)
        return NULL;
    TreeNode *newnode = CreateNode(root->data); 
    newnode->lchild = TreeClone(root->lchild);
    newnode->rchild = TreeClone(root->rchild);
    return newnode;
}

size_t TreeSize(TreeNode* root)
{
    if(root == NULL)
        return 0;
    return 1 + TreeSize(root->lchild) + TreeSize(root->rchild);
}
size_t TreeLeafSize(TreeNode* root)
{
    if(root == NULL)
        return 0;
    if((root->lchild == NULL) && (root->rchild == NULL))
        return 1;
    return TreeLeafSize(root->lchild) + TreeLeafSize(root->rchild);
}
/** 
 * * @brief 求一棵树第 K 层节点的个数 
 * * 
 * * @param root 
 * * 
 * * @return 
 * */ 
size_t TreeKLevelSize(TreeNode* root, int K)
{
<<<<<<< HEAD
    if(root == NULL)
=======
    if(root == NULL && K > 0)
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
        return 0;
    if(K == 1)
        return 1;
    return TreeKLevelSize(root->lchild,K-1) + TreeKLevelSize(root->rchild,K-1);
}

size_t TreeHeight(TreeNode* root)
{
    if(root == NULL)
        return 0;
    size_t lheigh = TreeHeight(root->lchild);
    size_t rheigh = TreeHeight(root->rchild);
    return (lheigh > rheigh ? lheigh : rheigh) + 1;
}

TreeNode* TreeFind(TreeNode* root, TreeNodeType to_find)
{
    if(root == NULL)
        return NULL;
    if(root->data == to_find)
        return root;
    else
    {
<<<<<<< HEAD
        TreeFind(root->rchild,to_find);
        TreeFind(root->lchild,to_find);
    }
    return NULL;
=======
        TreeNode *l = TreeFind(root->rchild,to_find);
        TreeNode *r = TreeFind(root->lchild,to_find);
        return (l == NULL ? r : l);
    }
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
}

TreeNode* LChild(TreeNode *root , TreeNode* node)
{
    assert(root);
    assert(node);
    TreeNode* tmp = TreeFind(root,node->data);
    if(tmp != NULL)
        return tmp->lchild;
    else
    {
<<<<<<< HEAD
        return NULL;
=======
		return NULL;
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
    }
}

TreeNode* RChild(TreeNode *root,TreeNode* node)
{
    assert(root);
    assert(node);
    TreeNode* tmp = TreeFind(root,node->data);
    if(tmp != NULL)
        return tmp->rchild;
    else
    {
        return NULL;
    }
}
TreeNode* _Parent(TreeNode *root,TreeNode *node)
{
    if(root == NULL)
        return NULL;
<<<<<<< HEAD
    if(root->lchild == node)
        return root;
    if(root->rchild == node)
        return root;
    else{
        TreeNode* ret = _Parent(root->lchild,node);
        ret = _Parent(root->rchild,node);
        return ret;
    }
=======
    if(root->lchild == node || root->rchild == node)
        return root;
    TreeNode* l = _Parent(root->lchild,node);
    TreeNode *r = _Parent(root->rchild,node);
    return (l==NULL? r : l);
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
}
TreeNode* Parent(TreeNode* root, TreeNode* node)
{
    assert(root);
    assert(node);
    TreeNode* tmp = TreeFind(root,node->data);
    if(tmp == NULL)
        return NULL;
    return _Parent(root,node);
}

<<<<<<< HEAD
void PreOrderByLoop(TreeNode* root); 

void InOrderByLoop(TreeNode* root); 

void PostOrderByLoop(TreeNode* root); 

void TreeMirror(TreeNode* root); 
=======
void PreOrderByLoop(TreeNode* root)
{
    assert(root);
    //使用栈完成
    SeqStack s;
    SeqStackInit(&s);
    //先将根节点入栈
    SeqStackPush(&s,root);
    //开始循环(循环条件:栈为空)
    TreeNode* value;
    while(SeqStackTop(&s,&value) != 0)
    {
      //访问栈顶元素，
      printf("%c ",value->data);
      fflush(stdout);
      SeqStackPop(&s);
      //将其出栈，再依次将其右子树、左子树入栈
      if(value->rchild != NULL)
        SeqStackPush(&s,value->rchild);
      if(value->lchild != NULL)
        SeqStackPush(&s,value->lchild);
    }
}

void InOrderByLoop(TreeNode* root)
{
    assert(root);
    //将根节点入栈
    //1.将cur指针指向root的左子树，将cur入栈，cur指向cur->lchild,直到cur的左子树为空
    //打印当前结点，
    //判断是否有右子树，若没有则将cur出栈，cur = 栈顶元素，继续循环
    //若有则返回返回循环的第一步
    //
}

void PostOrderByLoop(TreeNode* root); 

void swap(TreeNode **a,TreeNode **b)
{
    TreeNode *tmp = *a;
    *a = *b;
    *b = tmp;
}
void TreeMirror(TreeNode* root)
{
    if(root == NULL)
        return;
    swap((&root->lchild),&(root->rchild));
    TreeMirror(root->lchild);
    TreeMirror(root->rchild);
}
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073

int IsCompleteTree(TreeNode* root);
///////////////////////////测试代码///////////////////////////////
#define TESTHEAD printf("------------------------------%s------------------------------------\n",__FUNCTION__)

void testCreateTree()
{
<<<<<<< HEAD
  TreeNodeType array[]="abd##eg###c#f##";
  TreeNode *root = TreeCreate(array,sizeof(array)/sizeof(TreeNodeType),'#');
  printf("root->lchild :%c\n",root->rchild->data);
=======
  //TreeNodeType array[]="abd##eg###c#f##";
  TreeNodeType array[] = {};
  TreeNode *root = TreeCreate(array,sizeof(array)/sizeof(TreeNodeType),'#');
  if(root == NULL)
      printf("empty tree!\n");
  else
  {
      printf("root->lchild :%c\n",root->rchild->data);
  }
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
}
void testOrder()
{
    TESTHEAD;
    TreeNodeType array[]="abd##eg###c#f##";
    TreeNode *root = TreeCreate(array,sizeof(array)/sizeof(TreeNodeType),'#');
<<<<<<< HEAD
    PostOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PreOrder(root);
=======
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
    printf("\n");
    LevelOrder(root);
    printf("\n");
}
void testDestroy()
{
    TESTHEAD;
    TreeNodeType array[]="abd##eg###c#f##";
    TreeNode *root = TreeCreate(array,sizeof(array)/sizeof(TreeNodeType),'#');
    TreeDestroy(&root);
    printf("%p \n",root);
}
void testClone()
{
    TESTHEAD;
    TreeNodeType array[]="abd##eg###c#f##";
    TreeNode *root = TreeCreate(array,sizeof(array)/sizeof(TreeNodeType),'#');
    TreeNode *newroot = TreeClone(root);
    PostOrder(root);
    printf("\n");
    PostOrder(newroot);
    printf("\n");
}
void testLchild()
{
    TESTHEAD;
    TreeNodeType array[]="abd##eg###c#f##";
    TreeNode *root = TreeCreate(array,sizeof(array)/sizeof(TreeNodeType),'#');
<<<<<<< HEAD
    TreeNode* ret = LChild(root,root);
=======
    TreeNode* ret = LChild(root,root->lchild->rchild);
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
    if(ret != NULL)
        printf("lchild :%c\n",ret->data);
    else{
        printf("没有左孩子\n");
    }
}
void testRchild()
{
    TESTHEAD;
    TreeNodeType array[]="abd##eg###c#f##";
    TreeNode *root = TreeCreate(array,sizeof(array)/sizeof(TreeNodeType),'#');
<<<<<<< HEAD
    TreeNode* ret = RChild(root,root->lchild);
=======
    TreeNode* ret = RChild(root,root->rchild);
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
    if(ret != NULL)
        printf("rchild :%c\n",ret->data);
    else{
        printf("没有右孩子\n");
    }
}
void testParent()
{
    TESTHEAD;
    TreeNodeType array[]="abd##eg###c#f##";
    TreeNode *root = TreeCreate(array,sizeof(array)/sizeof(TreeNodeType),'#');
<<<<<<< HEAD
    TreeNode* ret = Parent(root,root->lchild->rchild);
    printf("parent :%c\n",ret->data);
=======
    TreeNode* ret = Parent(root,root->lchild);
    printf("parent : %c\n",ret->data);
}
void testFind()
{
    TESTHEAD;
    TreeNodeType array[]="abd##eg###c#f##";
    TreeNode *root = TreeCreate(array,sizeof(array)/sizeof(TreeNodeType),'#');
    printf("f  ---  %c\n",TreeFind(root,'f')->data);
}
void testMirror()
{
    TESTHEAD;
    TreeNodeType array[]="abd##eg###c#f##";
    TreeNode *root = TreeCreate(array,sizeof(array)/sizeof(TreeNodeType),'#');
    PreOrder(root);
    printf("\n");
    TreeMirror(root);
    PreOrder(root);
    printf("\n");
}
void testPreLoop()
{
    TESTHEAD;
    TreeNodeType array[]="abd##eg###c#f##";
    TreeNode *root = TreeCreate(array,sizeof(array)/sizeof(TreeNodeType),'#');
    PreOrder(root);
    printf("\n");
    PreOrderByLoop(root);
    printf("\n");
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
}
void test()
{
  testCreateTree();
  testOrder();
  testDestroy();
  testClone();
  testLchild();
  testRchild();
<<<<<<< HEAD
  testParent();
=======
  testFind();
  testParent();
  testMirror();
  testPreLoop();
>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
}

int main()
{
  test();
  return 0;
}
<<<<<<< HEAD
=======

>>>>>>> 903a053dd2769f8aa8cb863587e4f0bc045ae073
