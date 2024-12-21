# 🛠️ **SAL Virtual Machine Emulator** 🛠️

## 📚 **Overview**
This project implements a **SAL (Simple Assembly Language) Virtual Machine Emulator**. It allows you to simulate and execute a set of low-level assembly-like commands. The program parses a SAL script file, executes commands step-by-step or all at once, and displays the state of the machine during execution.

---

## 🚀 **Features**
- Supports a set of SAL instructions (`DEC`, `LDA`, `LDI`, `STR`, `XCH`, `JMP`, `JZS`, `ADD`, `SUB`, `HLT`).
- Command parsing and validation.
- Step-by-step execution (`s`) or full program execution (`a`).
- Memory and register state visualization.
- Error handling for invalid commands or memory overflow.

---

## 📂 **Project Structure**

```
📦 SAL-Virtual-Machine
├── main.cpp        // Entry point of the program
├── Machine.cpp     // Machine implementation
├── Machine.h       // Machine class definition
├── Invoker.cpp     // Command invoker implementation
├── Invoker.h       // Invoker class definition
├── Commands.cpp    // Command implementations
├── Commands.h      // Command class definitions
├── Command.h       // Base Command class
└── README.md       // Project documentation
```

---

## 🛠️ **Dependencies**
- **C++17** or later
- Standard C++ Libraries (iostream, fstream, sstream)
- CMake (optional for building)

---

## ⚙️ **How to Build and Run**

1. **Clone the repository:**
   ```bash
   git clone https://github.com/your-repo/SAL-Virtual-Machine.git
   cd SAL-Virtual-Machine
   ```

2. **Build the project:**
   ```bash
   g++ -std=c++17 main.cpp Machine.cpp Invoker.cpp Commands.cpp -o sal_vm
   ```

3. **Run the emulator:**
   ```bash
   ./sal_vm
   ```

4. **Input SAL Program File:**
   - Provide the path to your SAL script file when prompted.

5. **Control Execution:**
   - `s`: Execute one instruction step-by-step.
   - `a`: Execute all instructions at once.
   - `q`: Quit the emulator.

---

## 📑 **Supported SAL Instructions**
| **Instruction** | **Description**                 |
|------------------|---------------------------------|
| `DEC sym`       | Declare a symbol in memory.     |
| `LDA sym`       | Load memory value into A.       |
| `LDI val`       | Load immediate value into A.    |
| `STR sym`       | Store A value into memory.      |
| `XCH`           | Exchange registers A and B.     |
| `JMP addr`      | Jump to address.                |
| `JZS addr`      | Jump if zero flag is set.       |
| `ADD`           | Add registers A and B.          |
| `SUB`           | Subtract B from A.              |
| `HLT`           | Halt execution.                 |

---

## 🧠 **How It Works**
1. **Command Parsing:** Reads SAL commands from a file and parses them into corresponding command objects.
2. **Invoker:** Stores commands and manages execution flow.
3. **Machine:** Holds registers, memory, and program counter.
4. **Command Execution:** Executes instructions and updates the machine state accordingly.

---

## 👨‍💻 **Example SAL Program**
```sal
DEC X
LDI 5
STR X
LDA X
ADD
HLT
```

---

## 🐞 **Error Handling**
- Invalid commands or addresses are gracefully reported.
- Memory overflow prevention.
- Step execution stops on invalid instructions.
