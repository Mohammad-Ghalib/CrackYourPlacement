class Solution {
public:
    
    static bool compare(Job a, Job b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr, arr+n, compare);
        
        int maxDeadline = 0, jobsDone=0, totalProfit=0;
        for(int i=0; i<n; i++){ 
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        vector<int> deadline(maxDeadline+1, 0);
        
        for(int i=0; i<n; i++){
            for(int j=arr[i].dead; j>=1; j--){
                if(!deadline[j]){
                    jobsDone++;
                    totalProfit += arr[i].profit;
                    deadline[j] = 1;
                    break;
                }
            }
        }
        
        return {jobsDone, totalProfit};
    } 
};