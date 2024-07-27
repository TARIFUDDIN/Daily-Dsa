class Solution{
  public:
  int solve(string str , int l , int h , vector<vector<int>>&dp){
     if (l >= h) {
            return 0;
        }
      
      if(dp[l][h] != -1){
          return dp[l][h];
      }
      
      if(str[l] == str[h]){
          dp[l][h] = solve(str , l+1 , h-1 , dp);
      }
      else{
          dp[l][h] = 1+min(solve(str , l+1 , h,dp) , solve(str , l , h-1 , dp));
      }
      return dp[l][h];
  }
    int countMin(string str){
      int n = str.length();
      vector<vector<int>>dp(n , vector<int>(n+1 , -1));
      return solve(str , 0 , n-1 , dp);
    }
};