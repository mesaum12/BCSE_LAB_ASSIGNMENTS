import re
def validPhoneNumber(phone_number):
    check_string=re.compile("(0/91)?[789][0-9]{9}")
    return check_string.match(phone_number)

phone_num=input("Enter a phone number to check for validity(for India):")

if validPhoneNumber(phone_num):
    print("Yes, the number is valid!")
else:
    print("Oops! Invalid number entered")
