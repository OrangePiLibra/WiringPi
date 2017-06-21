WiringPi on OrangePi
-----------------------------------------------

The Open source project of WiringPi on OrangePi. maintain from www.orangepi.org

### Usage

  * Download

    ```
      On OrangePi 2G-IOT:
        env GIT_SSL_NO_VERIFY=true git clone https://github.com/OrangePiLibra/WiringPi.git 
      On Other board:
        git clone https://github.com/OrangePiLibra/WiringPi.git
    ```
  * Compile and install wiringPi
   
    On OrangePi 2G-IOT

    ```
      cd WiringPi
      sudo ./build OrangePi_2G-IOT
      sudo ./build OrangePi_2G-IOT install
    ```
    On OrangePi PC2

    ```
      cd WiringPi
      sudo ./build OrangePi_PC2
      sudo ./build OrangePi_PC2 install
    ```
    On OrangePi Win/Win plus

    ```
      cd WiringPi
      sudo ./build OrangePi_A64
      sudo ./build OrangePi_A64 install
    ```
    On OrangePi PC/PC plus/One/Lite/PC plus

    ```
      cd WiringPi
      sudo ./build OrangePi_H3
      sudo ./build OrangePi_H3 install
    ```
    On OrangePi Zero

    ```
      cd WiringPi
      sudo ./build OrangePi_ZERO
      sudo ./build OrangePi_ZERO install
    ```
  * Utilze WiringPi

    The location of demo code for WiringPi on OrangePi as follow:
    ```
      cd WiringPi/example/OrangePi
      make OrangePi
      ./OrangePi
    ```
  
  * More information

    More information about WiringPi on OrangePi, please refer:
    ```
      cd  WiringPi/example/OrangePi
      cat README.md
    ```
  * Gpio readall
   
    Use command `gpio readall`.

    ```
       orangepi@orangepi:~$ gpio readall
       +-----+-----+----------+------+---+--OrangePi+---+------+---------+-----+--+
       | BCM | wPi |   Name   | Mode | V | Physical | V | Mode | Name     | wPi | BCM |
       +-----+-----+----------+------+---+----++----+---+------+----------+-----+-----+
       |     |     |     3.3v |      |   |  1 || 2  |   |      | 5v       |     |     |
       |   2 |  -1 |    SDA.0 |      |   |  3 || 4  |   |      | 5V       |     |     |
       |   3 |  -1 |    SCL.0 |      |   |  5 || 6  |   |      | 0v       |     |     |
       |   4 |   6 | IO6 PA06 |  OUT | 0 |  7 || 8  |   |      | TxD3     |     |     |
       |     |     |       0v |      |   |  9 || 10 |   |      | RxD3     |     |     |
       |  17 |  -1 |     RxD2 |      |   | 11 || 12 | 0 | OUT  | IO1 PD14 | 1   | 18  |
       |  27 |  -1 |     TxD2 |      |   | 13 || 14 |   |      | 0v       |     |     |
       |  22 |  -1 |     CTS2 |      |   | 15 || 16 | 0 | OUT  | IO4 PC04 | 4   | 23  |
       |     |     |     3.3v |      |   | 17 || 18 | 0 | OUT  | IO5 PC07 | 5   | 24  |
       |  10 |  -1 |     MOSI |      |   | 19 || 20 |   |      | 0v       |     |     |
       |   9 |  -1 |     MISO |      |   | 21 || 22 |   |      | RTS2     |     |     |
       |  11 |  -1 |     SCLK |      |   | 23 || 24 |   |      | SPI-CE0  |     |     |
       |     |     |       0v |      |   | 25 || 26 |   |      | CE1      |     |     |
       |   0 |  -1 |    SDA.1 |      |   | 27 || 28 |   |      | SCL.1    |     |     |
       |   5 |   7 |  IO7 PA7 |  OUT | 0 | 29 || 30 |   |      | 0v       |     |     |
       |   6 |   8 |  IO8 PA8 |  OUT | 0 | 31 || 32 | 0 | OUT  | IO9 PG08 | 9   | 12  |
       |  13 |  10 | IO10 PA9 |  OUT | 0 | 33 || 34 |   |      | 0v       |     |     |
       |  19 |  12 | IO12PA10 |  OUT | 0 | 35 || 36 | 0 | OUT  | IO13PG09 | 13  | 16  |
       |  26 |  14 | IO14PA20 |  OUT | 0 | 37 || 38 | 0 | OUT  | IO15PG06 | 15  | 20  |
       |     |     |       0v |      |   | 39 || 40 | 0 | OUT  | IO16PG07 | 16  | 21  |
       +-----+-----+----------+------+---+----++----+---+------+----------+-----+-----+
       | BCM | wPi |   Name   | Mode | V | Physical | V | Mode | Name     | wPi | BCM |
       +-----+-----+----------+------+---+--OrangePi+------+----------+-----+-----+
      ```
