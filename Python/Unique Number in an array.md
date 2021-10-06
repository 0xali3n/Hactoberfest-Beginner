# Find the element that appears once in an array where every other element appears twice

### Problem Statement:
Given an array of integers. All numbers occur twice except one number which occurs once. Find the unique number.  

**First Approach** : Create a hash table and store frequency of each element and finally return the key whose frequency is 1.

**Code** :

~~~
def uniqueNumber(nums):
  dict = {}
  for i in nums:
      if i not in dict:
          dict[i]=1
      else:
          dict[i]+=1
  for key,value in dict.items():
      if value==1:
          return key
~~~

**Time Complexity**  : O(n)  
**Space Complexity** : O(n)

### Can we reduce the Space Complexity to O(1)  

**Second Approach** : Just take XOR (Exclusive OR) of all numbers present in the array, the numbers which are appearing in pairs will cancel out each other and we will be left with the unique number in the array.

**Code** :
~~~
def uniqueNumber(nums):
  xor = 0
  for i in nums:
      xor=xor ^ i
  return xor
~~~

**Time Complexity**  : O(n)  
**Space Complexity** : O(1)
