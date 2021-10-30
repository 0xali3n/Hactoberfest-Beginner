no = int(input("Enter the number of Numbers: " ))
list_no = []
for i in range no:
  n = int(input("Enter Number: "))
  list_no.append(n)
sum = 0
for x in list_no:
  sum = sum + x
print("The sum of all entered numbers is: ", sum) 
