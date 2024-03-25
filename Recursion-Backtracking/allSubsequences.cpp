#include <iostream>
#include <vector>
using namespace std;
// time complexity of this algorithm is O(n^3)
void allSubsequences(string s, string temp, vector<string> &ans)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                temp += s[k];
            }
            ans.push_back(temp);
            temp = "";
        }
    }
}
// using recursion
// time complexity : O(n)
void allSubsequencesR(string s, string temp, int i, vector<string> &ans)
{
    if (i == s.length())
    {
        ans.push_back(temp);
        return;
    }
    // including current character in the sequence
    temp += s[i];
    allSubsequencesR(s, temp, i + 1, ans);
    temp.pop_back();
    // excluding current character from the
    allSubsequencesR(s, temp, i + 1, ans);
}
int main()
{
    vector<string> ans;
    string s = "abcd";
    //    allSubsequences(s,"",ans);
    allSubsequencesR(s, "", 0, ans);
    cout << "All possible subsequences are : \n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " " << endl;
    }
}