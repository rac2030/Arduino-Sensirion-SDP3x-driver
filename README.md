# Arduino-Sensirion-SDP3x-driver
An arduino driver to interface the Sensirion SDP3x differential pressure sensor over I2C

This is currently a work in progress, the code was done during the MakeZurich hackathon and directly used in the project.
I try to sort it out and add all the funcitonality of the sensor as well as writing my first arduino library ;-)

Short documentation can be found on http://rac.su/libs/sensirion-sdp3x-driver

As I first used a SDP610 and a library I found on github I adhered the style from the SDP6x library from Antony Burness, but replaced the code with the sample code from Sensirion for the SDP3x

## Compatibility
This library is compatible with the following sensors:
- SDP3x series: SDP31, SDP32, SDP36, SDP37
- SDP8xx series: SDP800, SDP810, SDP806, SDP816

To use it with the SDP800 series, please keep in mind that the I2C address
needs to be adjusted. To do that, add the following line to your `init()`
function:

```c++
SDP3x.setI2CAddress(DEFAULT_SDP8XX_I2C_ADDRESS);
```

Note that while both the 500Pa and 125Pa version should work, the library has
only been tested with the 500PA version so far. Feedback on the 125Pa version
is appreciated!
