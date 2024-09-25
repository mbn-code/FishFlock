# Fiske Flok

Fiske Flok is a C++ project that simulates fish movement using the Raylib library. The project includes functionalities for fish flocking behavior, border avoidance, and smooth movement interpolation.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/mbn-code/fiske-flok.git
    cd fiske-flok
    ```

2. **Install dependencies:**
    Ensure you have Raylib installed. You can install it via Homebrew:
    ```sh
    brew install raylib
    ```

3. **Build the project:**
    Open the project in Visual Studio Code and use the provided build task:
    ```sh
    code .
    ```
    Then run the build task:
    - Press `Cmd+Shift+B` (or `Ctrl+Shift+B` on Windows/Linux)
    - Select `C/C++: clang++ build active file`

## Usage

1. **Run the application:**
    After building, you can run the executable:
    ```sh
    ./main
    ```

2. **Controls:**
    - The fish will automatically start moving and flocking.
    - Close the window to exit the application.

## Project Structure

- **Fish.cpp**: Implementation of fish-related functionalities.
- **Fish.hpp**: Declaration of the [`Fish`](command:_github.copilot.openSymbolFromReferences?%5B%22%22%2C%5B%7B%22uri%22%3A%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2FUsers%2Fmbn%2FDocuments%2FProgrammering%2Fc%2B%2B%2FFiskeFlok%2FFish.hpp%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%2C%22pos%22%3A%7B%22line%22%3A6%2C%22character%22%3A7%7D%7D%2C%7B%22uri%22%3A%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2FUsers%2Fmbn%2FDocuments%2FProgrammering%2Fc%2B%2B%2FFiskeFlok%2FFishMovement.hpp%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%2C%22pos%22%3A%7B%22line%22%3A8%2C%22character%22%3A24%7D%7D%2C%7B%22uri%22%3A%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2FUsers%2Fmbn%2FDocuments%2FProgrammering%2Fc%2B%2B%2FFiskeFlok%2Fmain.c%2B%2B%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%2C%22pos%22%3A%7B%22line%22%3A12%2C%22character%22%3A0%7D%7D%2C%7B%22uri%22%3A%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2FUsers%2Fmbn%2FDocuments%2FProgrammering%2Fc%2B%2B%2FFiskeFlok%2F.vscode%2Ftasks.json%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%2C%22pos%22%3A%7B%22line%22%3A11%2C%22character%22%3A32%7D%7D%5D%2C%2234f7e20d-ce57-432f-b939-ddd884ca4344%22%5D "Go to definition") struct and related functions.
- **FishMovement.cpp**: Implementation of fish movement behaviors.
- **FishMovement.hpp**: Declaration of the [`FishMovement`](command:_github.copilot.openSymbolFromReferences?%5B%22%22%2C%5B%7B%22uri%22%3A%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2FUsers%2Fmbn%2FDocuments%2FProgrammering%2Fc%2B%2B%2FFiskeFlok%2FFishMovement.hpp%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%2C%22pos%22%3A%7B%22line%22%3A6%2C%22character%22%3A6%7D%7D%2C%7B%22uri%22%3A%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2FUsers%2Fmbn%2FDocuments%2FProgrammering%2Fc%2B%2B%2FFiskeFlok%2Fmain.c%2B%2B%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%2C%22pos%22%3A%7B%22line%22%3A19%2C%22character%22%3A8%7D%7D%2C%7B%22uri%22%3A%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2FUsers%2Fmbn%2FDocuments%2FProgrammering%2Fc%2B%2B%2FFiskeFlok%2F.vscode%2Ftasks.json%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%2C%22pos%22%3A%7B%22line%22%3A12%2C%22character%22%3A32%7D%7D%5D%2C%2234f7e20d-ce57-432f-b939-ddd884ca4344%22%5D "Go to definition") class.
- **main.c++**: Entry point of the application, handles window creation and main loop.
- **main.hpp**: Declarations of main functions.

