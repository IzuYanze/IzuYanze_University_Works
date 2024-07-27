import requests
import json

data = requests.get('https://api.kcg.gov.tw/api/service/Get/aaf4ce4b-4ca8-43de-bfaf-6dc97e89cac0')

information = data.json()

#target = information[]

#KEH-5761


result = None
for item in information['data']:
    if item['car'] == "KEH-5761":
        result = f'[Time:{item["time"]}, Location:{item["location"]}, (x,y):({item["x"]},{item["y"]})]\n'
        break

# 顯示結果
print("找到車牌號碼為KEH-5761的資料:")
print(json.dumps(result, indent=4, ensure_ascii=False))

#with open("LocationByTime.json", "w", encoding='utf8') as outfile:
#    json.dump(information, outfile, ensure_ascii=False)