class Solution {
public:

    int ans=0;

    bool canPlace(int r,int c,int n, vector<string> board)
    {
        //col check

        for(int i=0;i<r;i++)
        {
            if(board[i][c]=='Q')return false;
        }

        int i=r-1,j=c-1;

        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')return false;

            i--;
            j--;
        }

        i=r-1,j=c+1;

        while(i>=0 && c<n)
        {
            if(board[i][j]=='Q')return false;

            i--;
            j++;

        }

        return true;
    }

    void answer(int r,int n ,vector<string> board)
    {
        if(r==n)
        {
            ans++;
            return ;
        }

        for(int i=0;i<n;i++)
        {
            if(canPlace(r,i,n,board))
            {
                board[r][i]='Q';
                answer(r+1,n,board);
                board[r][i]='.';
            }
        }

        return;
    }
    int totalNQueens(int n)
    {
        ans=0;

        string a="";
        for(int i=0;i<n;i++)
        {
            a.push_back('.');
        }

        vector<string> board;

        for(int i=0;i<n;i++)
        {
            board.push_back(a);
        }

        answer(0,n,board);

        return ans;
    }
};
