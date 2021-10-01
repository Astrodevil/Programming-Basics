def replace(str,a,b):
    if len(str) == 1:
        if str == a:
            return b
        else:
            return str
    
    if str[0] == a:
        return b + replace(str[1:],a,b)
    else:
        return str[0] + replace(str[1:],a,b)

str = 'Hacktoburfest2021'
#Opops there is a mistake in the spelling , Let's replace

replaced_str = replace(str,'u','e')

print(replaced_str) #Output = Hacktoberfest2021

# we have replaced it 🥳🥳🥳
