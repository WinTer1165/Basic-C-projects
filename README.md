# Basic C Projects

A collection of small, beginner-friendly programs written in plain C. Each one lives in its own folder and is meant to be easy to read, compile, and tinker with. If you're learning C in school or just picking it up on your own, this is a good place to see how the basics come together in real little programs.

New to the repo? Start with [LEARN.md](LEARN.md).

## What's inside

| Project | What it does |
| --- | --- |
| [Password Generator](Password%20Generator) | Builds random passwords from digits, letters, and special characters based on a length you pick. |
| [Rock Paper Scissor](Rock%20Paper%20Scissor) | Classic rock-paper-scissors against the computer, played over as many rounds as you choose. |
| [Tic Tac Toe](Tic%20Tac%20Toe) | Two-player tic-tac-toe on a 3x3 board, with input mapped to the number pad. |
| [Hangman](Hangman) | Guess the hidden word before the stick figure is fully drawn. Comes with ASCII art and two versions. |
| [Weather Station](Weather%20Station) | Reads a week of temperatures and reports the average, the hottest day, and the coldest day. |
| [Robot Game V1](Robot%20Game%20V1) | Drive a little robot around a grid using w/a/s/d commands. |
| [Hotel Management System](Hotel%20Management%20System) | Add, edit, delete, search, and sort hotel rooms. Saves everything to a text file. |
| [My_String_Dot_H](My_String_Dot_H) | A from-scratch take on `string.h`, reimplementing functions like string length and compare so you can see how they work under the hood. |
| [Graph Plotter](Graph%20Plotter) | Plots a quadratic equation `y = ax^2 + bx + c` as ASCII art in the terminal. Contributed by [PPraneesh](https://github.com/PPraneesh). |
| [Calculator](Calculator) | A menu-driven calculator that adds, subtracts, multiplies, and divides, looping until you choose to exit. |
| [Number Guessing Game](Number%20Guessing%20Game) | The computer picks a secret number from 1 to 100 and gives higher/lower hints until you guess it. |
| [Caesar Cipher](Caesar%20Cipher) | Encrypts or decrypts a message by shifting each letter through the alphabet. |
| [Morse Code Translator](Morse%20Code%20Translator) | Converts plain text into dots and dashes, letter by letter. |
| [Quiz Game](Quiz%20Game) | A short multiple-choice quiz on C basics that scores you at the end. |
| [To-Do List](To-Do%20List) | Add, view, and delete tasks. Saves them to a file so they're still there next time. |
| [Banking System](Banking%20System) | Open accounts, deposit, withdraw, and check balances using structs and a menu. |
| [Dice Roller](Dice%20Roller) | Rolls one or more dice and draws each result as an ASCII dice face. |

### A bit more advanced

These ones lean on structs, menus, and saving data to a file, so they're a good next step once the smaller programs make sense.

| Project | What it does |
| --- | --- |
| [Library Management System](Library%20Management%20System) | Add books, issue and return them, search the shelf, and delete old titles. Saves the whole library to a file. |
| [Student Result Management System](Student%20Result%20Management%20System) | Record marks across five subjects, then get totals, averages, letter grades, and the class topper. Results are saved to a file. |
| [Inventory Management System](Inventory%20Management%20System) | Track stock for a small shop: sell, restock, see low-stock warnings, and check the total value on hand. Saved to a file. |
| [Bus Reservation System](Bus%20Reservation%20System%20V3) | Book and manage bus seats. Comes in three versions (V1, V2, V3) that grow more capable as you go. |


The Bus Reservation System has three folders. V1 and V2 are earlier takes, and V3 is the most complete one, with a splash screen and the choice of saving data to either `.txt` or `.dat` files.

## Running a project

Most of these were written and tested on Windows, so a few of them use `windows.h` (for example, `Sleep()` and clearing the screen). They'll compile fine with GCC.

1. Open a terminal in the project folder you want to run.
2. Compile the C file:

   ```bash
   gcc main.c -o program
   ```

   Some folders name the file differently (for example `bus_reservation.c`), so use whatever `.c` file is in that folder.

3. Run it:

   ```bash
   ./program        # Linux / macOS
   program.exe      # Windows
   ```

If a project reads or writes a data file (like the hotel system's `rooms.txt`), run the program from inside its own folder so it can find that file.

## Contributing

Pull requests are welcome. If you'd like to add a project or fix something:

1. Fork this repository.
2. Create a branch for your change: `git checkout -b feature/your-feature-name`.
3. Make your changes and commit them with clear messages.
4. Push the branch to your fork: `git push origin feature/your-feature-name`.
5. Open a pull request against this repo.

More projects will be added over time, so check back.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
