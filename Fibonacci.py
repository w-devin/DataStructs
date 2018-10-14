import numpy as np
import datetime

# 1, 1, 2, 3, 5, 8, 13, 21, 34, 55

def matrix(n):
	ans = np.eye(2)
	C = np.array([[1, 1], [1, 0]])
	
	for x in range(n - 1):
		ans = ans.dot(C)
		
	return int(ans[0][0])


def array(n):
	ans = [1, 1]
	
	if n <= 2:
		return 1
		
	for i in range(n - 2):
		ans.append(sum(ans[-2:]))
		
	return ans[-1]
	
	
def twoVar(n):
	a, b = 1, 1
	
	if n <= 2:
		return 1;
	
	for i in range(n - 2):
		b = a + b
		a = b - a
	
	return b
	
	
def recursion(n):
	if n <= 2:
		return 1
		
	return recursion(n - 1) + recursion(n - 2)
	

if __name__ == '__main__':
	n = 30
	
	startTime = datetime.datetime.now()
	print(matrix(n))
	endTime = datetime.datetime.now()	
	print('---matrix----')
	print(endTime - startTime)
	
	startTime = datetime.datetime.now()
	print(array(n))
	endTime = datetime.datetime.now()	
	print('---array----')
	print(endTime - startTime)
	
	startTime = datetime.datetime.now()
	print(twoVar(n))
	endTime = datetime.datetime.now()	
	print('---twoVar----')
	print(endTime - startTime)
	
	startTime = datetime.datetime.now()
	print(recursion(n))
	endTime = datetime.datetime.now()	
	print('---recursion----')
	print(endTime - startTime)
	
