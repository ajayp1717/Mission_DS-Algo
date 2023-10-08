class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int passes=tickets[k];
        int ans=0;
        for(int i=0;i<k;i++){
            if(tickets[i]<passes)ans+=tickets[i];
            else ans+=passes;
        }
        for(int i=k;i<tickets.size();i++){
            if(tickets[i]<passes)ans+=tickets[i];
            else ans+=(passes-1);

        }

        return ans+1;
    }

};