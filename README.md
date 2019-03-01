<p align="center">
  <img src="logo.png" width="300">
</p>

# Inject
After getting tired of writing things like
 ```c++
#include <iostream> using namespace std; int main(int argc, char* argv[]) { ... }
  ```

and  

```html
<DOCTYPE!html><htmllang="en"><head><meta charset="utf-8">...
```
over and *over* and ***over*** again, I decided to write Inject. Inject is a command line tool that implements the new C++17 filesystem library. Inject pipes template files right into your current directory to aid in development. For example, if you want a basic index HTML file, you can just type:
```bash
C:/.../your_directory$ inject html file  
```
and an HTML file will be piped right into your directory. Quick and simple!

## Install
To install Inject, you must have a C++ with the `std::filesystem` (C++17 for example). Then, download and navigate to this repository on your command line and run the command:
```bash
C:/.../inject$ g++ -std=c++17 inject.cpp -o inject -lstdc++fs
```
After compiling, you will need to add `inject.exe` to your `PATH` variable so that you can call `inject` anywhere from the command line.

## Planned Features
Features that are being planned or currently in development:
* **Directory Injection**: This will allow you to inject whole template projects. For example, you can rapidly set up a BrowserSync web-development environment by calling `$ inject BrowserSync project`
* **File Variables**: This will allow you to fill in simple variables into a file. For example, if you want to make an HTML file titled "Homepage" you can call `$inject html file title=Homepage` and it will plug in:
```html
<title>Homepage</title>
```
