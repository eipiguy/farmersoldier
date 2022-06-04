# Farmer Soldier

The basic theme of the game is trying to conquer territory while having to manage feeding your people. Territory is used to grow food, food provides the ability to sustain people, and people can either grow food or conquer more territory.

The game can accommodate any number of players, but for simplicity we start by considering just two.

## Environment

The game is played on a grid. This could be of any shape, such as triangular, rectangular, or hexagonal, even potentially 3d or more. The grid could be infinite, periodic, or finite. The gameplay would still follow the same steps, and nothing would break really.

For convenience of concept and analysis, I will start with a finite, two dimensional, three by three, rectangular grid (like a tic-tac-toe board). Each space in the grid represents a single "unit" of territory.

Each unit of territory can yield one unit of food, and can theoretically hold any number of people. Practically speaking, the number of people on each territorial unit will be limited by the available food that can be moved to that location.

## People

The game progresses in turns. Each turn consists of manipulating the number and location of people in the environment's grid.

People in this game can be one of three types: **farmer**, **soldier**, or **child**.
- Each person requires one unit of food each turn to survive (remain on the board).
- Each **farmer** creates one child in their location every turn and enables their location to produce two units of food every turn.
- Each **soldier** removes one opposing soldier from their location near the end of every player's turn. It also removes all opposing farmers or children if there are no opposing soldiers in that location afterwards.
- Each **child** that is on the board at the beginning of a turn becomes either a farmer or a soldier based on the choice of the owning player.

One potential I haven't investigated: Should farmers and soldiers be allowed to switch their identity at the end of each turn?

## Turns

Each turn is mostly concerned with movement of the people and food. On each turn, the following steps are followed. They all concern only the current player's pieces, except "combat", which involves all the soldiers from every player.

The game ends when only one player's pieces remain on the board.

### Steps

1. All of the current player's **children** on the board are converted to either farmers or soldiers, and each farmer that was not converted this turn creates a child.
2. The current player's people and food can **move** to any adjacent space.
3. Each of the current player's people must **consume** (remove from the game) one unit of food at their location, and if they cannot they are removed from the game themselves.
4. **Combat**:
    - Soldiers from all players can secretly mark one opposing soldier at their location for removal.
    - All soldiers marked for removal are removed from the game.
    - Any remaining soldiers remove all opposing farmers and children at their location from the game.
5. Each location that has a farmer remaining yields two units of **food**.
