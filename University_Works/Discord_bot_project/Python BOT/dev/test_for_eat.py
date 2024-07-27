import discord
from discord.ext import commands, tasks
import json, asyncio
from dev.readsheet.sheet_update import update

with open('setting.json',mode='r', encoding='utf8') as jfile:
    config = json.load(jfile) 
with open('dev/readsheet/Restaurants_List.json',mode='r', encoding='utf8') as jfile:
    List = json.load(jfile) 

class Eat(commands.Cog):
    def __init__(self, bot):
        self.bot = bot
        self.Update_the_Restaurant_List.start()
        print('test loaded')
        

    @tasks.loop(minutes = 5)
    async def Update_the_Restaurant_List(self):
        update()
        print('餐廳列表已更新!')

    @commands.command()
    async def 餐廳列表(self , ctx):
        content = ""
        for restaurant in List["NameList"]:
            content = content + ',' + restaurant
        content = content[1:]
        await ctx.send(content)
    
    @commands.command()
    async def 吃啥(self , ctx , *argvs):
        result = ''
        await ctx.send(result)
    



async def setup(bot):
    await bot.add_cog(Eat(bot))