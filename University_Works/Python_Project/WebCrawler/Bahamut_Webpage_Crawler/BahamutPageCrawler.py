import requests
from bs4 import BeautifulSoup
import time, json
import os
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys

send_headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36"}
options = webdriver.ChromeOptions()
options.add_experimental_option('excludeSwitches', ['enable-logging'])


UID = 'BahaID' #巴哈帳號
PW = 'BahaPswd' #巴哈密碼
URL = 'https://forum.gamer.com.tw/C.php?bsn=60076&snA=4672961'
floor_target = 55056

driver = webdriver.Chrome(chrome_options=options)
driver.get('https://user.gamer.com.tw/login.php')
driver.find_element(By.NAME, "userid").send_keys(UID)
driver.find_element(By.NAME, "password").send_keys(PW)
input('登入完畢請按enter')
time.sleep(0.5)
os.system('cls')


with open('BahaPosts.json',mode='r', encoding='utf8') as jfile:
    DATAS = json.load(jfile)
last_floor = DATAS["record_floor"]
URL += f'&page={int((last_floor-1)/20)+1}'
driver.get(URL)

while True:

    Posts = driver.find_element(By.CSS_SELECTOR,"div[id=BH-master]").find_elements(By.CSS_SELECTOR,'section[id*="post_"]')
    post_number = len(Posts)
    print(post_number,'則文章 於第',int((last_floor-1)/20)+1,'頁\n')
    for floor in Posts:
        new_record = False
        now_floor = int(floor.find_element(By.CSS_SELECTOR,'a[data-floor]').text[:-2])
        print('現在',now_floor,' 紀錄',last_floor)
        if last_floor >= now_floor:
            print('skip')
            continue
        print(f'第{now_floor}整在讀取...\n')

        info = floor.find_element(By.CLASS_NAME,"c-article__content")
        content = info.text
        #info = info.find_elements(By.TAG_NAME,"div")
        #for paragraph in info:
        #    content += paragraph.text
        print(content)

        if '#測試' not in content:
            continue
        print('found\n')
        new_record = True
        post_time = floor.find_element(By.CSS_SELECTOR,'a[data-mtime]').get_attribute('data-mtime')
        post_author = floor.find_element(By.CLASS_NAME,'username').text
        folder = {
            "floor":f"{now_floor}",
            "Author":f"{post_author}",
            "Time":f"{post_time}",
            "content":f"{content}"
        }


        with open('DC bot/crawler_test/posts.json','r+') as file:
            data = json.load(file)
            data["data_to_send"].append(folder)
            data["data_count"] += 1
            data["record_floor"] = now_floor
            file.seek(0)
            json.dump(data,file,ensure_ascii=True,indent=4)
    
    last_floor = now_floor
    
    action = ActionChains(driver)
    action.send_keys(Keys.F8)
    action.perform()

    time.sleep(30)