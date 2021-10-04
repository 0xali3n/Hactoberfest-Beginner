# Find the Duplicate Number 

**Problem Statement** : Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, find this repeated number.


### First Approach :
**Intuition** : We can just keep a count of numbers appearing in the Array using a hash map (Dictionary in Python)and later we can go through the values of it and whichever key has count more than 1, return that key as answer.

**Code** :

~~~
def findDuplicate(nums):
  d={}                 # Create an empty dictionary
  for i in nums:
    if d.get(i):       # Searching for an element, if it is found, increase its count
      d[i]+=1
    else:
      d[i]=1           # If the element is not found, set count of that element to 1
  for k,v in d.items():
    if v>1:
      return k         # Go through the values of dictionary, if value > 1, return the key as answer
  ~~~
          
          
### Complexity :
**Time Complexity**  : O(n)  
**Space Complexity** : 0(n)

### Can we reduce Space complexity to O(1) ?

### Second Approach :
**Intuition** : Use two pointers the fast and the slow. The fast one goes forward two steps each time, while the slow one goes only step each time. They must meet the same item when slow==fast. In fact, they meet in a circle, the duplicate number must be the entry point of the circle when visiting the array from nums[0]. Next we just need to find the entry point. We use a point(we can use the fast one before) to visit form begining with one step each time, do the same job to slow. When fast==slow, they meet at the entry point of the circle.

**Code** :

~~~
def findDuplicate(nums):
  slow = nums[0]
  fast = nums[nums[0]]

  while slow!=fast:
      slow=nums[slow]
      fast=nums[nums[fast]]
  fast=0
  while slow != fast:
      slow=nums[slow]
      fast=nums[fast]
  return slow
 ~~~
  
  ### Complexity :
**Time Complexity**  : O(n)  
**Space Complexity** : 0(1)
