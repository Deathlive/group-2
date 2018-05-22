def Palindrome(word):
    if word[0] == word[-1]:
        word = word[1:-1]
        if len(word) <= 1:
            return True
        return Palindrome(word)
    else:
        return False

spam = input("Enter word: ")
print(Palindrome(spam))