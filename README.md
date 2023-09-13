# AUTO-Sorting-Connect-4
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Connect4-sorting-gif-demo.gif)

Fully 3D printed Connect 4 add-on that sorts the pieces for you at the touch of a button.
The solution is made up of 3 parts which will be broken down below: sensing color, dividing pieces, and one-row handling.

Attached is the Fusion 360 so the models can be edited directly and used to better understand how it is broken down. A YouTube link for the build process and comedic relief: https://www.youtube.com/watch?v=7tsY3SJziWs&t=1s

![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/3d-Connect-4-model.PNG)

The layout of the sensors and servos in reference to the 3D prints can be seen below. Along with the placement, you can also see the way that the cables can be effectively managed (don't forget to leave slack for the platform of the lever to go all the way up and down.

![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Disassembled-view.jpg)
# Sensing Color
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Color-sensing-gif-demo.gif)

The IR sensor is able to reflect and receive off of the red piece but not the black piece allowing for a simple binary approach. This requires that one of the piece colors be black, but this method reduces the number of cables and is the simple solution. The most compact place for the sensors, which also does not block the view of the gameplay, ends up being the bottom; we can combine them with the levers that push the pieces to one side or the other.

![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/IR-Sensor-Working.gif)
# Dividing Peices
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Servo-lever-system-gif-demo.gif)

A lever system (think seesaw) is used to push the pieces to one side or the other. A server with a simple linkage is used to tilt the single-point mounted platform to one side or the other and let gravity do the rest. This system is not the most robust system and has its issues but is a solution to the problem and can be improved upon. The platform must stop in the middle of each row to sense the pieces before picking a side.
# One Row Handling
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/One-row-handling-gif-demo.gif)

The pieces traditionally come out of the bottom so we can use the existing slider to drop the pieces one at a time using a precise servo. The servo can be mounted to the side support and can provide an action that is quick and precise enough to consistently only drop one row at a time. This works under the load of one row or all six.
