class Solution {
public:

    vector<vector<int> > ans;

    void answer(int i,vector<int> arr,vector<int> temp )
    {
        if(i==arr.size())
        {
            ans.push_back(temp);
            return;
        }

        answer(i+1,arr,temp);

        temp.push_back(arr[i]);

        answer(i+1,arr,temp);

    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        if(nums.size()==0)return ans;

        vector<int> temp;
        answer(0,nums,temp);

            return ans;

    }
};
