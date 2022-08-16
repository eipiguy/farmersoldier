## Classes

When playing the game some things should obviously be represented by classes, owing to their inheritance.

Children become either farmers or soldiers, and so there should be a base "child" class and "farmer" and "soldier" classes that inherit from it.

- Child
    - Farmer
    - Soldier

The board is a little more complicated. My first instinct is to make a board a class that is a collection of locations. Each location should somehow point to a collection of pieces and food on it. That seems like an obvious thing to implement in C, but less so in python where pointers don't exist.

Moreover, should these locations be stored in a structure that dictates their relationship to each other, or should each location have a pointer to it's neighbors? It seems like the first one is more realistic, while the second allows for more complicated topology.

- Location
- Board
    - Neighbor Structure (collection of location relationships)
