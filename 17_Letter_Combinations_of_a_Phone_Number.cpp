class Solution {
public:
    vector<string> ans;

    vector<string> freq={"","","abc","def","ghi","jkl","mno","pqrs","tuv", "wxyz"};

    void combinations(int i,string digit,string temp)
    {
        if(i==digit.length())
        {
            ans.push_back(temp);
            return;
        }
        int num= digit[i]-'0';
        string str=freq[num];

        for(int j=0;j<str.length();j++)
        {
            temp.push_back(str[j]);

            combinations(i+1,digit,temp);

            temp.pop_back();
        }


    }
    vector<string> letterCombinations(string digits)
    {
        if(digits.length()==0)return ans;
        combinations(0,digits,"");

        return ans;
    };
};
