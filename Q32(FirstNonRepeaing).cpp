// First non-repeating character in a stream

// Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

// NOTE:
// 1. You need to find the answer for every i (0 <= i < n)
// 2. In order to find the solution for every i you need to consider the string from starting position till ith position.

// Link : https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<int> vis(26 , 0);
		    vector<char> v;
		    string ans = "";
		    for(int i = 0;i<A.size() ; i++){
		        if((vis[A[i]-'a']) == 0){
		            v.push_back(A[i]);
		        }
		        vis[A[i]-'a']++;
		        int f = 0;
		        for(int j = 0 ;j<v.size() ; j++){
		            if(vis[v[j]- 'a'] == 1){
		                f = 1;
		                ans.push_back(v[j]);
		                break;
		            }
		        }
		        if(f == 0){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};

// Time Complexity: O(N)
// Auxiliary Space: O(1)