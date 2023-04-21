# Assign Cookies
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Assume you are an awesome&nbsp;parent of <strong>N</strong> children&nbsp;and want to give your children some cookies out of given <strong>M</strong> cookies. But, you should give each child atmost one cookie.<br>
Each child<strong> i</strong> has a greed factor <strong>greed [ i ]</strong>, which is the minimum size of cookie that the child will be content with; and each cookie <strong>j</strong> has a size <strong>sz&nbsp;[ j ]</strong>. If <strong>sz [ j ] &gt;= greed [ i ]</strong>, we can assign the cookie<strong> j</strong> to the child<strong> i<sup>th</sup></strong>, and the child <strong>i</strong> will be content.<br>
Your goal is to <strong>maximize</strong> the number of your content children and return&nbsp;the maximum number.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<div style="--darkreader-inline-bgcolor:#222426; --darkreader-inline-bgimage:initial; --darkreader-inline-border-bottom:#3e4446; --darkreader-inline-border-left:#3e4446; --darkreader-inline-border-right:#3e4446; --darkreader-inline-border-top:#3e4446; background:#eeeeee; border:1px solid #cccccc; padding:5px 10px"><span style="font-size:18px"><strong>Input:</strong><br>
N = 3&nbsp;<br>
M = 2<br>
greed [ ] = {1, 2, 3}<br>
sz [ ] = {1, 1}<br>
<strong>Output: </strong>1<br>
<strong>Explanation:</strong>&nbsp;<br>
You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.</span><br>
<span style="font-size:18px">And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.<br>
You need to return&nbsp;1.</span></div>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<div style="--darkreader-inline-bgcolor:#222426; --darkreader-inline-bgimage:initial; --darkreader-inline-border-bottom:#3e4446; --darkreader-inline-border-left:#3e4446; --darkreader-inline-border-right:#3e4446; --darkreader-inline-border-top:#3e4446; background:#eeeeee; border:1px solid #cccccc; padding:5px 10px"><span style="font-size:18px"><strong>Input:</strong><br>
N = 2&nbsp;<br>
M = 3<br>
greed [ ] = {1, 2}<br>
sz [ ] = {1, 2, 3}<br>
<strong>Output: </strong>2<br>
<strong>Explanation:</strong>&nbsp;<br>
You have 2&nbsp;children and 3&nbsp;cookies. The greed factors of 2 children are 1, 2.</span><br>
<span style="font-size:18px">You have 3 cookies and their sizes are big enough to gratify all of the children.<br>
You need to output 2.</span></div>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>maxChildren()</strong>&nbsp;which takes the interger <strong>N</strong>, integer <strong>M</strong>&nbsp;and two integer array <strong>greed [ ] </strong>and <strong>sz [ ]&nbsp;</strong>as parameters and returns the maximum number of content children.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(max( NlogN , MlogM&nbsp;))<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤&nbsp; 5 * 10<sup>4</sup><br>
1 ≤ M&nbsp;≤&nbsp; 5 * 10<sup>4</sup><br>
1 ≤ greed [ i ] , sz [ i ]&nbsp;≤ 10<sup>9</sup></span></p>
</div>