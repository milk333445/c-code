//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MagicSquare.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define MaxSize 30
int square[MaxSize][MaxSize];
int n;
int row_sum[MaxSize];
int col_sum[MaxSize];
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}

void MagicSquare(int n, int flag)
{
	 int i, j, k, l, data;
	 for (i=0; i<n; i++)
	 {
		 for (j=0; j<n; j++)
		 {
			 square[i][j]=0;
		 }
	 }

	 if (flag==1)//left-up magic square
	 {
	 i=0;
	 j=(n-1)/2;
	 square[i][j]=1;
	 data=2;

	 while (data <= n*n)
	 {
		 k=(i-1<0) ? n-1 : i-1;
		 l=(j-1<0) ? n-1 : j-1;
		 if (square[k][l]>0) i=(i+1)%n;
		 else
		 {
			i=k;
			j=l;
		 }
		 square[i][j]=data++;
	 }
	 }
	 else if (flag==2)//right-bottom magic square
	 {
      i=(n-1)/2;
	  j=n-1;
	  square[i][j]=1;
	  data=2;

	 while (data<=n*n)
	 {
		k=(i-1<0) ? (n-1):(i-1);
		l=(j+1>(n-1)) ? (0):(j+1);
		if (square[k][l]>0) j=(j-1) % n;
		else
		{
            i=k;
			j=l;
        }
        square[i][j]=data++;
	 }
	 }
	 else if (flag==3)//left-bottom magic square
	 {
		i=(n-1);
		j=(n-1)/2;
		square[i][j]=1;
		data=2;

	 while (data<=n*n)
	 {
		k=(i+1>(n-1)) ? (0):(i+1);
		l=(j+1>(n-1)) ? (0):(j+1);
		if (square[k][l]>0) i=(i-1) % n;
        else
        {
			i=k;
            j=l;
        }
        square[i][j]=data++;
	 }
	 }
	 else if (flag==4)//left-up magic square
	 {
      i=(n-1)/2;
	  j=0;
	  square[i][j]=1;
	  data=2;

	  while (data<=n*n)
	  {
        k=(i+1>(n-1)) ? (0):(i+1);
        l=(j-1<0) ? (n-1):(j-1);
        if (square[k][l]>0) j=(j+1) % n;
        else
        {
            i=k;
            j=l;
        }
		square[i][j]=data++;
	  }

	 }
}

void MagicSquareSelfCheck(int row_sum[], int col_sum[], int n, int flag)
{
	//檢查每行相加跟每列相加是否相同
	int i;
	for (i=0; i<n-1; i++)
	{
		 if (row_sum[i]!=row_sum[i+1] || col_sum[i]!=col_sum[i+1]) break;
	}
	if (i==n-1)
	{
	   if (flag==1)
		   Form3->Memo1->Lines->Add("correct MagicSquare");
	   else if (flag==2)
		   Form3->Memo2->Lines->Add("correct MagicSquare");
	   else if (flag==3)
		   Form3->Memo3->Lines->Add("correct MagicSquare");
	   else if (flag==4)
		   Form3->Memo4->Lines->Add("correct MagicSquare");

	}

	else
	{
	   if (flag==1)
		   Form3->Memo1->Lines->Add("wrong MagicSquare");
	   else if (flag==2)
		   Form3->Memo2->Lines->Add("wrong MagicSquare");
	   else if (flag==3)
		   Form3->Memo3->Lines->Add("wrong MagicSquare");
	   else if (flag==4)
		   Form3->Memo4->Lines->Add("wrong MagicSquare");

	}

}


