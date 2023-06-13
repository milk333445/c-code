//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <time.h>
#define MAX_SIZE 300000
#define maxsize 1000
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
int list[MAX_SIZE];
int n;
int stack[MAX_SIZE];
int top = -1;
int front = -1;
int heap_stack[MAX_SIZE];
int original_list[MAX_SIZE];
float selectsorttime[MAX_SIZE];
float insertsorttime[MAX_SIZE];
float bubblesorttime[MAX_SIZE];
float rquicksorttime[MAX_SIZE];
float nrquicksorttime[MAX_SIZE];
float mergesorttime[MAX_SIZE];
float nrmergesorttime[MAX_SIZE];
float heapsorttime[MAX_SIZE];

#include "sort.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

// selection_sort
void selection_sort(int list[], int rep)
{
	 int min, temp;
	for(int j = 0 ; j < rep; j++){
	   min = j;
	   for(int i = j+1 ; i < rep; i++){
		   if (list[min] > list[i])
			  min = i;
	 }
	 SWAP(list[j], list[min], temp);
	}
}

// bubble_sort
void bubble_sort(int list[], int z)
{
	int temp, i, j;
	for (i=z-1; i>0; i--)
	{
		for (j=0; j<i; j++)
		{
			if (list[j] > list[j+1])
			{
				SWAP(list[j], list[j+1], temp);
			}
		}
	}
}

void insertion_sort(int list[], int n)
{
	int i, j, target;
	for (i=1; i<n; i++)
	{
		target = list[i];
		j = i;
		while ((list[j-1] > target) && (j>0))
		{
			list[j] = list[j-1];
			j--;
		}
		list[j] = target;
	}
}

// quick_sort(recursive versions)
void quick_sort(int list[], int left, int right)
{
	int i, j, target, temp;
	if (left < right)
	{
		i = left + 1;
		j = right;
		target = list[left];
		do
		{
		while ((list[i] < target) && (i <= j)) i++;
		while ((list[j] >= target) && (i <= j)) j--;
		if (i < j) SWAP(list[i], list[j], temp);
		} while (i < j);

		if (left < j) SWAP(list[left], list[j], temp);
		quick_sort(list, left, j-1);
		quick_sort(list, j+1, right);

	}
}



void push(int element)
{
	if (top == MAX_SIZE-1)
	{
		Form8->Memo2->Lines->Add("StackFull");
	}
	else
	{
		stack[++top] = element;
	}
}


int pop()
{
	if (top == -1)
	{
	   Form8->Memo2->Lines->Add("StackEmpty");
	}
	return stack[top--];
}



