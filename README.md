# Mummy Maze CLI Game — Update Notes

## 1. Overview
This update focuses on fixing the critical bug where the exit marker `e` could be overwritten and disappear when the mummy passed over it. The map rendering logic has been refactored to make the game state more robust and easier to maintain.

---

## 2. Fixed Issues

| Issue | Description | Status |
|-------|-------------|--------|
| Exit overwrite bug | The mummy's movement logic restored its previous tile to `.` after moving. If the mummy left the exit cell, it would erase the `e` marker. | Fixed |
| Map-state coupling | Player, mummy, and exit symbols were stored directly inside the `maze` array, making state updates error-prone. | Refactored |

---

## 3. Key Changes

### 3.1 Static Map Array
The `maze` array now only stores static terrain:
- `#` — Wall
- `.` — Floor/path

Dynamic entities (`p`, `m`, `e`) are no longer stored in the map array.

### 3.2 Dynamic Rendering (`showmap`)
Entities are drawn at render time based on their current coordinates:
1. **Player `p`** — highest draw priority
2. **Mummy `m`**
3. **Exit `e`**
4. **Static maze tile**

This ensures that overlapping entities or entities moving over special tiles never corrupt the underlying map.

### 3.3 Simplified Movement Logic
Both `pmove` and `mmove` now only update coordinate variables (`prow`, `pcol`, `mrow`, `mcol`). There is no need to restore previous tiles, which eliminates the root cause of the exit-overwrite bug.

### 3.4 Mummy Movement Rules (Preserved)
- The mummy moves **twice** per player turn.
- If the mummy and player are **not in the same row**, horizontal movement is attempted first.
- If horizontal movement is blocked by a wall, vertical movement is attempted.
- If they are **in the same row**, only horizontal movement is attempted.
- The mummy cannot move through walls.

---

## 4. Configuration
Edit the `CONFIG AREA` at the top of the source file to customize the game:

```cpp
int prow = 7, pcol = 2;  // Player start position
int mrow = 2, mcol = 6;  // Mummy start position
int erow = 2, ecol = 3;  // Exit position
int MAZER = 10, MAZEC = 20;  // Maze dimensions
```

When modifying the maze layout, ensure that:
- The outer border remains walls (`#`).
- The player, mummy, and exit positions match walkable floor tiles (`.`).
- `MAZER` and `MAZEC` match the actual row and column count of the maze strings.

---

## 5. How to Play
1. Compile the program with any C++ compiler, for example:
   ```bash
   g++ mummy_maze.cpp -o mummy_maze
   ```
2. Run the executable:
   ```bash
   ./mummy_maze
   ```
3. Use the following controls:
   - `w` — Move up
   - `s` — Move down
   - `a` — Move left
   - `d` — Move right
4. Reach the exit `e` before the mummy `m` catches you.

---

## 6. Win / Lose Conditions
| Condition | Result |
|-----------|--------|
| Player reaches `e` | `Congratulations! You escaped!` |
| Mummy reaches player | `You were caught by the mummy! Game Over!` |

---

## 7. Known Limitations
- The game uses `system("cls")`, which is designed for Windows. On Linux/macOS, replace `system("cls")` with `system("clear")` for proper screen clearing.
- There is currently no input validation for keys other than `w`, `a`, `s`, `d`.

---

## 8. Files
| File | Description |
|------|-------------|
| `mummy_maze.cpp` | Main source file containing the full game logic |

---

## 9. Latest Version
**Version:** Alpha 0.1.1

**Date:** 2025-01-09

**Changes:** Bug fix, render refactor.
