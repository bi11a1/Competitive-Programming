// Tutorial: https://codeforces.com/blog/entry/68138
// Finding bridge/articulation point usign DFS tree

int chk[MX], up[MX], depth[MX];

void bridge(int node){
     chk[node]=1;
     up[node]=-1;   // Not counting parent edge as back-edge
     for(auto child:adj[node]){
          if(chk[child]){
               if(depth[node]<depth[child]) up[node]--;  // Downward edge
               else if(depth[node]>depth[child]) up[node]++;  // Upward edge
               continue;
          }
          depth[child]=1+depth[node];
          bridge(child);
          up[node]+=up[child];
     }

     if(depth[node]>1 && up[node]==0){
          ///TODO: Found a bridge
     }
}
