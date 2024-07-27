from random import random
from time import strftime
import discord
from discord.ext import commands
import json, random, datetime, asyncio

with open('setting.json',mode='r', encoding='utf8') as jfile:
    jdata = json.load(jfile) 

with open('datas/emoji.json',mode = 'r', encoding='utf8') as jfile:
    Emojis = json.load(jfile)

class secret(commands.Cog):
    def __init__(self, bot):
        self.bot = bot
    
    
    # @commands.command()
    # async def check(self , ctx):
    #     test = str(ctx.author)
    #     print(f'{test}')
    

    @commands.command()
    async def ping(self , ctx):
        embed = discord.Embed(description = f'{round(self.bot.latency*1000)} ms' , color = 0xE547EC)
        await ctx.send(embed=embed)
        print(f'now latency is {round(self.bot.latency*1000)}ms')

    @commands.command()
    async def saydel(self , ctx , *, msg):
        if str(ctx.author) == jdata['IzuYanze']:
            await ctx.message.delete()
            await ctx.send(msg)
        else:
            await ctx.send('您沒有權限')

    @commands.command()
    async def says(self , ctx , channel : int , *, msg):
        if str(ctx.author) == jdata['IzuYanze']:
            sender = self.bot.get_channel(channel)
            await sender.send(msg)
        else:
            await ctx.send('您沒有權限')
    
    @commands.command()
    async def sayemo(self , ctx , emo = 'Love' ):
        user = ctx.author
        if str(user) == jdata['IzuYanze']:
            await ctx.message.delete()
            if emo == 'Cry' or emo == 'cry':
                emo = self.bot.get_emoji(Emojis['Cry'])
            elif emo == 'Angry' or emo == 'angry':
                emo = self.bot.get_emoji(Emojis['Angry'])
            else:
                emo = self.bot.get_emoji(Emojis['Love'])
            await ctx.send(emo)

    @commands.command()
    async def clean(self , ctx , num :int):
        if str(ctx.author) in jdata['Moderators']:
            await ctx.channel.purge(limit=num+1)
            print(f'{ctx.author} has clean up {num} messages.')
        else:
            print(f'{ctx.author} try to delete messege but have no permission！')
        now = str(datetime.datetime.now())
        re_cord = f'{ctx.author} 於 {now} 嘗試於 [{ctx.guild} 的 {ctx.channel}] 進行 {num} 行的刪除\n'
        fp = open("record.txt", "a", encoding='UTF-8')
        fp.write(re_cord)
        fp.close()

                

        



async def setup(bot):
    await bot.add_cog(secret(bot))