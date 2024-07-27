import requests
from bs4 import BeautifulSoup
import time, json, datetime
import os
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys

send_headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36"}
options = webdriver.ChromeOptions()
options.add_experimental_option('excludeSwitches', ['enable-logging'])

URL = 'CCU LESSON WEBSITE' #中正大學選課系統

driver = webdriver.Chrome(chrome_options=options)
driver.get(URL)
rows = input("該課程在介面的的第幾排:\n") #刪掉
target = driver.find_element(By.XPATH,f'/html/body/center/form/table/tbody/tr[1]/th/table/tbody/tr[{str(rows+1)}]') #刪掉

while True:
    last = target.find_element(By.XPATH,'/th[3]/font').text #這邊放選課人數的Xpath
    print(last)
    
    if last != '0':
        target.find_element(By.XPATH, '/th[1]/input').click() #這邊放選課點勾勾的那個Xpath
        driver.find_element(By.XPATH,'/html/body/center/form/table/tbody/tr[2]/th/input').click() #這邊放送出選擇的按鈕的Xpath
        try:
            driver.find_element(By.LINK_TEXT,'重新選取。').click()
        except:
            input("已搶到課")

    driver.refresh()
    time.sleep(1)