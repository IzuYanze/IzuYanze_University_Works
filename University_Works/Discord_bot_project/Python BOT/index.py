from random import random
import discord
from discord.ext import commands
import json
import os, datetime, asyncio

with open('setting.json',mode='r', encoding='utf8') as jfile:
    config = json.load(jfile) 

intents = discord.Intents.all()
intents.members = True

bot = commands.Bot(intents=intents , command_prefix='&')

@bot.event
async def on_ready():
    print("dev機器人準備就緒")
    game = discord.Game('discord.py 程式碼測試中...')
    await bot.change_presence(status=discord.Status.online, activity=game)

@bot.event
async def on_connect():
    print("dev機器人連線成功")

@bot.event
async def on_disconnect():
    print(f"dev斷線於 {datetime.datetime.now()}")
    re_cord = f'dev斷線時間:{datetime.datetime.now()} \n'
    fp = open("record.txt", "a", encoding='UTF-8')
    fp.write(re_cord)
    fp.close()

#套件相關

@bot.hybrid_command(
    name='載入模塊',
    description = '載入特定模組'
)
async def load(ctx , extension):
    await bot.load_extension(extension)
    await ctx.send(f'{extension} 安裝完畢')

    
@bot.hybrid_command()
async def unload(ctx , extension):
    await bot.unload_extension(extension)
    await ctx.send(f'{extension} 解除安裝完畢')
    
@bot.hybrid_command()
async def reload(ctx , extension):
    await bot.reload_extension(f'dev.{extension}')
    await ctx.send(f'{extension} 重新載入完畢')

@bot.command()
async def list_ext(ctx):
    await ctx.send(bot.extensions)


async def load_extensions():
    for filename in os.listdir("./dev"):
        if filename.endswith(".py"):
            extension = filename[:-3]
            await bot.load_extension(f'dev.{extension}')
            print(f'\'{extension}\' 已載入')
            
        



if __name__ == "__main__":
    asyncio.run(load_extensions())
    bot.run(config['tokenTest'])