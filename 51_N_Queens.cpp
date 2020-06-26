class Solution {
public:

    vector<vector<string>> ans;

    bool canPlace(int r,int c,vector<string> board,int n)
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

        while(i>=0 && j<n)
        {
            if(board[i][j]=='Q')return false;

            i--;
            j++;
        }

        return true;


    }

   void answer(int r,int n,vector<string> board)
    {
       if(r==n)
       {
           ans.push_back(board);

           return;
       }

        for(int i=0;i<n;i++)
        {
            if(canPlace(r,i,board,n))
            {
                board[r][i]='Q';

                answer(r+1,n,board);

                //if(success)return true;

                board[r][i]='.';
            }
        }

       return ;
    }

    vector<vector<string>> solveNQueens(int n)
    {
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
