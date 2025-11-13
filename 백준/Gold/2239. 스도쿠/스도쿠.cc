#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> blanks;
bool finished = false;

bool isValid(int y, int x, int num) 
{

    for (int i = 0; i < 9; i++) 
    {
        if (board[y][i] == num) return false;
    }


    for (int i = 0; i < 9; i++) 
    {
        if (board[i][x] == num) return false;
    }


    int sy = (y / 3) * 3;
    int sx = (x / 3) * 3;
    for (int i = sy; i < sy + 3; i++) 
    {
        for (int j = sx; j < sx + 3; j++) 
        {
            if (board[i][j] == num) return false;
        }
    }

    return true;
}


void dfs(int idx) 
{
    if (idx == blanks.size()) 
    {
        finished = true;
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) cout << board[i][j];
            cout << "\n";
        }
        return;
    }

    int y = blanks[idx].first;
    int x = blanks[idx].second;

    for (int num = 1; num <= 9; num++) 
    {
        if (isValid(y, x, num)) 
        {
            board[y][x] = num;
            dfs(idx + 1);
            if (finished) return;
            board[y][x] = 0;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    for (int i = 0; i < 9; i++) 
    {
        string row;
        cin >> row;
        for (int j = 0; j < 9; j++) 
        {
            board[i][j] = row[j] - '0';
            if (board[i][j] == 0)
                blanks.push_back({ i, j });
        }
    }

    dfs(0);
}
