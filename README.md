# MIECT_KIT

## How to use:

1. Assemble the kit
1. [Install Arduino IDE](https://www.arduino.cc/en/main/software "download")
2. Download the code files
3. Install ESP8266 Add-on in Arduino IDE:
4. Uploade your code
5. Have fun!

## Assemble the kit

Pick up all the components and assemble them as shown below:  
![Insert link](https://github.com/FilipeMiguelVale/MIECT_KIT/blob/master/Images/Board%20Final1.jpg)

After this, plug the NodeMCU to your USB port and check if a blue led blink's!

## Install ESP8266 Add-on in Arduino IDE
1. In your Arduino IDE, go to **File> Preferences**:

![Find the preferences](https://github.com/FilipeMiguelVale/MIECT_KIT/blob/master/Images/Prints/preferences.jpg)

2. Enter the link below into the “Additional Boards Manager URLs” field as shown in the figure below. Then, click the “OK” button:
>  http://arduino.esp8266.com/stable/package_esp8266com_index.json

![Insert link](https://github.com/FilipeMiguelVale/MIECT_KIT/blob/master/Images/Prints/preferences2.jpg)
![Find the preferences](https://github.com/FilipeMiguelVale/MIECT_KIT/blob/master/Images/Prints/preferences3.jpg)

3. Open the Boards Manager. Go to **Tools > Board > Boards Manager**:
![find board](https://github.com/FilipeMiguelVale/MIECT_KIT/blob/master/Images/Prints/board1.jpg)

4. Search for **ESP8266** and press install button for the **“ESP8266 by ESP8266 Community“**:
It should be installed after a few seconds
![find board](https://github.com/FilipeMiguelVale/MIECT_KIT/blob/master/Images/Prints/board2.jpg)

## Uplode your code

1. Go to **Tools > Board** and make sure that the **NodeMCU 1.0 (ESP-12E Module)** is selected :
![find board](https://github.com/FilipeMiguelVale/MIECT_KIT/blob/master/Images/Prints/board3.jpg)

2. Select the **COM PORT** that yout ESP is plugged in
3. Make sure that your **Upload Speed** is **115200**
4. Make sure that your **CPU Frequeny** is **160Mhz**

## Have Fun!
After uploading your code to the NodeMCU you should see the **green and the red led's ON**
Connect your device to the "**IOTKIT**"  
![find board](https://github.com/FilipeMiguelVale/MIECT_KIT/blob/master/Images/Prints/Ethernet1.jpg)

Go to your browser check this URL: **192.168.1.1** 

![find board](https://github.com/FilipeMiguelVale/MIECT_KIT/blob/master/Images/Prints/Ethernet2.jpg)
turn **ON** and **OFF** the led's and have fun!

## Support
mail: NEECT@aauav.pt
## Important Links
