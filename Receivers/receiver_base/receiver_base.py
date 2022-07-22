# Importing modules
import urllib.request
import http
import pymysql

# Declarations
base = "http://192.168.1.102/" # EDIT
noSOS = True
counter = 1

# Function definitions
def transfer(data1):
    try:
        n = urllib.request.urlopen(base + data1).read()
        n = n.decode("utf-8")
        return n

    except http.client.HTTPException as e:
        return e
    
def deleteLast():
    db = pymysql.connect(
        host = "sql6.freemysqlhosting.net",
        user = "sql6496157",
        password = "VScNHRCZqQ",
        database = "sql6496157",
        port = 3306
    )
    cursor = db.cursor()
    delete = "DELETE FROM cpe101_final_project_g9 ORDER BY timeStamp DESC limit 1"
    cursor.execute(delete)
    db.commit()
    
def receiveFromDatabase():
    db = pymysql.connect(
        host = "sql6.freemysqlhosting.net",
        user = "sql6496157",
        password = "VScNHRCZqQ",
        database = "sql6496157",
        port = 3306
    )
    cursor = db.cursor()
    select = """SELECT * FROM cpe101_final_project_g9 ORDER BY timeStamp DESC
                    LIMIT 1"""
    cursor.execute(select)
    retrieve = cursor.fetchone()
    return retrieve

# Main loop
while(True):
    try:
        received = receiveFromDatabase()
        print("{}. SOS/<NodeMCU{}>".format(counter, received[1]))
        transfer(str(received[1]))
        deleteLast()
        counter += 1
    except:
        continue
