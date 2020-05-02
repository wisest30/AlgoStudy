from collections import defaultdict


class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        tables = defaultdict(lambda: defaultdict(int))
        menu = set()
        
        for customer, n, food in orders: 
            menu.add(food)
            tables[int(n)][food] += 1
                
        menu = sorted(menu)
        display = [[str(n)] + [str(tables[n].get(m, 0)) for m in menu] for n in sorted(tables)]
        return [['Table'] + menu] + display
