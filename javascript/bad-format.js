require('dotenv').config();
const Discord = require('discord.js');
const bot = new Discord.Client();

const prefix = "!"

const TOKEN = process.env.TOKEN;
 client.on('ready', () => { 
  console.log('Bot is ready'); bot.on('ready', () => { 
  console.info(`Logged in as ${bot.user.tag}!`);
 const args = 
  msg.content.split(/ +/); const command = args.shift().toLowerCase();
 console.info(`Called command:
 ${command}`);
 if (!bot.commands.has(command)) return;
 try {bot.commands.get(command).execute(msg, args);
  } catch (error) {
    console.error(error); msg.reply('there was an error trying to execute that command!');
  }
});

bot.login(TOKEN);
