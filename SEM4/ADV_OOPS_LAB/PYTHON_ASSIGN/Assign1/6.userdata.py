import re
check_pattern="^(\w|\.|\_|\-)+[@](\w|\_|\-|\.)+[.]\w{2,3}$"
def is_valid_email(email_id):
    if re.match(check_pattern,email_id):
        return True
    else:
        return False

user_data=[("Saurabh","mesaurabh37@gmail.com",21),("Samir","hellosamir",14),("Lisa","lisa@yahoo.com",19),("Rajesh","raj123@gmail.com",15)]
user_name_set=set()

file=open("saurabh.txt","a")
for element in user_data:
    if element[0] in user_name_set:
        raise Exception("Duplicate name")
    elif element[2]<0:
        raise Exception("Sorry age cannot be negative")
    elif element[2]<16:
        raise Exception("The age is below 16 yrs")
    elif is_valid_email(element[1]) == False:
        raise Exception("The email id is not valid")
    if element[2]>16:
        file.write("Name:"+element[0]+" EmailId:"+element[1]+"\n")
        print("Data written successfully")
    user_name_set.add(element[0])





