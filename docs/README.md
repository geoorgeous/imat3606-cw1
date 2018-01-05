# IMAT3606 Games Programming CW1

Welcome to the repository for my IMAT3606 (Games Programming) project! This project is intended for the submission of the module's first coursework. It's a very basic 3D game engine which focusses on demonstrating several game engine related techniques and technical skills including:
 - 3D games programming in C++ using OpenGL
 - Object Oriented Programming
 - Component-based systems
 - C++ interfaces
 - Data-driven engine architecture
 - Object serialization and parsing (JSON)
 
 ### [Read the documentation!](https://george-mcdonagh.github.io/imat3606-cw1/documentation/)
 
 ---

### Directory Structure

The project directory is laid out as follows:
 - __dependencies__: All third party project dependencies. 
   - __include__: Library include files (.h/.hpp).
   - __libs__: Library binary files (.lib).
 - __docs__: All project realted documents.
   - __documentation__: doxygen-generated documentation.
 - __imat3606-cw1__: Visual Studio solution folder.
   - __bin__: Project binaries (Debug/Release, Win32/x64).
   - __include__: Project header files.
   - __res__: Project resources (assets, data files, etc).
   - __src__: Project source files.
   - __temp__: Visual Studio intermediate/temporary files for each build configuration.
   
---

### Project Dependencies

My project depends on various third-party libraries and source code. See below for a listing of these libraries.
 
Name | Use
--- | ---
[__GLEW__](http://glew.sourceforge.net/) | OpenGL extension wrangler - loads all of the OpenGL implementation's function headers
[__GLFW__](http://www.glfw.org/) | OpenGL context creation
[__Assimp__](http://assimp.sourceforge.net/) | 3D asset importing
[__DearImgui__](https://github.com/ocornut/imgui) | Easy to use, easy to implement, extensive immediate-mode GUI
[__stb_image.h__](https://github.com/nothings/stb/blob/master/stb_image.h) | Single header file for image file reading
[__fmt__](https://github.com/fmtlib/fmt) | C++ safe `printf` alternative used for logging. Allows for fast print-string formatting.

While [GLM](https://glm.g-truc.net/0.9.8/index.html) is generally recommended as the best OpenGL maths library, I've challenged myself to write my own simple maths library. This includes only exactly what I need for the engine and is built upon as and when need be. Currently the library only includes matrix and vector mathematics.

---

I'm using GitHub and Visual Studio's Team Explorer to source control the project. This allows me to keep track of the project's development and also keeps my progress safe in the cloud. [I'm also using GitHub issues](https://github.com/george-mcdonagh/imat3606-cw1/issues) to make notes for myself on how things should work or things that need doing. [Doxygen](http://www.stack.nl/~dimitri/doxygen/) is being used to generate HTML documentation for the bulk of my source code. You can view the latest documentation [here](https://george-mcdonagh.github.io/imat3606-cw1/documentation/).
