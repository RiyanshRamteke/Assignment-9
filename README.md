# Assignment 9: Implementation of std::move (utility header) in C++
## About the Program

This C++ program demonstrates `std::move`, which is declared in the `<utility>` header (C++11 and later).

`std::move` does not move anything by itself. It only converts an object into an rvalue, which tells the compiler: "this object is no longer needed, you may take its resources". The real moving is done by the **move constructor** (or move assignment operator).

| Point | Copy | Move |
|---|---|---|
| What happens | A new duplicate of the data is created | The data (pointer) is taken from the old object |
| Speed | Slower for big data | Fast |
| Old object | Keeps its value | Left empty |
| Constructor | `Box(const Box &other)` | `Box(Box &&other)` |

## Program Flow

1. **String:** The word is copied into `s2` (both keep the word). Then `s3 = move(s1)` is used, so `s3` gets the word and `s1` becomes empty.
2. **Vector:** `v2 = move(v1)` transfers all 5 elements to `v2`, and `v1` becomes empty (size 0).
3. **Copy and Move Constructor:** The class `Box` owns memory created with `new`.
   - `Box b2 = b1;` calls the **copy constructor** (new memory is created).
   - `Box b3 = move(b1);` calls the **move constructor** (only the pointer is taken, and `b1` becomes `nullptr`).

## Files

| File | Description |
|---|---|
| `assi9.cpp` | C++ source code |
| `README.md` | Project description |

## How to Compile and Run

Requirement: a C++ compiler (g++) supporting C++11 or later, or Visual Studio Code with a C++ setup.

```bash
g++ -std=c++11 assi9.cpp -o assi9
./assi9
```

On Windows PowerShell use `.\assi9` to run.

> **Note:** Do not use a space in the word while giving input (use `Hello`, not `Hello World`), because `cin >>` stops reading at a space.

## Sample Input and Output

**Input:**

```
Hello 10
```

**Output:**

```
Enter a word and a number: 
--- 1. String ---
After copy: s1 = [Hello], s2 = [Hello]
After move: s1 = [], s3 = [Hello]

--- 2. Vector ---
v1 size = 0
v2 size = 5

--- 3. Copy and Move Constructor ---
Constructor called
Copy constructor called (new memory created)
Move constructor called (pointer taken, no new memory)
b1 is empty (data is nullptr)
b2 value = 10
b3 value = 10
```

## Test Cases

| Test Case | Input | Expected Result |
|---|---|---|
| 1 | `Hello 10` | After move `s1 = []`, `s3 = [Hello]`; v1 size 0, v2 size 5; b1 empty, b2 and b3 value = 10 |
| 2 | `World 25` | After move `s1 = []`, `s3 = [World]`; v1 size 0, v2 size 5; b1 empty, b2 and b3 value = 25 |

## Important Points

- `std::move` only casts an object to an rvalue; it does not move the data by itself.
- After a move, the old object is in a valid but unspecified state (usually empty). Do not use its old value.
- A `const` object cannot be moved; a copy is made instead.
- The move constructor sets the old pointer to `nullptr` so that the same memory is not deleted twice.

## Learning Outcomes

- Use `std::move` to transfer the contents of one object to another.
- Write a move constructor that takes the resource and leaves the old object empty.
- Explain the difference between copying and moving.
- Understand the state of an object after it is moved.

## Repository Details

- **Repository:** https://github.com/YOUR_USERNAME/Assignment9
- **Branch:** main
