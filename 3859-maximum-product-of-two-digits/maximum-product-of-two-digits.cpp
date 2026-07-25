class Solution {
public:
    int maxProduct(int n) {
        int max = 0;
        vector<int> num ; 
        while( n > 0 ) {
            num.push_back(n % 10);
            n /= 10 ;
        }
        for(int i=0 ; i<(int)num.size()-1 ; i++) {
            for (int j = i + 1; j < (int)num.size(); j++) {
                int p = num[i] * num[j];
                if(p >= max){
                    max = p;
                }
            }
        }
        return max;
    }
};