#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


int main() {
class Solution {
public:
    string longestPalindrome(string s) {
        vector <vector<int>> dp(s.length(),vector<int>(s.length(),0));
        // 当只有一个字符的时候，肯定是回文字符串
        for (int i = 1; i < s.length(); ++i) {
            dp[i][i]=1;
        }
        int longest = 1;
        int result[]={0,0};

        for (int i=2; i <= s.length(); ++i) {
            for (int j=0 ; j+i<s.length(); j+=i) {
                if(i==2){
                    dp[j][j+1]=s[j]==s[j+1];
                }
                dp[j][j+i-1]=dp[j+1][j+i-2] && s[j]==s[j+i-1];

                if(dp[j][j+i-1] && i>=longest){
                    result[0]=j;
                    result[1]=j+i-1;
                }
            }

        }

        cout<< s.substr(result[0], result[1]);
    }
};
return 0;
}
