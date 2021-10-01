from plyer import notification
import time
try:
    if __name__=="__main__": 
        while True:
            notification.notify( 
                title = "Water...", 
                message="Its 1 hour and you need to drink water now." ,
                app_name="Water Remainder",
                app_icon= "C:/Users/hp/Desktop/Work/glass.ico" ,
                toast = True,
            
                # displaying time 
                timeout=5 
       
            ) 
            # waiting time 
            time.sleep(3600)
except Exception as e:
    print(e)

