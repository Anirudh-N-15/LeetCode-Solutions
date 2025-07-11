class Solution {
public:
    using ll = long long;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<pair<ll,int>> rooms(n); //avail_time,meet_count
        sort(meetings.begin(),meetings.end());

        for(const auto & meet : meetings) {
            int start = meet[0], end = meet[1]; 
            ll minRoomAvailTime = LLONG_MAX;
            int minAvailTime = 0;
            bool foundRoom = false ;

            for(int i=0;i<n;i++){
                if(rooms[i].first <= start) {
                    foundRoom = true;
                    rooms[i].second++ ;
                    rooms[i].first = end;
                    break;
                }
                if(minRoomAvailTime > rooms[i].first){
                    minRoomAvailTime = rooms[i].first;
                    minAvailTime = i;
                }
            }

            if(!foundRoom) {
                rooms[minAvailTime].first += end - start ;
                rooms[minAvailTime].second++ ;
            }
        }
        int maxMeetingCount = 0, maxMeetingRoom = 0;
        for(int i = 0; i < n; i++) {
            if(rooms[i].second > maxMeetingCount) {
                maxMeetingCount = rooms[i].second;
                maxMeetingRoom = i;
            }
        }
        return maxMeetingRoom ;
    }
};