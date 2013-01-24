MWorks Force Dimension Haptic Device Plugin
===========================================


Overview
--------

This is an [MWorks](http://mworks-project.org/) plugin that provides an interface to [Force Dimension](http://www.forcedimension.com/) haptic devices.


How to Build
------------

1. [Download](http://mworks-project.org/downloads/) and [install](http://help.mworks-project.org/kb/installation/installing-mworks) the MWorks nightly build.

2. Download the Force Dimension [Haptic SDK](http://www.forcedimension.com/sdk-overview).  Open the disk image, copy the SDK folder (e.g. `sdk-3.4.4`) to the top-level source directory (i.e. where this README resides), and rename it `sdk`.

3. Download the [Eigen library](http://eigen.tuxfamily.org/).  Unpack the archive file, copy the source folder (e.g. `eigen-eigen-5097c01bcdc4`) to the top-level source directory, and rename it `eigen`.

4. Open `FDHapticDevice.xcodeproj` in [Xcode](https://developer.apple.com/xcode/) and build the "Everything" target.

5. To verify that the plugin works, try running the included example experiment (`example.xml`).


Extending the Plugin
--------------------

Most of the plugin's work happens in `FDHapticDevice`.  This where you'll find the run loop that acquires the device's current position and velocity, obtains and sums forces from the attached force components, and sends the computed force to the device.  If you want to change how this works, this is the place to do it.

Force components derive from an abstract base class named `Force`, which implements functionality common to all forces.  Currently, the plugin provides one concrete force type, `FixedForce`, which implements a force of constant magnitude and direction.  To define additional force types, create new subclasses of `Force`.

If you implement new components (or add parameters to existing ones), be sure to update `FDHapticDevice/MWLibrary.xml`, so that the new/updated components are available in MWEditor.
