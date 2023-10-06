# AUTO-Sorting-Connect-4
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Media/Connect4-sorting-gif-demo.gif)

Fully 3D printed Connect 4 add-on that sorts the pieces for you at the touch of a button.
The solution is made up of 3 parts which will be broken down below: sensing color, dividing pieces, and one-row handling.

Attached is the Fusion 360 so the models can be edited directly and used to better understand how it is broken down. A YouTube link for the build process and comedic relief: https://www.youtube.com/watch?v=7tsY3SJziWs&t=1s

![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Media/3d-Connect-4-model.PNG)

Below is the full Arduino schematic for anyone trying to build the project. For those who want a closer look, the diagram can be found in the Fritzing Schematic folder. If there are any confusions feel free to ask in the discussion. (don't forget to leave slack in the wires for the platform of the lever to go all the way up and down)

![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Media/connect4-shcematic.PNG)

# Sensing Color
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Media/Color-sensing-gif-demo.gif)

The IR sensor is able to reflect and receive off of the red piece but not the black piece allowing for a simple binary approach. This requires that one of the piece colors be black, but this method reduces the number of cables and is the simple solution. The most compact place for the sensors, which also does not block the view of the gameplay, ends up being the bottom; we can combine them with the levers that push the pieces to one side or the other.

![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Media/IR-Sensor-Working.gif)
# Dividing Peices
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Media/Servo-lever-system-gif-demo.gif)

A lever system (think seesaw) is used to push the pieces to one side or the other. A server with a simple linkage is used to tilt the single-point mounted platform to one side or the other letting gravity do the rest. This system is not the most robust approach and has its flaws but is a solution to the problem and can be improved upon. The platform must stop in the middle of each row drop to sense the color before picking a side.
# One Row Handling
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Media/One-row-handling-gif-demo.gif)

The pieces traditionally come out of the bottom so we can use the existing slider to drop the pieces one at a time using a precise servo. The servo can be mounted to the side support and can provide an action that is quick and precise enough to consistently only drop one row at a time. This works under the load of one row or all six.
