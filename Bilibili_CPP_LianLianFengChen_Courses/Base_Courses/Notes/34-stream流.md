---
title: 零基础C++(34) 常用的stream流
date: 2025-03-03 18:17:10
tags: [零基础C++]
categories: [零基础C++] 
---

## 1. C++流的基本概念



**流（Stream）** 是C++中用于处理输入和输出的抽象概念。流可以看作是数据的通道，例如从键盘到程序，或者从程序到文件。C++标准库提供了多种流类型来处理不同的数据传输需求。



### 常见的流类型



- **标准输入流**：`std::cin`
- **标准输出流**：`std::cout`
- **标准错误流**：`std::cerr`
- **文件输入流**：`std::ifstream`
- **文件输出流**：`std::ofstream`
- **文件流（读写）**：`std::fstream`
- **字符串流**：`std::stringstream`, `std::istringstream`, `std::ostringstream`



## 2. 输出流 `std::cout`



`std::cout` 是C++中用于输出数据到标准输出（通常是终端）的流对象。



### 2.1 基本输出



**示例说明**：使用 `std::cout` 输出文本和变量。



```cpp
#include <iostream>

int main() {
    int age = 25;
    std::cout << "Hello, World!" << std::endl;
    std::cout << "I am " << age << " years old." << std::endl;
    return 0;
}
```



**输出**：



```css
Hello, World!
I am 25 years old.
```



**解释**：



- `<<` 运算符用于将数据插入到输出流中。
- `std::endl` 用于输出一个换行符并刷新缓冲区。



### 2.2 格式化输出



C++ 提供了多种方式来格式化输出，例如设置字段宽度、小数点精度等。



**示例说明**：使用不同的格式化操纵器。



```cpp
#include <iostream>
#include <iomanip> // 引入iomanip头文件以使用操纵器

int main() {
    double pi = 3.141592653589793;
    int num = 42;

    // 设置浮点数的显示精度
    std::cout << "Pi with default precision: " << pi << std::endl;
    std::cout << "Pi with 4 decimal places: " << std::fixed << std::setprecision(4) << pi << std::endl;

    // 设置字段宽度和对齐方式
    std::cout << "Number with width 5: |" << std::setw(5) << num << "|" << std::endl;
    std::cout << "Number with width 5 (left aligned): |" << std::left << std::setw(5) << num << "|" << std::endl;

    return 0;
}
```



**输出**：



```sql
Pi with default precision: 3.14159
Pi with 4 decimal places: 3.1416
Number with width 5: |   42|
Number with width 5 (left aligned): |42   |
```



**解释**：



- `std::fixed`：以固定小数点格式显示浮点数。
- `std::setprecision(4)`：设置小数点后4位精度。
- `std::setw(5)`：设置输出字段宽度为5个字符。
- `std::left`：设置左对齐。



## 3. 文件输出流 `std::ofstream`



`std::ofstream` 用于创建和写入文件。



### 3.1 创建和打开文件



在使用 `std::ofstream` 写入文件之前，需要创建一个 `ofstream` 对象并打开目标文件。



### 3.2 向文件写入数据



使用 `<<` 操作符可以向文件中写入数据，类似于 `std::cout`。



### 3.3 关闭文件



写入完成后，应关闭文件以释放资源。



### 3.4 示例代码



**示例说明**：创建一个文本文件并写入数据。

``` cpp
#include <iostream>
#include <fstream> // 引入 fstream 头文件

int main() {
    // 创建一个ofstream对象，并打开文件 "output.txt"
    std::ofstream outfile("output.txt");

    // 检查文件是否成功打开
    if (!outfile) {
        std::cerr << "无法打开文件进行写入。" << std::endl;
        return 1;
    }

    // 向文件中写入数据
    outfile << "这是第一行。\n";
    outfile << "这是第二行，数字：" << 100 << std::endl;
    outfile << "浮点数：" << 3.14159 << std::endl;

    // 关闭文件
    outfile.close();

    std::cout << "数据已成功写入 output.txt 文件。" << std::endl;

    return 0;
}

```

**运行结果**：



```lua
数据已成功写入 output.txt 文件。
```



**`output.txt` 文件内容**：



```undefined
这是第一行。
这是第二行，数字：100
浮点数：3.14159
```



**解释**：



- 创建 `std::ofstream` 对象时，如果文件不存在则会自动创建，若存在则默认覆盖。
- 使用 `<<` 操作符写入字符串、整数和浮点数到文件。
- `outfile.close()` 用于关闭文件。



------



## 4. 文件输入流 `std::ifstream`



`std::ifstream` 用于打开和读取文件内容。



### 4.1 打开和读取文件



使用 `std::ifstream` 对象打开目标文件，并读取其中的数据。



