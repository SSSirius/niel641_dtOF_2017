
# Face Galaxy

## Luqi NIE

A self-portrait of galaxy generated by your face

Use particle system to draw the galaxy, and the data was tracking by Facetraker2(modified)

#### Addons used:

- ofxFacetraker2(modified)
- ofxGui
- ofxCv

---
#### Process:
**#1 find the spots on the face**

ofxFacetraker2 is faster and stabler then ofxFacetraker, but without some functions
For example, drawMesh( ), which I have to add manually.
Then, I tried to find the position of every facial feature, make those points stand out, and calculate the distance or size of every feature.
Also, I wrote the function to call these data array back.

![face](face.png)

**#2 draw the galaxy orbit**

In order to mimic the galaxy, I found a research about how to render the galaxy

[Rendering a Galaxy with the density wave theory](http://beltoforion.de/article.php?a=spiral_galaxy_renderer)

The formula is to complex to me, so I referred the pic of ellipse orbits and drew those ellipses in my own way. ( only use X  axis and Y axis)

![orbit](orbit.gif)

**#3 add stars**

After I draw those ellipses, I randomly generate spheres in every orbit area
The Z axis is mapping with the sequence of the orbit.

![stars](stars.gif)

**#4 link the data of face to the galaxy**

I create a class named Calc to calculate the radio of mouth, eyes, nose to face
and to call this parameter easily, I created a public class called Param

If multi-faces are tracked by this App, the parameters will provide the average data form those faces.


![facegalaxy](facegalaxy.gif)

###### inspiration:
[Facetype](http://mary-huang.com/portfolio/typeface/)






