Approach 1 : Naive . using maxDepth function to find lh and rh
TC : O(N^2)  . The maxDepth functions are increasing the complexity to N^2 .
Approach 2: We have to find a way so that our maxDepth functions can be removed.
The optimal approach will be to make makeDepth function in such a way that along with the height of tree , it will also let us know if its balanced tree or not .
So to achieve that , if our tree is balanced we will return its height and if its not balanced we will return -1