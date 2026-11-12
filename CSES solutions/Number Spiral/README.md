## Why the brute force solution wont work?
What is the complexity of constructing an x * y grid piece by piece? It is O(xy).

The worst case scenario is (10^9) * (10^9) = 10^18. The processing speed of the judge is 10^8 operations per second, hence, 10^18 operations will take 321 years!!

But regardless of this very stupid time complexity, let us just construct an algorithm that builds this Number Spiral Grid so we could mathematically analyze it to discover deep hidden connections and rules that we shall exploit for an elegant solution.

## Code to build the Number Spiral
We need to define what does up, down, right, left mean in a grid.

Given a grid G of dimensions r * c. (rows * columns),

Up = G[x--, y]

Down = G[x++, y]

Right = G[x, y++]

Left = G[x, y--]

Note that in the Number Spiral movement pattern each move is only done with one step and the moves starts from G[0,0] which is the first element from the first array which is the top-left element. Note that the movement pattern of this spiral is this:

Right

Down by 1

Left by 1

Down

Right by 2

Up by 2

Right

Down by 3

Left by 3

Down

Right by 4

Up by 4

Right

Down by 5

Left by 5

Down

Right by 6

Up by 6

..... etc

This is the [code](code) that prints a Number Spiral in the console
