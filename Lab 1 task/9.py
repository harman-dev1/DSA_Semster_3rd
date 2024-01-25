def PalindromRecursive(word):
     end = len(word)-1
     start = 0
     if end <= 0:    
         return "Palindrome"
     
     if word[start]  == word[end] :
         string = word[start+1:end]         
         return PalindromRecursive(string)
         
     if word[end]  != word[start] :
        return "No it's not"
    
    
    
print(PalindromRecursive("abcdefghhgfedcba"))
