class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> diff(n+1,vector<int>(n+1,0));
        for(auto &k : q){
            int r1=k[0],c1=k[1],r2=k[2],c2=k[3];
            diff[r1][c1]+=1;
            diff[r1][c2+1]-=1;
            diff[r2+1][c1]-=1;
            diff[r2+1][c2+1]+=1;
        }
        //row wise(left --> right) prefix sum
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                diff[i][j]+=diff[i][j-1];
            }
        }
        //column wise(top --> bottom) prefix sum
        for(int j=0;j<n;j++){
            for(int i=1;i<n;i++){
                diff[i][j]+=diff[i-1][j];
            }
        }
        //final matrix
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=diff[i][j];
            }
        }
        return ans;
    }
};