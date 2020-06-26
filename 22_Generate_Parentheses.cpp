class Solution {
public:
    vector<string> ans;

    void generate(int open,int close,int n,string temp)
    {
        if(open==n && close==n)
        {
            ans.push_back(temp);
            return;
        }

        if(open<n)
        {
            temp.push_back('(');
            generate(open+1,close,n,temp);
            temp.pop_back();
        }

        if(close<open)
        {
            temp.push_back(')');
            generate(open,close+1,n,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        if(n==0)return ans;
        generate(0,0,n,"");

        return ans;

    }
};