//quick sort function (non-recursive versions)
void quicksort(int list[], int left, int right)
{
	int i, j, target, tmp;
	top = -1;
	push(left);
	push(right);
	while (top != -1)
	{
	   right = pop();
	   left = pop();
	   target = list[left];
	   i = left+1;
	   j = right;
	   do
	   {
           while ((list[i] < target) && (i <= j)) i++;
		   while ((list[j] >= target) && (i <= j)) j--;
		   if (i < j) SWAP(list[i], list[j], tmp);

	   }while (i < j);
	   if (left < j) SWAP(list[left], list[j], tmp);

	   if (j+1 < right)
	   {
		  push(j+1);
		  push(right);
	   }
	   if (left < j-1)
	   {
		  push(left);
		  push(j+1);
	   }
	}
}
 void merge(int C[], int k, int A[], int i, int m, int B[], int j, int n)
 {
	   while ((i<=m) && (j<=n))
	   {
		   if (A[i] <= B[j])
		   {
			   C[k++] = A[i++];
		   }
		   else
		   {
			   C[k++] = B[j++];
		   }
	   }
	   while (i<=m) C[k++] = A[i++];
	   while (j<=n) C[k++] = B[j++];
 }

 // merge_sort (non-recursive versions)
 void merge_sort(int A[], int left, int right)
 {
	 int len = 2;
	 int i;
	 while (len <= n)
	 {
		 for (i=0; i<n; i+=len)
		 {
			 merge(A, i, A, i, i+len/2-1, A, i+len/2, i+len-1);
		 }
		 len *= 2;
	 }
 }



 // merge_sort (recursive versions)
 void mergesort(int A[], int left, int right)
 {
	 int i, j, k, m;
	 if (left < right)
	 {
		 m = (left+right)/2;
		 mergesort(A, left, m);
		 mergesort(A, m+1, right);
		 merge(A, left, A, left, m, A, m+1, right);
	 }

 }


 void restore(int s, int t, int list[])
 {
	 int i = s, j;
	 int temp;
	 while (i <= t/2)
	 {
		if (list[2*i] < list[2*i+1])
		{
			j = 2*i;
		}
		else
		{
			j = 2*i+1;
		}
		if (list[i] < list[j]) break;
		SWAP(list[i], list[j], temp);
		i = j;
	 }
 }

 void heap_sort(int A[], int n)
 {
	 int i;
	 for (i=n/2; i>0; i--)
	 {
		 restore(i, n, A);
	 }
	 for (i=n; i>0; i--)
	 {
		 heap_stack[++front] = A[1];
		 A[1] = A[i];
		 restore(1, i-1, A);
	 }
	 front = -1;
 }

 void get_data(int list[], int original_list[], int n)
 {
	int i, j;
	for(int i = 0; i < n; i++)
	{
		list[i] = original_list[i];
	}
 }

 void get_heap(int list[], int original_list[], int n)
 {
	int i, j;
	for(int i = 1; i < n+1; i++)
	{
		list[i] = original_list[i-1];
	}

 }



 // check whether the sort is correct

 void right_sort(int list[], int n, int flag)
 {
	int i;
	int reptimes = 0;
	for (i=0; i<n; i++)
	{
	   if (i == 0)
		  continue;

	   else if (list[i] < list[i-1])
	   {
		   if (flag == 1)
		   {
			  Form8->Memo1->Lines->Add("Selection sort Wrong!");
			  break;
		   }
		   else if (flag == 2)
		   {
			  Form8->Memo1->Lines->Add("Insertion sort Wrong!");
			  break;
		   }
		   else if (flag == 3)
		   {
			  Form8->Memo1->Lines->Add("Bubble sort Wrong!");
			  break;
		   }
		   else if (flag == 4)
		   {
			  Form8->Memo1->Lines->Add("Quick sort (recursive) Wrong!");
			  break;
		   }
		   else if (flag == 5)
		   {
			  Form8->Memo1->Lines->Add("Quick sort (non-recursive) Wrong!");
			  break;
		   }
		   else if (flag == 6)
		   {
			  Form8->Memo1->Lines->Add("Merge sort (recursive) Wrong!");
			  break;
		   }
		   else if (flag == 7)
		   {
			  Form8->Memo1->Lines->Add("Merge sort (non-recursive) Wrong!");
			  break;
		   }
		   else
		   {
			  Form8->Memo1->Lines->Add("Heap sort Wrong!");
			  break;
		   }

	   }
	   else reptimes++;

	}

	if (reptimes == n-1)
	{
	   if (flag == 1)
		  Form8->Memo1->Lines->Add("Selection sort Right!");
	   else if (flag == 2)
		  Form8->Memo1->Lines->Add("Insertion sort Right!");
	   else if (flag == 3)
		  Form8->Memo1->Lines->Add("Bubble sort Right!");
	   else if (flag == 4)
		  Form8->Memo1->Lines->Add("Quick sort (recursive) Right!");
	   else if (flag == 5)
		  Form8->Memo1->Lines->Add("Quick sort (non-recursive) Right!");
	   else if (flag == 6)
		  Form8->Memo1->Lines->Add("Merge sort (recursive) Right!");
	   else if (flag == 7)
		  Form8->Memo1->Lines->Add("Merge sort (non-recursive) Right!");
	   else
		  Form8->Memo1->Lines->Add("Heap sort Right!");
	}
 }






