
# Instructions for the Mummy Maze CLI Game

## Game Overview

This is a turn-based maze escape game. You play as an adventurer who must avoid being caught by mummies, navigate through a maze full of traps, and reach the treasure (exit) to win. If you’re caught by a mummy, you lose the game.

---

## How to Play

1. **Run the Program**
   Compile and run your Mummy Maze program.

2. **Movement Commands**
   You have one move per turn. Use the following keys followed by Enter to control your direction:

   - `w` : Move up
   - `s` : Move down
   - `a` : Move left
   - `d` : Move right

3. **Mummy’s Actions**
   - After each of your moves, the mummy automatically takes two consecutive steps immediately (prioritizing horizontal movement per rules).
   - The mummy always tracks the player automatically.

4. **Map Symbols**
   - `p` : Your current position (player)
   - `m` : The mummy’s current position
   - `e` : The location of the exit (treasure)
   - `#` : Walls, cannot be passed through
   - `.` : Open space, can be traversed

5. **Win/Lose Conditions**
   - When you reach the exit (`e`), it displays “Congratulations! You escaped!” indicating victory.
   - If you end up in the same cell as the mummy (`p` overlaps with `m`), the game ends with “You were caught by the mummy! Game Over!”

---

## Important Notes

- **Enter only one direction letter at a time.**
- Press Enter after each input to confirm.
- If the input isn’t `w`/`a`/`s`/`d` or points toward a wall, you’ll stay in place.
- Rapid typing won’t result in multiple moves; the system only responds to each individual input.

---

## Tips

- Try to stay away from the mummy’s direct path and use the maze’s walls to block it.
- Plan your moves carefully to avoid getting trapped or hitting the mummy head-on.

Alpha 0.1.2, published on 2026-08-15T14:20:31+08:00
---

Have fun playing, and brave the mummies to escape!
