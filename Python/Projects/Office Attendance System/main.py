import os  # import libraries like open,close and more for file handeling
import ast
import random
from tkinter import *
import tkinter as tk
from functools import partial
#import tkMessageBox
import os
##
##


def change_color():
    if window["background"] == "white":
        window["background"] = "black"
        # print(window)
        # tk.mycolor["text"] = "black theme"

    else:
        window["background"] = "white"
        # tk.mycolor["text"] = "black theme"


def data_update(userid):
    update_data1 = tk.Tk()
    update_data1.configure(bg="black")
    update_data1.title("update data")

    def update_entry(name, age, address, user_id):
        name = name.get()
        age = age.get()
        address = address.get()
        myfile = open("data.txt", "r")
        dic = myfile.read()
        user1 = ast.literal_eval(dic)
        myfile.close()
        user1[userid]['name'] = name
        user1[userid]['age'] = age
        user1[userid]['address'] = address
        myfile = open("data.txt", "w")
        myfile.write(str(user1))
        myfile.close()
        tk.Label(master=update_data1, text="your data updated").grid()

    name = tk.StringVar(update_data1)
    age = tk.StringVar(update_data1)
    address = tk.StringVar(update_data1)

    # username
    tk.Label(master=update_data1, text="Update Profile",
             font="none 20 bold", fg='white', bg="black").grid()

    tk.Label(master=update_data1, text="name",
             width=10, bg="black", fg="red").grid(row=1)
    tk.Entry(master=update_data1, textvariable=name,
             bg="red").grid(column=1, row=1)
    # age
    tk.Label(master=update_data1, text="age", width=10,
             bg="black", fg="red").grid(row=2)
    tk.Entry(master=update_data1, textvariable=age,
             bg="red").grid(column=1, row=2)
    # address
    tk.Label(master=update_data1, text="address", width=10,
             bg="black", fg="red", font="none 10 bold").grid(row=4)
    tk.Entry(master=update_data1, textvariable=address,
             bg="red").grid(column=1, row=4)
    update_entry1 = partial(update_entry, name, age, address, userid)
    tk.Button(master=update_data1, text="Proceed",
              command=update_entry1, width=10).grid(row=6, column=1, pady=2)
    tk.Button(master=update_data1, text="Exit",
              command=update_data1.destroy, width=10).grid(row=6, column=2, pady=2)


def userInfo():
    def call_result(n1):
        num1 = (n1.get())
        myfile = open("data.txt", "r")
        dic = myfile.read()
        user1 = ast.literal_eval(dic)
        myfile.close()
        print(user1)

        if num1 not in user1.keys():
            tk.Label(master=profile, text='Invalid ID. Try Again!').grid()
            print('$$$$$', num1)
        else:
            tk.Label(master=profile, text="Name", width=20, bg="black",
                     fg="red", font="none 12 bold", justify=LEFT).grid(row=6, pady=3)
            tk.Label(master=profile, text=user1[num1]['name'], bg="black", fg="white",
                     font="none 9", justify=LEFT).grid(column=1, row=6, pady=3, padx=4)
          # age
            tk.Label(master=profile, text="Age", width=20, bg="black",
                     fg="red", font="none 12 bold", justify=LEFT).grid(row=7, pady=3)
            tk.Label(master=profile, text=user1[num1]['age'], bg="black",
                     fg="white", font="none 9", justify=LEFT).grid(column=1, row=7, pady=3)
          # address
            tk.Label(master=profile, text="Address", width=20, bg="black",
                     fg="red", font="none 12 bold", justify=LEFT).grid(row=8, pady=3)
            tk.Label(master=profile, text=user1[num1]['address'], bg="black",
                     fg="white", font="none 9", justify=LEFT).grid(column=1, row=8, pady=3)
           # salary
            tk.Label(master=profile, text="Salary", width=20, bg="black",
                     fg="red", font="none 12 bold", justify=LEFT).grid(row=10, pady=3)
            tk.Label(master=profile, text=user1[num1]['salary'], bg="black", fg="white",
                     font="none 12 bold", justify=LEFT).grid(column=1, row=10, pady=3)
          # attendance
            tk.Label(master=profile, text="Attendance", width=20, bg="black",
                     fg="red", font="none 12 bold", justify=LEFT).grid(row=9, pady=3)
            tk.Label(master=profile, text=user1[num1]['attendance'], bg="black",
                     fg="white", font="none 9", justify=LEFT).grid(column=1, row=9, pady=3)
            data_update1 = partial(data_update, num1)

            tk.Button(master=profile, text="Update Data",
                      command=data_update1, width=10).grid(row=12, column=1, pady=3)
            tk.Button(master=profile, text="Exit", command=profile.destroy, width=10).grid(
                row=12, column=2, pady=3)

    profile = tk.Tk()
    numberr = tk.StringVar(profile)
    profile.geometry('720x450')
    profile.title("View Logs")
    profile.configure(bg='black')
    tk.Label(master=profile, text="User  Profile", font="none 20 bold",
             fg='white', bg="black").grid(row=1, column=2)
    tk.Label(master=profile, text="UserId", width=10,
             bg="black", fg="red").grid(row=2, column=2)
    username = tk.Entry(master=profile, textvariable=numberr,
                        bg="red").grid(column=3, row=2)

    call_result11 = partial(call_result, numberr)

    buttonCal = tk.Button(master=profile, text="Enter",
                          command=call_result11).grid(row=2, column=4, padx=6)


