# Mini Shell

A lightweight Unix-like command-line shell built from scratch in **C** on Linux.

This project explores the fundamentals of systems programming, process execution, command handling, and the interaction between user-space programs and the operating system.

The goal is to understand how a shell works internally by implementing its core functionality rather than relying on an existing shell.

## Overview

A shell is a command-line interpreter that acts as an interface between users and the operating system.

It reads user input, interprets commands, executes programs, manages processes, and provides an environment for interacting with the system.

This project implements a basic interactive shell with a modular C codebase and GNU Readline integration for improved terminal input and command history.

## Features

- Interactive command-line interface.
- Command execution.
- Built-in command handling.
- Directory navigation using `cd`.
- Command-line input using GNU Readline.
- Command history support.
- History persistence using GNU Readline history functions.
- Modular source-code organization.
- Automated compilation using GNU Make.

## Tech Stack

| Component | Technology |
|---|---|
| Language | C |
| Operating System | Linux |
| Compiler | GCC |
| Build System | GNU Make |
| Input Handling | GNU Readline |
| Debugging | GDB |
| Development Environment | EndeavourOS |

## Project Structure

```text
mini-shell/
├── src/
│   ├── shell.c
│   ├── history.c
│   └── history.h
├── Makefile
├── README.md
└── .gitignore
```

### Source Code Organization

**`shell.c`**
- Contains the main shell implementation.
- Handles command processing and execution.
- Implements built-in shell commands.
- Manages the interactive shell loop.

**`history.c`**
- Implements command history functionality.
- Handles history initialization and cleanup.
- Reads user input through GNU Readline.
- Maintains command history.

**`history.h`**
- Declares history-related functions.
- Provides the interface between the shell and history modules.

**`Makefile`**
- Automates compilation.
- Links the required GNU Readline library.
- Provides build, run, and clean targets.

## Getting Started

### Prerequisites

Make sure the following packages are installed:

```bash
sudo pacman -S gcc make readline
```

### 1. Clone the repository

```bash
git clone https://github.com/rootaashu/mini-shell.git
cd mini-shell
```

### 2. Build the project

Compile using the Makefile:

```bash
make
```

### 3. Run the shell

```bash
make run
```

Alternatively:

```bash
./minishell
```

### 4. Clean generated files

```bash
make clean
```

## Usage

Once launched, the shell provides an interactive prompt where commands can be entered.

Example:

```text
>> ls
>> pwd
>> cd ..
>> ls
>> exit
```

Command availability depends on the implemented built-ins and external command execution support.

## Core Concepts Explored

This project focuses on understanding several fundamental systems-programming concepts:

- **Process Management:** Understanding how processes are created, executed, and monitored.
- **Command Execution:** Exploring how commands are interpreted and passed to the operating system.
- **System Calls:** Learning how programs interact with Linux through system interfaces.
- **Modular Programming:** Separating functionality across multiple C source and header files.
- **Command History:** Using GNU Readline to manage interactive terminal input.
- **Build Automation:** Using GNU Make to simplify compilation and project management.
- **Memory Management:** Understanding allocation, cleanup, and resource handling in C.

## Future Improvements

Planned enhancements include:

- Improved command parsing and argument handling.
- Input and output redirection.
- Pipeline implementation using `pipe()`.
- Background process execution.
- Improved signal handling (`SIGINT`, `SIGCHLD`).
- Command history navigation improvements.
- Better error handling and memory management.
- Support for environment variables and shell expansion.

