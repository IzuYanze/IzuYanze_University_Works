import discord
from discord.ext import commands, tasks
import json, datetime, asyncio, random

with open('setting.json',mode='r', encoding='utf8') as jfile:
    jdata = json.load(jfile) 

class Task(commands.Cog):

    def __init__(self , bot):
        self.bot = bot
        print('task 正在執行')
        self.timer.start()
        self.datecounter.start()
        self.Hello.start()
        self.bot.nowtime = datetime.datetime.now().strftime('%H%M')
        self.bot.nowdate = '20221024'
        self.bot.getup = datetime.time(random.randint(6,13),random.randint(0,59)).strftime('%H%M')

    def cog_unload(self):
        self.timer.cancel()
        self.datecounter.cancel()
        self.Hello.cancel()
        

    @tasks.loop(minutes=1)
    async def timer(self):
        self.bot.nowtime = datetime.datetime.now().strftime('%H%M')
        #if self.bot.nowtime in ['0400','0430','0500','0530']: #叫(secret)睡覺
        #    guild = self.bot.get_guild(secret)
        #    user = guild.get_member(secret)
        #    if user.status != discord.Status.offline:
        #        await user.send('該去睡覺囉')
        #        channel = self.bot.get_channel(secret)
        #        await channel.send('已經叫(secret)去睡覺了')
                




    @tasks.loop(hours=24)
    async def datecounter(self):
        self.bot.nowdate = datetime.datetime.now().strftime('%y%m%d')
        self.bot.getup = datetime.time(random.randint(6,13),random.randint(0,59)).strftime('%H%M')

    @tasks.loop(minutes= 1)
    async def Hello(self):
        if self.bot.nowtime == self.bot.getup :
            channel = self.bot.get_channel("secret") #安安頻道
            #channel = self.bot.get_channel(secret)
            await channel.send(f'早安喜樂')
            await asyncio.sleep(60)

    @commands.command()
    async def checker(self , ctx):
        await ctx.send(self.bot.getup)
        await ctx.send(self.bot.nowtime)




async def setup(bot):
    await bot.add_cog(Task(bot))