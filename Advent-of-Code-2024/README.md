<h1> Advent of Code 2024 - My Solutions </h1>

This repository contains my solutions to **Advent of Code 2024**. I'm participating in this event by solving each day's puzzle throughout the month. Each day I will provide a brief explanation of my code and what I learned solving the challenge. My primary goal is to practice and improve my C++ programming skills. 

***Please note that the code will not always be the most efficient or optimized solution.***


<h2>Day 1: Historian hysteria</h2>

Today's task involved handling two lists of location IDs that didn't match up. 

<h3>Part 1</h3>

I wrote a C++ program that reads numbers from an input file with two separate lists, and the program calculates the **total distance** by adding the differences between matching indices of the sorted lists.

<h3>Part 2</h3>

The program also computes a **similarity score** by checking how many times each number from the first list appears in the second list, and summing their values.

<h3>What I Learned</h3>

This exercise helped me gain experience handling input from a file, sorting numbers and handling data in C++.


<h2>Day 2: Red-Nosed Reports</h2>

Today's task involved analyzing reactor safety reports composed of sequences of levels represented by integers. The goal was to determine how many reports are safe based on specific criteria: the levels must be either all increasing or all decreasing, and any  two adjacent levels must differ by at least one and at most three.

<h3>Part 1</h3>

I wrote a program that reads each report from an input file and checks whether it meets the safety criteria. The program parses each line into integers and verifies that the differences between adjacent levels are within the allowed range and that the sequence is all increasing or decreasing.

<h3>Part 2</h3>

For the second part, the program accounts for a **Problem Dampener** that allows the removal of a single bad level to make and otherwise unsafe report safe. It does this by removing each level one at a time and re-evaluating the report's safety.

<h3>What I Learned</h3>

I learned about the utility of function overloading to handle different types of input, how to efficently process data with string streams, and implement complex logical coditions to validate a spefic sequence.

<h2>Day 3: Mull It Over</h2>

Today's task was to scan a corrupted memory string to search for a valid instruction in the form of **mul(x,y)** where x and y are 3 digit positive integers.

<h3>Part 1</h3>

I had to sum the product of x and y and return this sum. Invalid characters or instructions that did not follow the specified format were ignored.

<h3>Part 2</h3>

For part two, the program also needed to ahndle **do()** and **don't()** instructions that respetively enables or disables subsequent "mul" operations. 

<h3>What I Learned</h3>

This challenge enhanced my skills in string parsing and patern recognition, but after examing other people's solutions, I am inspired to learn how to use regular expressions to simplify and improve my code. My code is relatively inefficient and hard to read. Learning regex would fix this issue.

<h2>Day 4: Ceres Search</h2>

Today, the task involved finding different patterns in a 140x140 word search containing the letters in "XMAS".

<h3>Part 1</h3>

For Part1, it checks for the word XMAS" starting from "X" in all valid directions. The total number of occurences is outputted.

<h3>Part 2</h3>

For Part 2 the goal was to find occurences of "MAS" arranged in the shape of and X, centered around the letter "A". The program looks for the pattern by examing the diagonal characters around the letter "A".

<h3>What I Learned</h3>

This exercise improved my ability to work with 2 dimensional vectors and implement search algorithms.
