// https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

int Solution::fibsum(int n) {
    vector <int> fib;
 		fib.push_back(1);fib.push_back(1);      
 		for(int i=2;fib[i-1]<n;i++){
 			int val=fib[i-1]+fib[i-2];
 			fib.push_back(val);
		 }
		 int ans=0;
		 int size=fib.size();
		 size--;
		 while(n>0){
		 	while(fib[size]>n){       
		 		size--;
			 }                         
			 n=n-fib[size];
			 ans++;
		 }
		 return ans;
}
