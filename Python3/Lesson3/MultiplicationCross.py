colours = [ "red", "green", "yellow", "blue" ] 
things = [ "house", "car", "tree" ] 
result = [(color, thing) for color in colours for thing in things]
print(result)