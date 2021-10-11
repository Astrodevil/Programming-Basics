#helper dictionary containes english words of some required numbers
numInEng={0:'',1:'One',2:'Two',3:'Three',4:'Four',
        5:'Five',6:'Six',7:'Seven',8:'Eight',9:'Nine',
        10:'Ten',11:'Eleven',12:'Twelve',13:'Thirteen',
        14:'Fourteen',15:'Fifteen',16:'Sixteen',
        17:'Seventeen',18:'Eighteen',19:'Nineteen',
        20:'Twenty',30:'Thirty',40:'Fourty',50:'Fifty',
        60:'Sixty',70:'Seventy',80:'Eighty',90:'Ninety',
        100:'Hundred',1000:'Thousand'}
        
def convertToList(num):
    temp=[int(a) for a in str(num)]
    return temp
    
def numToText(num):
    if(num==0):
        print("Zero")
    elif(num>=1 and num<=20):
        print(numInEng[num])
    else:
        lst = convertToList(num)
        numberofdigits=len(lst)
        # print(lst)
        if(numberofdigits==2):
            if(num in numInEng):
                print(numInEng[num])
            else:
                print(numInEng[lst[0]*10]+" "+numInEng[lst[1]])
        elif(numberofdigits==3):
            if(num in numInEng):
                print(numInEng[num])
            else:
                print(numInEng[lst[0]]+" "+numInEng[100]+" "+numInEng[lst[1]*10]+" "+numInEng[lst[2]])
        elif(numberofdigits==4):    
            if(num in numInEng):
                print("One "+numInEng[num])
            else:
                print(numInEng[lst[0]]+" "+numInEng[1000]+" "+numInEng[lst[1]]+" "+numInEng[100]+" "+numInEng[lst[2]*10]+" "+numInEng[lst[3]])
        else:
            print("Please enter a 4 digit Number")

if __name__ == '__main__':
    num = int(input("Enter a 4 digit Number\n"))
    numToText(num)


#uncomment this code to test add any number of your choice in 4 digit range the tests list
    # tests=[0,1,10,50,99,999,1000,2000,2222,3434,5656,7777,8989,9988,0000,9999]
    # for each in tests:
    #     numToText(each)
