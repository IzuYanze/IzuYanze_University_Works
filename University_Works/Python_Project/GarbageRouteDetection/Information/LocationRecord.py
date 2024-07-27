import requests
import time
from datetime import datetime

#target = information[]

#KEH-5761
#KEB-6876

result = None
oldresult = None
while datetime.now().time().hour < 20 :
    data = requests.get('https://api.kcg.gov.tw/api/service/Get/aaf4ce4b-4ca8-43de-bfaf-6dc97e89cac0')
    information = data.json()

    result = None
    for item in information['data']:
        if item['car'] == "KEH-5761":
            result = f'[Time:{item["time"]}, Location:{item["location"]}, (x,y):({item["x"]},{item["y"]})]\n'
            break
    
    if result != oldresult:
        print(result)

        with open("KEH5761Record.txt","a",encoding='utf8') as outfile:
            outfile.write(result)
            outfile.close()
    else:
        print('checked')
    oldresult = result
    time.sleep(30)


#with open("LocationByTime.json", "w", encoding='utf8') as outfile:
#   json.dump(information, outfile, ensure_ascii=False)