class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int Customers=0;
        for( char c:customers){
            if(c=='Y')Customers++;
        }
        
        int prefSum=0;
        int minP=Customers;
        int ans=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='N')prefSum++;

            int noCustP=prefSum;
            int CustP=Customers-(i+1-prefSum);
            int P=noCustP+CustP;
            if(P<minP){
                minP=P;
                ans=i+1;
            }
        }
       return ans; 
    }
};