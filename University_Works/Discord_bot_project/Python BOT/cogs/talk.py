from http import client
import discord
from discord.ext import commands
import json
import random

with open('setting.json',mode='r', encoding='utf8') as jfile:
    jdata = json.load(jfile)

with open('datas/emoji.json',mode = 'r', encoding='utf8') as jfile:
    Emojis = json.load(jfile)

with open('datas/photo.json',mode='r', encoding='utf8') as jfile:
    photo = json.load(jfile) 

class talk(commands.Cog):
    def __init__(self, bot):
        self.bot = bot
    
    @commands.command()
    async def talkpack_ck(self , ctx):
        await ctx.send('Talk pack is installed')

    @commands.Cog.listener()
    async def on_member_join( self , member ):#中正場外
        if member.guild == self.bot.get_guild("secret"):
            channel = self.bot.get_channel(int(jdata['Hello_Lobby'])) #頻道ID
            await channel.send(f'歡迎{member.mention}的加入 >w<  \n 記得去下面找Mee 6領取身分組才能發言歐～')
            print(f'{member} has joined CCU server')

        if member.guild == self.bot.get_guild("secret"):#BTS
            channel = self.bot.get_channel("secret") #頻道ID
            await channel.send(f'歡迎{member.mention}加入"secret"的測試用伺服器')
            print(f'{member} has joined BTS server')

    @commands.Cog.listener()
    async def on_member_remove( self , member ):
        if member.guild == self.bot.get_guild("secret"):
            channel = self.bot.get_channel(int(jdata['Hello_Lobby'])) #頻道ID
            await channel.send(f'{member}離開了 小心慢走QAQ')
            print(f'{member} has left CCU server')

        if member.guild == self.bot.get_guild("secret"):#BTS
            channel = self.bot.get_channel("secret") #頻道ID
            await channel.send(f'{member.mention}小心慢走~')
            print(f'{member} has left BTS server')

    
#    @commands.Cog.listener()
#    async def on_message( self , msg ):
#        Author = msg.author
#        guild = msg.guild
#        if(guild != None):
#            Me = guild.get_member(secret) 
#            if f'{Me.mention}' in msg.content:
#                if str(Author) == jdata['IzuYanze']:
#                    await msg.add_reaction(self.bot.get_emoji(Emojis['Love']))
#                    if '拜託妳' in msg.content:
#                        await msg.channel.send(f'{Author.mention} 好的！')
#                        Yes = self.bot.get_emoji(Emojis['Yes'])
#                        await msg.channel.send(f'{Yes}')
#                else:
#                    pass
#                
#        if msg.content == '安安' and Author != self.bot.user :
#            await msg.channel.send(f'{Author.mention}安安～！')
#        elif msg.content == 'C8763':
#            emoji = self.bot.get_emoji(secret)
#            await msg.add_reaction(emoji)
#        elif msg.content in jdata["bomb"]:
#            if random.randint(1,8) == 1:
#                await msg.channel.send(f'斷')
#        elif msg.content == 'secret':
#            await msg.channel.send('secret')
#        elif msg.content in jdata["Ecourse 2"]:
#            embed=discord.Embed(title="Ecourse 2", url="https://ecourse2.ccu.edu.tw/", description="National Chung Cheng University", color=0x2c485f)
#            embed.set_thumbnail(url="https://ecourse2.ccu.edu.tw/pluginfile.php/1/theme_sideblock/favicon/1651665859/favicon-2020122205004845.ico")
#            embed.add_field(name="Ecourse 2", value="國立中正大學", inline=True)
#            await msg.channel.send(embed=embed)
#        elif msg.content in jdata["CCU single entry"]:
#            embed=discord.Embed(title="國立中正大學單一入口", url="https://portal.ccu.edu.tw/", description="CCU single entry", color=0x3e76d0)
#            embed.set_thumbnail(url="https://upload.wikimedia.org/wikipedia/zh/thumb/5/5d/National_Chung_Cheng_University_logo.svg/320px-National_Chung_Cheng_University_logo.svg.png")
#            await msg.channel.send(embed=embed)
#        elif msg.content in jdata["CCU website"]:
#            embed=discord.Embed(title="國立中正大學", url="https://www.ccu.edu.tw/", description="National Chung Cheng University", color=0x3e76d0)
#            embed.set_thumbnail(url="https://upload.wikimedia.org/wikipedia/zh/thumb/5/5d/National_Chung_Cheng_University_logo.svg/320px-National_Chung_Cheng_University_logo.svg.png")
#            await msg.channel.send(embed=embed)
#        elif msg.content == '星爆' and Author != self.bot.user :
#            await msg.channel.send(f'氣流斬')
#        elif msg.content == '星爆氣流斬' and Author != self.bot.user :
#            await msg.channel.send(photo["StarburstStream"])
#        elif msg.content in jdata["stay cool"] and Author != self.bot.user :
#            await msg.channel.send(photo["StayCool"])
#        elif '撐十秒' in msg.content and Author != self.bot.user :
#            await msg.channel.send(photo["ten_seconds"])





async def setup(bot):
    await bot.add_cog(talk(bot))