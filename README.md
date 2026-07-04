# CryptX-Core 🔐

> Advanced Encryption & Cipher Engine Simulator built in C++ emphasizing modern Object-Oriented Programming (OOP) architectures, Runtime Polymorphism, and Dependency Injection.

---

## 🚀 Overview

**CryptX-Core** is a lightweight, backend-focused cryptographic simulation engine designed to demonstrate secure data masking and strategy-driven software design. Instead of relying on tightly coupled code, the project implements a flexible architecture where encryption algorithms can be dynamically swapped at runtime without altering the core messaging pipeline.

## 🧠 Architectural Highlights

- **Abstract Base Engine Interface:** Utilizes C++ pure virtual functions (`= 0`) to define a strict contract for all future cryptographic algorithms, mimicking a Java-style interface structure.
- **Dependency Injection (DI):** The `GuvenliMesajMerkezi` (Manager Class) acts as a decoupled controller that receives encryption strategies from the outside, enforcing the **Dependency Inversion Principle**.
- **Runtime Polymorphism:** Leverages heap-allocated base class pointers to dynamically swap execution strategies on the fly.
- **Bitwise & Substitution Ciphers:** Implements a standard custom Caesar Shift algorithm along with a robust Bitwise XOR (`^`) data masking mechanism.

---

## 🛠️ Implemented Algorithms

### 1. Caesar Substitution
Shifts each character's ASCII value by a predetermined integer key. Simple, deterministic, and excellent for demonstrating character streaming.

### 2. Bitwise XOR (`^`) Masking
A low-level bit manipulation cipher heavily used in core systems and networking. Applying the same character key twice restores the original state, making encryption and decryption symmetric and efficient.

---

## 💻 Technical Stack & Implementation

- **Language:** C++17
- **Paradigm:** Object-Oriented Programming (OOP), Loose Coupling Architecture
- **Memory Management:** Manual heap allocation tracking with explicit virtual destructors to prevent memory leaks in polymorphic deep classes.

### How to Compile and Run
Run the standard GNU Compiler Collection (GCC) pipeline on your terminal:

```bash
# Compile the core simulation
g++ -std=c++17 cryptx.cpp -o cryptx

# Execute the engine
./cryptx