### 4.2 处理读取的数据



可以逐行读取、逐词读取或按其他格式读取数据。



### 4.3 关闭文件



读取完成后，应关闭文件。



### 4.4 示例代码



**示例说明**：读取 `output.txt` 文件并输出内容到控制台。



```cpp
#include <iostream>
#include <fstream>
#include <string> // 引入 string 头文件

int main() {
    // 创建一个ifstream对象，并打开文件 "output.txt"
    std::ifstream infile("output.txt");

    // 检查文件是否成功打开
    if (!infile) {
        std::cerr << "无法打开文件进行读取。" << std::endl;
        return 1;
    }

    std::string line;

    // 逐行读取文件内容
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }

    // 关闭文件
    infile.close();

    return 0;
}
```



**输出**：



```undefined
这是第一行。
这是第二行，数字：100
浮点数：3.14159
```



**解释**：



- 使用 `std::getline` 函数逐行读取文件内容。
- 读取到的每一行存储在 `std::string` 类型的 `line` 变量中。
- 通过 `std::cout` 将读取到的每一行输出到控制台。



------



## 5. 文件流 `std::fstream` （读写结合）



`std::fstream` 允许同时进行文件的读写操作。



### 5.1 同时进行读写操作



通过打开文件的不同模式，可以实现对同一文件的读取和写入。



### 5.2 示例代码



**示例说明**：在同一个文件中读取现有内容并追加新内容。



```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 创建一个 fstream 对象，并以读写模式打开文件 "data.txt"
    std::fstream file("data.txt", std::ios::in | std::ios::out | std::ios::app);

    // 检查文件是否成功打开
    if (!file) {
        std::cerr << "无法打开文件进行读写。" << std::endl;
        return 1;
    }

    // 向文件追加新内容
    file << "追加的一行内容。\n";

    // 将文件指针移动到文件开头以读取内容
    file.seekg(0, std::ios::beg);

    std::string line;

    std::cout << "文件内容如下：" << std::endl;

    // 读取文件内容并输出
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    // 关闭文件
    file.close();

    return 0;
}
```



**解释**：



- `std::ios::in`：以读取模式打开文件。
- `std::ios::out`：以写入模式打开文件。
- `std::ios::app`：以追加模式写入文件（数据会被添加到文件末尾）。
- 使用 `seekg` 将读取位置移动到文件开头，以便读取整个文件内容。
- 先写入数据，再读取整个文件内容，实现读写结合。



**注意**：



- 如果文件不存在，使用 `std::ios::in` 和 `std::ios::out` 组合可能无法创建新文件。在这种情况下，可以添加 `std::ios::trunc` 或 `std::ios::ate` 标志，或者先创建文件。



------



## 6. 字符串流 `std::stringstream`



`std::stringstream` 是 C++ 标准库提供的一个类，用于在字符串和其他数据类型之间进行格式化输入和输出。它允许我们像操作文件或控制台流一样操作字符串，非常适合于字符串解析、格式化和转换。



### 6.1 `std::stringstream` 的基本概念



- **`std::stringstream`**：同时具备 `std::istringstream`（输入流）和 `std::ostringstream`（输出流）的功能，既可以从字符串中读取数据，也可以向字符串中写入数据。
- **`std::istringstream`**：仅用于从字符串中读取数据。
- **`std::ostringstream`**：仅用于向字符串中写入数据。



### 6.2 字符串与其他数据类型的转换



`std::stringstream` 常用于以下场景：



1. **将其他数据类型转换为字符串**。
2. **将字符串解析为其他数据类型**。
3. **构建复杂的字符串**。



### 6.3 示例代码



#### 6.3.1 将多个数据类型组合成一个字符串



**示例说明**：使用 `std::stringstream` 将整数、浮点数和字符串组合成一个字符串。



```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    int id = 101;
    std::string name = "Alice";
    double score = 95.5;

    std::stringstream ss;
    ss << "ID: " << id << ", Name: " << name << ", Score: " << score;

    std::string result = ss.str();
    std::cout << result << std::endl;

    return 0;
}
```



**输出**：



```yaml
ID: 101, Name: Alice, Score: 95.5
```



**解释**：



- 创建 `std::stringstream` 对象 `ss`。
- 使用 `<<` 操作符将不同类型的数据插入到流中。
- 使用 `ss.str()` 获取累积的字符串内容。



#### 6.3.2 从字符串中解析数据



**示例说明**：使用 `std::stringstream` 从一个格式化的字符串中提取数据。



```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string data = "2023 JohnDoe 85.6";
    int year;
    std::string name;
    double grade;

    std::stringstream ss(data);
    ss >> year >> name >> grade;

    std::cout << "Year: " << year << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Grade: " << grade << std::endl;

    return 0;
}
```



