vowels = [ 'a', 'e', 'o', 'i', 'u', 'A','E','I','O','U' ]
strs = input("Enter Word: ")
word = [word for word in strs for vowel in vowels if word == vowel]
result = "".join(word)
print(result)