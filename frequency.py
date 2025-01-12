strings="123234589190180"
diction={}
for char in strings:
    if char in diction:
        diction[char]+=1
    else:
        diction[char]=1
print(diction)

tupp=(1,2,3,4,5,6,(5,6,7))
print(tupp.count(5))

for i in range(6,0,-1):
    for k in range(6,i,-1):
        print(" ",end="")
    for j in range(i):
        print(" * ",end="")
    print("\n")