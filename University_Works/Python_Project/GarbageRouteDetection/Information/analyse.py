import json

# 讀取JSON檔案
with open('抵達時間預估.json', 'r', encoding='utf-8') as file:
    data = json.load(file)

# 提取所有車牌號碼
car_licenses = [item['car_licence'] for item in data['data']]

# 找出不同的車牌號碼
unique_car_licenses = set(car_licenses)

# 計算不同車牌號碼的數量
unique_count = len(unique_car_licenses)

print(f"不一樣的車牌號碼有 {unique_count} 種")

with open('car_licenses.txt', 'w', encoding='utf-8') as file:
    file.write(f"不一樣的車牌號碼有 {unique_count} 種")
    for license in unique_car_licenses:
        file.write(f"{license}\n")