void printSquare(int n,int flag)
{
	 int row_sum[MaxSize]={0};
	 int col_sum[MaxSize]={0};
	 if (flag==1)
	 {
	 Form3->StringGrid1->RowCount = n+1; //StringGrid上多一行放每row總和
	 Form3->StringGrid1->ColCount = n+1; //StringGrid上多一行放每col總和
	 }
	 else if (flag==2)
	 {
	 Form3->StringGrid2->RowCount = n+1;
	 Form3->StringGrid2->ColCount = n+1;
	 }
	 else if (flag==3)
	 {
	 Form3->StringGrid3->RowCount = n+1;
	 Form3->StringGrid3->ColCount = n+1;
	 }
	 else if (flag==4)
	 {
	 Form3->StringGrid4->RowCount = n+1;
	 Form3->StringGrid4->ColCount = n+1;
	 }
	 for (int i=0; i<n; i++)
	 {
		  for (int j=0; j<n; j++)
		  {
			   //計算每行每列總和
			   row_sum[i]+=square[i][j];
			   col_sum[j]+=square[i][j];
			   if (flag==1)
				   Form3->StringGrid1->Cells[j][i]=IntToStr(square[i][j]);
			   else if (flag==2)
				   Form3->StringGrid2->Cells[j][i]=IntToStr(square[i][j]);
			   else if (flag==3)
				   Form3->StringGrid3->Cells[j][i]=IntToStr(square[i][j]);
			   else if (flag==4)
				   Form3->StringGrid4->Cells[j][i]=IntToStr(square[i][j]);
		  }
	 }
	 if (flag==1)
	 {
	 //顯示每row的總和
	 Form3->StringGrid1->RowCount++;
	 for (int i=0; i<n; i++)
	 {
		  Form3->StringGrid1->Cells[n][i]=IntToStr(row_sum[i]);
	 }
	 //顯示每col的總和
	 Form3->StringGrid1->ColCount++;
	 for (int i=0; i<n; i++)
	 {
		  Form3->StringGrid1->Cells[i][n]=IntToStr(col_sum[i]);
	 }
	 }
	 else if (flag==2)
	 {
	 Form3->StringGrid2->RowCount++;
	 for (int i=0; i<n; i++)
	 {
		  Form3->StringGrid2->Cells[n][i]=IntToStr(row_sum[i]);
	 }
	 Form3->StringGrid2->ColCount++;
	 for (int i=0; i<n; i++)
	 {
		  Form3->StringGrid2->Cells[i][n]=IntToStr(col_sum[i]);
	 }
	 }
	 else if (flag==3)
	 {
	 Form3->StringGrid3->RowCount++;
	 for (int i=0; i<n; i++)
	 {
		  Form3->StringGrid3->Cells[n][i]=IntToStr(row_sum[i]);
	 }
	 Form3->StringGrid3->ColCount++;
	 for (int i=0; i<n; i++)
	 {
		  Form3->StringGrid3->Cells[i][n]=IntToStr(col_sum[i]);
	 }
	 }
	 else if (flag==4)
	 {
	  Form3->StringGrid4->RowCount++;
	  for (int i=0; i<n; i++)
	  {
		  Form3->StringGrid4->Cells[n][i]=IntToStr(row_sum[i]);
	  }
	  Form3->StringGrid4->ColCount++;
	  for (int i=0; i<n; i++)
	  {
		  Form3->StringGrid4->Cells[i][n]=IntToStr(col_sum[i]);
	  }
	 }
}

//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
      if (!TryStrToInt(Edit1->Text,n) || n<1 || n%2==0 || n> MaxSize)
		 {
			  ShowMessage("請輸入正整數且奇數且不超過"+IntToStr(MaxSize));
			  return;
		 }
		 MagicSquare(n,1);
		 printSquare(n,1);

		 if (CheckBox1->Checked)//是否有將CheckBox勾選
			 MagicSquareSelfCheck(row_sum, col_sum, n, 1);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
       if (!TryStrToInt(Edit1->Text,n) || n<1 || n%2==0 || n> MaxSize)
		 {
			  ShowMessage("請輸入正整數且奇數且不超過"+IntToStr(MaxSize));
			  return;
		 }
		 MagicSquare(n,2);
		 printSquare(n,2);
		 if (CheckBox1->Checked)
			 MagicSquareSelfCheck(row_sum, col_sum, n, 2);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
       if (!TryStrToInt(Edit1->Text,n) || n<1 || n%2==0 || n> MaxSize)
		 {
			  ShowMessage("請輸入正整數且奇數且不超過"+IntToStr(MaxSize));
			  return;
		 }
		 MagicSquare(n,3);
		 printSquare(n,3);
		 if (CheckBox1->Checked)
			 MagicSquareSelfCheck(row_sum, col_sum, n, 3);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
       if (!TryStrToInt(Edit1->Text,n) || n<1 || n%2==0 || n> MaxSize)
		 {
			  ShowMessage("請輸入正整數且奇數且不超過"+IntToStr(MaxSize));
			  return;
		 }
		 MagicSquare(n,4);
		 printSquare(n,4);
		 if (CheckBox1->Checked)
			 MagicSquareSelfCheck(row_sum, col_sum, n, 4);
}
//---------------------------------------------------------------------------

