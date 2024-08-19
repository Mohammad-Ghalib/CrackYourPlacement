class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        set<string> words;
        for(auto it : wordList){
            words.insert(it);
        }

        if(words.find(endWord) == words.end()) return 0;

        while(!q.empty()){
            string curr = q.front().first;
            int num = q.front().second;
            q.pop();

            string temp = curr;

            for(int i=0; i<curr.size(); i++){
                curr = temp;
                for(int j=0; j<26; j++){
                    curr[i] = char(j + 'a');

                    if(curr == endWord) return num+1;

                    if(words.find(curr) != words.end()){
                        q.push({curr, num+1});
                        words.erase(curr);
                    }
                }
            }
        }

        return 0;
    }
};