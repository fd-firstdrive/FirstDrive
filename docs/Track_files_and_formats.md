FirstDrive's tracks are composed of 3D-modeled objects in .JOE format, PNG graphic files for textures, and text files describing the objects and track.

Files
-----

The files that define each track are within the **data/tracks/*trackname*/** directory, where *trackname* is the "short name" of the track.

### about.txt

Simple text file with the track's full name as the first line. Credits may be on following lines.

### roads.trk

This file defines the road surface for the track. It is generated by the [track editor](Creating_tracks.md). Following is the format of this file:

    <number_of_roads>
    <number_of_Bezier_patches_for_the_1st_road>
    Control point coordinates of Bezier patch 1 (total 16 points)
    Control point coordinates of Bezier patch 2 (total 16 points)
    .
    .
    .
    .
    <number_of_Bezier_patches_for_the_2nd_road>
    Control point coordinates of Bezier patch 1 (total 16 points)
    Control point coordinates of Bezier patch 2 (total 16 points)
    .
    .
    .
    .
    <and so on>

### trackshot.png

This is a 512x512 PNG graphic file that is displayed in the menu when selecting the track to race on.

### track.txt

This file defines various track parameters. This file is in FirstDrive's [Config file format](Config_file_format.md).

### objects/\*.png

The PNG files have names corresponding to the object they belong to. These are the textures for the 3D model objects that make up the track.

### objects/list.txt

This is a plain text file that defines the relationship between objects and textures, and also sets object properties. It is generated and edited with the [Listedit tool](Listedit_tool.md) which is part of the [Track editor](Track_editor.md) tools.

A description of each field in the list.txt file can be found at the following location: <http://svn.vdrift.net/viewvc.cgi/trunk/listedit/format.txt?root=FirstDrive+Track+Editor&view=co>

### objects/objects.jpk

This file contains all the files that define the 3D models for the objects that make up the track. It is in the [JOEPack format](JOEPack_format.md), which contains many files in the [JOE format](JOE_format.md).

<Category:Tracks>