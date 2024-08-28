class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long m=0, n=0, mul=10, mod=1e9 + 7;
        
        while(first || second){
            if(first){
                m = m*mul + (long long)first->data;
                m %= mod;
                first = first->next;
            }
            if(second){
                n = n*mul + (long long)second->data;
                n %= mod;
                second = second->next;
            }
        }
        
        return (m*n)%mod;
    }
};