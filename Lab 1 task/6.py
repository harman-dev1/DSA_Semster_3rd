def SumIterative(number):
    sum = 0
    while number != 0:
        remainder = int(number % 10)
        sum = sum + remainder
        number = int(number / 10)
    print(sum)
    
def SumRecursive(number):
    sum = 0
    remainder = int(number % 10)
    sum = sum + remainder
    number = int(number / 10)
    if number == 0:
        return remainder
    return sum + SumRecursive(number) 
    
    
    
    
    
    
SumIterative(1524)
print(SumRecursive(1544))