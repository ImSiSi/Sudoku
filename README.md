# Sudoku Solver

A simple C++ implementation of a Sudoku solver using backtracking.

## 🔧 Features

- Solves any valid 9x9 Sudoku puzzle
- Uses recursive backtracking with validity checks
- Command-line input interface

## 📦 How to Build

Make sure you have a C++ compiler like `g++` or `clang++` installed.

bash
clang++ Sudoku.cpp -o Sudoku

## ▶️ How to Run
bash
./Sudoku
You will be prompted to enter the board row by row:
	•	Use 0 to represent empty cells
	•	Separate each character with a space

## 🧠 How It Works

The algorithm recursively tries numbers from 1 to 9 in each empty cell.
If it encounters an invalid configuration, it backtracks and tries another number.

## 📘 Example Input
5 3 0 0 7 0 0 0 0  
6 0 0 1 9 5 0 0 0  
0 9 8 0 0 0 0 6 0  
8 0 0 0 6 0 0 0 3  
4 0 0 8 0 3 0 0 1  
7 0 0 0 2 0 0 0 6  
0 6 0 0 0 0 2 8 0  
0 0 0 4 1 9 0 0 5  
0 0 0 0 8 0 0 7 9

This project is for educational purposes.
Feel free to fork, modify, and experiment with it.
