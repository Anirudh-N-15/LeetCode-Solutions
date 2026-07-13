class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        string startHr, startMin, startSec ;
        string endHr, endMin, endSec ;

        int sHr, sMin, sSec ;
        int eHr, eMin, eSec ;

        startHr = startTime.substr(0,2) ;
        sHr = stoi(startHr) ;
        startMin = startTime.substr(3,2) ;
        sMin = stoi(startMin) ;
        startSec = startTime.substr(6,2) ;
        sSec = stoi(startSec) ;

        endHr = endTime.substr(0,2) ;
        eHr = stoi(endHr) ;
        endMin = endTime.substr(3,2) ;
        eMin = stoi(endMin) ;
        endSec = endTime.substr(6,2) ;
        eSec = stoi(endSec) ;

        int totalStart =0,totalEnd = 0;

        totalStart = sHr * 3600 + sMin * 60 + sSec ;
        totalEnd = eHr * 3600 + eMin * 60 + eSec ;

        return totalEnd - totalStart ;

        
    }
};