#include <iostream>

int main() {
   int age = 20;
   int years = 5;

   int futureAge = age + years;

   std::cout << "Current age: " << age << std::endl;
   std::cout << "Future age: " << futureAge << std::endl;

   return 0;
}


/*
============================================================
C++ REFERENCE NOTES
TOPIC: HELLO WORLD, COMPILATION, AND DEBUGGING
ENVIRONMENT: macOS + Visual Studio Code
COMPILER: Apple Clang
DEBUGGER: LLDB
LANGUAGE STANDARD: C++17
============================================================


SECTION 1: DEVELOPMENT ENVIRONMENT
============================================================

Visual Studio Code (VS Code)
------------------------------------------------------------
VS Code is the code editor used to write, organize, and
debug C++ programs.

VS Code does not compile C++ code by itself. It uses
external tools to compile and debug programs.

Extensions installed:

1. C/C++ (Microsoft)
   - Provides syntax highlighting.
   - Provides IntelliSense (code suggestions).
   - Helps identify potential errors.
   - Supports code navigation and debugging integration.

2. CodeLLDB
   - Integrates the LLDB debugger with VS Code.
   - Allows breakpoints and step-by-step execution.
   - Allows inspection of variables during execution.


SECTION 2: TERMINAL COMMANDS
============================================================

The terminal allows us to interact with the operating
system and execute development tools using commands.

On macOS, the default terminal shell is usually Zsh.

------------------------------------------------------------
COMMAND 1: Install Apple's Command Line Tools
------------------------------------------------------------

xcode-select --install

Purpose:
Installs Apple's Command Line Developer Tools.

These tools include:
- Clang: C and C++ compiler.
- LLDB: Debugger.
- Additional development utilities.

The full Xcode application is not required.

This command generally only needs to be run once.

------------------------------------------------------------
COMMAND 2: Check the C++ compiler
------------------------------------------------------------

clang++ --version

Purpose:
Displays information about the installed C++ compiler.

clang++:
The Clang C++ compiler executable.

--version:
Requests the compiler's version information.

If a version appears, the compiler is accessible.

------------------------------------------------------------
COMMAND 3: Check the debugger
------------------------------------------------------------

lldb --version

Purpose:
Displays information about the installed LLDB debugger.

LLDB allows us to:
- Pause program execution.
- Inspect variables.
- Execute code one line at a time.
- Investigate crashes and unexpected behavior.

------------------------------------------------------------
COMMAND 4: Display the current directory
------------------------------------------------------------

pwd

Purpose:
Print Working Directory.

Displays the absolute path of the folder the terminal
is currently operating inside.

Example:

/Users/username/Documents/Cpp-Learning

This is useful because compilation commands operate
relative to the terminal's current directory unless
another path is specified.

------------------------------------------------------------
COMMAND 5: List files in the current directory
------------------------------------------------------------

ls -l

Purpose:
Lists files and folders in the current directory.

ls:
Lists directory contents.

-l:
Displays detailed information such as permissions,
file sizes, and modification dates.

Example files:

hello.cpp
hello
hello.dSYM

------------------------------------------------------------
COMMAND 6: Check the VS Code configuration directory
------------------------------------------------------------

ls -l .vscode

Purpose:
Lists files inside the .vscode directory.

This directory can contain project-specific VS Code
settings and configurations.

For example:

launch.json
tasks.json
settings.json

If the directory does not exist, the terminal may
display a "No such file or directory" message.

------------------------------------------------------------
COMMAND 7: Compile the C++ program
------------------------------------------------------------

clang++ -std=c++17 -g hello.cpp -o hello

Purpose:
Converts the C++ source code into an executable program.

Breakdown:

clang++
    Runs Apple's Clang C++ compiler.

-std=c++17
    Instructs the compiler to use the C++17 standard.

-g
    Includes debugging information in the executable.

hello.cpp
    Specifies the source code file to compile.

-o
    Specifies the output filename.

hello
    Names the compiled executable "hello".

The compiler generally produces no terminal output
when compilation completes successfully.

If the code contains errors, the compiler displays
diagnostic messages instead.

------------------------------------------------------------
COMMAND 8: Execute the compiled program
------------------------------------------------------------

./hello

Purpose:
Runs the compiled executable.

./
    Refers to the current directory.

hello
    Refers to the executable file.

Expected output:

Hello, World!

IMPORTANT:
The executable does not automatically update when
the source code changes.

After modifying hello.cpp, compile again to update
the executable before running or debugging it.


SECTION 3: UNDERSTANDING C++ SOURCE FILES
============================================================

hello.cpp
------------------------------------------------------------

This is the source code file.

.cpp:
A common file extension for C++ source code.

The file contains human-readable C++ instructions.

The compiler translates these instructions into
machine code that the computer can execute.

hello
------------------------------------------------------------

This is the compiled executable.

On macOS, executables do not normally require a
filename extension.

The executable is produced by the compiler and linker.

hello.dSYM
------------------------------------------------------------

This is a debugging symbol bundle.

On macOS, Clang may produce a .dSYM bundle when
debugging information is enabled.

It helps the debugger associate compiled machine code
with source code locations and debugging symbols.

It is not the program itself.

The executable is still the file named "hello".


SECTION 4: BASIC C++ PROGRAM STRUCTURE
============================================================

Our original program:

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

Explanation of each component:

------------------------------------------------------------
#include <iostream>
------------------------------------------------------------

#include is a preprocessor directive.

It instructs the compiler's preprocessing stage to
include the contents of the specified header.

<iostream> is part of the C++ Standard Library.

It provides declarations for standard input and
output streams, including std::cout and std::cin.

------------------------------------------------------------
int main()
------------------------------------------------------------

main() is the program's entry-point function.

When the program starts, execution eventually
enters the main function.

int:
Specifies that main returns an integer.

main:
The required name of the entry-point function
for a normal hosted C++ program.

():
The function's parameter list.

An empty parameter list means this version of
main does not accept command-line arguments.

------------------------------------------------------------
{ }
------------------------------------------------------------

Curly braces define a block of code.

The opening brace { begins the function body.

The closing brace } ends the function body.

Statements inside the braces belong to main().

------------------------------------------------------------
std::cout
------------------------------------------------------------

std:
The namespace containing C++ Standard Library
declarations.

::
The scope resolution operator.

cout:
The standard character output stream.

std::cout usually sends text to the terminal.

------------------------------------------------------------
<<
------------------------------------------------------------

The stream insertion operator.

When used with std::cout, it inserts data into
the output stream.

Example:

std::cout << "Hello";

Multiple insertions can be chained together.

Example:

std::cout << "Hello" << " World";

------------------------------------------------------------
"Hello, World!"
------------------------------------------------------------

This is a string literal.

A string literal represents a sequence of characters
enclosed in double quotation marks.

Here, it represents the text to display.

------------------------------------------------------------
std::endl
------------------------------------------------------------

A stream manipulator.

It performs two operations:

1. Inserts a newline character.
2. Flushes the output stream.

Flushing requests that buffered output be written
to the underlying destination.

For simple newline output, '\n' is often preferred
because it does not require an explicit flush.

Example:

std::cout << "Hello, World!\n";

------------------------------------------------------------
;
------------------------------------------------------------

The semicolon terminates many C++ statements.

Example:

return 0;

Forgetting a required semicolon is a common
beginner syntax error.

------------------------------------------------------------
return 0;
------------------------------------------------------------

Ends the main function and returns an integer value.

A return value of 0 conventionally indicates that
the program completed successfully.

A nonzero return value usually indicates some
form of failure or abnormal termination.

In C++, reaching the end of main() without an
explicit return is equivalent to returning 0.


SECTION 5: COMPILATION PROCESS
============================================================

C++ is generally a compiled programming language.

Our basic development workflow is:

1. Write source code.
2. Save the source file.
3. Compile and link the program.
4. Run the executable.
5. Debug the executable when necessary.

Simplified process:

hello.cpp
    |
    v
Clang Compiler + Linker
    |
    v
hello (Executable)
    |
    v
Program Execution

A more detailed process includes:

Preprocessing:
Processes directives such as #include.

Compilation:
Translates C++ source code toward machine code.

Assembly:
Produces object code.

Linking:
Combines object code with required libraries and
other compiled components into an executable.

The clang++ command normally coordinates these
stages for us.


SECTION 6: DEBUGGING
============================================================

Debugging is the process of investigating and
correcting problems in software.

Our debugger is LLDB, integrated into VS Code
through the CodeLLDB extension.

The debugger operates on the compiled executable.

This is why we compile before debugging.

------------------------------------------------------------
BREAKPOINTS
------------------------------------------------------------

A breakpoint tells the debugger to pause execution
at a particular location in the program.

To create a breakpoint:

1. Open hello.cpp.
2. Click in the margin to the left of a code line.
3. A red dot should appear.
4. Start debugging using F5.

When the breakpoint is reached, execution pauses
before the corresponding instruction executes.

------------------------------------------------------------
CONTINUE (F5)
------------------------------------------------------------

Resumes program execution.

The program continues until:
- Another breakpoint is reached.
- The debugger encounters a stopping event.
- The program finishes.

------------------------------------------------------------
STEP OVER (F10)
------------------------------------------------------------

Executes the current source-level step without
entering called functions.

Useful for moving through code line by line.

------------------------------------------------------------
STEP INTO (F11)
------------------------------------------------------------

Attempts to enter a function being called.

Useful for examining what happens inside
your own functions.

------------------------------------------------------------
STEP OUT (Shift + F11)
------------------------------------------------------------

Continues execution until the current function
returns, then pauses in its caller when possible.

Useful when you have finished examining a function.

------------------------------------------------------------
STOP (Shift + F5)
------------------------------------------------------------

Stops the debugging session.

These keyboard shortcuts are VS Code defaults.
On some Mac keyboards, the Fn key may also be
required to use function keys.


SECTION 7: DEBUGGER PANELS
============================================================

VARIABLES
------------------------------------------------------------

Displays variables accessible at the current
execution location.

Variables may include:
- Names
- Values
- Data types

Useful for verifying whether values are correct.

WATCH
------------------------------------------------------------

Allows us to monitor selected expressions.

Example expressions:

age
years
age + years

These expressions are evaluated when the debugger
is paused and the values are available.

CALL STACK
------------------------------------------------------------

Displays the active chain of function calls.

This helps identify how execution reached
the current function.

BREAKPOINTS
------------------------------------------------------------

Displays configured breakpoints.

Breakpoints can be enabled, disabled, or removed.


SECTION 8: VS CODE DEBUGGER CONFIGURATION
============================================================

VS Code can use a file named:

.vscode/launch.json

This file contains debugging configurations.

Our configuration:

{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug C++",
            "type": "lldb",
            "request": "launch",
            "program": "${workspaceFolder}/hello",
            "args": [],
            "cwd": "${workspaceFolder}"
        }
    ]
}

IMPORTANT:
This is JSON configuration, not C++ code.

It belongs inside launch.json, not hello.cpp.

Explanation:

version:
    Specifies the VS Code debug configuration format.

configurations:
    Contains available debugging configurations.

name:
    The name displayed in VS Code.

type:
    Identifies the debugger integration.

    "lldb" uses CodeLLDB.

request:
    "launch" starts a program for debugging.

program:
    Specifies the executable to debug.

${workspaceFolder}:
    Refers to the folder opened as the workspace
    in VS Code.

args:
    Contains command-line arguments passed to
    the executable.

cwd:
    Specifies the working directory of the
    program while it runs.

IMPORTANT:
If "program" points to the wrong location,
the debugger may report that the program
does not exist.


SECTION 9: COMMON ERRORS
============================================================

ERROR 1: Incorrect stream insertion operator
------------------------------------------------------------

Incorrect:

std::cout < "Hello, World!" << std::endl;

Correct:

std::cout << "Hello, World!" << std::endl;

Explanation:

< is the less-than comparison operator.

<< is the stream insertion operator when used
with std::cout.

Using the wrong operator causes compilation errors.

------------------------------------------------------------
ERROR 2: Program does not exist
------------------------------------------------------------

Possible causes:

1. The executable has not been compiled.
2. The executable is in a different directory.
3. launch.json points to the wrong executable.
4. The output filename does not match.

Troubleshooting commands:

pwd
ls -l

Then compile:

clang++ -std=c++17 -g hello.cpp -o hello

Verify the executable exists before debugging.

------------------------------------------------------------
ERROR 3: Changes do not appear when running
------------------------------------------------------------

Cause:

The source code was modified, but the executable
was not rebuilt.

Solution:

Save the source code.

Compile again:

clang++ -std=c++17 -g hello.cpp -o hello

Then execute:

./hello

------------------------------------------------------------
ERROR 4: Compilation fails
------------------------------------------------------------

Possible causes:

- Missing semicolon.
- Incorrect operator.
- Misspelled variable or function name.
- Missing header.
- Incorrect syntax.

The compiler usually provides:
- Filename
- Line number
- Column number
- Description of the error

Read the first meaningful error and examine
the indicated line and surrounding code.


SECTION 10: USEFUL VS CODE SHORTCUTS (MAC)
============================================================

Cmd + S
    Save the current file.

Cmd + Shift + X
    Open Extensions.

Cmd + Shift + D
    Open Run and Debug.

Ctrl + `
    Toggle the integrated terminal.

F5
    Start or continue debugging.

F10
    Step Over.

F11
    Step Into.

Shift + F11
    Step Out.

Shift + F5
    Stop debugging.

Some Mac keyboards require holding Fn when
pressing function keys.


SECTION 11: KEY CONCEPTS TO REMEMBER
============================================================

1. VS Code is our development editor.

2. Clang compiles our C++ source code.

3. LLDB debugs the compiled executable.

4. hello.cpp is the source code.

5. hello is the executable.

6. hello.dSYM contains debugging symbols.

7. Compilation must succeed before the new
   version of the program can be executed.

8. A breakpoint pauses execution.

9. Step Over executes the current source-level
   step without entering called functions.

10. Variables and Watch help inspect program state.

11. launch.json tells VS Code how to start
    a debugging session.

12. Compiler errors identify problems that
    prevent successful compilation.

13. Debuggers help investigate problems in
    programs that can be executed.


============================================================
END OF REFERENCE NOTES
============================================================
*/


// ==========================================================
// ORIGINAL HELLO WORLD PROGRAM
// ==========================================================

// Includes the standard input/output stream library.
// This allows us to use std::cout.
#include <iostream>

// main() is the entry point of our program.
// The int return type indicates it returns an integer.
int main() {

    // std::cout sends output to the terminal.
    // << inserts the string into the output stream.
    // std::endl adds a newline and flushes the stream.
    std::cout << "Hello, World!" << std::endl;

    // Returning 0 indicates successful program completion.
    return 0;
}
