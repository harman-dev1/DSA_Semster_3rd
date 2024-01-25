def SearchA(Arr, x) :
    i = 0
    length = len(Arr) - 1
    arr = []
    while i < length:
        if x == Arr[i]:
            arr.append(str(i) )
        i = i+1;
    return arr



Arr = [22,2,1,7,11,13,5,2,9]
x = int(input("Enter a number :"))
return_array = SearchA(Arr, x)
print(return_array)
print(10/0)