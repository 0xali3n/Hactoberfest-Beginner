'''
Input Format

The first line contains the number of items, .
The next  lines contains the item's name and price, separated by a space.

Constraints


Output Format

Print the item_name and net_price in order of its first occurrence.

Sample Input
>>9
>>BANANA FRIES 12
>>POTATO CHIPS 30
>>APPLE JUICE 10
>>CANDY 5
>>APPLE JUICE 10
>>CANDY 5
>>CANDY 5
>>CANDY 5
>>POTATO CHIPS 30

Sample Output
BANANA FRIES 12
POTATO CHIPS 60
APPLE JUICE 20
CANDY 20
'''


from collections import OrderedDict

items = int(input())
total_list = OrderedDict()
# for item in range(0,items):
for item in range(0,items):
    lst_item = list(input().split())
    item_name_lst = lst_item[0:-1]               #select all item in list accept last item
    item_name = " ".join(item_name_lst)          #Convert the list in string
    net_price = lst_item[-1]
    if item_name in total_list:
        total_list[item_name] = total_list[item_name] + int(net_price)
    else:
        total_list[item_name] = int(net_price)
for food in total_list:
    print(food, total_list[food])