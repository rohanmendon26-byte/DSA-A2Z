class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int negetivecount=0;
        int negetivemax=INT_MIN;
        int positivemin=INT_MAX;
        bool haszero=false;
        long long product=1;
        
        for(int x:arr){
            if(x==0)
              haszero=true;
           else if(x<0){
                negetivecount++;
                negetivemax=max(negetivemax,x);
                product*=x;
            }
            else{
                positivemin = min(positivemin, x);
                product*=x;
            }
        }
        
        if(negetivecount==0){
            if(haszero)
              return 0;
             return positivemin;
        }
        
        if(negetivecount%2==1){
            return product;
        }
        
        product/=negetivemax;
        
        return product;
    }
};


// Input: arr[] = [1, 2, 3]
// Output: 1
// Explanation: The possible subset products are 1, 2, 3, 2, 3, 6, and 6. The minimum product is 1, obtained by selecting the subset [1].

// Input: arr[] = [4, -2, 5]
// Output: -40
// Explanation: The minimum product is -40, obtained by selecting the subset [4, -2, 5].