vector<vector<long long int>> matrixMultiply(vector<vector<long long int>> a, vector<vector<long long int>> b, int mod){
    int n, m, o;
    if(a[0].size() == b.size()){
        n = a.size(), m = b[0].size(), o = a[0].size();
    }else{
        return {{-1, -1}};
    }

    vector<vector<long long int>> ans(n, vector<long long int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < o; k++){
                ans[i][j] = (ans[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }

    return ans;
}