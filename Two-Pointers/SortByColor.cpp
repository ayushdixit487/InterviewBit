 void Solution::sortColors(vector<int>& A) {
        int n = A.size();
    int s =0;
    int e= n-1;
    int i =0;
    while(i<=e){
        if(A[i]==0){
        swap(A[i],A[s]);
        s++;    
        }
        else if(A[i]==2){
            swap(A[i],A[e]);
            e--;
            continue;
            
        }
        i++;
    }
    }
