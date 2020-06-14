void validIPs(string S,string sub,int index ,vector<string> &res){
    if(index ==4 || S.size()==0 ){
        if(index ==4 && S.size()==0 ){
        res.push_back(sub.substr(0, sub.size()-1) );
    }
      return;
    }
    //case 1 choose 1 
    validIPs(S.substr(1),sub+S.substr(0,1)+".",index+1, res);
    //case 2 choose 2
    if(S.size()>1 && S[0]!='0'){
        validIPs(S.substr(2),sub+S.substr(0,2)+".",index+1, res);
    }
    if(S.size()>2 && stoi(S.substr(0,3))<=255  && S[0]!='0'){
        validIPs(S.substr(3),sub+S.substr(0,3)+".",index+1, res);
    }
    
}
vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> res;
    if(A.size()<4 || A.size()>12)
    return res;
    
     validIPs(A,"",0,res);
     return res;
}
