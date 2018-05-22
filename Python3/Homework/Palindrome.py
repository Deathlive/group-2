text=input("Enter text:")
if(text.lower()==text.lower()[::-1]):
    print("The text is a palindrome")
else:
    print("The text isn't a palindrome")
