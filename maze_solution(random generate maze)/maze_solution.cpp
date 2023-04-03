//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "maze_solution.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
const int MAZE_SIZE_MAX = 100;

struct position{
	int x, y;
};

struct cood
{
	int dx, dy;
};

const int s = 4;
cood f1[s] = {{0,1},{-1,0},{0,-1},{1,0}};
cood f2[s] = {{0,2},{-2,0},{0,-2},{2,0}};

int **maze;
int **mark;
int rows, cols, top = -1, d;

position stack[MAZE_SIZE_MAX*MAZE_SIZE_MAX];

void push(position data)
{
    if (top == MAZE_SIZE_MAX*MAZE_SIZE_MAX-1)
        ShowMessage("Stack is full");
	else
        stack[++top] = data;
}

position pop()
{
	if (top == -1)
        ShowMessage("Stack is empty");
    else
		return stack[top--];
}

int nextMove(position step)
{
	for (int i=0; i<s; i++)
		if (maze[step.x+f2[i].dx][step.y+f2[i].dy] == 1)
            return 1;
    return 0;
}

void mazeDFS(position step)
{
    push(step);
    maze[step.x][step.y] = 0;
	while(top != -1)
    {
        step = pop();
		while(nextMove(step))
        {
            d = rand()%s;
			position next;
            next.x = step.x + f2[d].dx;
            next.y = step.y + f2[d].dy;
			if (maze[next.x][next.y] == 1)
            {
                maze[step.x + f1[d].dx][step.y + f1[d].dy] = 0;
				push(next);
                maze[next.x][next.y] = 0;
                step = next;
			}
        }
    }
}

void displayMaze(int **maze, int rows, int cols)
{
	Form5->StringGrid1->RowCount = rows;
	Form5->StringGrid1->ColCount = cols;
	for (int i=0; i<rows; i++)
		for (int j=0; j<cols; j++)
            Form5->StringGrid1->Cells[j][i] = maze[i][j];
}

void generateMaze(int rows, int cols)
{
    // Allocate memory for maze
	maze = new int*[rows];
	for (int i = 0; i < rows; i++)
		maze[i] = new int[cols];
	mark = new int*[rows];
	for (int i = 0; i < rows; i++)
		mark[i] = new int[cols];

	// Initialize maze to all walls
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
		{    maze[i][j] = 1;
             mark[i][j] = 0;
		}
	// Generate maze
    position start;
    start.x = 1;
	start.y = 1;
    mazeDFS(start);

	// Set border of maze to walls
    for (int i = 0; i < rows; i++)
    {
		maze[i][0] = 1;
        maze[i][cols - 1] = 1;
    }
	for (int j = 0; j < cols; j++)
    {
        maze[0][j] = 1;
		maze[rows - 1][j] = 1;
    }

	// Display maze
    displayMaze(maze, rows, cols);
}

//find a tour
enum directions {N, NE, E, SE, S, SW, W, NW};
//定義結構
struct position1{
    int x;
	int y;
    directions dir;
};
struct offsets{
    int dx;
    int dy;
}offset_move[8] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};

struct position1 *Stack;
void push1(position1 data)
{
	if (top == MAZE_SIZE_MAX*MAZE_SIZE_MAX - 1)
		ShowMessage("Stack is full");
    else
		Stack[++top] = data;
}
position1 pop1()
{
    if (top == -1)
		ShowMessage("Stack is empty");
    else
		return Stack[top--];
}


