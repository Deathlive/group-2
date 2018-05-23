def add_tags(tag, sti):
    result = "<" + tag + ">" + sti + "</" + tag + ">"
    return result

st = input("Enter word: ")
tg = input("Enter tags: ")

value = add_tags(tg, st)
print(value)