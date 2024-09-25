### Project 2 - Game of Life
### Paedar Rader
---

<ul>
    <li>Please note that in the file hierarchy, the gol_cmd.h contains all the library definitions, and all files must include to that said path. <em>This is a note for the programmer.</em></li>
</ul>

<strong>This is what the board will look like:</strong>
```
----------------
-------@--------
------@@@-------
-------@--------
-----------@----
----------------
```
<li>All '@' characters represent live cells, while all '-' characters represent dead cells.</li>

###### All functionality is based on the input text file which must follow these guidelines specifically:

```
number of grid rows
number of grid cols
number of iterations to simulate
i j
i j
...
```
<strong>After the first three lines, it is followed by the coordinates of every live cell[s] <em>&nbsp;(i, j)</em>. To be noted, the top left cell is position (0,0), so all positions must take into account that <ins>indexing/positioning starts at zero.</ins></strong>

<em>Example Input File:</em>
```
30
30
100
29 1
28 2
27 0
27 1
27 2
```
This will create a glider, and run for 100 iterations in a 30x30 grid.

---
### How to Run:

1. <strong>Build the program using the Makefile:</strong>
```
% make
```
2. <strong>Execute, and make sure to include the required parameters:</strong>
```
% ./gol <filename>.txt <wraptype> <showtype> <framerate>
```
<em>Example execution:</em>
```
% ./gol glider.txt nowrap show fast
```
3. (Optional) <strong>To clean/clear current make:</strong>
```
% make clean
```

#### Command Line Parameters:
```
% ./gol file.txt wrapType showType framerate
```
<ul>
    <li><ins>./gol</ins>: executable filename, cannot be changed</li>
    <li><ins>file.txt</ins>: filename input, must be in same file location as program</li>
    <li><ins>wrapType</ins>: either <strong>wrap</strong> or <strong>nowrap</strong>, determines if the program will wrap around when it reaches the borders during simulation, or if it will stop, treating it as a border</li>
    <li><ins>showType</ins>: either <strong>show</strong> or <strong>hide</strong>, determines if the program will be displayed to output terminal, or if it will be hidden. Hidden still executes, just does not display the board for the user</li>
    <li><ins>framerate</ins>: either <strong>slow</strong>, <strong>med</strong>, or <strong>fast</strong>, determines the framerate (fps) of the program. <strong>slow = 3fps, med = 10fps, fast = 30fps</strong>. This is not needed if using the 'hide' keyword.</li>
</ul>

---

##### Additional Notes:
<li>In function descriptions present in .h files, the use of the word 'pointer' or 'reference' are condensed to their respective characters. So, for an <strong>integer pointer</strong> it would instead be listed as <strong>integer*</strong>. This allows for less cluttered code, and more concise descriptions for functions and their parameters.</li>