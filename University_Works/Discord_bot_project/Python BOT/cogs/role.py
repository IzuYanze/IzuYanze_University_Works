import discord
from discord.ext import commands
import json

with open('setting.json',mode='r', encoding='utf8') as jfile:
    jdata = json.load(jfile) 

with open('datas/emoji.json',mode = 'r', encoding='utf8') as jfile:
    Emojis = json.load(jfile)

class role(commands.Cog):
    def __init__(self, bot):
        self.bot = bot
   
    @commands.Cog.listener()
    async def on_raw_reaction_add(self, data):
        if data.message_id == "secret":#訊息ID #測試用
            if str(data.emoji) == '0️⃣':
                guild = self.bot.get_guild(data.guild_id)
                role = guild.get_role("secret")#身分組ID
                user = guild.get_member(data.user_id)
                await user.add_roles(role)
            if str(data.emoji) == '1️⃣':
                guild = self.bot.get_guild(data.guild_id)
                role = guild.get_role("secret")#身分組ID
                user = guild.get_member(data.user_id)
                await user.add_roles(role)

        if data.message_id == int(jdata['RoleMsg1']):#訊息ID 領取遊戲身分組 
            if str(data.emoji) == '1️⃣':#LOL
                guild = self.bot.get_guild(data.guild_id)
                role = guild.get_role("secret")#身分組ID
                user = guild.get_member(data.user_id)
                await user.add_roles(role)
            if str(data.emoji) == '2️⃣':#APEX
                guild = self.bot.get_guild(data.guild_id)
                role = guild.get_role("secret")#身分組ID
                user = guild.get_member(data.user_id)
                await user.add_roles(role)
            if str(data.emoji) == '3️⃣':#Valorant
                guild = self.bot.get_guild(data.guild_id)
                role = guild.get_role("secret")#身分組ID
                user = guild.get_member(data.user_id)
                await user.add_roles(role)

        if data.message_id == "secret":#訊息ID  普物幫 
            guild = self.bot.get_guild(data.guild_id)
            role = guild.get_role("secret")#身分組ID
            user = guild.get_member(data.user_id)
            await user.add_roles(role)

        if data.message_id == "secret":#訊息ID  化生幫  
            guild = self.bot.get_guild(data.guild_id)
            role = guild.get_role("secret")#身分組ID
            user = guild.get_member(data.user_id)
            await user.add_roles(role)

        if data.message_id == "secret":#訊息ID  老地方歡樂送 
            guild = self.bot.get_guild(data.guild_id)
            Emoji = self.bot.get_emoji(Emojis['Old_Place'])
            if data.emoji == Emoji:
                role = guild.get_role("secret")#老地方歡樂送ID
                user = guild.get_member(data.user_id)
                await user.add_roles(role)
        
    

    @commands.Cog.listener()
    async def on_raw_reaction_remove(self, data):
        if data.message_id == "secret":#訊息ID
            if str(data.emoji) == '0️⃣':
                guild = self.bot.get_guild(data.guild_id)
                role = guild.get_role("secret")#身分組ID
                user = guild.get_member(data.user_id)
                await user.remove_roles(role)
            if str(data.emoji) == '1️⃣':
                guild = self.bot.get_guild(data.guild_id)
                role = guild.get_role("secret")#身分組ID
                user = guild.get_member(data.user_id)
                await user.remove_roles(role)

        if data.message_id == int(jdata['RoleMsg1']):#訊息ID  領取遊戲身分組 
            if str(data.emoji) == '1️⃣':#LOL
                guild = self.bot.get_guild(data.guild_id)
                role = guild.get_role("secret")#身分組ID
                user = guild.get_member(data.user_id)
                await user.remove_roles(role)
            if str(data.emoji) == '2️⃣':#APEX
                guild = self.bot.get_guild(data.guild_id)
                role = guild.get_role("secret")#身分組ID
                user = guild.get_member(data.user_id)
                await user.remove_roles(role)
            if str(data.emoji) == '3️⃣':#Valorant
                guild = self.bot.get_guild(data.guild_id)
                role = guild.get_role("secret")#身分組ID
                user = guild.get_member(data.user_id)
                await user.remove_roles(role)
        
        if data.message_id == "secret":#訊息ID  普物幫  
            guild = self.bot.get_guild(data.guild_id)
            role = guild.get_role("secret")#身分組ID
            user = guild.get_member(data.user_id)
            await user.remove_roles(role)
        
        if data.message_id == "secret":#訊息ID  化生幫  
            guild = self.bot.get_guild(data.guild_id)
            role = guild.get_role("secret")#身分組ID
            user = guild.get_member(data.user_id)
            await user.remove_roles(role)
    



async def setup(bot):
    await bot.add_cog(role(bot))