def exitWindow():
    notice = tk.Tk("Admin Portaal")

    def destroy_all():
        notice.destroy()
        window.destroy()

    notice.title("exit")
    tk.Label(notice, text="do you really want to exit?").grid()
    tk.Button(notice, text="Yes", command=destroy_all).grid(column=1, row=6)
    tk.Button(notice, text="NO", command=notice.destroy).grid(row=6, column=2)


def create_profile():

    def call_result(name, age, address):
        name = (name.get())
        age = (age.get())
        address = (address.get())
        uni = random.randrange(1000, 2000)
        uni_id = []

        while(uni in uni_id):
            uni = random.randrange(1000, 2000)
            uni_id.append(uni)
        uni_print = "Your unique id :" + str(uni)
        tk.Label(master=create_profile, text=uni_print,
                 font="none 10 bold", fg="black").grid(row=8, column=3)
        file_logs(name, age, address, uni)

    create_profile = tk.Tk()
    create_profile.title("Create Profile")

    name = tk.StringVar(create_profile)
    age = tk.StringVar(create_profile)
    address = tk.StringVar(create_profile)
    create_profile.geometry('720x600')
    create_profile.configure(bg='black')

    # username
    tk.Label(master=create_profile, text="Create Profile",
             font="none 20 bold", justify=LEFT, fg='white', bg="black").grid()

    tk.Label(master=create_profile, text="Name", width=10, height=2,
             font="none 10", bg="black", fg="red").grid(row=1, pady=2)
    tk.Entry(master=create_profile, textvariable=name,
             font="none 8", bg="red").grid(column=1, row=1)
    # age
    tk.Label(master=create_profile, text="Age", font="none 10",
             width=10, height=2, bg="black", fg="red").grid(row=2, pady=2)
    tk.Entry(master=create_profile, textvariable=age,
             bg="red", font="none 8").grid(column=1, row=2)
    # address
    tk.Label(master=create_profile, text="Address", width=10, height=2,
             bg="black", fg="red", font="none 10").grid(row=4, pady=2)
    tk.Entry(master=create_profile, textvariable=address,
             bg="red", font="none 8").grid(column=1, row=4)

    call_result11 = partial(call_result, name, age, address)

    instructions = 'Instruction to create a profile:- \n \n 1)Fill your name,age,postion and address.(All fields are required)\n 2)Then click generate id  \n 3) this will create your profile \n 4)To create another profile just fill the new details and click generate unique id.'
    tk.Label(master=create_profile, text=instructions, bg="black",
             fg="white", font="none 8", justify=LEFT).grid(row=8, pady=20)

    buttonCal = tk.Button(master=create_profile, text="Generate unique id",
                          command=call_result11).grid(row=5, column=3)
    buttonCal = tk.Button(master=create_profile, text="Home",
                          command=create_profile.destroy).grid(row=9, pady=2, column=0)


