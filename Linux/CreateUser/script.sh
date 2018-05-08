#!/bin/bash

USER=''
GROUP=''

echo "##############################"
echo "0 Creating users"
echo "1 Change username"
echo "2 Change login user"
echo "3 Add users to a group"
echo "4 Add user to SUDO"
echo "5 Change user password"
echo "6 Delete users"
echo "7 Creating groups"
echo "8 Change group name"
echo "9 Delete groups"
echo "10 info"
echo "11 EXIT"
echo "##############################"

while true; do
echo -n "Select Menu: "
read verb
case $verb in
0)
#Creating users
echo -n "Enter the name for the user: "
read USER
sudo useradd USER
echo "Command completed"
;;
1)
#Change username
echo -n "Enter the username: "
read USER
echo -n "Enter the NEW username: "
read GROUP
sudo usermod -l GROUP -d /home/GROUP -m USER
echo "Command completed"
;;
2)
#Change login users
echo -n "Enter the name for the user: "
read USER
su USER
echo "Command completed"
;;
3)
#Add users to a group
echo -n "Enter the name for the user: "
read USER
echo -n "Enter the name for the group: "
read GROUP
sudo usermod -a -G GROUP USER
echo "Command completed"
;;
4)
#Add user to SUDO
echo "Add this line below the root"
echo "Username    ALL=(ALL:ALL) ALL"
sleep 5
visudo
echo "Command completed"
;;
5)
#Change user password
echo -n "Enter the name for the user: "
read USER
sudo passwd USER
echo "Command completed"
;;
6)
#Delete users
echo -n "Enter the name for the user: "
read USER
userdel -r USER
echo "Command completed"
;;
7)
#Creating groups
echo -n "Enter the name for the group: "
read GROUP
sudo groupadd GROUP
echo "Command completed"
;;
8)
#Change group name
echo -n "Enter the group name: "
read GROUP
echo -n "Enter the NEW group name: "
read USER
sudo groupmod -n USER GROUP
echo "Command completed"
;;
9)
#Delete groups
echo -n "Enter the name for the group: "
read GROUP
sudo groupdel GROUP
echo "Command completed"
;;
10)
#info
echo "##############################"
cat /etc/passwd
echo "##############################"
cat /etc/group
echo "##############################"
groups
echo "##############################"
id
echo "##############################"
#info
;;
11)
exit 0
;;
*)
echo "Choose the correct options"
;;
esac
done