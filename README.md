# Project Euler Solutions

## Background

This repo will hold my work to solve [Project Euler](https://projecteuler.net/) problems.

My motivation for doing these is equal parts
- enjoyment (🤷 better than doom-scrolling)
- building some muscle memory for C++, which I'm now using professionally for the first time.
- developing an intuition on improving software performance.

I might include a README for the individual problems with the prompt, some notes, or a reflection on the problem — or not.

I'm using CMake and Clang and developing locally in vim with some simple syntax highlighting. The setup is intentionally low-tech.

## Building && Running

I use bash executables to build and run the programs with configurable user input.
- `./clean.sh` will delete everything in `./problem*/build/`.
- `./makeit.sh` generates build files and builds into `./problem*/build/`.
- `./run.sh` will run the program with user input passed without a flag: `./run.sh 10`.

---

🌊🌊🏄🌊
