from random import random
import discord
from discord.ext import commands
import json , re
import random

with open('setting.json',mode='r', encoding='utf8') as jfile:
    jdata = json.load(jfile) 

class test(commands.Cog):
    
    pass




async def setup(bot):
    await bot.add_cog(test(bot))