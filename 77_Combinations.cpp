class Solution {
public:
    vector<vector<int>> ans;

    void answer(int curr,int n,int k,vector<int> temp)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=curr;i<=n;i++)
        {
            temp.push_back(i);
            answer(i+1,n,k,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int > temp;
         answer(1,n,k,temp) ;

        return ans;
    }
};
