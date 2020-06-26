class Solution {
public:

    int Find(int a)
    {
        if(a>=0 && a<3)return 0;

        if(a>=3 && a<6)return 3;

        return 6;
    }

    bool canPlace(vector<vector<char>> board,int r,int c,int x)
    {
        char num=x+'0';

        //row col check
        for(int i=0;i<9;i++)
        {
            if(board[r][i]==num)return false;

            if(board[i][c]==num)return false;
        }

        int row=Find(r);
        int col=Find(c);

        for(int i=row;i<row+3;i++)
        {
            for(int j=col;j<col+3;j++)
            {
                if(board[i][j]==num)return false;
            }
        }

        return true;


    }

   bool solve(vector<vector<char>>& board,int r,int c)
    {
        if(r==9)return true;

        if(c==9)
        {
            return solve(board,r+1,0);
        }

        if(board[r][c]!='.')
        {
            return solve(board,r,c+1);
        }
        else
        {
            for(int i=1;i<=9;i++)
            {
                if(canPlace(board,r,c,i))
                {
                    board[r][c]=i+'0';

                    bool success=solve(board,r,c+1);

                    if(success)return true;

                    board[r][c]='.';
                }
            }
        }

       return false;

    }
    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board,0,0);
    }
};