**输出**：



```yaml
Year: 2023
Name: JohnDoe
Grade: 85.6
```



**解释**：



- 将字符串 `data` 初始化到 `std::stringstream` 对象 `ss` 中。
- 使用 `>>` 操作符从流中提取数据，按顺序赋值给变量。



#### 6.3.3 字符串与数字的相互转换



**示例说明**：将字符串转换为整数和浮点数，以及将数字转换为字符串。



```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    // 字符串转换为整数和浮点数
    std::string numStr = "12345";
    std::string floatStr = "98.76";
    int number;
    double decimal;

    std::stringstream ss1(numStr);
    ss1 >> number;

    std::stringstream ss2(floatStr);
    ss2 >> decimal;

    std::cout << "字符串 \"" << numStr << "\" 转换为整数：" << number << std::endl;
    std::cout << "字符串 \"" << floatStr << "\" 转换为浮点数：" << decimal << std::endl;

    // 数字转换为字符串
    int num = 6789;
    double dec = 12.34;
    std::stringstream ss3;
    ss3 << num << " and " << dec;

    std::string combinedStr = ss3.str();
    std::cout << "数字转换为字符串：" << combinedStr << std::endl;

    return 0;
}
```



**输出**：



```bash
字符串 "12345" 转换为整数：12345
字符串 "98.76" 转换为浮点数：98.76
数字转换为字符串：6789 and 12.34
```



**解释**：



- 使用 `std::stringstream` 将字符串解析为数字。
- 使用 `std::stringstream` 将数字格式化为字符串。



#### 6.3.4 使用 `std::istringstream` 和 `std::ostringstream`



`std::istringstream` 和 `std::ostringstream` 是 `std::stringstream` 的专门化版本，分别用于只读和只写操作。



**示例说明**：分别使用 `std::istringstream` 读取数据，和 `std::ostringstream` 构建字符串。



```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    // 使用 std::istringstream 读取数据
    std::string input = "2023 Bob 75.5";
    int year;
    std::string name;
    double score;

    std::istringstream iss(input);
    iss >> year >> name >> score;

    std::cout << "Parsed Data:" << std::endl;
    std::cout << "Year: " << year << ", Name: " << name << ", Score: " << score << std::endl;

    // 使用 std::ostringstream 构建字符串
    std::ostringstream oss;
    oss << "Year: " << year << ", Name: " << name << ", Score: " << score;

    std::string output = oss.str();
    std::cout << "Formatted String: " << output << std::endl;

    return 0;
}
```



**输出**：



```yaml
Parsed Data:
Year: 2023, Name: Bob, Score: 75.5
Formatted String: Year: 2023, Name: Bob, Score: 75.5
```



**解释**：



- `std::istringstream` 用于从字符串 `input` 中提取数据。
- `std::ostringstream` 用于将数据格式化为字符串 `output`。



#### 6.3.5 处理复杂的字符串格式



**示例说明**：从包含逗号分隔值的字符串中提取数据。



```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string csvData = "John,25,80.5";
    std::string name;
    int age;
    double score;

    std::stringstream ss(csvData);
    std::getline(ss, name, ','); // 使用逗号作为分隔符
    ss >> age;
    ss.ignore(1); // 忽略逗号
    ss >> score;

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Score: " << score << std::endl;

    return 0;
}
```



**输出**：



```makefile
Name: John
Age: 25
Score: 80.5
```



**解释**：



- 使用 `std::getline` 从 `stringstream` 中读取以逗号分隔的字符串。
- 使用 `ignore` 忽略分隔符。



### 6.4 总结



`std::stringstream` 是一个强大的工具，适用于字符串与其他数据类型之间的转换、格式化输出和解析复杂的字符串数据。通过熟练掌握 `std::stringstream` 的使用，可以大大简化数据处理任务，提高代码的可读性和维护性。



------



## 7. 其他流操作



除了基本的读写操作，C++流还提供了许多其他功能，如错误检查、不同的读取方式、不同的打开模式等。



### 7.1 检查文件是否成功打开



在进行任何读写操作前，检查文件是否成功打开是一个好习惯。



**示例**：



```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outfile("output.txt");
    if (!outfile.is_open()) {
        std::cerr << "文件无法打开！" << std::endl;
        return 1;
    }
    // 其他操作
    outfile.close();
    return 0;
}
```



### 7.2 逐行读取 vs 逐词读取



- **逐行读取**：使用 `std::getline` 逐行读取文件内容。
- **逐词读取**：使用 `>>` 运算符逐词读取文件内容。



**示例**：



