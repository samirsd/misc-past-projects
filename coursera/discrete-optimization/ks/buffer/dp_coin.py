# def coinChange(centsNeeded, coinValues):
#     minCoins = [[0 for j in range(centsNeeded + 1)]
#                 for i in range(len(coinValues))]
#     minCoins[0] = range(centsNeeded + 1)
#
#     # print(coinValues)
#     # print(minCoins)
#     for i in range(1, len(coinValues)):
#         for j in range(0, centsNeeded + 1):
#             if j < coinValues[i]:
#                 minCoins[i][j] = minCoins[i - 1][j]
#             else:
#                 minCoins[i][j] = min(minCoins[i - 1][j],
#                                      1 + minCoins[i][j - coinValues[i]])
#     # print(minCoins)
#     return minCoins[-1][-1]
#
#
# print(coinChange(30, [25, 10, 1, 5]))

#
# def fib_naive(n):
#     if n <= 2:
#         return 1
#     else:
#         return fib(n - 1) + (n - 2)


# memo = {}
#
#
# def fib(n):
#     if n in memo:
#         return memo[n]
#     if n <= 2:
#         f = 1
#     else:
#         f = fib(n - 1) + fib(n - 2)
#     memo[n] = f
#     # print(memo)
#     return f


memo = {}

def fib(n):
    for k in range(1,n+1):
        if k <= 2:
            f = 1
        else:
            f = memo[k-1] + memo[k-2]
        memo[k] = f
    return memo[n]




#
# w = []
#
# v = 0
#
#
# def O(k, j):
#     if j == 0:
#         return 0
#     if w[j] <= k:
#         return max(O(k, j - 1), v + O(k - w[j], j - 1))
#     else:
#         return O(k, j - 1)

#
# allocate array for memo;
#  set all elements of memo to zero;
#
#  fib(n) {
#     if n is 1 or 2, return 1;
#     if memo[n] is not zero, return memo[n];
#     memo[n] = fib(n-1) + fib(n-2);
#     return memo[n];
#  }
#

#
#
# def fib(n):
#     if n <= 2:
#         return 1
#     if memo[n] is not 0:
#         return memo[n]
#     else:
#         memo[n] = fib(n - 1) + fib(n - 2)
#     return memo[n]



print(fib(5000000))
# print(fib_naive(5))
