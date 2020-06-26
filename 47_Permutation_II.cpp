class Solution {
public:

    vector<vector<int>> ans;
    set<vector<int> > s;

    void permute(int i,vector<int> arr)
    {
        if(i==arr.size())
        {
            // for(int j=0;j<ans.size();j++)
            // {
            //     if(arr==ans[j])return;
            // }

            if(s.find(arr)==s.end())
            {
                 ans.push_back(arr);
                s.insert(arr);
            }

            return;
        }

        for(int j=i;j<arr.size();j++)
        {
            swap(arr[i],arr[j]);
            permute(i+1,arr);
            swap(arr[i],arr[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        if(nums.size()==0)return ans;

        permute(0,nums);

        return ans;
    }
};
