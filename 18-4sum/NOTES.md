**Approach1**:
The main idea is to sort the array, and then we can think of searching in the array using the binary search technique. Since we need the 4 numbers which sum up to target. So we will fix three numbers as nums[i], nums[j] and nums[k], and search for the remaining (target – (nums[i] + nums[j] + nums[k])) in the array. Since we sorted the array during the start, we can apply binary search to search for this value, and if it occurs we can store them. In order to get the unique quads, we use a set data structure to store them.
​
**Approach 2**
*Intuition*: In the previous approach we fixed three-pointers and did a binary search to find the fourth. Over here we will fix two-pointers and then find the remaining two elements using two pointer technique as the array will be sorted at first.
​
*Approach*: Sort the array, and then fix two pointers, so the remaining sum will be (target – (nums[i] + nums[j])). Now we can fix two pointers, one front, and another back, and easily use a two-pointer to find the remaining two numbers of the quad. In order to avoid duplications, we jump the duplicates, because taking duplicates will result in repeating quads. We can easily jump duplicates, by skipping the same elements by running a loop.
​