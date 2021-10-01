#-------------Importing all packages Package---------
import discord
from discord.ext import commands
from pandas_datareader import data as pdr
import datetime as dt
import yfinance as yf
import pandas as pd
import matplotlib.pyplot as plt
from bs4 import BeautifulSoup
import bs4
import ssl
import io
import requests
%matplotlib inline


#---------Using it to allow nested event loops---------------
#-------Using it so that multiple functions can be called together/It manages running of all coroutines, tasks, callbacks.-----------------
#-------async- allowing the code after the asynchronous call to be executed immediately without waiting-------------
import nest_asyncio
nest_asyncio.apply()

#-----activates workaround-------------
#----using pdr to create dataframe from various internet resources---------
yf.pdr_override() 

#------Creating a client or a handle to connect to our bot & a prefix-----
client=commands.Bot(command_prefix=".")
    

#---------------Giving 6 months history---------------------------------
@client.command(name='history')
async def history(ctx,arg):
    #-----------Today's date--------------
    date=dt.date.today()
    nowy=date.year
    nowm=date.month
    nowd=date.day

    #------start date-----------
    syear=nowy+(nowm-7)//12
    smonth=(nowm-7)%12+1
    sday=nowd

    start=dt.datetime(syear,smonth,sday)
    now=dt.datetime.now()
    
    df=pdr.get_data_yahoo(arg,start,now,interval="1mo")
    df=df.reset_index()
    df_close=df[['Date','Close']]
    df_close.set_index('Date',inplace=True)
    f=plt.figure()
    plt.plot(df_close,'b')
    plt.plot(df_close,'ro')
    plt.grid(True)
    plt.title(arg+" "+"Close Price Representation")
    plt.xlabel('Trading Months')
    plt.ylabel("Close Price")

    #-------Setting the bg as white--------------
    rect = f.patch
    rect.set_facecolor("white")
    #-----------Generating the html link & setting bg as white--------------
    fig = plt.gcf()
    buf = io.BytesIO()
    fig.savefig(buf, format='png',facecolor=f.get_facecolor())
    #buf.seek(0)
    #string = base64.b64encode(buf.read())
    #uri = 'data:image/png;base64,' + urllib.parse.quote(string)
    #html='<img src = "%s"/>' % uri

    #----------Saving the plot------------------
    #plt.plot(df_close)
    plt.savefig('plot_history_6.png')
    #plt.show()

    await ctx.send(file=discord.File("plot_history_6.png"))
    

    
#----------------Current OHLC Price of a stock--------------------------
@client.command(name='stock')
async def stock(ctx,arg):
    #-------Getting channel/server info----------
    guild=ctx.guild
    #---------Getting info of the members--------------
    member = ctx.message.author
    
    stck=yf.Ticker(arg)
    curr=stck.history(period='1d',interval='1m')
    curr=curr.reset_index()
    df_curr=curr[['Datetime','Open','High','Low','Close']]
    df_curr=df_curr.values.tolist()
    df_curr=df_curr[-1]
    stk=str(stck)
    embed=discord.Embed(
        title=f"{arg} OHLC Price",
        color=0xa200ff,
        timestamp=dt.datetime.utcnow()
    )
    embed.add_field(name="Open",value=df_curr[1],inline=False)
    embed.add_field(name="High",value=df_curr[2],inline=False)
    embed.add_field(name="Low",value=df_curr[3],inline=False)
    embed.add_field(name="Close",value=df_curr[4],inline=False)
    embed.set_author(name="RS-Updates",icon_url=guild.icon_url)
    embed.set_thumbnail(url=member.avatar_url)
    embed.set_footer(text=f"Requested by {member.name}")
    
    await ctx.send(embed=embed)
    
#----------TOP 25 Gainers---------------  
@client.command(name="gainers")
async def gain(ctx):
    #-------Getting channel/server info----------
    guild=ctx.guild
    #-------------Incase SSL Certificate error occurs-------------
    ct=ssl.create_default_context()
    ct.check_hostname=False
    ct.verify_made=ssl.CERT_NONE

    url=('https://www.moneycontrol.com/stocks/marketstats/nsegainer/index.php')
    r=requests.get(url)



    soup=BeautifulSoup(r.content,'html.parser')
    company=soup.find_all('a',style="color:#333")
    high=soup.find_all('td',align="right",width="75")
    low=soup.find_all('td',align="right",width="80")
    lPrice=soup.find_all('td',align="right",width="85")
    PClose=soup.find_all('td',align="right",width="80")

    h=list()
    l=list()
    lP=list()
    PC=list()
    com=list()
    
    for i in high:
        h.append(i.text)
    for i in low:
        l.append(i.text)
    for i in lPrice:
        lP.append(i.text)
    for i in PClose:
        PC.append(i.text)
    for c in company:
        com.append(c.text)

    lw=list()
    for i in range(0,len(l),2):
        lw.append(l[i])
    pc=list()
    for i in range(1,len(PC),2):
        pc.append(PC[i])
    df=pd.DataFrame(list(zip(com,h,lw,lP,pc)),columns=['Company Name','High','Low','Last Price','Previous Price'])
    embed = discord.Embed(title="Top 25 Gainers", color=0x03f8fc,timestamp=dt.datetime.utcnow())
    embed.set_thumbnail(url=guild.icon_url)
    embed.set_footer(text="Daily Updates")
    for i in range(len(df)):
        embed.add_field(name=f'**{df.loc[i, "Company Name"]}**',value=f'> High: {df.loc[i,"High"]}\n> Low: {df.loc[i,"Low"]}\n> Last Price: {df.loc[i,"Last Price"]}',inline=False)
    await ctx.send(embed=embed)
        
#----Connecting to our bot using its token key---------
client.run('----------------------------------------------------')