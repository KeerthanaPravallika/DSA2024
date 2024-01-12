'''
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
'''

class Solution:
    def halvesAreAlike(self, s: str) -> bool:

        str1 = s[:len(s)//2]
        str2 = s[len(s)//2:]

        print(str1,str2)
        cn1 = str1.count('a')+str1.count('e')+str1.count('i')+str1.count('o')+str1.count('u') +str1.count('A')+str1.count('E')+str1.count('I')+str1.count('O')+str1.count('U')

        cn2 = str2.count('a')+str2.count('e')+str2.count('i')+str2.count('o')+str2.count('u') +str2.count('A')+str2.count('E')+str2.count('I')+str2.count('O')+str2.count('U')

        if cn1 == cn2:
            return True
        return False
        
