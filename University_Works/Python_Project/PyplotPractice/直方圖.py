import matplotlib.pyplot as plt
import statistics as stat
import random

# 提供的數據

data = [] #建立一個空的陣列

for i in range(1,20):  #對1到20之間的每個整數 (range(a,b)是創建a~b的整數列)
    data.append(random.random()) #在data後面接上一個數字  數字的數值為 random.random()的值  (0~1的隨機數字)

# 取得數據
data_median = stat.median(data) #取得中位數
data_mean = stat.mean(data)     #取得平均數
data_mode = stat.mode(data)     #取得眾數

# 指定Bin值
bin_value = 3

# 繪製直方圖
plt.hist(data, bins=bin_value, edgecolor='black', log=True)

#median_data = 0.7829510755
#color = 'red'
#mean_data = 0.781948203
#color2 = 'yellow'

# 幻燕:平均
plt.axvline(data_mean, color='red', label='data Mean', linewidth=2)         #繪製中位數
plt.axvline(data_median, color='yellow', label='data Mean', linewidth=2)    #繪製平均數
plt.axvline(data_mode, color='navy', label='data Mode', linewidth=2)        #繪製眾數
# plt.axvline([該線的數值], color='navy'[顏色  請參考https://matplotlib.org/stable/_images/sphx_glr_named_colors_003.png] , label='data Mode' [顯示名稱] , linewidth=2 [線的粗細] )

plt.legend()

# 添加標題和標籤
plt.title('Histogram Example-2022月平均常態化差值植生指標(NDVI)')
plt.xlabel('NDVI')
plt.ylabel('Frequency')

plt.tight_layout()

# 顯示圖表
plt.show()