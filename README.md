# Wordle

A brief description of what this project does and who it's for

## Building the program

The below command will make a new executable/equivalent

```bash {"id":"01J6WZ5475C5VKJF1Y4H4HQVXC"}
gcc wordle.c color.c randomindex.c wordcheck.c hash.c -o wordle 
```

## Run Locally

Clone the project

```bash {"id":"01J6WZ5476B3T2H75SW9AQ2Z83"}
  git clone https://github.com/smresponsibilities/Wordle
```

Go to the project directory

```bash {"id":"01J6WZ5476B3T2H75SWBA0ZHDY"}
  cd Wordle
```

Running the project

For linux (as i have already given a prebuilt file)

```bash {"id":"01J6WZ5476B3T2H75SWH9QRR4R"}
  ./wordle  
```

For windows, both commands are individually capable enough to run the program

```bash {"id":"01J71YET5SHQ310X2ZJ5YMQYH0"}
 wordle.exe
```

```bash {"id":"01J727AW1WJVX36T5N5GFD2B1V"}
.\wordle
```

## Features

- A single word for the whole day
- Implemented a pseudo hash technique with no collisions
- Very modular
- Cross platform

## Running Tests

To run tests, go to the test directory on your machine

```bash {"id":"01J71Z0343QPEB3AYS0HMT7J3G"}
 cd test
```

To run the script on Windows , either run the below bat file or the next commands

```bash {"id":"01J6WZ5476B3T2H75SWKG4J3EM"}
./test.bat 
```

```bash {"id":"01J6WZA2VB89ZTG611BNCZF8FD"}
gcc -I.. ../hash.c ../randomindex.c testhash.c testrandom.c maintest.c -o maintest 
./maintest
```

To run the tests on Linux , run the following script

```bash {"id":"01J6WZC1VX396Z6Z4HH9SMTZEZ"}
sh test.sh
```

## Demo

Insert gif or link to demo

## Roadmap

- Transition from terminal to gui
- Add more words and slangs
- Using socket

## Screenshots

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)

## Author

- [@smresponsibilities](https://www.github.com/smresponsibilities)