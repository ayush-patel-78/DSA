
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> st;
        if(digits.size()==0) return st;
        unordered_map<char, vector<string>> mpp;
        mpp['2'].push_back("a");
        mpp['2'].push_back("b");
        mpp['2'].push_back("c");
        mpp['3'].push_back("d");
        mpp['3'].push_back("e");
        mpp['3'].push_back("f");
        mpp['4'].push_back("g");
        mpp['4'].push_back("h");
        mpp['4'].push_back("i");
        mpp['5'].push_back("j");
        mpp['5'].push_back("k");
        mpp['5'].push_back("l");
        mpp['6'].push_back("m");
        mpp['6'].push_back("n");
        mpp['6'].push_back("o");
        mpp['7'].push_back("p");
        mpp['7'].push_back("q");
        mpp['7'].push_back("r");
        mpp['7'].push_back("s");
        mpp['8'].push_back("t");
        mpp['8'].push_back("u");
        mpp['8'].push_back("v");
        mpp['9'].push_back("w");
        mpp['9'].push_back("x");
        mpp['9'].push_back("y");
        mpp['9'].push_back("z");
        vector<string> temp;
        for (int j = 0; j < mpp[digits[0]].size(); j++)
        {
            string s = mpp[digits[0]][j];
            cout<<s<<" ";
            temp.push_back(s);
        }
        if(digits.length() == 1)return temp;
        int i = 1;
        while (i <= digits.size() - 1)
        {
            vector<string> temp2 = temp;
            temp.clear();
            for (int j = 0; j < temp2.size(); j++)
            {
                for (int k = 0; k < mpp[digits[i]].size(); k++)
                {
                    string str = temp2[j];
                    str += mpp[digits[i]][k];
                    temp.push_back(str);
                }
            }
            i++;
        }
        return temp;
    }
};
