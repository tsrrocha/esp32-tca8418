# KeyPad with ESP32 using TCA8418

This project uses the integrated circuit (IC) TCA8418, a keypad scanner with I2C interface, for keypad 4 columns per 4 rows (4x4).
I write a I2C gatekeeper to control the use of I2C bus. Only the gatekeeper can use the resource I2C bus.


## Pinout

In this project, the GPIO pins for I2C communication interface are 21 and 22. The pin 21 is SDA (data) and pin 22 is SCL (clock).


|Pinout|Name|Description||
|:----:|:---:|:---|:---|
|21|SDA (data)|The Data pin for I2c communication||
|22|SCL (clock)|The Clock pin for I2c communication||
|17|INT (Interrupt keypad)|The interrupt pin when any key is pressed||


## OK






(See the README.md file in the upper level 'examples' directory for more information about examples.)

This is the simplest buildable example. The example is used by command `idf.py create-project`
that copies the project to user specified path and set it's name. For more information follow the [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project)



## How to use example
We encourage the users to use the example as a template for the new projects.
A recommended way is to follow the instructions on a [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project).

## Example folder contents

The project **sample_project** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both). 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  This is the file you are currently reading
```
Additionally, the sample project contains Makefile and component.mk files, used for the legacy Make based build system. 
They are not used or needed when building with CMake and idf.py.
