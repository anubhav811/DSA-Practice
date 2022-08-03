class MyCalendar {
public:
    vector<pair<int,int>> bookings;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for (int i= 0 ; i<bookings.size();i++)
            if (max(bookings[i].first, start) < min(end, bookings[i].second)) 
                return false;
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */