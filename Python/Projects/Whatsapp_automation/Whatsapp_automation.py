from selenium import webdriver
import time

PATH = 'PATH OF CHROME DRIVER LOCATED IN YOUR MACHINE'

driver = webdriver.Chrome(PATH)
driver.get('https://web.whatsapp.com/')
print('----------------------------------------------------------------\n'
      '|                  WELCOME TO WHATSAPP AUTOMATION             |\n'
      '----------------------------------------------------------------\n')
time.sleep(10)

chatting = True
while chatting:
    time.sleep(2)
    print('OPTIONS :\n'
          '1.chat\n'
          '00.Quit')
    chat_option = input('Enter your choice : ')
    if chat_option == '1':
        select_chat = True
        time.sleep(2)
        while select_chat:
            print('---------------\n'
                  '|  ALL CHATS  |\n'
                  '---------------')
            time.sleep(2)
            all_chats = driver.find_elements_by_xpath('/html/body/div/div[1]/div[1]/div[3]/div/div[2]/div[1]/div/div/div')
            for i in range(len(all_chats)):
                chatname = driver.find_element_by_xpath(f'/html/body/div/div[1]/div[1]/div[3]/div/div[2]/div[1]/div/div/div[{str(i+1)}]/div/div/div[2]/div[1]/div[1]/span').text
                print(f' ==>  {i+1} . {chatname}')
            print(f' ==>  00 . EXIT')
            option = input('\nEnter the chat index given above : ')
            time.sleep(2)
            if option != '00':
                driver.find_element_by_xpath(f'/html/body/div/div[1]/div[1]/div[3]/div/div[2]/div[1]/div/div/div[{str(int(option))}]').click()
                in_chat = True
                while in_chat:
                    print('Type of messaging : \n'
                          '  choice-1 : single message\n'
                          '  choice-2 : spam with a message\n'
                          '  choice-3 : BACK TO ALL CHATS')
                    choice_in = input('Enter your choice(number) : ')
                    if choice_in == '1':
                        message = input('Enter a messsage : ')
                        driver.find_element_by_xpath('/html/body/div/div[1]/div[1]/div[4]/div[1]/footer/div[1]/div[2]/div/div[2]').send_keys(f'{message} \n')
                    elif choice_in == '2':
                        message = input('Enter a messsage : ')
                        number = int(input('Enter No.of messages : '))
                        for i in range(number):
                            driver.find_element_by_xpath('/html/body/div/div[1]/div[1]/div[4]/div[1]/footer/div[1]/div[2]/div/div[2]').send_keys(f'{message} \n')
                    elif choice_in == '3':
                        driver.get('https://web.whatsapp.com/')
                        in_chat = False
            else:
                select_chat = False
    else:
        chatting = False
        driver.quit()
