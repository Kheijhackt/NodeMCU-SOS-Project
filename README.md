# NodeMCU-SOS-Project
This project uses 5 NodeMCUs together. One is for the base, and the other four act as a sender of the signal to the base. The base acts as the receiver.

## The Developers
- Aurelio, Jethro
- Batingan, Michael
- Bernas, Alexandra
- Pornobi, Lloyd Aldrin
- Tubalinal, Kian Jacob Anthony
---
## Configurations
CONFIGURATIONS: 
1. Gather at least 5 participants for this project.
2. One participant will be the base and the other four participants
	will be the senders. 
3. Assign whose going to be the sender 1, 2, 3, and 4.
4. Each sender will have their corresponding sender folder based 
	on their numbers and will modify them based on some
	conditions. This also applies to the base.
5. Press "Ctrl + F" on your keyboard and find the word "//EDIT". 
6. The lines that has the "//EDIT" word are the only lines that
	are modifiable. You can only modify the "pins" and the 
	"Wi-fi credentials" of the code. 
7. Modify the pins depending on which pins did you use to connect
	the LEDs and the button. 
8. Modify the Wi-fi credentials depending on your Wi-fi network. 
	NOTE: Your network should have internet access. 
9. Each sender have the same python code, "sender_general.py".
10. Show serial monitor. Run the ".ino" file. 
11. Edit the "url" variable on the "sender_general.py" file and 
	change it depending on what IP address did you get from the
	serial monitor of your ".ino" file.
12. For the base of this project, do step 5 to 8 as well. NOTE: The
	python code of the base is placed on the "Receivers" folder
	that is named "receiver_base.py".

NOTE: This project uses our own personal-created database, if you want
	to use yours, just modify the connectors on the python files. The table of the database consists of a timestamp, and
	an integer column. The integer column is where the sender
	number of this project will be placed, whether it is a 
	sender 1, 2, 3, or 4.
---
## How to Use
1. The senders will press and hold the button for at least 3 seconds. 
2. When the button is being pressed, the built-in LED of the NodeMCU
	will light up. This will serve as your guide whether you're 
	really pushing the button or not. If this LED won't light up,
	check your circuit and follow the schematic diagrams properly.
3. If the button is pressed for 3 seconds, the built-in LED will be 
	turned off.
4. The red and white LED will blink alternately for 3 seconds.
	NOTE: You cannot send an SOS within this 3 seconds. 
5. When an SOS is sent to the base, the LEDs on the base will light
	up respectively, depending on which sender sent an SOS from.
6. The base will now respond to the SOS by pressing the corresponding
	button. Each button will turn off a single respective LED.
7. This means that the role of the base is to just wait for an SOS 
	message from the senders. 
8. Both senders and the base may look up on their monitor of the 
	python file to check for its activity log.
