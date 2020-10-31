class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        n = len(ages)
        dp = [0] * n
        players = list(zip(ages, scores))
        players.sort()
        for idx, (_, score) in enumerate(players):
            dp[idx] = (score, score)
            for i in range(idx):
                if score >= dp[i][1]:
                    if score + dp[i][0] > dp[idx][0]:
                        dp[idx] = (score + dp[i][0], max(dp[idx][1], score))
                    elif score + dp[i][0] == dp[idx][0] and score < dp[idx][1]:
                        dp[idx] = (score + dp[i][0], score)
        max_score = max([score for score, _ in dp])
        return max_score
