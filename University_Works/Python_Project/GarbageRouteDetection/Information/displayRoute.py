import re
import pandas as pd
import folium

# 解析txt文件並提取數據
with open('KEH5761Record.txt', 'r', encoding='utf-8') as file:
    lines = file.readlines()

data = []
for line in lines:
    match = re.search(r'\[Time:(.*?), Location:.*?, \(x,y\):\((.*?),(.*?)\)\]', line)
    if match:
        timestamp = match.group(1)
        latitude = float(match.group(3))
        longitude = float(match.group(2))
        data.append([timestamp, latitude, longitude])

# 將數據轉換為DataFrame
df = pd.DataFrame(data, columns=['timestamp', 'latitude', 'longitude'])

# 建立Folium地圖
m = folium.Map(location=[df['latitude'][0], df['longitude'][0]], zoom_start=13)

# 繪製路徑
points = list(zip(df['latitude'], df['longitude']))
folium.PolyLine(points, color='blue').add_to(m)

# 為每個座標點添加標記（可選）
for idx, row in df.iterrows():
    folium.Marker([row['latitude'], row['longitude']], popup=row['timestamp']).add_to(m)

# 保存地圖到HTML文件
html_file = 'garbage_truck_route.html'
m.save(html_file)
