import numpy as np
arr=np.array([[1, 2, 3],
                [4, 5, 6]])
print("Sum row wise:",np.sum(arr,axis=1))
print("Sum column wise:",np.sum(arr,axis=0))
print("Sum cumulative :",np.cumsum(arr,axis=1))
print("Max column wise:",np.max(arr,axis=0))
print("Min column wise:",np.min(arr,axis=0))