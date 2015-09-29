# NurseryTemperatureSensor
The idea is to keep a track of the nursery's room temperature. The temperature scale displayed reflects what would be ideal for a baby. The details of this data can be obtained here:<br>
http://www.newkidscenter.com/Room-Temperature-for-Babies.html<br>
###1) Sensor :
TMP102. A tiny digital temperature sensor. Details can be found <a href="https://www.sparkfun.com/products/11931">here</a>.
The sensor is pretty simple. It has 5 inputs which are namely:<br>
-Power,<br>
-Ground, <br>
-SCL(Serial Control Logic-which is D1 pin in our photon)<br>
-SDA(Serial Data Input - connected to D0 pin)<br>
-Address pin(Left unconnected defaults to 0x48 address)<br>
Particle has an inbuilt Wire.h library with functions for reading the input. 
The value returned is in 12-bit int. So we have to use 2-complement to convert into it into a meaningful scale.
The entire code chunk for reading the temperature can be obtained <a href="http://bildr.org/2011/01/tmp102-arduino/">here</a><br>
This data is passed on as an float to the serial input. Logical operations can thus be performed on this data. 
<br><br>
###2) Visualization: 
I have ditched all the tools and plugins that I used for IA1. I had used JQPLOT and PLOTLY.
This time around I have namely 3 different visuals on screen.<br>
-A meter-gauge displaying temperature data as it reads from serial. This visualization is created using Highcharts. The details can be found <a href="http://www.highcharts.com/">here</a><br>
-The actual visual of a baby reflecting its mood. This has been created using CSS styles. The data being read from serial is read into the html document as a string. I convert it into float to perform the logical operations and work with CSS implementation.
-A temperature v/s time series for keeping track of the data. All the data being read from serial input is uploaded to data.sparkfun. The sparkfun repository creates it own timestamp with every input. This has been visualized using Highcharts. The advantage of using highcharts is that it allows us to provide absolute paths to its script files without requiring us to download all the scripts. Moreover, because of the way it has been structured, it is better suited to handle live data.<br>
<br><br>
###3) Output - 
I have used an common anode RGB led for providing a physical output, apart from the visualization that we see on the browser. Because it is a common anode, we have to use the concept of negative ground (the circuit gets grounded through the line which has the lowest current flowing). Each pin of the LED is for each respective color-RGB.
The colour of the LED matches the colour being shown on the meter gauge. The color scheme is also pretty intuitive.
The logic for handling the LED is coded in the .ino file itself. And it is triggered as and when we read an input from the serial.

The link for visualization of data on cloud:
http://rawgit.com/tirumalavan/BabyTemperatureSensor/master/balaji_ia2_iframe.html

Pictures of the circuits:
https://github.com/tirumalavan/BabyTemperatureSensor/tree/master/Circuits
