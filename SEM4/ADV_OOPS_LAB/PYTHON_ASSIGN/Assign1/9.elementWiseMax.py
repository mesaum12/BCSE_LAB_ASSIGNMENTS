studentlist=["Saurabh","Sachin","Abhishek","Sagar"]
subjectList=["ComputerScience","Biology","FoodProduction","StrengthOfMaterials"]
MarksList=[99,99,100,99]
list1=list(zip(studentlist,subjectList,MarksList))
print(list1)
# list1 created using zip
name,subject,marks=" "," ",0
for element in list1:
    if element[0]>name:
        name=element[0]
    if element[1]>subject:
        subject=element[1]
    if element[2]>marks:
        marks=element[2]

print("Name:"+name+" Subject:"+subject+" Marks:",marks)