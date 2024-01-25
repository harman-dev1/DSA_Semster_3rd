def index_of_minimum_no(arr, start,end):
    mini = 0
    i = 0
    lenght = len(arr)
    while i < lenght:
        if mini < arr[i]:
            mini = arr[i]   
        i +=1
        
    i = start
    count = 0
    while i <= end:
        if mini > arr[i]:
            mini = arr[i]   
            count = i
        i +=1

    return count

arr = []
n = int(input("Enter no of elements :"))
i = 0
while i < n:
    no = int(input("Enter Number :"))
    arr.append(no)
    i +=1
start  = int(input("Enter Starting index :"))
end = int(input("Enter Ending index :"))
print(index_of_minimum_no(arr,start,end))