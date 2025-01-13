# Pipex

## Introduction
**Pipex** is a project designed to replicate the behavior of shell pipelines. It takes two commands and an input/output file configuration, executes the commands, and passes the output of the first command as input to the second command using pipes, similar to:

```bash
< file1 cmd1 | cmd2 > file2
```

This project demonstrates an understanding of processes, file descriptors, and inter-process communication in Unix-like systems.

---

## Features
- Mimics shell pipelines (`|`) with two commands.
- Handles redirection of input and output from files.
- Demonstrates the use of system calls like `pipe()`, `fork()`, `dup2()`, and `execve()`.
- Includes robust error handling for file access, invalid commands, and failed system calls.

---

## How to Build

1. Clone the repository:
   ```bash
   git clone https://github.com/BusCops/Pipex.git
   cd pipex
   ```

2. Build the project using `make`:
   ```bash
   make
   ```

3. The executable `pipex` will be created in the project directory.

---

## Usage

```bash
./pipex file1 "cmd1" "cmd2" file2
```

### Parameters
- **file1**: Input file whose contents will be used as input to `cmd1`.
- **cmd1**: The first command to execute.
- **cmd2**: The second command, which takes the output of `cmd1` as its input.
- **file2**: Output file where the final output of `cmd2` is written.

### Example
```bash
./pipex input.txt "grep foo" "wc -l" output.txt
```
This command:
1. Reads from `input.txt`.
2. Passes the content through `grep foo`.
3. Pipes the output of `grep foo` to `wc -l`.
4. Writes the result to `output.txt`.

---

## Error Handling
- Prints an error message if:
  - A file cannot be opened.
  - A command is invalid or not found.
  - A system call (e.g., `fork()`, `pipe()`) fails.
- Returns the appropriate error code for debugging.

---

## Project Structure

```
pipex/
├── libft           # A library of function
├── Makefile        # Build configuration
├── pipex.c         # Main
├── pipex_utils.c   # pipex utils
└── pipex.h         # Header file
```

---

## Allowed Functions
The following functions are used in the project:
- `open`, `close`, `read`, `write`
- `pipe`, `dup`, `dup2`
- `fork`, `wait`, `waitpid`
- `execve`
- `perror`, `strerror`
- `malloc`, `free`

---

## Known Issues
If there are any specific limitations or bugs, they can be listed here. For example:
- Limited to two commands.
- Does not support command-line argument parsing for commands beyond simple strings.

---

## Future Improvements
- Extend functionality to handle more than two commands (like a full shell pipeline).
- Add support for advanced shell features, such as environment variable expansion.
- Improve error messages for better debugging.

---

## Credits
Developed by **abenzaho** as part of the 42 curriculum.

---

## License
This project is open-source and available under the [MIT License](LICENSE).

