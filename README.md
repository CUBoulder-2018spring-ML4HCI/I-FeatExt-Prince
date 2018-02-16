# I-FeatExt-Prince

## But what is it?
It's mainly just a CMake file that wrangles those two huge depends together and build correctly. (Leap Motion isn't so bad with the shared object file packaging most things)

The idea behind getting a C++ version of LeapMotion+OSC to work together was mainly in case I (or anyone else) wants to use [GVF](https://github.com/bcaramiaux/ofxGVF) in a final project. GVF only supports C++ as one might imagine.

## Depends
* [LeapMotion SDK](https://developer.leapmotion.com/)
I have used `V2` because `Orion` is not supported on Linux. I do not know how Orion will behave but I imagine it will work since the shared object library takes care of most of the links. Might have to be wary of legacy methods.
* [OSCPack](http://www.rossbencina.com/code/oscpack)
This is a rather large OSC library but works well since it can be used on any operating system without external depends.

## Building
Firstly, I have made this for Linux (and to a lesser extent, OSX) since CLion was throwing a fit with whatever CMake version I have installed.

As CLion uses CMake extensively to set up and build your project, I have only provided a CMake script. There is nothing stopping Make from working as well, OSCPack even has a good [Makefile](https://github.com/MariadeAnton/oscpack/blob/master/Makefile) that could be adapted easily to that end.
### Requirements
* Cmake (v3+ was used, v2 *should* work)
* LeapMotion SDK
* OSCPack

### SDK install locations
If you're comfortable modifying the CMake, place them wherever and change `${LEAP_INCLUDE_PATH}`, `${OSC_INCLUDE_PATH}` and `${LEAP_LIBRARY_PATH}` as required.

Otherwise, I have installed the LeapMotion SDK in `/usr/local/lib64/` and the OSCPack in `/usr/local/lib/`

NOTE: Windows users will have to modify `${IpSystemTypePath}` to be `ip/win32` but I have not tried compiling.

Then simply run `cmake` in the root directory and all should be well. I just ran straight from CLion.

## Why shouldn't I just use the Processing LeapMotion example?
Honestly, you probably should. The Leam Motion SDK has all sorts of super-fancified things like averaging positions and tracking objects and taking speed measurements and small gesture recognition. I think it would be easier to use DTW or a heavily tuned input helper to map outputs properly. Modifying this proram takes a long time and would likely be easier to start from (a little more than) scratch.


## Further Plans
* Better compile options
* Many-a-#define to easily tweak settings
* Break out some getters or integrate the OSC handle more closely with the Leap Motion interface.
* Make the default state more usefull.
* Make a "Processing-replacement" CLI program.
