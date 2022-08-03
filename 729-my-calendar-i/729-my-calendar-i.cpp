class MyCalendar {
public:
    // Approach 2 : Use ordered set to reduce the comparison.
    
    set<pair<int, int>>bookings;
    MyCalendar() {
    }
    bool book(int start, int end) {    
       auto slot = bookings.lower_bound({start,end});
        if( slot != bookings.end()   && !(slot -> first >= end) ||   
            slot != bookings.begin() && !(prev(slot) -> second <= start)) 
			    return false;         
        bookings.insert({start, end});
        return true;
    }
    
    // APPROACH 1 :  Use map to store values then compare

    // unordered_map<int, int>bookings;
    // MyCalendar() {
    // }
    // bool book(int start1, int end1) {
    //         for(auto [start2, end2] : bookings) 
    //             if(!(start1 >= end2 || start2 >= end1))   
    //     // if neither of above condition is satisfied, there exists an intersection
    //                 return false; 
    //         bookings[start1] = end1;
    //     // no intersection found, so insert the new slot and return true
    //         return true;
    //     }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */