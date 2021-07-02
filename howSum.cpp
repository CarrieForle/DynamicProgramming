#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> howSum(int targetNum, vector<int>& v, vector<int> result = {})
{
    if(targetNum < 0)
    {
        return {-1};
    }
    if(targetNum == 0)
    {
        return result;
    }
    for(int i : v)
    {
        cout << i;
        vector<int> x = howSum(targetNum-i, v, result);
        if(x.empty() || x.front() != -1)
        {
            x.push_back(i);
            return x;
        }
    }
    cout << "\n";
    return {-1};
}

vector<int> howSumMemo(int targetNum, vector<int>& v, vector<int> result = {})
{
    static map<int, vector<int>> memo;
    if(targetNum < 0)
    {
        return {-1};
    }
    if(targetNum == 0)
    {
        return result;
    }
    if(memo.find(targetNum) != memo.end())
    {
        return memo[targetNum];
    }
    for(int i : v)
    {
        //cout << i;
        vector<int> x = howSumMemo(targetNum-i, v, result);
        if(x.empty() || x.front() != -1)
        {
            x.push_back(i);
            memo[targetNum] = x;
            return x;
        }
    }
    //cout << "\n";
    memo[targetNum] = {-1};
    return {-1};
}

int main() {
    vector<int> v = {150, 406, 54, 60, 4, 504, 6, 45, 46};

    auto result = howSumMemo(465, v);
    if(result.empty())
        cout << "[]";
    else if(result.front() == -1)
        cout << "null";
    else 
    {
        cout << "[ ";
        for(int i : result)
        {
            cout << i << " ";
        }
        cout << "]";
    }
    return 0;
}
