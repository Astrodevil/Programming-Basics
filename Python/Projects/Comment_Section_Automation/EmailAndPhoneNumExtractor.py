import re

# Read the text file from which you need to extract email ids and phone no.s 
file = open("your_text_file.txt","r")
reading = file.read()

a=reading.split("\n\n")

emails = []
phone = []
mobile = []

for i in a:
    emailRegex = re.compile(r'[\w\.]+@[\w\.]+')
    em = emailRegex.findall(i)
    phoneRegex = re.compile(r'\d\d\d-\d\d\d\d-\d\d\d\d')
    ph = phoneRegex.findall(i)
    mobileRegex = re.compile(r'\d{10}')
    mob = mobileRegex.findall(i)
    if em:
        emails.append(em)
    else:
        emails.append(None)
    if ph:
        phone.append(ph)
    else:
        phone.append(None)
    if mob:
        mobile.append(mob)
    else:
        mobile.append(None)
    
maping = zip(emails, phone, mobile)
maping = list(maping)
print(maping)
    
# Write all the extracted info into a separate text file
fptr = open("PhoneandEmail.txt", "w")
for i in range(0, len(maping)) :
    a = str(maping[i])
    print(maping[i])
    fptr.write(a + '\n')

fptr.close()
file.close()
