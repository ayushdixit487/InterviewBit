// https://www.interviewbit.com/problems/binary-representation/

string Solution::findDigitsInBinary(int A) {
    stringstream ss;
    
    if(A == 0){
        return "0";
    }
    
    while(A){
        ss << A%2;
        A = A/2;
    }
    
    string ans = ss.str();
    
    for(int i = 0; i < ans.size()/2; i++){
        char temp = ans[i];
        ans[i] = ans[ans.size()-1-i];
        ans[ans.size()-1-i] = temp;
    }
    
    return ans;
    
}
