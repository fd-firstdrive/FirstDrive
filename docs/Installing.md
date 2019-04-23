This page describes how to install the latest FirstDrive package. It assumes you have [downloaded the latest release](Downloading.md).

Windows
-------

-   Double click the **vdrift-*yyyy-mm-dd*.exe** file (probably in your **Downloads** folder).
-   Follow the instructions in the wizard that opens.
-   Start FirstDrive from the Start menu (if you have chosen to install the shortcuts).

OS X
----

-   If your browser hasn't automatically opened it, double click the **vdrift-mac-*yyyy-mm-dd*.dmg** file (probably in your **Downloads** folder).
-   Drag or copy the **FirstDrive** application from the resulting mounted disk image named **FirstDrive** to your **Applications** folder.
-   Double-click the **FirstDrive** application now found in your **Applications** folder.

Linux
-----

FirstDrive hasn't been released with a standalone binary package for several releases. If you think you could help us with this, please post in the forums!

FreeBSD
-------

To install the binary package, just use **pkg\_add**:

    pkg_add -r vdrift
    cd /usr/ports/games/vdrift-data && make install clean clean-depends

<Category:Installation>
