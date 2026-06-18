class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (30 * hour) + (minutes * 0.5) ;
        double minuteAngle = minutes * 6 ;
        double ans = abs(hourAngle - minuteAngle) ;
        return min(ans, 360.00 - ans) ;
    }
};