# KENDRICK.

Welcome to **KENDRICK.**, where you battle with your friend, and kill drake(or, kendrick).

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Game Rules](#game-rules)
- [Screenshots](#screenshots)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction

**KENDRICK.** is a fan-based game where players select either Kendrick Lamar or Drake and engage in battle. The goal is to default the other character to prove who the real GOAT is.

## Features

- Choose between Kendrick Lamar and Drake
- Dynamic real time score records
- Interactive and engaging gameplay
- High-quality graphics and sound effects

## Installation

To install and run the game locally, follow these steps:

1. Clone the repository:

   ```sh
   git clone https://github.com/thisismars-x/KENDRICKLAMAR.git
   ```

2. Navigate to the project directory:

   ```sh
   cd KENDRICKLAMAR
   ```

3. Install the necessary dependencies:

   ```sh
   # For windows
   git clone https://github.com/Microsoft/vcpkg.git
   cd vcpkg
   ./bootstrap-vcpkg.bat


   # On Linux
   sudo apt update
   sudo apt install libsdl2-dev libsdl2-mixer-dev libsdl2-ttf-dev libsdl2-image-dev

   ```

4. Start the game:

   ```sh
   g++ finals.cpp -Isrc/Include -Lsrc/lib -o main -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
   ./main
   ```

## Usage

After starting the game, you can:

1. Choose your favorite artist: Kendrick Lamar or Drake.
2. Play the game and defeat your opponent.
3. Enjoy the game divisions(entry and exit).

## Game Rules

- Select your artist.
- Use [wasd] to control kendrick and [UP,LEFT,DOWN,RIGHT] to control drake.
- Defeat your opponent

## Screenshots

_Add screenshots of your game here to give users a visual understanding of the gameplay._

## Contributing

We welcome contributions to enhance the game! To contribute, follow these steps:

1. Fork the repository.
2. Create a new branch:

   ```sh
   git checkout -b feature/your-feature-name
   ```

3. Make your changes and commit them:

   ```sh
   git commit -m "Add your message here"
   ```

4. Push to the branch:

   ```sh
   git push origin feature/your-feature-name
   ```

5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Contact

If you have any questions or feedback, feel free to reach out:

- GitHub: [thisismars-x](https://github.com/thisismars-x)
- Email: [avikc.copy@gmail.com](mailto:avikc.copy@gmail.com)

---

Feel free to modify and expand this template to suit the specifics of your game and project requirements.
