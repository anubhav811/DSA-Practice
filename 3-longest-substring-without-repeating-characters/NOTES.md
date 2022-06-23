**Optimised  Approach 1**
We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point of substring while ‘right’ will maintain the endpoint of the substring.’ right’ pointer will move forward and check for the duplicate occurrence of the current element if found then ‘left’ pointer will be shifted ahead so as to delete the duplicate elements.
​
[Demonstration](https://lh4.googleusercontent.com/aMQirjlxaiN8IBm5FckhirAltc-njpQsvsRoj_0fah3eoebaBZOgDRm6GGJ0o7ZC5jlsEG7RZSVwqc668ackaIRqsBWU5zwNqWthQhkXgp8CMjh0Cd-vjfPQpBsA_QSISzkmoMR1)
​
​
**Optimised  Approach 2**
In this approach, we will make a map that will take care of counting the elements and maintaining the frequency of each and every element as a unity by taking the latest index of every element.
​
[Demonstration](https://lh5.googleusercontent.com/GH56iZCr9JG8MDLCJCHsAIpc6-PHczH8nvyrqyE3q2KFxCqtktxoG5gwIZOs53EnkNWfx349AIIe_foy3qY2P2HM7Tw5cHeOTcQimnRrS2a9NoX4jGIi0Ff8MqujUTdt8VnG9aSK)
​
​
​
​