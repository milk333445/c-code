//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Shortest_path.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
int **W;
int **D;
int **A;
int **AP;
int **TC;
int *E;
int n, range, max_range, LargeInt;
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}

bool allshorest(bool *found)
{
	int i;
	for (i=0; i<n; i++)
	{
		if (found[i] == false)
		{
			return false;
		}

	}
	return true;
}

//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
	   int i, j, k;
	   if (W != NULL)
	   {
		   for (i = 0; i<n; i++)
		   {
			   delete(W[i]);
		   }
		   delete(W);
	   }
	   if (TC != NULL)
	   {
		   for (i = 0; i<n; i++)
		   {
			   delete(TC[i]);
		   }
		   delete(TC);
	   }

	   n = StrToInt(Edit1->Text);
	   range = StrToInt(Edit2->Text);
	   max_range = StrToInt(Edit3->Text);
	   LargeInt = StrToInt(Edit4->Text);
	   W = new int *[n];
	   for (i=0; i<n; i++)
	   {
		   W[i] = new int [n];
	   }
	   for (i=0; i<n; i++)
	   {
		   for (j=0; j<n; j++)
		   {
			   W[i][j] = rand()%range + 1;
			   if (W[i][j] > max_range)
			   {
				   W[i][j] = LargeInt;
			   }
		   }
		   W[i][i] = 0;
	   }

	   if (CheckBox1->Checked)
	   {
		   StringGrid1->RowCount = n+1;
		   StringGrid1->ColCount = n+1;
		   for (i=1; i<n+1; i++)
		   {
			   StringGrid1->Cells[0][i] = i-1;
			   StringGrid1->Cells[i][0] = i-1;
		   }
		   for (i=1; i<n+1; i++)
		   {
			   for (j=1; j<n+1; j++)
			   {
				   StringGrid1->Cells[j][i] = W[i-1][j-1];
			   }
		   }
	   }
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button2Click(TObject *Sender)
{
	   int i, j, k, v, mark;
	   int count = 0;
	   int min = 9999;
	   bool *found;
	   if (D != NULL)
	   {
		   for (i=0; i<n; i++)
		   {
				delete(D[i]);
		   }
		   delete(D);
	   }
	   int start = StrToInt(Edit5->Text);
	   D = new int *[n];
	   E = new int [n];
	   found = new bool [n];
	   for (i=0; i<n; i++)
	   {
		   D[i] = new int [n];
	   }

	   for (j=0; j<n; j++)
	   {
		   D[j][0] = W[start][j];
		   found[j] = false;
		   E[j] = start;
	   }
	   found[start] = true;
	   D[start][0] = 0;
	   while (allshorest(found) == false)
	   {
		   for (i=0; i<n; i++)
		   {
			   if ((D[i][count] <= min) && (found[i] == false))
			   {
					min = D[i][count];
					mark = i;
			   }
		   }
		   found[mark] = true;
		   count++;
		   for (v=0; v<n;v++)
		   {
			   if (!found[v] && ((D[mark][count-1]+W[mark][v]) < D[v][count-1]))
			   {
				   D[v][count] = D[mark][count-1]+W[mark][v];
				   E[v] = mark;
			   }
			   else
			   {
				   D[v][count] = D[v][count-1];
			   }

		   }
		   min = 9999;
	   }
	   if (CheckBox2->Checked)
	   {
		   StringGrid2->RowCount = n+1;
		   StringGrid2->ColCount = n+2;
		   for (i=1; i<n+1; i++)
		   {
			   StringGrid2->Cells[0][i] = i-1;
			   StringGrid2->Cells[i][0] = i-1;
		   }

		   for (i=1; i<n+1; i++)
		   {
			   for (j=1; j<n+1; j++)
			   {
				   StringGrid2->Cells[j][i] = D[i-1][j-1];
			   }
			   StringGrid2->Cells[n+1][i] = E[i-1];
		   }
	   }

	   for (v=0; v<n; v++)
	   {
		   String r = "";
		   int a, b;
		   r = "-->" + IntToStr(v);
		   for (b=v, a=E[b]; a!=start; b=a, a=E[b])
		   {
			   r = "--" + IntToStr(a) + "--[" + IntToStr(W[a][b]) + "]"+r;
		   }
		   Form8->Memo1->Lines->Add("The shortest distance from " +IntToStr(start)+ " to " +IntToStr(v)+ " is " +IntToStr(D[v][n-1])+ " with path " +IntToStr(start)+ "--[" +IntToStr(W[start][b])+"]"+r);
	   }
	   Form8->Memo1->Lines->Add("------------------------");
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button3Click(TObject *Sender)
{
	   int i, j, k, v;
	   if (A != NULL)
	   {
		   for (i=0; i<n; i++) delete A[i];
		   delete A;
	   }
	   if (AP != NULL)
	   {
		   for (i=0; i<n; i++) delete AP[i];
		   delete AP;
	   }
	   A = new int *[n];
	   for (i=0; i<n; i++)
	   {
		   A[i] = new int [n];
	   }
	   AP = new int *[n];
	   for (i=0; i<n; i++)
	   {
		   AP[i] = new int [n];
	   }
	   for (i=0; i<n; i++)
	   {
		   for (j=0; j<n; j++)
		   {
			   A[i][j] = W[i][j];
			   AP[i][j] = i;
		   }
	   }
	   for (k=0; k<n; k++)
	   {
		   for (i=0; i<n; i++)
		   {
			   for (j=0; j<n; j++)
			   {
				   if (A[i][j] > A[i][k] + A[k][j])
				   {
					   A[i][j] = A[i][k] + A[k][j];
					   AP[i][j] = k;
				   }
			   }
		   }
	   }

	   if (CheckBox2->Checked)
	   {
		   StringGrid3->RowCount = n+1;
		   StringGrid3->ColCount = n+1;
		   for (i=1; i<n+1; i++)
		   {
			   StringGrid3->Cells[0][i] = i-1;
			   StringGrid3->Cells[i][0] = i-1;
		   }
		   for (i=1; i<n+1; i++)
		   {
			   for (j=1; j<n+1; j++)
			   {
				   StringGrid3->Cells[j][i] = A[i-1][j-1];
			   }
		   }

	   }
	   if (CheckBox2->Checked)
	   {
		   StringGrid4->RowCount = n+1;
		   StringGrid4->ColCount = n+1;
		   for (i=1; i<n+1; i++)
		   {
			   StringGrid4->Cells[0][i] = i-1;
			   StringGrid4->Cells[i][0] = i-1;
		   }
		   for (i=1; i<n+1; i++)
		   {
			   for (j=1; j<n+1; j++)
			   {
				   StringGrid4->Cells[j][i] = AP[i-1][j-1];
			   }
		   }

	   }
	   for (k=0; k<n; k++)
	   {
		   for (v=0; v<n; v++)
		   {
			   String r = "";
			   int a, b;
			   r = "-->" +IntToStr(v);
			   for (b=v, a=AP[k][b]; a!=k; b=a, a=AP[k][b])
			   {
				   r = "--" +IntToStr(a)+ "--[" +IntToStr(A[a][b])+ "]"+r;
			   }
			   Form8->Memo1->Lines->Add("The shortest distance from " +IntToStr(k)+ " to " +IntToStr(v)+ " is " +IntToStr(A[k][v])+ " with path " +IntToStr(k)+ "--[" +IntToStr(A[k][b])+"]"+r);
		   }
		   Form8->Memo1->Lines->Add("------------------------");
	   }


}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button4Click(TObject *Sender)
{
	   int i, j, k, v;
	   TC = new int *[n];
	   for (i=0; i<n; i++)
	   {
		   TC[i] = new int [n];
	   }
	   for (i=0; i<n; i++)
	   {
		   for (j=0; j<n; j++)
		   {
			   if (W[i][j] < max_range)
			   {
				   TC[i][j] = 1;
			   }
			   else TC[i][j] = 0;

		   }
		   TC[i][i] = 0;
	   }
	   for (k=0; k<n; k++)
	   {
		   for (i=0; i<n; i++)
		   {
			   for (j=0; j<n; j++)
			   {
				   TC[i][j] = TC[i][j] || (TC[i][k] && TC[k][j]);
			   }

		   }
	   }

       if (CheckBox2->Checked)
	   {
		   StringGrid5->RowCount = n+1;
		   StringGrid5->ColCount = n+1;
		   for (i=1; i<n+1; i++)
		   {
			   StringGrid5->Cells[0][i] = i-1;
			   StringGrid5->Cells[i][0] = i-1;
		   }
		   for (i=1; i<n+1; i++)
		   {
			   for (j=1; j<n+1; j++)
			   {
				   StringGrid5->Cells[j][i] = TC[i-1][j-1];
			   }
		   }

	   }


}
//---------------------------------------------------------------------------
