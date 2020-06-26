class Solution {
public:

    vector<vector<int> > ans;

    void answer(int i,vector<int> arr,int tar,vector<int> temp)
    {
        if(tar==0)
        {
            for(int i=0;i<ans.size();i++)
            {
                if(ans[i]==temp)return;
            }

            ans.push_back(temp);

            return;
        }

        if(i==arr.size())return ;

        if(arr[i]<=tar)
        {
            temp.push_back(arr[i]);
            answer(i+1,arr,tar-arr[i],temp);
            temp.pop_back();
        }
        answer(i+1,arr,tar,temp);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        if(target==0 || candidates.size()==0)return ans;

        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        answer(0,candidates,target,temp);

        return ans;
    }
};
