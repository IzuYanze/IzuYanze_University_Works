import discord
from discord.ext import commands
import json, asyncio


with open('setting.json',mode='r', encoding='utf8') as jfile:
    config = json.load(jfile) 


class MorningCall(commands.Cog):
    def __init__(self, bot):
        self.bot = bot
            
    
    @commands.hybrid_command(name='test', description = '測試用指令')
    async def test(self,ctx):
        await ctx.send('test')




async def setup(bot):
    await bot.add_cog(MorningCall(bot))