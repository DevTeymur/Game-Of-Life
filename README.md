# Game-Of-Life

## How to run

After clonning the repo, go inside build directory

* cd build
*  cmake ../
After the makefile will be created inside build folder.
* make
* ./gameoflife

## Requirements
### Setting up SDL 2 on Linux

For those of you who have Advanced Packaging Tool available (ie Ubuntu and Debian) you'll want to search the apt-get cache to find the current SDL 2 version to install. You can search the apt-get available packages using the command:
```sh
apt-cache search libsdl2
```
<br>
You'll want to download the development version of SDL 2. As of the last update of this tutorial, the development package of SDL 2 is libsdl2-dev. You can install this package using the command:

```sh
apt-get install libsdl2-dev
```
### If you are using another system like Windows, macOS etc.<br>
You can look at documentation [here] (https://wiki.libsdl.org/Installation)

sudo apt-get install libsdl2-2.0

### Setting up Image loading library for SDL 2 on Linux <br>
Install libsdl2-image-dev by entering the following commands in the terminal:

```sh
sudo apt update
sudo apt install libsdl2-image-dev
```
