<div id="top"></div>

<!-- PROJECT SHIELDS -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links-->


<!-- PROJECT LOGO -->
<br />
<!-- UPDATE -->
<div align="center">


  <h3 align="center">BOIDS SIMULATION</h3>

  <p align="center">
  <!-- UPDATE -->
    <i>Simulating nature’s flocking magic — birds, fish, and swarms in motion</i>
  </p>
</div>


<!-- TABLE OF CONTENTS -->
<details>
<summary>Table of Contents</summary>

- [About The Project](#about-the-project)
- [Getting Started](#getting-started)
  - [Installation](#installation)
- [Usage](#usage)
- [Contact](#contact)
  - [Maintainer(s)](#maintainers)
  - [creators(s)](#creators)
- [Raylib-Quickstart](#Raylib-Quickstart)
<!--- [Additional documentation](#additional-documentation)-->

</details>


<!-- ABOUT THE PROJECT -->
## About The Project
<!-- UPDATE -->
<div align="center">
  <a href="https://github.com/cgs-iitkgp/PROJECT_NAME">
    <img width="80%" alt="image" src="https://github.com/user-attachments/assets/5fa44726-f9fe-4c54-982f-f477db6875ff">
  </a>
</div>


This project demonstrates the simulation of BOIDS using C++ and the raylib graphics library. BOIDS, short for “bird-oid objects,” is a model introduced by Craig Reynolds to simulate the natural flocking behavior seen in groups of birds, fish, or other animals. The system is governed by three core rules: separation (avoiding crowding neighbors), alignment (matching the average direction of nearby boids), and cohesion (moving toward the average position of the group). By applying these simple principles at each frame, complex and lifelike group movement emerges. Raylib is used to render the boids in real time, handle user input, and manage the simulation loop, resulting in an interactive and visually engaging representation of collective motion.

The rules are :

Seperation which makes two boids coming to close to each other move apart.

Alignment which makes a group of neighbouring boids move in the same direction.

Cohesion which causes the nearby boids to try to move towards their respective centre.

<p align="right">(<a href="#top">back to top</a>)</p>

## Getting Started

To set up a local instance of the application, follow the steps below.


### Installation

_Now that the environment has been set up and configured to properly compile and run the project, the next step is to install and configure the project locally on your system._
<!-- UPDATE -->
1. Clone the repository
   ```sh
   git https://github.com/blaZe2603/BOIDS_SIMULATION.git
   ```
2. Execute the script
   ```sh
   press f5 
   ```

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Usage
<!-- UPDATE -->
This project simulates **boid flocking behavior** in C++ using simple rules for separation, alignment, and cohesion.  
It can be used to visualize swarm intelligence, simulate bird flocks, or model fish schools.

<p align="right">(<a href="#top">back to top</a>)</p>

## Contact

### Maintainer(s)

The currently active maintainer(s) of this project.

<!-- UPDATE -->
- [KESHAV BAHETI](https://github.com/blaZe2603)

### Creator(s)

Honoring the original creator(s) and ideator(s) of this project.

<!-- UPDATE -->
- [NAME](https://github.com/GITHUB_USERNAME)

<p align="right">(<a href="#top">back to top</a>)</p>
<!-- 
## Additional documentation
<!-- 
  - [License](/LICENSE)
  - [Code of Conduct](/.github/CODE_OF_CONDUCT.md)
  - [Security Policy](/.github/SECURITY.md)
  - [Contribution Guidelines](/.github/CONTRIBUTING.md)
<!-- 
<p align="right">(<a href="#top">back to top</a>)</p>
-->
<!-- MARKDOWN LINKS & IMAGES -->


[issues-shield]: https://img.shields.io/github/issues/cgs-iitkgp/PROJECT_NAME.svg?style=for-the-badge
[issues-url]: https://github.com/cgs-iitkgp/PROJECT_NAME/issues
[license-shield]: https://img.shields.io/github/license/cgs-iitkgp/PROJECT_NAME.svg?style=for-the-badge
[license-url]: https://github.com/cgs-iitkgp/PROJECT_NAME/blob/master/LICENSE

# Raylib-Quickstart
A simple cross platform template for setting up a project with the bleeding edge raylib code.
Works with C or C++.

## Supported Platforms
Quickstart supports the main 3 desktop platforms:
* Windows
* Linux
* MacOS

# Naming projects
Do not name your game project 'raylib', it will conflict with the raylib library.

# VSCode Users (all platforms)
*Note* You must have a compiler toolchain installed in addition to vscode.

* Download the quickstart
* Rename the folder to your game name
* Open the folder in VSCode
* Run the build task ( CTRL+SHIFT+B or F5 )
* You are good to go

# Windows Users
There are two compiler toolchains available for windows, MinGW-W64 (a free compiler using GCC), and Microsoft Visual Studio
## Using MinGW-W64
* Double click the `build-MinGW-W64.bat` file
* CD into the folder in your terminal
  * if you are usiing the W64devkit and have not added it to your system path environment variable, you must use the W64devkit.exe terminal, not CMD.exe
  * If you want to use cmd.exe or any other terminal, please make sure that gcc/mingw-W64 is in your path environment variable.
* run `make`
* You are good to go

### Note on MinGW-64 versions
Make sure you have a modern version of MinGW-W64 (not mingw).
The best place to get it is from the W64devkit from
https://github.com/skeeto/w64devkit/releases
or the version installed with the raylib installer
#### If you have installed raylib from the installer
Make sure you have added the path

`C:\raylib\w64devkit\bin`

To your path environment variable so that the compiler that came with raylib can be found.

DO NOT INSTALL ANOTHER MinGW-W64 from another source such as msys2, you don't need it.

## Microsoft Visual Studio
* Run `build-VisualStudio2022.bat`
* double click the `.sln` file that is generated
* develop your game
* you are good to go

# Linux Users
* CD into the build folder
* run `./premake5 gmake`
* CD back to the root
* run `make`
* you are good to go

# MacOS Users
* CD into the build folder
* run `./premake5.osx gmake`
* CD back to the root
* run `make`
* you are good to go

# Output files
The built code will be in the bin dir

# Working directories and the resources folder
The example uses a utility function from `path_utils.h` that will find the resources dir and set it as the current working directory. This is very useful when starting out. If you wish to manage your own working directory you can simply remove the call to the function and the header.

# Changing to C++
Simply rename `src/main.c` to `src/main.cpp` and re-run the steps above and do a clean build.

# Using your own code
Simply remove `src/main.c` and replace it with your code, and re-run the steps above and do a clean build.

# Building for other OpenGL targets
If you need to build for a different OpenGL version than the default (OpenGL 3.3) you can specify an OpenGL version in your premake command line. Just modify the bat file or add the following to your command line

## For OpenGL 1.1
`--graphics=opengl11`

## For OpenGL 2.1
`--graphics=opengl21`

## For OpenGL 4.3
`--graphics=opengl43`

## For OpenGLES 2.0
`--graphics=opengles2`

## For OpenGLES 3.0
`--graphics=opengles3`

# License
Copyright (c) 2020-2025 Jeffery Myers

This software is provided "as-is", without any express or implied warranty. In no event 
will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial 
applications, and to alter it and redistribute it freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not claim that you 
  wrote the original software. If you use this software in a product, an acknowledgment 
  in the product documentation would be appreciated but is not required.

  2. Altered source versions must be plainly marked as such, and must not be misrepresented
  as being the original software.

  3. This notice may not be removed or altered from any source distribution.
