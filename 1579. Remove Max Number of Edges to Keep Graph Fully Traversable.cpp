class Solution {
public:
    int find(int i,vector<int> &par){
        if(par[i] == -1){
            return i;
        }
        // Path compression optimization
        return par[i] = find(par[i],par);
        
    }
    bool union_set(int x,int y,vector<int> &par,vector<int> &rnk){
        int s1 = find(x,par);
        int s2 = find(y,par);
        
        if(s1 != s2){
            // Union by rank optimization
            if(rnk[s1] > rnk[s2]){
                par[s2] = s1;
                rnk[s1] += rnk[s2];
            }
            else{
                par[s1] = s2;
                rnk[s2] += rnk[s1];
            }
            return true;
        }
        return false;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        sort(edges.begin(),edges.end(),[](vector<int> &a,vector<int> &b){
            return a[0] > b[0]; 
        });
        
        int rem = 0;
        
        vector<int> parAlice(n,-1);
        vector<int> parBob(n,-1);
        vector<int> rnkAlice(n,1);
        vector<int> rnkBob(n,1);
        
        for(int i=0;i<edges.size();i++){
            if(edges[i][0] == 3){
                bool fg1 = union_set(edges[i][1]-1,edges[i][2]-1,parAlice,rnkAlice);
                bool fg2 = union_set(edges[i][1]-1,edges[i][2]-1,parBob,rnkBob);
                if(fg1==false && fg2==false){
                    // Both Alice and Bob are already connected to the same node,
                    // so remove this edge.
                    rem += 1;
                }
            }
            else if(edges[i][0] == 2)
            {
                bool fg2 = union_set(edges[i][1]-1,edges[i][2]-1,parBob,rnkBob);
                if(fg2 == false){
                    // Bob is already connected to the same node, so remove this edge.
                    rem += 1;
                }
            }
            else{
                bool fg1 = union_set(edges[i][1]-1,edges[i][2]-1,parAlice,rnkAlice);
                if(fg1 == false){
                    // Alice is already connected to the same node, so remove this edge.
                    rem += 1;
                }
            }
        }
        
        int co1=0,co2=0;
        for(int i=0;i<n;i++){
            if(parAlice[i]==-1){co1++;}
            if(parBob[i]==-1){co2++;}
            // If the nodes can be connected then there will be only one parent in the parent array.
        }
        if(co1==1 && co2==1){return rem;}
        return -1;
    }
};
