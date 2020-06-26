class Solution {
public:

    vector<vector<int>> ans;

    set<vector<int> > s;

    void findAnswer(vector<int> arr,int tar,int n, vector<int> temp)
    {
        if(tar==0)
        {
            if(s.find(temp)==s.end())
            {
                ans.push_back(temp);
                s.insert(temp);
            }
            return;
        }

        if(n==0)return;

        if(arr[n-1]<=tar)
        {
            temp.push_back(arr[n-1]);
            findAnswer(arr,tar-arr[n-1],n,temp);
            temp.pop_back();
        }

        return findAnswer(arr,tar,n-1,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        if(candidates.size()==0 || target==0)return ans;

        vector<int> temp;

        sort(candidates.begin(),candidates.end());

        findAnswer(candidates,target,candidates.size(),temp);

        return ans;
    }
};
