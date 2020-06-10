// https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &A) {
    // Base case     
    if(A.size() <= 1)return 0;
    vector<int> v1 (A.size(), 0), v2(A.size(), 0);
    
    // Fill the first array with minimum from the left
    v1[0] = A[0];
    for(int i = 1 ; i < A.size(); i++)v1[i] = min(v1[i-1], A[i]);
    
    // Fill the second array with maximum from the right
    v2[A.size()-1] = A[A.size()-1];
    for(int i = A.size()-2 ; i >= 0 ; i--)v2[i] = max(v2[i+1], A[i]);
    
    
    int i = 0, j = 0;
    int ans = -1;
    while(j < A.size() && i < A.size()){
        if(v2[j] >= v1[i]){
            if(j-i > ans){
                ans = j-i;
            }
            j = j + 1;
        }else i = i + 1;
    }
    return ans;
}
