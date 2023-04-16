//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "infix2postfixandprefix.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define max_size 100
String Stack[max_size];  //裝運算子
String Stack_another[max_size];    //裝運算元
int top = -1;
int top_another = -1;
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}

String pop(int flag)
{   switch(flag)
	   {    case(1):
					//處理運算子
					if (top == -1)
					{   Form6->Memo1->Lines->Add("Stack is empty!");
					}
					else return Stack[top--];
					break;
			case(2):
					//處理運算元
					if (top_another == -1)
					{
						Form6->Memo1->Lines->Add("Stack is empty!");
					}
					else return Stack_another[top_another--];
					break;
			default:
			Form6->Memo1->Lines->Add("Invalid stack flag!");
			break;
	   }
}

int p(String op)
{
    if (op == "+") return 3;
	if (op == "-") return 3;
    if (op == "*") return 4;
    if (op == "/") return 4;
    if (op == "%") return 4;
    if (op == "^") return 5;
    if (op == "(") return 6;
    if (op == "&&") return 2;
    if (op == "||") return 1;
    if (op == "#") return -1;
    // default
    return 0;
}

int q(String op)
{
    if (op == "+") return 3;
    if (op == "-") return 3;
    if (op == "*") return 4;
    if (op == "/") return 4;
    if (op == "%") return 4;
    if (op == "^") return 5;
    if (op == "(") return 0;
	if (op == "&&") return 2;
    if (op == "||") return 1;
    if (op == "#") return -1;
    // default
    return 0;
}

void print_stack_another()
{
	int i;
	String data1 = "", data2 = "";
	for (i = 0; i <= top; i++) data1 += Stack[i]+" ";
	for (i = 0; i <= top_another; i++) data2 += Stack_another[i]+" ";
	Form6->Memo1->Lines->Add("Stack 1 => "+data1);
	if (top_another != -1) Form6->Memo1->Lines->Add("Stack 2 => "+data2);


}


void push(int flag, String data)
{   switch(flag)
	   {    case(1):
					if (top == max_size-1)
					{
						Form6->Memo1->Lines->Add("Stack is full!");
						return;
					}
					else Stack[++top] = data;
					break;
			case(2):
					if (top_another == max_size-1)
					{
						Form6->Memo1->Lines->Add("Stack is full!");
                        return;
					}
					else Stack_another[++top_another] = data;
					break;
	   }
	   if (Form6->CheckBox1->Checked) print_stack_another();
}

bool addParenthesis(String x, String y)
{
	 if (p(x) > q(y)) return true;
	 if (x == "-" && (y == "-" || y == "+")) return true;
	 if (x == "/" && (y == "/" || y == "*")) return true;
	 return false;
}

void get_fix(String x, int flag)
{
	String a = pop(2);
	a = (flag == 1) ? x+pop(2)+a : pop(2)+a+x;
	push(2, a);

}

boolean IsOperand(String s)
{
	if ((s!="+") && (s!="-") && (s!="*") && (s!="/")
		 && (s!="(") && (s!=")") && (s!="&&") && (s!="||")
		 && (s!="^") && (s!="#") && (s!="%"))
		 return true;
	return false;
}


boolean IsOpreator(String s)
{
	if ((s=="+") || (s=="-") || (s=="*") || (s=="/")
		|| (s=="(") || (s==")") || (s=="&&") || (s=="||")
		|| (s=="^") || (s=="#") || (s=="%"))
		return true;
	return false;
}

String transformation(String infix, int flag)
{
	int n = infix.Length();
	int i, j;
	String s, x;
		push(1, "#");
		for (i=1; i<=n; i++)
		{
			s = infix[i];
			if (IsOperand(s))
				 push(2, s);
			else if (s == ")")
			{
				 while((x=pop(1))!="(")
				 {
					 get_fix(x, flag);
				 }

            }
			else
			{
				while(p(s) <= q(Stack[top]))
				{
					x = pop(1);
					get_fix(x, flag);
				}
				push(1, s);

			}
		}
		while(Stack[top] != "#")
		{
			x = pop(1);
			get_fix(x, flag);
		}
		pop(1);
		return pop(2);
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
	 String infix = Edit1->Text;
	 String prefix = transformation(infix, 1);
	 Edit3->Text = prefix;
	 Form6->Memo1->Lines->Add("infix:   "+infix);
	 Form6->Memo1->Lines->Add("prefix:   "+prefix);
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button2Click(TObject *Sender)
{
	 String infix = Edit1->Text;
	 String postfix = transformation(infix, 2);
	 Edit2->Text = postfix;
	 Form6->Memo1->Lines->Add("infix:   "+infix);
	 Form6->Memo1->Lines->Add("postfix:   "+postfix);
}
//---------------------------------------------------------------------------
