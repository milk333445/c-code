//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BST.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

struct BSTreeNode
{
    struct BSTreeNode *leftchild;
    int data;
    struct BSTreeNode *rightchild;
};
struct BSTreeNode *root;
String tree = "";

struct BSTreeNode *NewBSTNode(int x)
{
    struct BSTreeNode *node = new struct BSTreeNode;
    node->data = x;
    node->leftchild = NULL;
    node->rightchild = NULL;
    return node;
}

//新增資料
struct BSTreeNode *InsertBSTree(BSTreeNode *node, int x)
{
    if (node == NULL) return NewBSTNode(x);
    if (x < node->data)
        node->leftchild = InsertBSTree(node->leftchild, x);
    else
        node->rightchild = InsertBSTree(node->rightchild, x);
    return node;
}


void inorder(struct BSTreeNode *node)
{
    if (node != NULL)
    {
		inorder(node->leftchild);
		tree += IntToStr(node->data) + "_";
        inorder(node->rightchild);
	}
}

struct BSTreeNode *InorderSucc(struct BSTreeNode *node)
{
   struct BSTreeNode *p = node;
   while (p->leftchild != NULL)
        p = p->leftchild;
   return p;
}

//刪除資料
struct BSTreeNode *DeleteBSTree(struct BSTreeNode *node, int x)
{
    struct BSTreeNode *temp;
    if (node == NULL) return node;
    if (x < node->data)
        node->leftchild = DeleteBSTree(node->leftchild, x);
    else if (x > node->data)
		node->rightchild = DeleteBSTree(node->rightchild, x);
    else //x found in node
    {
        if ((node->leftchild == NULL) || (node->rightchild == NULL))
        {
			temp = node->leftchild ? node->leftchild : node->rightchild;
            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else *node = *temp;
            free(temp);
        }
        else //兩顆子樹
        {
            temp = InorderSucc(node->rightchild);
            node->data = temp->data;
            node->rightchild = DeleteBSTree(node->rightchild, temp->data);
        }
    }
    return node;
}




struct BSTreeNode* SearchBST(struct BSTreeNode* node, int x)
{
    while (node != NULL)
    {
        if (x == node->data)
        {
            Form8->Memo1->Lines->Add("data is found");
            return node;
        }
        if (x < node->data)
            node = node->leftchild;
        else
            node = node->rightchild;
    }
    Form8->Memo1->Lines->Add("data is not found");
    return NULL;
}



void postorder(struct BSTreeNode *node)
{
    if (node != NULL)
    {
        postorder(node->leftchild);
        postorder(node->rightchild);
		tree += IntToStr(node->data) + "_";
    }
}


void preorder(struct BSTreeNode *node)
{
    if (node != NULL)
    {
		tree += IntToStr(node->data) + "_";
        preorder(node->leftchild);
        preorder(node->rightchild);
    }
}


struct QNode
{
    struct BSTreeNode *treenode;
    struct QNode *next;
};


struct QNode *Front, *rear;
void AddQueue(struct BSTreeNode *Tnode)
{
    struct QNode *node;
    node = new struct QNode;
    node->treenode = Tnode;
    node->next = NULL;
    if (Front == NULL) Front = node;
    else rear->next = node;
    rear = node;
}

struct BSTreeNode *DeleteQueue()
{
    struct BSTreeNode *Tnode;
    struct QNode *old_front;
    if (rear == NULL)
        return NULL;
    else
    {
        Tnode = Front->treenode;
        old_front = Front;
        Front = Front->next;
        free(old_front);
        return Tnode;
    }
}

void LevelOrder(struct BSTreeNode *node)
{
    if (node != NULL)
    {
        AddQueue(node);
        while(Front != NULL)
        {
            node = DeleteQueue();
			tree += IntToStr(node->data) + "_";
            if (node->leftchild != NULL)
                AddQueue(node->leftchild);
            if (node->rightchild != NULL)
                AddQueue(node->rightchild);
        }
    }
}




TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
	  int data = Edit1->Text.ToInt();
	  root = InsertBSTree(root, data);
	  tree = "";
	  inorder(root);
	  Form8->Memo1->Lines->Add(tree);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button2Click(TObject *Sender)
{
	  int data = Edit2->Text.ToInt();
	  root = DeleteBSTree(root, data);
	  tree = "";
	  inorder(root);
      Form8->Memo1->Lines->Add(tree);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button3Click(TObject *Sender)
{
	  int n = Edit3->Text.ToInt();
	  int range = Edit4->Text.ToInt();
	  int data;  \
	  tree = "";
	  for (int i = 0; i < n; i++)
	  {
		  data = rand() % (range + 1);
		  root = InsertBSTree(root, data);
	  }
	  inorder(root);
	  Form8->Memo1->Lines->Add(tree);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button4Click(TObject *Sender)
{
	  int target = Edit5->Text.ToInt();
	  SearchBST(root, target);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button5Click(TObject *Sender)
{
	  tree = "";
	  preorder(root);
	  Form8->Memo1->Lines->Add(tree);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button6Click(TObject *Sender)
{
	  tree = "";
	  inorder(root);
	  Form8->Memo1->Lines->Add(tree);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button7Click(TObject *Sender)
{
	  tree = "";
	  postorder(root);
	  Form8->Memo1->Lines->Add(tree);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button8Click(TObject *Sender)
{
	  tree = "";
	  LevelOrder(root);
	  Form8->Memo1->Lines->Add(tree);
}
//---------------------------------------------------------------------------
