# 🎮 Tetris

A classic Tetris game implemented in C++, playable directly in the terminal. This project emphasizes clean object-oriented design and provides an engaging console-based gaming experience.

---

## 🧩 Features

- **Classic Tetris Gameplay**: Enjoy the traditional Tetris experience with falling tetrominoes.
- **Terminal-Based Interface**: Play the game directly in your terminal without any graphical interface.
- **Object-Oriented Design**: Modular code structure with classes like `Game`, `Board`, `Piece`, and `Player`.
- **Configurable Settings**: Easily adjust game settings through the `GameConfig.h` file.

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler supporting C++11 or higher.
- A terminal or console environment.

### Compilation

To compile the game, use the following command:

```bash
g++ -std=c++11 -o Tetris main.cpp Board.cpp Game.cpp Piece.cpp Player.cpp Point.cpp General.cpp
Ensure all the .cpp and .h files are in the same directory or adjust the paths accordingly.

🎮 Controls
Left Arrow (←): Move the piece left.

Right Arrow (→): Move the piece right.

Down Arrow (↓): Accelerate the piece's descent.

Up Arrow (↑): Rotate the piece clockwise.

Spacebar: Instantly drop the piece to the bottom.

P: Pause or resume the game.

Q: Quit the game.

🛠️ Code Structure
main.cpp: Entry point of the application.

Game.h / Game.cpp: Manages the game loop and overall game state.

Board.h / Board.cpp: Represents the game board and handles piece placement.

Piece.h / Piece.cpp: Defines the tetromino shapes and their rotations.

Player.h / Player.cpp: Handles player-specific data and actions.

Point.h / Point.cpp: Utility class for coordinate management.

General.h / General.cpp: Contains general utility functions.

GameConfig.h: Configuration file for game settings like board size and speed.

🧪 Future Enhancements
High Score Tracking: Implement a system to record and display high scores.

Multiple Levels: Introduce increasing difficulty levels as the game progresses.

Sound Effects: Add audio feedback for actions like line clears and game over.

Graphical Interface: Develop a GUI version using libraries like SDL or SFML.

📄 License
This project is open-source and available under the MIT License.


📬 Feedback
Feel free to open issues or submit pull requests to contribute to the project. Your feedback is highly appreciated!
