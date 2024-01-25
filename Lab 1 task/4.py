def sorted(arr):
    for i in range(len(arr) -1, 0,-1):
        for j in range(i):
            if arr[j] > arr[j+1]:
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
    return arr


#main function.........

arr = []
n = int(input("Enter no of elements :"))
i = 0
while i < n:
    no = int(input("Enter Number :"))
    arr.append(no)
    i +=1

print(sorted(arr))