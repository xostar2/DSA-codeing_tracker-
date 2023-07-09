bool obs(int i , int j , int n ,int m , vector<vector<int>>&grid){
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1){
            return true;
        }
        return false;
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        int time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        if(fresh==0)return 0;
        
        while(!q.empty()){
            int size=q.size();
            int temp=0;
            
            while(size!=0){
                pair<int,int>x=q.front();
                q.pop();
                int x1=x.first;
                int x2=x.second;
                
                int arr1[4]={1,-1,0,0};
                int arr2[4]={0,0,1,-1};
                
                for(int i=0;i<4;i++){
                    int n1=arr1[i]+x1;
                    int n2=arr2[i]+x2;
                    
                    if(obs(n1,n2,n,m,grid)){
                        grid[n1][n2]=2;
                        temp++;
                        q.push({n1,n2});
                    }
                }
                size--;
            }
            if(temp>0)time++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    time=0;
                    break;
                }
            }
        }
        
        return (time==0)?-1:time;
        
    }
};