int maze1 [30][30];
int mark1 [30][30] = {0};
void path(int m, int p, int flag)
{
	Stack = new struct position1 [m*p];
	//初始化堆疊
	top = -1;

	//設置起點
    int i, j, u, v;
	directions d;
	position1 step;
	step.x = 1;
	step.y = 1;
	step.dir = E;
	push1(step);
	if (flag == 1)
	{
	mark[1][1] = 1;
	while(top != -1)
	{
		step = pop1();
		i = step.x;
		j = step.y;
		d = step.dir;
		while(d <= 7)
		{
			u = i + offset_move[d].dx;
			v = j + offset_move[d].dy;

			if (u == m-2 && v == p-2)
			{
				//找到終點，輸出路徑
				mark[u][v] = 1;
				while(top != -1)
				{
					step = pop1();

				}

				return;
			}

            if (maze[u][v] == 0 && mark[u][v] == 0)
			{
				// 記錄路徑
				mark[u][v] = 1;
				step.x = i;
				step.y = j;
                step.dir = static_cast<directions>(d+1);
				push1(step);
				i = u;
				j = v;
				d = N;
			}
			else
			{
				d = static_cast<directions>(d+1);
			}
		 }
	}
	ShowMessage("no path found");
	}
	else if (flag == 2)
	{
	mark1[1][1] = 1;
	 while(top != -1)
	 {
		step = pop1();
		i = step.x;
		j = step.y;
		d = step.dir;
		while(d <= 7)
		{
			u = i + offset_move[d].dx;
			v = j + offset_move[d].dy;

			if (u == m-2 && v == p-2)
			{
				//找到終點，輸出路徑
				mark1[u][v] = 1;
				while(top != -1)
				{
					step = pop1();

				}

                return;
			}

			if (maze1[u][v] == 0 && mark1[u][v] == 0)
			{
				// 記錄路徑
				mark1[u][v] = 1;
				step.x = i;
				step.y = j;
				step.dir = static_cast<directions>(d+1);
				push1(step);
				i = u;
                j = v;
				d = N;
			}
			else
			{
				d = static_cast<directions>(d+1);
			}
		 }
	}
	ShowMessage("no path found");

	}
}


void __fastcall TForm5::Button1Click(TObject *Sender)
{
    rows = StrToInt(Edit1->Text);
	cols = StrToInt(Edit2->Text);
	generateMaze(rows+2, cols+2);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button2Click(TObject *Sender)
{
	rows = StrToInt(Edit1->Text);
	cols = StrToInt(Edit2->Text);
	path(rows+2, cols+2, 1);
	Form5->StringGrid2->RowCount = rows+2;
	Form5->StringGrid2->ColCount = cols+2;
	for (int i=0; i<rows+2; i++)
		for (int j=0; j<cols+2; j++)
			if (mark[i][j] == 1)
				Form5->StringGrid2->Cells[j][i] = 3;
			else
				Form5->StringGrid2->Cells[j][i] = maze[i][j];
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button3Click(TObject *Sender)
{
     FILE *fp; // Define fp as a pointer pointing to some file (with data type FILE) in HD
	 String out;
	 int m, n, i, j;
	 AnsiString infile;
	 if (OpenDialog1->Execute())
	 {
		infile = OpenDialog1->FileName;
		fp = fopen(infile.c_str(), "r+");
		fscanf(fp, "%d %d", &m, &n);
		Form5->Memo1->Lines->Add("(m, n)="+IntToStr(m)+", "+IntToStr(n));
	 for (i=0; i<m; i++)    // Reda in m*n 0/1/2's into maze[][]
		 for (j=0; j<n; j++)
			 fscanf(fp, "%d", &maze1[i][j]);

	 fclose(fp);
	 Form5->StringGrid3->RowCount = m;
	 Form5->StringGrid3->ColCount = n;
	 for (i=0; i<m; i++)
		 for (j=0; j<n; j++)
			 Form5->StringGrid3->Cells[j][i] = maze1[i][j];

	 }
	 path(m, n, 2);
	 Form5->StringGrid4->RowCount = m;
	 Form5->StringGrid4->ColCount = n;
	 for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			if (mark1[i][j] == 1)
				Form5->StringGrid4->Cells[j][i] = 3;
			else
				Form5->StringGrid4->Cells[j][i] = maze1[i][j];
}
//---------------------------------------------------------------------------

