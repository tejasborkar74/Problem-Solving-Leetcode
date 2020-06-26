class Solution {
public:
    vector<vector<int>> ans;

    void permutation(int i,vector<int> arr)
    {
        if(i==arr.size())
        {
            ans.push_back(arr);
            return;
        }

        for(int j=i;j<arr.size();j++)
        {
            swap(arr[i],arr[j]);
            permutation(i+1,arr);
            swap(arr[i],arr[j]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        if(nums.size()==0)return ans;
        permutation(0,nums);

        return ans;
    }
};
