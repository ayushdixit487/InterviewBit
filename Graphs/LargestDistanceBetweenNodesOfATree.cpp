pair<int, int> process(queue<pair<int, int> >& q, vector<int>& visited, unordered_map<int, vector<int> >& x){
    // Typical BFS with keeping track of the longest distance and farthest element.
    int maxi = INT_MIN, farthest = 0;
    while(!q.empty()){
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();
        if(distance > maxi){
            maxi = distance;
            farthest = node;
        }
        visited[node] = 1;
        for(int i = 0; i < x[node].size(); i++){
            if(!visited[x[node][i]]){
                visited[x[node][i]] = 1;
                q.push({x[node][i], distance+1});
            }
        }
    }
    return {maxi, farthest};
}

int Solution::solve(vector<int> &A) {
    // Base Case
    if(A.size() <= 1)return 0;
    vector<int> visited(A.size(), 0);
    
    unordered_map<int, vector<int> > x;
    x.clear();
    
    for(int i = 0; i < A.size(); i++){
      
        if( A[i] != -1){
            x[A[i]].push_back(i);
            x[i].push_back(A[i]);
        }
    }
  
    queue<pair<int, int> > q;
    q.push({0, 0});
    visited[0] = 1;
    int farthest = process(q, visited, x).second;

    vector<int> vis(A.size(), 0);
    q.push({farthest, 0});
    vis[farthest] = 1;
    return process(q, vis, x).first;
}
