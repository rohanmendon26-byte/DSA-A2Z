
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3]={0};
        for(int x:stones){
            cnt[x%3]++;
        }

        if(cnt[0]%2==0){
            return min(cnt[1],cnt[2])>0;
        }

        return abs(cnt[1]-cnt[2])>2;
    }
};






// Input: stones = [2,1]
// Output: true
// Explanation: The game will be played as follows:
// - Turn 1: Alice can remove either stone.
// - Turn 2: Bob removes the remaining stone. 
// The sum of the removed stones is 1 + 2 = 3 and is divisible by 3. Therefore, Bob loses and Alice wins the game.

// Input: stones = [2]
// Output: false
// Explanation: Alice will remove the only stone, and the sum of the values on the removed stones is 2. 
// Since all the stones are removed and the sum of values is not divisible by 3, Bob wins the game.