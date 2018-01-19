# IMAT3606 Games Programming CW1

Welcome to the repository for my IMAT3606 (Games Programming) project! This project is intended for the submission of the module's first coursework. It's a very basic 3D game engine which focusses on demonstrating several game engine related techniques and technical skills including:
 - 3D games programming in C++ using OpenGL
 - Object Oriented Programming
 - Component-based systems
 - C++ interfaces
 - Data-driven engine architecture
 - Object serialization and parsing (JSON)
 
I'm using GitHub and Visual Studio's Team Explorer to source control the project. This allows me to keep track of the project's development and also keeps my progress safe in the cloud. [I'm also using GitHub issues](https://github.com/george-mcdonagh/imat3606-cw1/issues) to make notes for myself on how things should work or things that need doing. [Doxygen](http://www.stack.nl/~dimitri/doxygen/) is being used to generate HTML documentation for the bulk of my source code. __You can view the latest documentation by downloading the repository and opening ```docs/documentation/index.html``` in your favourite browser__.

## Overview

### Asset Management

The AssetManager class handles all loading and unloading of assets such as 3D meshes and Shader Program files (which contain all shader program source code). AssetManager is implemented statically - in order to load an asset the programmer would call ```AssetManager::getAsset("asset/filepath/and_name.ext")```. From here, the AssetManager will either load the Asset in to its static cache if it hasn't already been loaded, or it will simply retrieve it from the cache and return it.. Similarly, to unload an asset, the programmer would call ```AssetManager::unloadAsset("asset/filepath/and_name.ext")```. I have tried to create an asset management system which has is minimal effort in terms of using the API. As the sytem is static, ```AssetManager::unloadAll()``` must be called before the application exits in order to avoid memeory leaks.

### Debugging

To help me with debugging I wanted to create a robust logging system that would allow me to avoid the constant use of ```std::cout``` and/or ```printf()```. The Logger class also handles Windows console colour formatting which is a nice feature to have. Included in the Logger class are macros which are extremely helpful while debugging with OpenGL. For example the macro:
```
#define GL_CALL(x)\
engine::utils::Logger::glClearErrorQueue();\
x;\
ASSERT(engine::utils::Logger::glCheckErrors(#x, __FILE__, __LINE__))
```
is used to call OpenGL functions which might trigger errors. It checks to see if any OpenGL errors have been generated because of the funtion call and breaks to debug if one has been.

As well as the Logger class and logging to the console, I am using DearImGui to easily draw output to the application context screen. This is a lightweight, easy to use library which has minimal impact on development.

### Camera and Mathematics

I'm proud to have written my own mathematics library which includes fully developed classes to represent the following:
 - 2D, 3D, and 4D Vectors.
 - 2D, 3D, and 4D Matrices.
 - Quaternions.
These of course are used a lot in 3D graphics. In this project they are primarily used to control and compute the Camera's movements and projections. The use of Quaternions allows me to create a camera which can be manipulated free of gimbal-lock. Currently a scene's Camera can be controlled in two ways. The first way is in a First-Person mode in which the Camera's pitch is clamped so that it can't look "over" or "under" itself. The up-vector is also restricted to the world's up vector (0, 1, 0). The other currently implemented mode is simple a free-camera mode in which the Camera's movements and orientation offsets are completely relevent to its local axes. This type of Camera might be useful in a space-flight simulator.

### Serialization

I chose to write an ISerializer interface class so that if in the future I have the option to implement multiple serializers for multiple languages, such as Lua or XML. Currently the application only serializes and deserializes to and from JSON. To Serialize something the programmer would call ```Serializer::write<ObjectType>(Object, "object/filepath/and_name.json")```. If a function template specialization hasn't been implemented for the ObjectType specified by the programmer then the Serializer class will log an error. To deserialize an Object the programmer would call ```Serializer::read<ObjectType>("object/filepath/and_name.json")```.

### Scene Objects

A Game's scene has a collection of SceneObject pointers. The SceneObject class has several derived classes to represent various different kinds of SceneObjects. Currently there are four:
 - StaticObject: A simple static scene object which simply gets rendered.
 - StaticObjectSpinning: A variation of a StaticObject, this object will rotate while being updated.
 - Pawn: Derives from StaticObject but can be moved using messages.
 - Player: Derives from Pawn. This scene object is cotnrolled by the user. Currently this functionality is not implemented.

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
