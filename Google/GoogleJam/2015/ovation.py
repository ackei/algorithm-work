t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
  n, m = [s for s in input().split(" ")]  # read a list of integers, 2 in this case
  n = int(n)
  ans = 0
  s = int(m[0])
  for j in range(1,n+1):
      if s < j:
          ans += j-s
          s += j - s
      s += int(m[j])
  print("Case #{}: {}".format(i, ans))