window = tk.Tk()
window.configure(bg='black')
window.title("mainScreen")
heading = tk.Label(master=window, text="Welcome to the Admin Panel !!",
                   font="none 20 bold", fg='white', bg="black").grid()


def attend():
    def attendance_update():
        att = ID.get()
        myfile = open("data.txt", "r")
        dic = myfile.read()
        user1 = ast.literal_eval(dic)
        myfile.close()
        if att not in user1.keys():
            tk.Label(master=popup, text='Invalid ID. Try Again!').grid()
            # print('$$$$$',num1)
        else:
            user1[att]['attendance'] = user1[att]['attendance']+1
            if user1[att]['attendance'] == 0:
                user1[att]['salary'] = 10000
                user1[att]['position'] = 'employee'
            elif user1[att]['attendance'] == 3:
                user1[att]['salary'] = 20000
                user1[att]['position'] = 'senior employee'
            elif user1[att]['attendance'] == 5:
                user1[att]['salary'] = 30000
                user1[att]['position'] = 'team manager'
            elif user1[att]['attendance'] == 7:
                user1[att]['salary'] = 40000
                user1[att]['position'] = 'senior manager'

            tk.Label(master=popup, text="Attendance Marked").grid()
            myfile = open("data.txt", "w")
            myfile.write(str(user1))
            myfile.close()

    popup = tk.Tk()
    popup.configure(bg="black")
    popup.title("Mark Attendance")
    ID = tk.StringVar(popup)
    tk.Label(master=popup, text="enter user id", font="none 10 bold",
             fg="white", bg="black").grid(row=2, padx=3, pady=3)
    tk.Entry(master=popup, textvariable=ID, bg="red").grid(row=2, column=1)
    Button = tk.Button(popup, text="Mark", command=attendance_update).grid(
        row=3, column=1, padx=3, pady=3)
    Button = tk.Button(popup, text="Exit", command=popup.destroy).grid(
        row=3, column=2, padx=3, pady=3)


diccc = tk.Button(master=window, text="Create Profile", font="none 10 ",
                  command=create_profile, width=20, height=4).grid(row=6, pady=15)

print(diccc)
tk.Button(master=window, text="View Logs", font="none 10 ",
          width=20, height=4, command=userInfo).grid(row=8, pady=15)
tk.Button(master=window, text="Mark attendence", font="none 10 ",
          width=20, height=4, command=attend).grid(row=2, pady=15)
top = tk.Button(master=window, text="QUIT", fg="red", font="none 10 ",
                command=exitWindow, width=20, height=4).grid(row=10, pady=15)
mycolor = tk.Button(master=window, text="change theme",
                    command=change_color, width=10).grid(row=20, pady=25)

user1 = {}


def file_logs(name_in, age_in, address_in, unique_gen):
    unique_gen = str(unique_gen)

    user1 = {}
    myfile = open("data.txt", "w+")
    myfile.close()
    myfile = open("data.txt", "r+")
    dic = myfile.read()
    print("########", name_in, dic)
    if dic != '':
        user1 = ast.literal_eval(dic)
        print("%%%%%%%%%")
        user1[unique_gen] = {}
        user1[unique_gen]['name'] = name_in
        user1[unique_gen]['age'] = age_in
        user1[unique_gen]['position'] = ''
        user1[unique_gen]['address'] = address_in
        user1[unique_gen]['salary'] = ''
        user1[unique_gen]['attendance'] = 0
        myfile.close()
        myfile = open("data.txt", "w")
        print("$$$$$$$$")
        myfile.write(str(user1))
        myfile.close()
    else:
        myfile.close()
        myfile = open("data.txt", "w")
        myfile.write(str(user1))
        myfile.close()
        myfile = open("data.txt", "r")
        dic = myfile.read()
        user1 = ast.literal_eval(dic)
        user1[unique_gen] = {}
        user1[unique_gen]['name'] = name_in
        user1[unique_gen]['age'] = age_in
        user1[unique_gen]['position'] = ''
        user1[unique_gen]['address'] = address_in
        user1[unique_gen]['salary'] = ''
        user1[unique_gen]['attendance'] = 0
        myfile.close()
        myfile = open("data.txt", "w")
        print("$$$$$$$$")
        myfile.write(str(user1))
        myfile.close()


window.mainloop()
