***Approach 1 :  Brute Force***
Nested for loops .
Add i and j and compare to target value.
Time : O(n^2) , Space : O(1)
***Approach 2 : Use maps and store indices***
Make a map store indices
Now using formula
*target-x=y*
where x is the value of element (key of map) . which we get while traversing
If the calculated value of y exists inside the map (as a key) then , current value of x & y from the map is the result
otherwise just put the value in map .=>  map[value in array] = its index
Time: O(n) , Space:O(n)
***Appoach 3: Two Pointer approach***
Make an array of pairs with values and their index.
Suitable for sorted array (ascending)
If array not sorted , then approach 2 is best but if sorted then approach 3
Make two pointers : start and end
add elements being pointed by start and end
If the sum exceeds target decrement end
if the sum is less than target increment start
finally when sum==target , start and end are the result
Time: O(nlogn) , Space:O(n)
​