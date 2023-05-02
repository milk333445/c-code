//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "list.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}

struct Node
{
    int data;
	struct Node* next;
};

struct Node *NewNode(int element)
{
	struct Node *newNode = new Node;
	newNode->data = element;
	newNode->next = newNode;
	return newNode;
}
struct Node* first = NewNode(0);
struct Node* last = first;
void InsertFront(int element)
{
   struct Node *p = NewNode(element);
   p->next = first->next;
   first->next = p;
}

void InsertLast(int element)
{
   struct Node *p = NewNode(element);
   p->next = first;
   last->next = p;
   last = p;
}
void PrintList()
{
	struct Node *current = first->next;
	while (current != first)
	{
		Form8->Memo1->Text += IntToStr(current->data) + " => ";
		current = current->next;
	}
	Form8->Memo1->Text += "\r\n";
}

void SearchDataHeader(int target)
{
	struct Node *p;
	for (p=first->next; (p->data!=target && p!=first); p=p->next) ;
	if (p->data == target)
	{
		Form8->Memo1->Lines->Add("target has been found");
	}
	else
	{
		Form8->Memo1->Lines->Add("target has not been found");
	}
}


void SearchDeleteHeader(int target)
{
	struct Node *q, *p;
	for (q=first, p=first->next; (p->data!=target && p!=first);q=p, p=p->next) ;
	if (p==first) Form8->Memo1->Lines->Add("target has not been found");
	q->next = p->next;
	delete(p);

}
void SearchInsertAfter(int target, int element)
{
	struct Node *q, *p;
	for (q = first, p = first->next; (p->data != target && p != first); q = p, p = p->next) ;
	if (p == first)
	{
	   Form8->Memo1->Lines->Add("Target has not been found");
	}
	else
	{
	   struct Node *newNode = NewNode(element);
	   newNode->next = p->next;
	   p->next = newNode;
	}

}
void SearchInsertBefore(int target, int element)
{
	struct Node *q, *p;
	for (q = first, p = first->next; (p->data != target && p != first); q = p, p = p->next) ;
	if (p == first)
	{
	   Form8->Memo1->Lines->Add("Target has not been found");
	}
	else
	{
	   struct Node *newNode = NewNode(element);
	   newNode->next = q->next;
	   q->next = newNode;
	}

}

void Insert_n_random_number_to_list(int n, int range)
{
	srand(time(NULL));
	for (int i=0; i<n; i++)
	{
		int randomNum = rand() % range;
		InsertLast(randomNum);

	}

}

void delete_last_one()
{
	if (first->next == first)
	{
		return;
	}
	struct Node *p = first;
    while (p->next->next != first)
	{
      p = p->next;
	}
	struct Node *lastNode = p->next;
	p->next = first;
    delete lastNode;
}












struct node
{
	int data;
	struct node* next;
};

struct node* top = NULL;

struct node* newnode(int element)
{
	struct node* newNode = new node;
	newNode->data = element;
	newNode->next = NULL;
	return newNode;
}

void PushStack(int element)
{
	struct node* x = newnode(element);
	if (top == NULL)
	{
		top = x;
	}
	else
	{
		x->next = top;
		top = x;
	}
}

int PopStack()
{
	if (top == NULL)
	{
		ShowMessage("Stack is empty");
		return -1; // 返回一個特定的錯誤碼，表示堆疊是空的
	}

	struct node* temp = top;
	int poppedData = temp->data;
	top = top->next;
	delete temp;

	return poppedData;
}
void PrintStack()
{
	Form8->Memo2->Clear(); // 清空 Memo2 的內容
	struct node* current = top;
	while (current != NULL)
	{
		Form8->Memo2->Text += IntToStr(current->data) + " => ";
		current = current->next;
	}
	Form8->Memo2->Text += "\r\n";
}




struct QueueNode
{
	 int data;
	 struct QueueNode *next;
};

struct QueueNode *front = NULL;
struct QueueNode *rear = NULL;


struct QueueNode *newnode1(int element)
{
	 struct QueueNode *p = new QueueNode;
	 p->data = element;
	 p->next = NULL;
	 return p;
}

void AddQueue(int element)
{
	 struct QueueNode *p;
	 p = newnode1(element);
	 if (rear == NULL)
	 {
		front = p;
	 }
	 else
	 {
		rear->next = p;
	 }
	 rear = p;
}

int DeleteQueue()
{
	struct QueueNode *p;
	int element;
	if (front == NULL)
	{
	   return -1;
	}
	else
	{
	   p = front;
	   front = front->next;
	   element = p->data;
	   free(p);
	   return element;

	}


}

void PrintQueue()
{
	Form8->Memo3->Clear(); // 清空 Memo2 的內容
	struct QueueNode* current = front;
	while (current != NULL)
	{
		Form8->Memo3->Text += IntToStr(current->data) + " => ";
		current = current->next;
	}
	Form8->Memo3->Text += "\r\n";
}

//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
     int element = StrToInt(Edit1->Text);
	 InsertFront(element);
	 PrintList();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button2Click(TObject *Sender)
{
    int element = StrToInt(Edit1->Text);
	InsertLast(element);
	PrintList();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button3Click(TObject *Sender)
{
     int target = StrToInt(Edit2->Text);
	 SearchDataHeader(target);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button4Click(TObject *Sender)
{
    int element = StrToInt(Edit1->Text);
	int target = StrToInt(Edit2->Text);
	SearchInsertAfter(target, element);
	PrintList();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button5Click(TObject *Sender)
{
    int element = StrToInt(Edit1->Text);
	int target = StrToInt(Edit2->Text);
	SearchInsertBefore(target, element);
	PrintList();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button6Click(TObject *Sender)
{
    int target = StrToInt(Edit2->Text);
	SearchDeleteHeader(target);
	PrintList();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button7Click(TObject *Sender)
{
    int n = StrToInt(Edit3->Text);
	int range = StrToInt(Edit4->Text);
	Insert_n_random_number_to_list(n, range);
	PrintList();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button8Click(TObject *Sender)
{
    delete_last_one();
	PrintList();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button9Click(TObject *Sender)
{
    int n = StrToInt(Edit5->Text);
	PushStack(n);
	PrintStack();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button10Click(TObject *Sender)
{
    int poppedData = PopStack();
	if (poppedData != -1)
	{
		ShowMessage("Popped data: " + IntToStr(poppedData));
		PrintStack();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button11Click(TObject *Sender)
{
     int element = StrToInt(Edit6->Text);
	 AddQueue(element);
	 PrintQueue();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button12Click(TObject *Sender)
{
	 int element = DeleteQueue();
	 if (element != -1)
	{
		ShowMessage("deleted data: " + IntToStr(element));
		PrintQueue();
	}

}
//---------------------------------------------------------------------------
