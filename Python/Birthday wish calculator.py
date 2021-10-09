import datetime
current_date=datetime.date.today().strftime('%Y-%m-%d')
current_date_ist=current_date.split('-')
b_date=input("Enter birthday date in year-month-date format : ")
name=input("Name of birthday legend : ")
b_date=b_date.split('-')
if current_date_ist[1] == b_date[1] and current_date_ist[2] == b_date[2] :
    age=int(current_date_ist[0]) - int(b_date[0])
    ordinal_suffix={1 : 'st',2 : 'nd',3 : 'rd',11 : 'th',12 : 'th',13 : 'th'}.get(age % 10 if not 10 < age <= 13 else age % 14,'th' )
    print(f" it's {name}'s {age}{ordinal_suffix} birthday" )
else:
    print("sorry today is not your birthday")

#Please enter your date of birth year-month-date format
