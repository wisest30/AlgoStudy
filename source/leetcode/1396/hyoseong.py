class UndergroundSystem:

    def __init__(self):
        self.A = dict()
        self.SE_sum = dict()
        self.SE_cnt = dict()

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.A[id] = [[stationName, t]]

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        self.A[id].append([stationName, t])
        key = self.A[id][0][0] + "_" + self.A[id][1][0]
        if key not in self.SE_sum :
            self.SE_sum[key] = 0
            self.SE_cnt[key] = 0
        
        self.SE_sum[key] += self.A[id][1][1] - self.A[id][0][1]
        self.SE_cnt[key] += 1

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        key = startStation + "_" + endStation
        return self.SE_sum[key] / self.SE_cnt[key]
