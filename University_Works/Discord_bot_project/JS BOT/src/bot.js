import { config } from 'dotenv';
import { Client, GatewayIntentBits, Routes, userMention } from 'discord.js';
import { REST } from '@discordjs/rest';

config();

const Token = process.env.Yanrin_bot2_TOKEN;
const CLIENT_ID = process.env.CLIENT_ID;
const GUILD_ID = process.env.TEST_GUILD_ID;

const client = new Client({ 
    intents: [
        GatewayIntentBits.Guilds, 
        GatewayIntentBits.GuildMessages,
        GatewayIntentBits.MessageContent
    ]
});

const rest = new REST({ version : '10' }).setToken(Token)

client.on('ready', ()=> {
    var Status = "BOT ONLINE"
    client.user.setActivity(Status);
    console.log(`${client.user.tag} Discord logged in `);
});

client.on('interactionCreate', async interaction => {
    if (!interaction.isChatInputCommand()) return;
  
    if (interaction.commandName == 'ㄐㄐ') {
        await interaction.reply('ㄐㄐ!');
    }
    if (interaction.commandName == '選擇') {
        var choice = interaction.options.getString('選項').split(/ +/g);
        const response = Math.floor(Math.random() * choice.length);
        await interaction.reply(`${interaction.member} 給你的選項是 ${choice[response]}!`);
    }
});

client.on( 'messageCreate', (message) => {
    if(message.guildId == `secret`){
        return;
    }
    console.log(`在${message.createdAt.toString()} ${message.author.tag}於 ${message.guild.name}的${message.channel.name}：「${message.content}」`);
});

async function main() {
    const commands = [
        {
            name: '你好',
            description: '對 就是你好',
        },
        {
            name: '選擇',
            description: '選擇東西',
            options:[
                {
                    name : '選項',
                    description : '你的選項\n 記得用空格隔開你的選項',
                    type : 3,
                    required : true,
                },
            ],
        },
    ];

    try{
        console.log('開始重整程式的 (/) 指令');
        await rest.put(Routes.applicationCommands( CLIENT_ID ), {
            body : commands,
        });
        
        client.login(Token);    
    } catch( err ) {
        console.log(err);
    }
}

main();