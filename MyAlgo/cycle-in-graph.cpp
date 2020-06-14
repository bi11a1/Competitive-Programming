/// Given a directed graph find out if a cycle exists
/// Returns boolean value 0/1
/// Starts at parameter node
/// For undirected graph to work must check if x is parent node or not
vector< int > adj[MX];   // Adjacency list representation of the directed graph
int nodeColor[MX];  // Holds state of the current node
bool cycle(int node){
     nodeColor[node]=1;  // Color=Gray/In process
     for(auto x:adj[node]){
          //For undirected graph if x==par then continue
          if(nodeColor[x]==0 && cycle(x)) return 1;     // Color=White/Not traversed
          else if(nodeColor[x]==1) return 1;
     }
     nodeColor[node]=2;  // Color: Black/Completed
     return 0;
}
