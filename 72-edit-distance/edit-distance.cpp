class Solution {
public:
    int n, m;
    int solve(string &word1, string &word2, int i, int j, vector<vector<int>> &dp) {
        if(i == n) {
            return m - j;
        }
        if(j == m) {
            return n - i;
        }
         if (dp[i][j] != -1){
           return dp[i][j];
        }
        if(word1[i] == word2[j]) {
            return solve(word1, word2, i + 1, j + 1,dp);
        }
        int deleteChar = solve(word1, word2, i + 1, j,dp);
        int insertChar = solve(word1, word2, i, j + 1,dp);
        int replaceChar = solve(word1, word2, i + 1, j + 1,dp);
        return dp[i][j]= 1 + min({
            deleteChar,
            insertChar,
            replaceChar
        });
    }
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(word1, word2, 0, 0,dp);
    }
};