#include<bits/stdc++.h>
using namespace std;

    vector<int> bfsofgraph(int V,vector<int> adj[]){
        vector<int> bfs;
        vector<int> visited(V+1,0);

        for(int i=1;i<=V;i++){
            if(visited[i]==0){
                queue<int> q;
                q.push(i);
                visited[i]=1;

                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    bfs.push_back(node);

                    for(auto it: adj[node]){
                        if(!visited[it]){
                            q.push(it);
                            visited[it]=1;
                        }
                    }
                }
            }
        }
        return bfs;
    }


int main(){
    int n,e;
    cin>>n>>e;
    vector<int> adj[n+1];

    for(int i=0;i<e;i++){
        int vertex1,vertex2;
        cin>>vertex1>>vertex2;
        adj[vertex1].push_back(vertex2);
        adj[vertex2].push_back(vertex1);
    }
    vector<int> bfs=bfsofgraph(n,adj);
    for(auto it:bfs){
        cout<<it<<" ";
    }

    return 0;
}