#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;
typedef pair<int,int> p;
class Graph{
    int V;
    list <p> *adj;
    public :
    Graph(int v){
        this->V=v;
        adj = new list<p>[v];
    }
    void addEdge(int u, int v,int w){
        adj[u-1].push_back(make_pair(v-1,w));
        adj[v-1].push_back(make_pair(u-1,w));
    }
    void dijikstra(int src){
        priority_queue <p,vector<p>,greater<p>> pq;
        vector<int> dist(V,INF);
        src-=1;
        pq.push(make_pair(0,src));
        dist[src] = 0;
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            list <p>::iterator it;
            for(it=adj[u].begin();it!=adj[u].end();it++)
            {
                int v=it->first;
                int weight=it->second;
                //cout<<v<<" weight is  "<<weight<<endl;
                if(dist[v]>dist[u]+weight){
                    dist[v]=dist[u]+weight;
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
        
        for(int i =0;i<V;i++)
        {
            if(dist[i]==INF){
                cout<<-1<<" ";
            }else if(dist[i]!=0){
                cout<<dist[i]<<" "; 
            }else{
               
            }
           
        }
        cout<<endl;
    }
};
int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        cin >> n >> m;
        Graph g=Graph(n);
        for(int a1 = 0; a1 < m; a1++){
            int u;
            int v;
            cin >> u >> v;
            g.addEdge(u,v,(int)6);
        }
        int s;
        cin >> s;
        g.dijikstra(s);
    }
    return 0;
}
