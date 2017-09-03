# 3d-ray-tracer

## Specs

### Object representation

Very simple object representation: an array of Points.

For example, a cube would have an array of every point on all of its external faces.

So a 2-by-2-by-2 pitch-black cube positioned at coordinate 2, 3, 4 would have 8 points:

(2, 3, 4, 0, 0, 0)
(2, 3, 5, 0, 0, 0)
(2, 4, 4, 0, 0, 0)
(2, 4, 5, 0, 0, 0)
(3, 3, 4, 0, 0, 0)
(3, 3, 5, 0, 0, 0)
(3, 4, 4, 0, 0, 0)
(3, 4, 5, 0, 0, 0)

Where the format is (x, y, z, r, g, b).

### Point representation

A Point has its 3d coordinates: x-coord, y-coord, z-coord, and a colour.

No plans to implement transparency, or different colours for different directions.

So all Points are 100% opaque.

### Camera-view representation

A camera view is an infinitely-small pinhole, with a camera pose (orientation).

The camera pose is specified with a Unit Vector (see "Ray representation").

You can specify the width of the lens up to 120 degrees. The lens has a square field of vision.

You can specify the resolution of the camera-image, e.g. 600 by 600 pixels. It must be square.

### Space representation

Space is a 3-d array of Points. In empty space, the Point has a flag which says it does not exist.

When it is a Point which exists and should be seen, its flag will be set to exist.

Locations in this space are represented by a Vector with 3 elements, for each x, y, and z coordinate.

### Ray representation

Rays are cast out from the camera pinhole. They radiate outwards in a single step defined by a Unit Vector.

The Unit Vector gives the magnitude of the steps along the x, y, and z coordinate, for a total magnitude (distance) of 1 Point's width.

The pinhole itself has its location specified by an Initial Location Vector.

By repeating single steps radiating out, I can simply increment the Initial Location Vector by the Unit Vector each time.

After every increment, I check if the ray has collided with an opaque Point. If so, I return the RGB colour to the image.

### Image representation

The image is a 3-d array with a shape of (ImageHeight, ImageWidth, NumberOfChannels).

Since we are doing RGB, the NumberOfChannels is 3.

So if the pixel at row 64, column 32 is bright red (RGB 255-0-0), then Image[64][32][0] is 255, Image[64][32][1] is 0, etc.

### Application setup

An object in your world should be represented as a swarm of Points on its surface. These Points are specified in a text file.

The Application will load every object you wish it to load, and render it within its 3-d array of Points.

Attempting to add conflicting Points should throw an exception.

The Application will load also the camera pose and camera location.

Location should be 3 doubles for x, y, z coordinates.

Pose should be 3 doubles corresponding to the entries in the Unit Vector: e.g. a camera posed exactly along the x-axis has (1.00, 0, 0).

The Application should output a bitmap image, corresponding to what the camera should see in its 3-d world.

