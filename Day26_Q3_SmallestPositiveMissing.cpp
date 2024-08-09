class Solution{
    public:
    
    int missingNumber(int arr[], int n) {
        
        for(int i=0;i<n;i++){
            while(arr[i]>0 && arr[i]<=n && arr[arr[i]-1]!=arr[i] ){
                int t=arr[arr[i]-1];
                arr[arr[i]-1]=arr[i];
                arr[i]=t;
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1) return i+1;
        }
        return n+1;
    }
};