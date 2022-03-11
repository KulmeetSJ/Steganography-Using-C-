This miniproject is on "Digital Steganography with C++" . In this miniproject , I have added OpenCV and CMake in my environment variables and also installed CMake extension in my VSCode to run this project without any errors. In this C++ project , we are using opencv (Computer Vision) , so to run opencv commands we have to include some opencv header files which might show error in your pc if you have not installed OpenCV on your system . Make sure to add this CMakeLists.txt in your project while running , so that it can help include opencv header files.

In this Project we are using LSB(Least Significant Bit) approach , that means that even if we encode some text inside the image , it won't be visible to naked eye.

Make sure to add this CMAKELists.txt in your folder and change the names of your project.


How to RUN-->>

Firstly , add file name you want to run in CMakeLists.txt by

add_executable {PROJECTNAME filename.cpp}

Then go to encode.cpp file and add paths of text file and image file in which you want to encode some text and then debug and run it. It will open the images and show a message in the Debug Console , a new encoded image will also be created in the folder.

Now after encoding successfully, add decode.cpp and remove encode.cpp in CMakeLists.txt and then go to decode.cpp file and add the path of the new encoded image and then again debug and run it. Encoded text will be displayed in the Debug Console.

Note :- Use a low pixel image in this code , a high pixel image will run , but it will show some warnings.




