# This is python code to send certain number of emails to multiple sources
# Here are instructions:
# 1) Enter details within this file near the $$$ sign comments
# 2) Enter email addresses you want to send emails to in 'emails_list.txt' 
# 3) Run code in console
# 4) Enjoy!


import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
 
# Parse text file for list of emails
# Enter emails on separate lines in the text file
with open("email_list.txt") as f:
    content = f.readlines()
content = [x.strip() for x in content]

#Ask user for number of emails
num = int(input("Enter the number of emails you want to send to each person -> "))
# if you don't want to input number of emails every time, you can remove this line and put
# "num = x", where x is number of emails 

#Enter your email data
email_user = 'sender_email@whatever.com' # $$$ your email
email_password = 'sender_password' # $$$ your password

#Subject ... duh
subject = "Title... here" # $$$ title of email here

msg = MIMEMultipart()
msg['From'] = email_user
msg['Subject'] = subject

#Body of your email
body = "Text ... here plz" # $$$ email title

msg.attach(MIMEText(body,'plain'))

for i in range(len(content)):
    #print process to console
    print("---------------")
    print(content[i])
     
    to = content[i]

    x = num

    while x > 0:
        x -= 1 #decrement
        # send server request
        try: 
            text = msg.as_string()
            # this is a gmail port, try other if using other email provider
            server = smtplib.SMTP('smtp.gmail.com',587)
            print(server)
            server.starttls()
            server.login(email_user,email_password)
            server.sendmail(email_user,content[i],text)
            server.quit()

            print ('Email sent!')
            print(" ")
        except: 
            print ('Something went wrong...')
            print(" ")

    print("DONE!")


# With love from Russian hackers 
# TRUMP won because we spilled tea on computer, sry
