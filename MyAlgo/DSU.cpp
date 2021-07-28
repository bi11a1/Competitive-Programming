///DSU - Disjoint Set Union
//Check carefully no_of_nodes
//DSU(int no_of_nodes) constructor needs to be called during initialization
class DSU{
  vector<int> parent;
 public:
  DSU(){}
  DSU(int no_of_nodes){
    parent.resize(no_of_nodes+1);
    for(int i=0; i<=no_of_nodes; ++i) parent[i]=i;
  }
  int find_parent(int node){
    if(node!=parent[node]) parent[node]=find_parent(parent[node]);
    return parent[node];
  }
  void merge_node(int u, int v){
    int par_u=find_parent(u), par_v=find_parent(v);
    parent[par_u]=par_v;
  }
};
