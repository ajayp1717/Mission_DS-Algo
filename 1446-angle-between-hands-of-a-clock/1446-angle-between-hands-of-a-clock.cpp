class Solution {
public:
    double angleClock(int hour, int minutes) {

        double hourAngle=(hour%12)*30 + (double)minutes*(0.5);
        double minAngle=minutes*6;
        
        double ans=abs(hourAngle-minAngle);   
            
        return min(ans,360.0 - ans);
    }
};