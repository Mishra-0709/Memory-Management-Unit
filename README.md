# 🧠 Memory Management Unit (MMU) Simulator

This project is a **Memory Management Unit (MMU) simulator** written in C, designed to mimic how modern operating systems handle memory allocation using dynamic memory blocks. It supports **First Fit**, **Best Fit**, and **Worst Fit** strategies, and is an excellent learning tool for understanding how low-level memory allocation works.
## 📌 Features
- 📦 Dynamic memory allocation and deallocation
- 🔍 Three allocation strategies: First Fit, Best Fit, Worst Fit
- 🔁 Merges adjacent free memory blocks to reduce fragmentation
- 📊 Visual display of memory block usage
- 🧩 Simple menu-driven CLI for interactive testing
## 🛠️ Technologies Used
- **Language**: C
- **Concepts**: Linked Lists, Dynamic Memory Management
- **Build**: Compile with `gcc` or any C compiler
## 📂 Folder Structure
MMU/
├── main.c # User interface and menu
├── memory.c # Memory allocation and deallocation logic
├── memory.h # Struct definitions and function prototypes
├── README.md # Project documentation

##🧠 **Concepts You Will Learn**
**-Linked list manipulation**
**-Memory fragmentation and compaction**
**-Fit strategies used in memory management**
**-Practical use of dynamic memory (malloc, free)**
**-Structuring code for simulation and debugging**

## 🚀 How to Run
### 🔧 Prerequisites
- A C compiler (`gcc`)
- Terminal / Command Prompt

### 📦 Compile the project
You can compile using `gcc`:
```bash
✍️ Sample Output 
text
Copy
Edit
Enter total memory size: 1000

Menu:
1. Allocate Memory
2. Deallocate Memory
3. Display Memory
4. Exit

Enter your choice: 1
Enter process size: 200
Choose strategy (F: First Fit, B: Best Fit, W: Worst Fit): F
Process allocated with Block ID: 1

