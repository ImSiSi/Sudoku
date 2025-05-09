# Sudoku Solver

A simple C++ implementation of a Sudoku solver using backtracking.

## 🔧 Features

- Solves any valid 9x9 Sudoku puzzle
- Uses recursive backtracking with validity checks
- Command-line input interface

## 📦 How to Build

Make sure you have a C++ compiler like `g++` or `clang++` installed.

```bash
clang++ Sudoku.cpp -o Sudoku

▶️ How to Run
```bash
./Sudoku

You will be prompted to enter the board row by row:
	•	Use 0 to represent empty cells
	•	Separate each character with a space

🧠 How It Works

The algorithm recursively tries numbers from 1 to 9 in each empty cell, and backtracks if it encounters an invalid configuration.


This project is for educational purposes. Feel free to fork and modify.
