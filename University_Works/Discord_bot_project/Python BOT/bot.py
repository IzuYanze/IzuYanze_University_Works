from random import random
import discord
from discord.ext import commands
import json
import os, datetime, asyncio

with open('setting.json',mode='r', encoding='utf8') as jfile:
    config = json.load(jfile) 

intents = discord.Intents.all()
intents.members = True

bot = commands.Bot(intents=intents , command_prefix='$')

@bot.event
async def on_ready():
    print("準備就緒")
    game = discord.Game('discord.py online')
    await bot.change_presence(status=discord.Status.online, activity=game)

@bot.event
async def on_connect():
    print("連線成功")

@bot.event
async def on_disconnect():
    print(f"斷線 {datetime.datetime.now()}")
    re_cord = f'斷線時間:{datetime.datetime.now()} \n'
    fp = open("record.txt", "a", encoding='UTF-8')
    fp.write(re_cord)
    fp.close()

#套件相關

@bot.command()
async def load(ctx , extension):
    await bot.load_extension(extension)
    await ctx.send(f'{extension} 安裝完畢')

    
@bot.command()
async def unload(ctx , extension):
    await bot.unload_extension(extension)
    await ctx.send(f'{extension} 解除安裝完畢')
    
@bot.command()
async def reload(ctx , extension):
    await bot.reload_extension(f'cogs.{extension}')
    await ctx.send(f'{extension} 重新載入完畢')

@bot.command()
async def list_ext(ctx):
    await ctx.send(bot.extensions)


async def load_extensions():
    for filename in os.listdir("./cogs"):
        if filename.endswith(".py"):
            extension = filename[:-3]
            await bot.load_extension(f'cogs.{extension}')
            print(f'\'{extension}\' 已載入')
            
        



if __name__ == "__main__":
    asyncio.run(load_extensions())
    bot.run(config['token'])
