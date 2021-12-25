class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        n = len(recipes)
        ret = []
        for i in range(n) :
            ingredients[i] = set(ingredients[i])
            for s in supplies :
                if s in ingredients[i] :
                    ingredients[i].remove(s)
            if not ingredients[i] :
                ret.append(recipes[i])
        
        check = ret.copy()
        while check :
            new_check = []
            for i in range(n) :
                if not ingredients[i] :
                    continue
                for c in check :
                    if c in ingredients[i] :
                        ingredients[i].remove(c)
                if not ingredients[i] :
                    ret.append(recipes[i])
                    new_check.append(recipes[i])
            check = new_check
        
        return ret
