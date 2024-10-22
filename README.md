# 3D Scene Overview
![image](https://github.com/user-attachments/assets/dcb2cd3e-1988-4aef-8e0b-850d4f01108a)


In this 3D scene, a virtual space is represented, allowing the user to observe and explore objects from different angles. The scene has several key elements that give the viewer a more realistic and dynamic experience.

1. **Reference Axes**: Reference axes are configured to serve as a guide to understand how objects are distributed in space. These axes act like an invisible "skeleton" that programmers use to organize the scene and ensure everything is well aligned.

2. **Objects in the Scene**: Although not shown directly in this fragment, the scene likely contains objects like cubes or other geometric shapes, which may or may not be visible, depending on the configurations the user chooses.

3. **Lights**: The scene uses several lights to illuminate the objects. This is important because the lights not only make objects visible but also create shadows and reflections, making them appear more realistic. Different light sources can be turned on and off as needed, and each light can influence the appearance of the scene in different ways.

4. **Virtual Camera**: The scene also features a "camera" that can move in different directions. This camera allows the user to view the objects from various angles and distances, creating an interactive experience. The user can zoom in or out on objects and rotate the camera to view them from any side.

5. **User Interaction**: The user can interact with the scene using a mouse. Depending on how the user moves or clicks the mouse, the view can change, allowing them to actively explore the scene.

6. **Visualization Modes**: The scene can be displayed in different ways. For example, some modes may show only the outline of objects, others may add more details, and some may apply textures to make the objects more realistic.

In summary, this 3D scene is designed to be an environment where the user can observe objects from different perspectives, with adjustable lighting and visualization modes that allow various ways to view those objects. The user's interaction with the scene is integral to the experience, as they can freely explore it by moving the camera and adjusting the behavior of the lights.

## Installation

To run a scene in OpenGL like the one described, you need to set up your development environment and ensure you have the necessary tools. Here's a list of the requirements:

### 1. OpenGL
- **What it is**: OpenGL (Open Graphics Library) is a standard API for rendering 2D and 3D graphics.
- **How to get it**: Most modern operating systems already support OpenGL. However, to develop with OpenGL, you will need to install some additional packages.

### 2. GLUT or FreeGLUT
- **What it is**: GLUT (or its modern variant FreeGLUT) is a library that simplifies window management, keyboard, and mouse input in OpenGL. It is used to create basic interfaces and simplify user interaction with the scene.
- **How to get it**:
  - On **Windows**, you can download FreeGLUT from its official page or use a package manager like MSYS2.
  - On **Linux** (such as Ubuntu), install it with: `sudo apt-get install freeglut3-dev`.
  - On **Mac**, you can use Homebrew with `brew install freeglut`.

### 3. GLEW (OpenGL Extension Wrangler Library)
- **What it is**: GLEW is a library that simplifies the use of OpenGL extensions. It is necessary to access advanced OpenGL functions that are not included in the base API.
- **How to get it**:
  - On **Windows**, it can be downloaded from the [official GLEW page](http://glew.sourceforge.net/).
  - On **Linux**, install it with: `sudo apt-get install libglew-dev`.
  - On **Mac**, use Homebrew: `brew install glew`.

### 4. A compatible compiler
You will need a compiler that supports C++ to compile the code. Common options include:
- **GCC/G++**: For Linux and Mac. On most systems, it is pre-installed, or you can install it with `sudo apt-get install build-essential` on Linux or with Xcode on Mac.
- **MinGW**: For Windows, along with tools like MSYS2 to facilitate the build environment.
- **Visual Studio**: This is an option on Windows that includes its own C++ compiler and OpenGL support.

### 5. Environment Setup
- **Windows**:
  - Set the paths to the OpenGL, FreeGLUT, and GLEW libraries in your compiler or IDE.
  - If using Visual Studio, add the libraries in the project properties (in the "linker" and "includes" sections).
  - If using MinGW, you'll need to manually configure the paths to the libraries and headers.
  
- **Linux**: The packages usually include the necessary paths for libraries and headers. You will only need to install the mentioned packages.

- **Mac**: OpenGL comes pre-installed, but you will need to use Homebrew to install FreeGLUT and GLEW, then configure your project to use them.

### 6. Code Editor or Development Environment
You can choose any code editor or development environment that you prefer. Popular options include:
- **Visual Studio Code**: Very versatile, with plugins for C++.
- **CLion**: A JetBrains development environment focused on C++.
- **Code::Blocks**: A more classic IDE for C/C++.
- **Visual Studio**: Ideal for large projects on Windows.

### 7. Execution
Once everything is set up, you'll need to run the `make` command from the terminal in the project folder to compile and execute the scene.


If you wish to contribute to this project, feel free to fork the repository and submit a pull request with your improvements.

This project is licensed under the MIT License. See the LICENSE file for more details.
