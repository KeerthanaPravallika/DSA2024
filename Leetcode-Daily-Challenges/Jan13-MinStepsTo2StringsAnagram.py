'''

Link : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/
You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

 

Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

'''

class Solution:
    def minSteps(self, s: str, t: str) -> int:

        minSteps = 0

        setT = set(t)
        setS = set(s)

        for let in setT:
            if t.count(let) - s.count(let) > 0:
                minSteps += t.count(let) - s.count(let)
        return minSteps

        

        
