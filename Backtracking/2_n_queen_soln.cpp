#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<vector<int>> &board, int row, int col)
    {

        // checking the current column
        for (int i = row - 1; i >= 0; i--)
        {
            if (board[i][col])
                return false;
        }

        // checking the left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j])
                return false;
        }

        // checking the right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
        {
            if (board[i][j])
                return false;
        }
        return true;
    }

    void fillPosition(vector<vector<int>> &board, vector<vector<int>> &ans, vector<int> &temp, int row)
    {
        if (row == board.size())
        {
            ans.push_back(temp);
            return;
        }
        for (int col = 0; col < board.size(); col++)
        {

            if (isPossible(board, row, col))
            {
                board[row][col] = 1;
                temp.push_back(col + 1);
                fillPosition(board, ans, temp, row + 1);
                temp.pop_back();
                board[row][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n)
    {

        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> ans;
        vector<int> temp;
        fillPosition(board, ans, temp, 0);
        return ans;
    }
};
