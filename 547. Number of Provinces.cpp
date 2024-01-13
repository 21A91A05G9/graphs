class Solution {
public:
    void dfs(int node,vector<int>&ch,vector<int>adj[]){
        ch[node]=1;
        for(auto e:adj[node]){
            if(ch[e]==0){
                dfs(e,ch,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),cnt=0;
        vector<int>ch(n+1,0);
        ch[0]=0;
       
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(ch[i]==0){
                cnt++;
                ch[i]=1;
                dfs(i,ch,adj);
            }
        }
        return cnt;
    }
};
