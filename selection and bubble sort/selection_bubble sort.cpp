//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "sort.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <time.h>
#define SWAP(x,y,t)(t=x,x=y,y=t)
int data [100000];
int original_data  [100000];
int n;
int range;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void SelectionSort(int data[],int n)
{
	int i,j;
	int min,temp;
	for (i=0; i<n; i++)
	{
		min=i;
		for (j=i+1; j<n; j++)
		{
			if (data[j]<data[min])
			{
				min=j;
			}

		}
		temp=data[i];
		data[i]=data[min];
		data[min]=temp;
	}
}

void printData(int data[],int n, int flag)
{
	 int i;
	 for (i=0; i<n; i++)
	 {
		  if (flag==1)
			  Form1->Memo1->Lines->Add("data["+IntToStr(i)+"]= "+IntToStr(data[i]));
		  else if (flag==2)
			  Form1->Memo2->Lines->Add("data["+IntToStr(i)+"]= "+IntToStr(data[i]));
		  else
			  Form1->Memo3->Lines->Add("data["+IntToStr(i)+"]= "+IntToStr(data[i]));
	 }
}

void CheckData(int data[], int n, int flag)
{
	  int i;
	  for (i=0; i<n; i++)
	  {
		   if (data[i]>data[i+1]) break;
	  }
	  if (i==n-1)
	  {
		  if (flag==2)
			  Form1->Memo2->Lines->Add("correctly sorted");
		  else if (flag==3)
			  Form1->Memo3->Lines->Add("correctly sorted");
	  }
	  else
	  {
		  if (flag==2)
			  Form1->Memo2->Lines->Add("not sorted");
		  else if (flag==3)
			  Form1->Memo3->Lines->Add("not sorted");
	  }
}

/*產生隨機資料*/
void randData(int data[], int n, int range)
{
	 int i;
	 for (i=0; i<n;i++)
	 {
		  data[i]=rand() % range+1;
	 }
}

/*將原始資料放到另一個串列裡，方便後續處理*/
void getData(int data[], int original_data[], int n)
{
	 int i;
	 for (i=0; i<n; i++)
	 {
		  original_data[i]=data[i];
	 }
}

void BubbleSort(int data[], int n)
{
	 int i,j,temp;
	 for (i=n-1; i>=0; i--)
	 {
		  for (j=1; j<i+1; j++)
		  {
			   if (data[j-1]>data[j])
				   SWAP(data[j-1],data[j],temp);
		  }

	 }

}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	 clock_t t_begin,t_end;
	 if (!TryStrToInt(Edit1->Text, n) || n<1)
	 {
		  ShowMessage("請輸入正整數的n");
		  return;
	 }
	 if (!TryStrToInt(Edit2->Text, range) || range<1)
	 {
		  ShowMessage("請輸入正整數的range");
		  return;
	 }
	 t_begin=clock();
	 randData(data,n,range);
	 t_end=clock();
	 if (CheckBox1->Checked) printData(data,n,1);
	 Form1->Memo1->Lines->Add("CPU time (sec.) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
     clock_t t_begin,t_end;
	 getData(data,original_data,n);
	 t_begin=clock();
	 SelectionSort(original_data,n);
	 t_end=clock();
	 if (CheckBox1->Checked) printData(original_data,n,2);
	 if (CheckBox2->Checked) CheckData(original_data,n,2);
	 Form1->Memo2->Lines->Add("CPU time (sec.) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
     clock_t t_begin,t_end;
	 getData(data,original_data,n);
	 t_begin=clock();
	 BubbleSort(original_data,n);
	 t_end=clock();
	 if (CheckBox1->Checked) printData(original_data,n,3);
	 if (CheckBox2->Checked) CheckData(original_data,n,3);
	 Form1->Memo3->Lines->Add("CPU time (sec.) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
}
//---------------------------------------------------------------------------

