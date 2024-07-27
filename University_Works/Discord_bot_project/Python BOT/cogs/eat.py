from random import random
import discord
from discord.ext import commands
import json, random, asyncio

with open('datas/food.json',mode='r', encoding='utf8') as jfile:
    jdata = json.load(jfile) 

with open('datas/emoji.json',mode = 'r', encoding='utf8') as jfile:
    Emojis = json.load(jfile)

class eat(commands.Cog):
    def __init__(self, bot):
        self.bot = bot
    
    @commands.command()
    async def 吃啥(self , ctx , period = '哪一餐' , vehicle = '有車' ):
        Trick = 1
        while Trick:
            Trick = 0
            Answer = ''
            if vehicle == '有車':
                if period == '早餐':
                    Answer = random.choice( jdata["BreakfastCar"] )
                elif period == '午餐':
                    Answer = random.choice( jdata["LunchCar"] )
                elif period == '晚餐':
                    Answer = random.choice( jdata["DinnerCar"] )
                elif period == '宵夜' or period == '消夜' :
                    Answer = random.choice( jdata["NightsnackCar"] )
                else:
                    period = '?'
            else :
                if period == '早餐':
                    Answer = random.choice( jdata["Breakfast"] )
                elif period == '午餐':
                    Answer = random.choice( jdata["Lunch"] )
                elif period == '晚餐':
                    Answer = random.choice( jdata["Dinner"] )
                elif period == '宵夜' or period == '消夜' :
                    Answer = random.choice( jdata["Nightsnack"] )
                else:
                    period = '?'
            if period == '?':
                await ctx.channel.send(f'請說你想吃哪餐')
            else:
                await ctx.channel.send(f'為您推薦 {Answer}～')
            if Answer in jdata["Troll"]:
                await ctx.channel.send(f'抱歉 資料庫出錯了 幫你再選一個新的 稍等一下...')
                Trick = 1
                await asyncio.sleep(3)

    @commands.command()
    async def 吃啥十連(self , ctx , period = '哪一餐' , vehicle = '有車' ):
        Trick = 1
        while Trick:
            Trick = 0
            Answer = ''
            if vehicle == '有車':
                if period == '早餐':
                    Answer = random.sample( jdata["BreakfastCar"] ,10 )
                elif period == '午餐':
                    Answer = random.sample( jdata["LunchCar"] ,10 )
                elif period == '晚餐':
                    Answer = random.sample( jdata["DinnerCar"] ,10 )
                elif period == '宵夜' or period == '消夜' :
                    Answer = random.sample( jdata["NightsnackCar"] ,10 )
                else:
                    period = '?'
            else :
                if period == '早餐':
                    Answer = random.sample( jdata["Breakfast"] ,10 )
                elif period == '午餐':
                    Answer = random.sample( jdata["Lunch"] ,10 )
                elif period == '晚餐':
                    Answer = random.sample( jdata["Dinner"] ,10 )
                elif period == '宵夜' or period == '消夜' :
                    Answer = random.sample( jdata["Nightsnack"] ,10 )
                else:
                    period = '?'
            if period == '?':
                await ctx.channel.send(f'請說你想吃哪餐')
            else:
                await ctx.channel.send(f'為您推薦以下這些 \n {Answer[0]} \n {Answer[1]} \n {Answer[2]} \n {Answer[3]} \n {Answer[4]} \n {Answer[5]} \n {Answer[6]} \n {Answer[7]} \n {Answer[8]} \n {Answer[9]}')

    @commands.command()
    async def 有啥吃(self , ctx , period ='?' , vehicle ='?' ):
        if vehicle == '沒車' :
            if period == '早餐':
                await ctx.send( jdata["Breakfast"] )
            elif period == '午餐':
                await ctx.send( jdata["Lunch"] )
            elif period == '晚餐':
                await ctx.send( jdata["Dinner"] )
            elif period == '宵夜' or period == '消夜' :
                await ctx.send( jdata["Nightsnack"] )
            else:
                Cry = self.bot.get_emoji(Emojis['Cry'])
                await ctx.send( f'你沒有說想看哪餐 {Cry}' )
        else:
            if period == '早餐':
                await ctx.send( jdata["BreakfastCar"] )
            elif period == '午餐':
                await ctx.send( jdata["LunchCar"] )
            elif period == '晚餐':
                await ctx.send( jdata["DinnerCar"] )
            elif period == '宵夜' or period == '消夜' :
                await ctx.send( jdata["NightsnackCar"] )
            else:
                Cry = self.bot.get_emoji(Emojis['Cry'])
                await ctx.send( f'你沒有說想看哪餐 {Cry}' )



async def setup(bot):
    await bot.add_cog(eat(bot))