import heapq
class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.foods = foods
        self.cuisines = cuisines
        self.ratings = ratings
        
        self.idx = dict()
        for i in range(len(foods)) :
            self.idx[foods[i]] = i

        self.dict_que = defaultdict(list)
        for i in range(len(foods)) :
            heapq.heappush(self.dict_que[cuisines[i]], (-ratings[i], foods[i], i))
        
    def changeRating(self, food: str, newRating: int) -> None:
        i = self.idx[food]
        self.ratings[i] = newRating
        heapq.heappush(self.dict_que[self.cuisines[i]], (-self.ratings[i], self.foods[i], i))

    def highestRated(self, cuisine: str) -> str:
        while True :
            rating, food, i = self.dict_que[cuisine][0]
            rating = -rating
            if rating != self.ratings[i] :
                heapq.heappop(self.dict_que[cuisine])
            else :
                break
        
        return self.dict_que[cuisine][0][1]
        


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