void __fastcall TForm8::Button1Click(TObject *Sender)
{
	  n = StrToInt(Edit2->Text);
	  int range = StrToInt(Edit3->Text);
	  int times = StrToInt(Edit1->Text);
	  int i, j;
	  int rep = n;
	  for (j=0; j<times; j++)
	  {
		  for (i=0; i<rep; i++)
		  {
			  original_list[i] = rand()%range+1;
			  if (CheckBox9->Checked)
				  Form8->Memo2->Lines->Add("list[" +IntToStr(i)+ "] = " +IntToStr(original_list[i]));

		  }
		  if (CheckBox1->Checked)
		  {   clock_t t_begin,t_end;
			  get_data(list, original_list, rep);
			  t_begin = clock();
			  selection_sort(list, rep);
			  t_end=clock();
			  float CPUTime = (float)(t_end-t_begin)/CLOCKS_PER_SEC;
			  selectsorttime[j] = CPUTime;
			  Form8->Memo2->Lines->Add("n="+IntToStr(rep)+"Selection sort"+" CPU time (sec.)= "+FloatToStr(selectsorttime[j]));
			  right_sort(list, rep, 1);
		  }
		  if (CheckBox2->Checked)
		  {   clock_t t_begin,t_end;
			  get_data(list, original_list, rep);
			  t_begin = clock();
			  insertion_sort(list, rep);
			  t_end=clock();
			  float CPUTime = (float)(t_end-t_begin)/CLOCKS_PER_SEC;
			  insertsorttime[j] = CPUTime;
			  Form8->Memo2->Lines->Add("n="+IntToStr(rep)+"Insertion sort"+" CPU time (sec.)= "+FloatToStr(insertsorttime[j]));
			  right_sort(list, rep, 2);
		  }
		  if (CheckBox3->Checked)
		  {   clock_t t_begin,t_end;
			  get_data(list, original_list, rep);
			  t_begin = clock();
			  bubble_sort(list, rep);
			  t_end=clock();
			  float CPUTime = (float)(t_end-t_begin)/CLOCKS_PER_SEC;
			  bubblesorttime[j] = CPUTime;
			  Form8->Memo2->Lines->Add("n="+IntToStr(rep)+"bubble sort"+" CPU time (sec.)= "+FloatToStr(bubblesorttime[j]));
			  right_sort(list, rep, 3);
		  }
		  if (CheckBox4->Checked)
		  {   clock_t t_begin,t_end;
			  get_data(list, original_list, rep);
			  t_begin = clock();
			  quick_sort(list, 0, rep-1);
			  t_end=clock();
			  float CPUTime = (float)(t_end-t_begin)/CLOCKS_PER_SEC;
			  rquicksorttime[j] = CPUTime;
			  Form8->Memo2->Lines->Add("n="+IntToStr(rep)+"Quick sort (recursive)"+" CPU time (sec.)= "+FloatToStr(rquicksorttime[j]));
			  right_sort(list, rep, 4);
		  }
		  if (CheckBox5->Checked)
		  {   clock_t t_begin,t_end;
			  get_data(list, original_list, rep);
			  t_begin = clock();
			  quicksort(list, 0, rep-1);
			  t_end=clock();
			  float CPUTime = (float)(t_end-t_begin)/CLOCKS_PER_SEC;
			  nrquicksorttime[j] = CPUTime;
			  Form8->Memo2->Lines->Add("n="+IntToStr(rep)+"Quick sort (non-recursive)"+" CPU time (sec.)= "+FloatToStr(nrquicksorttime[j]));
			  right_sort(list, rep, 5);
		  }
		  if (CheckBox6->Checked)
		  {   clock_t t_begin,t_end;
			  get_data(list, original_list, rep);
			  t_begin = clock();
			  merge_sort(list, 0, rep-1);
			  t_end=clock();
			  float CPUTime = (float)(t_end-t_begin)/CLOCKS_PER_SEC;
			  mergesorttime[j] = CPUTime;
			  Form8->Memo2->Lines->Add("n="+IntToStr(rep)+"Merge sort (recursive)"+" CPU time (sec.)= "+FloatToStr(mergesorttime[j]));
			  right_sort(list, rep, 6);
		  }
		  if (CheckBox7->Checked)
		  {   clock_t t_begin,t_end;
			  get_data(list, original_list, rep);
			  t_begin = clock();
			  mergesort(list, 0, rep-1);
			  t_end=clock();
			  float CPUTime = (float)(t_end-t_begin)/CLOCKS_PER_SEC;
			  nrmergesorttime[j] = CPUTime;
			  Form8->Memo2->Lines->Add("n="+IntToStr(rep)+"Merge sort (non-recursive)"+" CPU time (sec.)= "+FloatToStr(nrmergesorttime[j]));
			  right_sort(list, rep, 7);
		  }
		  if (CheckBox8->Checked)
		  {   clock_t t_begin,t_end;
			  get_heap(list, original_list, rep);
			  t_begin = clock();
			  heap_sort(list, rep);
			  t_end=clock();
			  float CPUTime = (float)(t_end-t_begin)/CLOCKS_PER_SEC;
			  heapsorttime[j] = CPUTime;
			  Form8->Memo2->Lines->Add("n="+IntToStr(rep)+"Heap sort"+" CPU time (sec.)= "+FloatToStr(heapsorttime[j]));
			  right_sort(heap_stack, rep, 8);
		  }


		  rep+=n;

	  }
}
//---------------------------------------------------------------------------

