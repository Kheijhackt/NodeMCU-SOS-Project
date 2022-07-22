# Importing modules
import urllib.request
import pymysql

# Declarations
url = "http://192.168.1.103/" # EDIT
counter = 1

# Function definitions
def sendSOS(senderNo):
    db = pymysql.connect(
        host = "sql6.freemysqlhosting.net",
        user = "sql6496157",
        password = "VScNHRCZqQ",
        database = "sql6496157",
        port = 3306
    )
    cursor = db.cursor()
    insert = "INSERT INTO cpe101_final_project_g9 (senderNo) VALUES ({})".format(senderNo)
    cursor.execute(insert)
    db.commit()
    return True

def get_data():
    global data

    n = urllib.request.urlopen(url).read()
    n = n.decode("utf-8") 
    
    data = n

# Main loop
while True:
    get_data()
    sendSOS(data)
    print("{}. SOS has been sent to the base! <NodeMCU{}>".format(counter, data))
    counter += 1