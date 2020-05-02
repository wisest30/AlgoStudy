from collections import Counter
class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        table_item_counter = Counter()
        food_set = set()
        table_set = set()
        for order in orders :
            custormerName, tableNumber, foodItem = order
            tableNumber = int(tableNumber)
            key = (tableNumber, foodItem)
            table_item_counter[key] += 1
            food_set.add(foodItem)
            table_set.add(tableNumber)
        
        food_list = sorted(food_set)
        table_list = sorted(table_set)

        ret = []
        ret.append(["Table"] + food_list)
        for tableNumber in table_list :
            row = [str(tableNumber)]
            for foodItem in food_list :
                key = (tableNumber, foodItem)
                row.append(str(table_item_counter[key]))
            ret.append(row)
        return ret

