# About
**This repo hold all files from a PC terminal applicaton which grabs ARINC429 data from a flight sensor (wireless aircraft data/statistics collection sensor), translates from ARINC429, & displays relevant data on the terminal. It is being designed by me for AirBus to be used in all future flight testing. Currently, I am working on an Android version as well.**

# Compilation
  1. Open PowerShell in Administrator mode
  2. Type: ```wsl``` 
      - Hit enter
  3. Type: ```sudo apt update``` 
      - Hit enter
  4. Type: ```sudo apt install g++```
      - Hit enter
  5. Navigate to the extracted folder within wsl
  6. Type: ```g++ -c main.cpp -o main.o```
      - Hit enter
  7. Type: ```g++ -o main main.o -lbtiCard -L.```
      - Hit enter
  8. Type: ```LD_LIBRARY_PATH="$(pwd)" ./main```
      - Hit enter
