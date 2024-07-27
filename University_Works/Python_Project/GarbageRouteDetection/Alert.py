import discord
import asyncio
import requests
from datetime import datetime

# User Discord ID
TARGET_USER_ID =  "NULL"  # 朋友的
#TARGET_USER_ID = "NULL"   # 我
# Bot 的 Token
TOKEN = "NULL"  #

async def detect_something():
    data = requests.get('https://api.kcg.gov.tw/api/service/Get/aaf4ce4b-4ca8-43de-bfaf-6dc97e89cac0')
    information = data.json()

    road = ""
    for item in information['data']:
        if item['car'] == "NULL":
            road = item["location"]
            break
    print(road)
    if "AA路" in road or "BB路" in road:
        return True 
    else:
        return False

class MyClient(discord.Client):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.bg_task = None

    async def setup_hook(self):
        self.bg_task = self.loop.create_task(self.background_task())

    async def on_ready(self):
        print(f'Logged in as {self.user}')

    async def background_task(self):
        await self.wait_until_ready()
        print('task ready')
        user = self.get_user(TARGET_USER_ID)
        await user.send("垃圾車機器人已啟動")
        while not self.is_closed():
            print('check')
            if await detect_something():
                await user.send("垃圾車已經抵達滾水路 約莫還有5分鐘到達")
            if datetime.now().time().hour >= 21:
                await self.close()
            await asyncio.sleep(60) 

intents = discord.Intents.default()
intents.message_content = True
intents.members = True

client = MyClient(intents=intents)
asyncio.run(client.start(TOKEN))
