w, h = 2, 10003
dp = [[0 for x in range(w)] for y in range(h)]

n = int(input())

dp[0][0] = dp[0][1] = 1

for i in range(1, n):
	dp[i][0] += dp[i - 1][1]
	dp[i][1] += dp[i - 1][1] + dp[i - 1][0]

print(dp[n - 1][1] + dp[n - 1][0])