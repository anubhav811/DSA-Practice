**Approach 1**: We can simply sort the array and run a for loop to find the longest consecutive sequence
Time Complexity: We are first sorting the array which will take O(N * log(N)) time and then we are running a for loop which will take O(N) time. Hence, the overall time complexity will be O(N * log(N)).
Space Complexity: The space complexity for the above approach is O(1) because we are not using any auxiliary space
​
**Approach 2**:
We will first push all are elements in the HashSet. Then we will run a for loop and check for any number(x) if it is the starting number of the consecutive sequence by checking if the HashSet contains (x-1) or not. If ‘x’ is the starting number of the consecutive sequence we will keep searching for the numbers y = x+1, x+2, x+3, ….. And stop at the first ‘y’ which is not present in the HashSet. Using this we can calculate the length of the longest consecutive subsequence
​
Time Complexity: The time complexity of the above approach is O(N) because we traverse each consecutive subsequence only once.
Space Complexity: The space complexity of the above approach is O(N) because we are maintaining a HashSet.
​
​