#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>

using namespace std;

class Code
{
private:
    static vector<int> bestSumMemo(int targetNum, const vector<int>& arr, map<int, vector<int>>& memo)
    {
        if(targetNum == 0) return {};
        if(targetNum < 0) return {-1};
        if(memo.find(targetNum) != memo.end())
        {
            return memo[targetNum];
        }

        vector<vector<int>> validresult;
        for(int i : arr)
        {
            int remainder = targetNum - i;
            vector<int> s = bestSumMemo(remainder, arr, memo);
            if(s.empty() || s[0] != -1)
            {
                s.push_back(i);
                validresult.push_back(s);
            }
        }
        if(validresult.empty()) return {-1};

        int index = 0;
        int max = validresult[0].size();
        for(int i = 1; i < validresult.size(); ++i)
        {
            if(validresult[i].size() < max)
            {
                max = validresult[i].size();
                index = i;
            }
        }
        memo[targetNum] = validresult[index];
        return validresult[index];
    }
public:
    static vector<int> bestSumMemo(int targetNum, const vector<int>& arr)
    {
        map<int, vector<int>> m;
        return bestSumMemo(targetNum, arr, m);
    }
};

int main()
{
    int value = 600;
    vector<int> s = {2, 3, 4, 5, 6, 7};
    vector<int> result = Code::bestSumMemo(value, s);
    for(int i : result)
        cout << i << " ";
    return 0;
}
