# Problem 125 - Debugger

**ACMOJ Problem ID**: 1884

## Table of Contents

- [Problem 125 - Debugger](#problem-125-debugger)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **1884. Debugger** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/125/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

Rabbit 在隐退江湖之前是一个 Debuger.

众所周知，Debug 工作往往是非常枯燥的，然而 Rabbit 不幸被分到了最枯燥的岗位上，负责检查程序中一系列变量相等/不等的约束是否矛盾。

假设 $x_1, x_2, x_3, \dots$ 代表程序中出现的变量，给定 $n$ 个形如 $x_i = x_j$ 或 $x_i \neq x_j$ 的变量相等/不等的约束条件，Rabbit 需要判定是否可以分别为每一个变量赋予恰当的值，使得上述所有约束条件同时被满足。例如，一个问题中的约束条件为：$x_1=x_2, x_2=x_3, x_3=x_4, x_4\neq x_1$，这些约束条件显然是不可能同时被满足的，因此这个问题应判定为不可被满足。

Rabbit 希望你能帮忙设计一个所谓的 Debug 自动机，即给出一些约束条件，判断这些条件是否可以被同时满足。

### Input Format

输入的第一行包含一个正整数 $t$，表示需要判定的问题个数。注意这些问题之间是相互独立的。
对于每个问题，包含若干行：

第一行包含一个正整数 $n$，表示该问题中需要被满足的约束条件个数。接下来 $n$ 行，每行包括三个整数 $i,j,e$，描述一个相等/不等的约束条件，相邻整数之间用单个空格隔开。若$e=1$，则该约束条件为 $x_i=x_j$。若$e=0$，则该约束条件为 $x_i\neq x_j$。

### Output Format

输出包括 $t$ 行。

输出文件的第 $k$ 行输出一个字符串 `YES` 或者 `NO`（字母全部大写），`YES` 表示输入中的第 $k$ 个问题判定为可以被满足，`NO` 表示不可被满足。

### Samples

#### Sample 1

**Input:**
```
2
3
1 2 1
2 3 1
3 1 1
4
1 2 1
2 3 1
3 4 1
1 4 0
```

**Output:**
```
YES
NO
```

### Data Constraints

对于前 30% 的数据， $n \leq 1000, 1 \leq i,j \leq 1000000$

对于前 80% 的数据， $n \leq 10^6, 1 \leq i,j \leq 10^9, 1 \leq t \leq 10$

对于最后 20% 的数据， $n \leq 2\times 10^6, 1 \leq i,j \leq 10^9, t = 40$

本题数据量大，建议使用 `scanf` 或读入优化。

## Resource Limits

- **Time Limit**: 2000 ms
- **Memory Limit**: 256 MiB

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 2000 ms
- **Memory Limit (per test case)**: 256 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/125/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
