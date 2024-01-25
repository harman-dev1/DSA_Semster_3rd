
#row wise sum...........
def row_sum(arr):
    row_sum_arr = []
    i = 0
    
    
    while i < len(arr):
        sum = 0
        j = 0
        while j < len(arr):
            sum = sum + arr[i][j]
            j = j+1
        i = i+1
        row_sum_arr.append((sum))
    return (row_sum_arr)

#column wise sum.........

def column_sum(arr):
    i = 0
    colm_arr = []
    
    while i < len(arr):
        j = len(arr)-1
        clm_sum = 0
        while j >= 0:
            clm_sum = clm_sum + arr[j][i]
            j  = j - 1 
        colm_arr.append(clm_sum)
        i = i+1
        
    return (colm_arr)


# starting point
arr = [
       [1,13,13],
       [5,11,6],
       [4,4,9]
]

row_arr = (row_sum(arr))
print("Row Wise :")
for a in row_arr:
    print(a)
    
print("Columns Wise :", column_sum(arr))