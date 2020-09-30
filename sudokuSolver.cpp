#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void prnt(vector<int> &board)
{
  for(int i = 0; i < board.size(); i++)
  {
    if(i%9 == 0 && i != 0)
      cout << endl;

    cout << board[i] << " ";
  }

  cout << endl;
}

bool insert(vector<int> &board, int ind, int num)
{
  // check row
  for(int i = (ind/9) * 9; i < ((ind/9) * 9) + 9; i++)
  {
    if(board[i] == num){
      return false;
    }
  }

  // check column
  for(int i = ind%9; i <= (ind%9) + 72; i=i+9)
  {
    if(board[i] == num){
      return false;
    }
  }

  // check subgrid
  int row = (((ind/9) / 3) * 3) * 9; // find index of the row that the subgrid is in
  int i = (((ind%9) / 3) * 3) + row; // find index of top left square of the subgrid

  for(int j = i; j < (i + 21); j=j+9)
  {
    for(int k = j; k < (j + 3); k++)
    {
      if(board[k] == num){
        return false;
      }
    }
  }

  return true;
}

void solve(vector<int> &board)
{
  for(int i = 0; i < board.size(); i++)
  {
    if(board[i] == 0)
    {
      for(int j = 1; j < 10; j++)
      {
        if(insert(board, i, j))
        {
          board[i] = j;
          solve(board);
          board[i] = 0;
        }
      }
      return;
    }
  }

  prnt(board);
  string x;
  cout << "\nEnter any key for more solutions ";
  cin >> x;
}

int main()
{
  fstream in;
  int x;
  vector<int> board;

  in.open("sudokuInput.txt");

  while(in >> x)
  {
    board.push_back(x);
  }

  in.close();

  solve(board);

  return 0;
}

