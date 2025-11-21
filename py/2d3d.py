import numpy as np
# arr2d=np.array([[10,20,30],[40,50,60],[70,80,90]])
# print("First row : ",arr2d[0])
# print("Second row: ",arr2d[:,0])
# print("Sub arrays(first 2 rows): ",arr2d[0:2])
arr=np.array([[[1,2,3,4],[5,6,7,8]],
            [[9,10,11,12],[13,14,15,16]]])
print("Shape: ",arr.shape)
print("All blocks,1st row: ",arr[:,0,:])
print("All blocks,row 2: ",arr[:,1,:])
print("Column Skiped by 1: ",arr[:,:,::2])
