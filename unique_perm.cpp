Question
Given an array arr[] of length n. Find all possible unique permutations of the array.

Input: 
n = 3
arr[] = {1, 2, 1}
Output: 
1 1 2
1 2 1
2 1 1
  
  
  Solution
  vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        // code here
          vector<int> vec = arr;
        vector< vector< int > > v;
        sort( arr.begin(), arr.end() );
        sort( vec.begin(), vec.end(), reverseSort );
        v.push_back(arr);
        
        while( arr != vec )
        {
            (next_permutation( arr.begin(), arr.end() ) );
            v.push_back(arr);
        }
        
        return v;
    
    }
