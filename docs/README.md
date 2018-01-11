# IMAT3606 Games Programming CW1

Welcome to the repository for my IMAT3606 (Games Programming) project! This project is intended for the submission of the module's first coursework. It's a very basic 3D game engine which focusses on demonstrating several game engine related techniques and technical skills including:
 - 3D games programming in C++ using OpenGL
 - Object Oriented Programming
 - Component-based systems
 - C++ interfaces
 - Data-driven engine architecture
 - Object serialization and parsing (JSON)
 
 I'm using GitHub and Visual Studio's Team Explorer to source control the project. This allows me to keep track of the project's development and also keeps my progress safe in the cloud. [I'm also using GitHub issues](https://github.com/george-mcdonagh/imat3606-cw1/issues) to make notes for myself on how things should work or things that need doing. [Doxygen](http://www.stack.nl/~dimitri/doxygen/) is being used to generate HTML documentation for the bulk of my source code. __You can view the latest documentation by downloading the repository and opening ```docs/documentation/index.html``` in your favourite browser__.

## Project Progress

A bird's eye view of the progress of this project according to the [project specification](https://github.com/george-mcdonagh/imat3606-cw1/blob/master/docs/coursework_spec.docx).
 
 - [ ] Components
 - [x] Interfaces
 - [ ] Data Driven Architexture
 - [ ] Input
 - [ ] Camera
   - [x] First Person
   - [ ] Third Person
 - [ ] Asset Pipeline
   - [ ] Scene Creation, Exporting, Importing with Maya
 - [ ] Software testing
   - [ ] Unit Tests
   - [ ] Runtime Debugging GUI
 - [ ] Professional Practices
   - [x] Documentation
   - [ ] Project Brief
   - [x] Source Control Management

## Directory Structure

The project directory is laid out as follows:
 - __```./dependencies/```__: All third party project dependencies. 
   - __```include/```__: Library include files (.h/.hpp).
   - __```libs/```__: Library binary files (.lib).
 - __```./docs/```__: All project realted documents.
   - __```documentation/```__: doxygen-generated documentation.
 - __```./imat3606-cw1/```__: Visual Studio solution folder.
   - __```bin/```__: Project binaries (Debug/Release, Win32/x64).
   - __```include/```__: Project header files.
   - __```res/```__: Project resources (assets, data files, etc).
   - __```src/```__: Project source files.
   - __```temp/```__: Visual Studio intermediate/temporary files for each build configuration.

## Project Dependencies

My project depends on various third-party libraries and source code. See below for a listing of these libraries.
 
__Name__ | __Use__
--- | ---
[__GLEW__](http://glew.sourceforge.net/) | OpenGL extension wrangler - loads all of the OpenGL implementation's function headers.
[__GLFW__](http://www.glfw.org/) | OpenGL context creation.
[__Assimp__](http://assimp.sourceforge.net/) | 3D asset importing.
[__DearImgui__](https://github.com/ocornut/imgui) | Easy to use, easy to implement, extensive immediate-mode GUI.
[__stb_image.h__](https://github.com/nothings/stb/blob/master/stb_image.h) | Single header file for image file reading.
[__fmt__](https://github.com/fmtlib/fmt) | C++ safe `printf` alternative used for logging. Allows for fast print-string formatting.
[__jsoncpp__](https://github.com/open-source-parsers/jsoncpp) | C++ library for interacting with JSON.

While [GLM](https://glm.g-truc.net/0.9.8/index.html) is generally recommended as the best OpenGL maths library, I've challenged myself to write my own simple maths library. This includes only exactly what I need for the engine and is built upon as and when need be. Currently the library only includes matrix and vector mathematics.
