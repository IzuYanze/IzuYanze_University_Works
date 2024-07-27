import matplotlib.pyplot as plt
import statistics as stat
import random

# 提供的數據

dataA = [] #陣列A
dataB = [] #陣列B
for i in range(1,20):  #對1到20之間的每個整數 (range(a,b)是創建a~b的整數列)
    dataA.append(random.random()) #在data後面接上一個數字  數字的數值為 random.random()的值  (0~1的隨機數字)
    dataB.append(random.random()) #在data後面接上一個數字  數字的數值為 random.random()的值  (0~1的隨機數字)


# plot
fig, ax = plt.subplots()
VP = ax.boxplot([dataA,dataB])


plt.show()