```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream infile("output.txt");
    if (!infile) {
        std::cerr << "无法打开文件。" << std::endl;
        return 1;
    }

    std::string word;
    std::cout << "逐词读取文件内容：" << std::endl;
    while (infile >> word) {
        std::cout << word << std::endl;
    }

    infile.close();
    return 0;
}
```



**输出**（假设 `output.txt` 内容如下）：



```undefined
这是第一行。
这是第二行，数字：100
浮点数：3.14159
```



**具体输出**：



```undefined
逐词读取文件内容：
这是第一行。
这是第二行，数字：100
浮点数：3.14159
```



**解释**：



- `infile >> word` 会根据空格、换行符等分隔符逐个读取单词。



### 7.3 错误处理



在文件操作中，可能会遇到各种错误情况，如文件不存在、权限不足等。通过流的状态标志可以进行相应的错误处理。



**示例**：



```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream infile("nonexistent.txt");
    if (!infile) {
        std::cerr << "错误：无法打开文件。" << std::endl;
        return 1;
    }

    // 其他操作

    infile.close();
    return 0;
}
```



**解释**：



- 如果文件 `nonexistent.txt` 不存在，程序会输出错误消息并退出。



### 7.4 追加模式



使用 `std::ios::app` 可以以追加模式打开文件，数据将被添加到文件末尾，而不是覆盖原有内容。



**示例**：



```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outfile("log.txt", std::ios::app);
    if (!outfile) {
        std::cerr << "无法打开文件进行追加写入。" << std::endl;
        return 1;
    }

    outfile << "新的一条日志记录。\n";

    outfile.close();
    std::cout << "日志已追加。" << std::endl;

    return 0;
}
```



**解释**：



- 每次运行该程序，新的日志记录都会被添加到 `log.txt` 的末尾，而不会删除之前的内容。



### 7.5 读写模式中的其他标志



- **`std::ios::binary`**：以二进制模式打开文件。
- **`std::ios::trunc`**：如果文件已存在，打开时会清空文件内容。
- **`std::ios::ate`**：打开文件并将文件指针移动到文件末尾，允许在文件末尾追加。



**示例**：



```cpp
#include <iostream>
#include <fstream>

int main() {
    // 以二进制模式写入数据
    std::ofstream outfile("binary.dat", std::ios::binary);
    if (!outfile) {
        std::cerr << "无法打开二进制文件。" << std::endl;
        return 1;
    }

    int number = 12345;
    outfile.write(reinterpret_cast<char*>(&number), sizeof(number));
    outfile.close();

    // 以二进制模式读取数据
    std::ifstream infile("binary.dat", std::ios::binary);
    if (!infile) {
        std::cerr << "无法打开二进制文件进行读取。" << std::endl;
        return 1;
    }

    int readNumber;
    infile.read(reinterpret_cast<char*>(&readNumber), sizeof(readNumber));
    std::cout << "读取的数字是：" << readNumber << std::endl;

    infile.close();
    return 0;
}
```



**输出**：



```undefined
读取的数字是：12345
```



**解释**：



- 使用 `std::ios::binary` 以二进制模式打开文件。
- `write` 和 `read` 方法用于写入和读取二进制数据。
- `reinterpret_cast<char*>` 将数据类型转换为字节流。



**注意**：



- 二进制模式适用于非文本数据，可以提高读写效率，但可读性较差。
- 在不同操作系统之间传输二进制文件时，需要注意字节序（Endianess）的问题。



### 7.6 实际应用示例



**示例说明**：读取一个文本文件，统计单词出现的次数，并将结果写入另一个文件。



```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    std::ifstream infile("input.txt");
    if (!infile) {
        std::cerr << "无法打开 input.txt 进行读取。" << std::endl;
        return 1;
    }

    std::map<std::string, int> wordCount;
    std::string word;

    // 逐词读取并统计
    while (infile >> word) {
        // 可以添加更多的处理，如去除标点符号、转换为小写等
        wordCount[word]++;
    }

    infile.close();

    std::ofstream outfile("word_count.txt");
    if (!outfile) {
        std::cerr << "无法打开 word_count.txt 进行写入。" << std::endl;
        return 1;
    }

    // 写入统计结果
    for (const auto& pair : wordCount) {
        outfile << pair.first << ": " << pair.second << std::endl;
    }

    outfile.close();

    std::cout << "单词统计已完成，结果保存在 word_count.txt 中。" << std::endl;

    return 0;
}
```



**解释**：



- 读取 `input.txt` 文件中的每个单词，并使用 `std::map` 统计每个单词出现的次数。
- 将统计结果写入 `word_count.txt` 文件中。
- 这是一个简单的文本分析工具，可以进一步扩展功能，如忽略大小写、去除标点符号等。



