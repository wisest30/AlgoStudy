class Solution:
    def countRectangles(self, rectangles: List[List[int]], points: List[List[int]]) -> List[int]:
        for i in range(len(points)) :
            points[i].append(i)

        rectangles.sort()
        points.sort()
        
        cnts = [0] * 101
        for r in rectangles :
            cnts[r[1]] += 1

        ret = [0] * len(points)
        i = j = 0
        while i < len(rectangles) and j < len(points) :
            if rectangles[i][0] < points[j][0] :
                cnts[rectangles[i][1]] -= 1
                i += 1
            else :
                for y in range(points[j][1], 101) :
                    ret[points[j][2]] += cnts[y]
                j += 1
        
        return ret
