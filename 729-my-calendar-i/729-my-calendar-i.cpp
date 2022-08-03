class MyCalendar {
public:
    unordered_map<int, int>bookings;
    MyCalendar() {
    }
    bool book(int start1, int end1) {
            for(auto [start2, end2] : bookings) 
                if(!(start1 >= end2 || start2 >= end1))   
        // if neither of above condition is satisfied, there exists an intersection
                    return false; 
            bookings[start1] = end1;
        // no intersection found, so insert the new slot and return true
            return true;
        }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */