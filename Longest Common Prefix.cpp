class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        vector<int> answer;
    
    for (int i = 0; i < words.size(); ++i) {
        vector<string> remaining;
        
        for(int j = 0; j < words.size(); ++j) {
            if(j != i){
                remaining.push_back(words[j]);
            }
        }

         if(remaining.empty()) {
            answer.push_back(0);
            continue;
        }
        
        int max_count = 1;
        string max_word = remaining[0];
        bool tie = false;
        int curr_count = 1;

        for (int k = 1; k < remaining.size(); ++k) {
            if(remaining[k] == remaining[k-1]) {
                curr_count++;
            } else {
                curr_count = 1;
            }
            
            if(curr_count > max_count) {
                max_count = curr_count;
                max_word = remaining[k];
                tie = false;
            } else if (curr_count == max_count && remaining[k] != max_word) {
                tie = true;
            }
        }
        
        if(tie) {
            answer.push_back(0);
        } else {
            answer.push_back(max_word.size());
        }
    }
    return answer;
    }
};
