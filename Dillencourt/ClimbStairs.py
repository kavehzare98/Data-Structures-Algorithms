n = 5

def climb(level, n):
	if level == n:
		return 1
	elif level > n:
		return 0
	else:
		return climb(level+1, n) + climb(level+2, n)

num = climb(0,n)
print(num)

def climbStairs(n):
	count = 0
	for i in range(n-1):
		left, right = i+1, i+2
		if left == n or right == n:
			count += 1
	return count

print("climbStairs Solution: ", climbStairs(n))

