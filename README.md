# AUTO-sorting-Connect-4
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Connect4-sorting-gif-demo.gif)

Fully 3D printed Connect 4 add-on that sorts the peices for you at the touch of a button.
The solution is maded up of 3 parts which will be broken down below: sensing color, dividing peices, one rwo handling.

Attached is the Fusion 360 so the models can be editted directly and used to better understand how it is brocken down. A youtube link for build process and comedic relief: https://www.youtube.com/watch?v=7tsY3SJziWs&t=1s
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/3d-Connect-4-model.PNG)

# Sensing Color
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/Color-sensing-gif-demo.gif)

The IR sensor is able to reflect off of the red peice but not the red peice alwoing for a simple binary approach. This requires that one of the peice colors is black, but this method reduces the number of cables and is the simple solution. The most compact place for the sensors, which also does not block the view of the gameplay, ends up being the bottom; we can combine them with the levers that push the peices to one side or the other.
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/IR-Sensor-Working.gif)
# Dividing Peices

# One Row Handling
![image](https://github.com/jareddilley/AUTO-sorting-Connect-4/blob/main/One-row-handling-gif-demo.gif)
The peices traditionally come out of the bottom so we can use the existing slider to drop the peices one at a time using a percise servo. The server can provide an action that is quick and percice enough to cosistantly only drop one row at a time. This works under the load of one row or all six.
