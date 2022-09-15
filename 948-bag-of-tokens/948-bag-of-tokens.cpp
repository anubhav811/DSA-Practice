class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        sort(tokens.begin(),tokens.end());
        
        int i = 0 ;
        int j = tokens.size()-1;
        
        while(i<j){
            if(power>=tokens[i]){
                power-=tokens[i];
                i++;
                score++;
            }
            else if(score>=1 && power+tokens[j]>=tokens[i]){
                power += tokens[j];
                j--;
                score--;
            }
            else break;
            
        }
        while(i < j + 1 && power >= tokens[i]) // when gap remains, then for that
            {
                power -= tokens[i];
                i++;
                score++;
            }
    return score;
    }
    
};