from random import random
import discord
from discord.ext import commands
import json
import random

with open('setting.json',mode='r', encoding='utf8') as jfile:
    jdata = json.load(jfile) 

class main(commands.Cog):
    def __init__(self, bot):
        self.bot = bot

    @commands.command()
    async def 找人(self , ctx):
        chosen = random.choice(ctx.channel.members.nick)
        await ctx.send(f'{chosen}')

    
    @commands.command()
    async def choose(self , ctx , *args):
        r = random.choice(args)
        await ctx.send(f'{ctx.message.author.mention} {r}')


    @commands.command()
    async def 外送告知(self , ctx , link):
        await ctx.message.delete()
        await ctx.send(f'<@&1035517936825290763> {link}')

    @commands.command()
    async def ctx_debuger(self , ctx ):
        print(f'>> Debug print :" {ctx.message.content} "<<')


async def setup(bot):
    await bot.add_cog(main(bot))