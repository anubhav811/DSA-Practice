class Solution {
public:
        void solveRecur(int start, int target, vector < int > & arr, vector < vector < int >> & superSet, vector < int > & currSubset) {
  if (target == 0) {
    superSet.push_back(currSubset);
    return;
  }
  for (int i = start; i < arr.size(); i++) {
    if (i > start && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    currSubset.push_back(arr[i]);
    solveRecur(i + 1, target - arr[i], arr, superSet, currSubset);
    currSubset.pop_back();
  }
}
vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> superSet;
  vector < int > currSubset;
  solveRecur(0, target, candidates, superSet, currSubset);
  return superSet;
}

};