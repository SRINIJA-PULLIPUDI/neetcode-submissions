class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(groupSize==1) return true;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        sort(hand.begin(), hand.end());
        for(int i=0;i<hand.size();i++){
            if(pq.empty()) pq.push({hand[i],1});
            else{
                pair<int,int> top = pq.top();
                if(top.first==hand[i]){
                    pq.push({hand[i],1});
                }
                else if((top.first+1)==hand[i]){
                    pq.pop();
                    top.first = hand[i];
                    top.second+=1;
                    if(top.second<groupSize) pq.push(top);
                }else return false;
            }
        }if(pq.empty()) return true;
        else return false;
    }
};
