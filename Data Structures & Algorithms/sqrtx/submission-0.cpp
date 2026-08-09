#define ll long long
class Solution {
public:
    int mySqrt(int x) {
        ll l=-1, r = 1e6;
        while((r-l)>1){
            ll mid = (l+r)/2;
            if(mid*mid<=x) l=mid;
            else r=mid;
        }
        return l;
    }
};