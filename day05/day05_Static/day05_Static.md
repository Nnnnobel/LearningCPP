# C++ 中的 `static`：The Cherno 学习笔记

你没听懂很正常，因为 `static` 不是只有一个意思。The Cherno 把它分成两期讲：

1. **Static in C++**：主要讲「函数外面的 `static`」和「函数里面的 `static`」。
2. **Static for Classes and Structs in C++**：主要讲「类里面的静态变量和静态函数」。

你现在先只记一句话：

> **`static` 的核心感觉：这个东西不再属于「一次临时使用」或「某一个具体对象」，而是被固定下来、共享下来，或限制在当前文件里。**

但它放在不同位置，作用不一样。

---

## 一、先不看 `static`：普通局部变量会怎么样？

```cpp
#include <iostream>

void Add()
{
    int x = 0;
    x++;
    std::cout << x << std::endl;
}

int main()
{
    Add();
    Add();
    Add();
}
```

输出：

```text
1
1
1
```

为什么不是 `1 2 3`？

因为每次调用 `Add()`，都会重新创建一个新的 `x`：

```text
第一次 Add()：
int x = 0;
x++;
输出 1;
函数结束，x 消失;

第二次 Add()：
int x = 0;
x++;
输出 1;
函数结束，x 消失;
```

你可以把普通局部变量想成：

> 每次进入函数，临时拿一张新的草稿纸；离开函数，草稿纸就被扔掉。

---

## 二、函数里面的 `static`：变量不会随着函数结束而消失

现在加上 `static`：

```cpp
#include <iostream>

void Add()
{
    static int x = 0;
    x++;
    std::cout << x << std::endl;
}

int main()
{
    Add();
    Add();
    Add();
}
```

输出：

```text
1
2
3
```

这里发生了什么？

```text
第一次 Add()：
static int x = 0;   // x 第一次被创建
x++;
输出 1;

第二次 Add()：
static int x = 0;   // 不会重新创建，不会重新变成 0
x++;
输出 2;

第三次 Add()：
x++;
输出 3;
```

函数内部的静态局部变量只会初始化一次；以后再次进入这个函数，会继续使用上一次留下来的那个变量。它的存储会持续到程序结束。

### 普通局部变量和静态局部变量对比

```cpp
void Normal()
{
    int x = 0;
    x++;
    std::cout << x << std::endl;
}

void Static()
{
    static int x = 0;
    x++;
    std::cout << x << std::endl;
}
```

调用：

```cpp
int main()
{
    Normal();
    Normal();
    Normal();

    Static();
    Static();
    Static();
}
```

输出：

```text
1
1
1

1
2
3
```

所以这里的 `static` 可以理解成：

> 虽然 `x` 只能在这个函数里使用，但它不会因为函数结束而被销毁。

注意两个概念：

- **作用域**：你能在哪里写出这个变量名。
- **生命周期**：这个变量能活多久。

对于：

```cpp
void Add()
{
    static int x = 0;
}
```

`x` 的作用域仍然只在 `Add()` 函数里面，但是它的生命周期变成了整个程序运行期间。

---

## 三、函数外面的普通变量：其他 `.cpp` 文件也可能访问它

假设你有两个文件。

### `Log.cpp`

```cpp
#include <iostream>

int s_Variable = 10;

void PrintVariable()
{
    std::cout << s_Variable << std::endl;
}
```

### `Main.cpp`

```cpp
#include <iostream>

extern int s_Variable;

int main()
{
    std::cout << s_Variable << std::endl;
}
```

这里的：

```cpp
extern int s_Variable;
```

意思是：

> 我知道这个变量不是在当前文件里定义的，但程序的其他地方定义了它，请让我使用它。

因此 `Main.cpp` 可以访问 `Log.cpp` 里面的 `s_Variable`。

但是这样会有一个问题：假如你在很多 `.cpp` 文件里都写了同名全局变量，就可能产生冲突。

---

## 四、函数外面的 `static`：变量只允许当前 `.cpp` 文件使用

现在把 `Log.cpp` 改成：

```cpp
#include <iostream>

static int s_Variable = 10;

void PrintVariable()
{
    std::cout << s_Variable << std::endl;
}
```

此时：

```cpp
static int s_Variable = 10;
```

意思就变成了：

> 这个变量只属于 `Log.cpp` 这个文件，不允许其他 `.cpp` 文件直接访问。

如果 `Main.cpp` 还这样写：

```cpp
extern int s_Variable;

int main()
{
    std::cout << s_Variable << std::endl;
}
```

链接时就会报错，因为 `Log.cpp` 中的 `s_Variable` 被 `static` 限制在当前文件内部了。

C++ 里，在函数外部，也就是文件范围或命名空间范围中声明的 `static` 变量或函数，具有「内部链接」：名称只能被当前翻译单元使用。你当前可以先把「翻译单元」粗略理解为「当前 `.cpp` 文件」。

### The Cherno 为什么喜欢写这种形式？

你可能看见他这样命名：

```cpp
static int s_Variable = 5;
```

开头的 `s_` 不是 C++ 语法，只是他自己的命名习惯：

```text
s_ 代表 static
```

意思是提醒自己：

> 这是一个当前文件私有的静态变量。

例如：

```cpp
// Player.cpp

static int s_PlayerCount = 0;
```

就表示这个变量用于 `Player.cpp` 内部管理，不希望其他文件直接访问。

---

## 五、函数也可以加 `static`

不只是变量，函数外面的函数也可以加 `static`。

```cpp
static void PrintMessage()
{
    std::cout << "Hello" << std::endl;
}
```

意思是：

> `PrintMessage()` 只能在当前 `.cpp` 文件里被调用，其他文件看不到它。

例如：

### `Math.cpp`

```cpp
static int Multiply(int a, int b)
{
    return a * b;
}

int Calculate(int x)
{
    return Multiply(x, 10);
}
```

这里 `Multiply()` 只是 `Math.cpp` 内部的辅助函数。其他文件不需要知道它的存在。

你可以把它理解为：

```text
static 函数 = 当前 cpp 文件内部专用函数
```

---

## 六、到这里先总结 The Cherno 第一节视频

### 1. 函数里面的 `static`

```cpp
void Function()
{
    static int x = 0;
}
```

意思：

> `x` 只能在这个函数里访问，但它只创建一次，并且会一直活到程序结束。

典型用途：记录函数被调用了多少次。

```cpp
void Visit()
{
    static int count = 0;
    count++;
    std::cout << "访问次数：" << count << std::endl;
}
```

### 2. 函数外面的 `static` 变量

```cpp
static int score = 0;
```

意思：

> `score` 只给当前 `.cpp` 文件使用，别的 `.cpp` 文件不能通过 `extern` 访问它。

### 3. 函数外面的 `static` 函数

```cpp
static void Helper()
{
}
```

意思：

> `Helper()` 只是当前 `.cpp` 文件的内部工具函数。

---

## 七、类里面的 `static`：不再属于每一个对象，而是所有对象共用

这应该是 The Cherno 下一节视频的内容，但你很快就会看到，所以直接把它讲清楚。

先看不加 `static` 的情况：

```cpp
#include <iostream>

struct Player
{
    int score = 0;
};

int main()
{
    Player a;
    Player b;

    a.score = 10;
    b.score = 20;

    std::cout << a.score << std::endl;
    std::cout << b.score << std::endl;
}
```

输出：

```text
10
20
```

这里 `a` 和 `b` 是两个不同的玩家对象。

它们各自拥有自己的 `score`：

```text
玩家 a：
    score = 10

玩家 b：
    score = 20
```

---

## 八、类里面的 `static` 变量：所有对象只有一份

```cpp
#include <iostream>

struct Player
{
    static int playerCount;
};

int Player::playerCount = 0;

int main()
{
    Player a;
    Player b;

    a.playerCount = 10;

    std::cout << a.playerCount << std::endl;
    std::cout << b.playerCount << std::endl;
}
```

输出：

```text
10
10
```

为什么？

因为：

```cpp
static int playerCount;
```

不是每个 `Player` 对象自己拥有一个，而是整个 `Player` 类型共同拥有一个。

```text
不是这样：

玩家 a：
    playerCount

玩家 b：
    playerCount

而是这样：

Player 类型公共区域：
    playerCount

玩家 a 和玩家 b 都访问同一个 playerCount
```

因此更推荐这样写：

```cpp
Player::playerCount = 10;

std::cout << Player::playerCount << std::endl;
```

而不是：

```cpp
a.playerCount = 10;
```

虽然通过对象访问通常也能编译，但会让人误以为 `playerCount` 属于 `a` 这个对象。

静态成员变量不属于某个具体对象；在整个程序中通常只有一份，可以通过 `Player::playerCount` 这种方式访问。

---

## 九、为什么要写这一行？

你可能会被这两行搞懵：

```cpp
struct Player
{
    static int playerCount;
};

int Player::playerCount = 0;
```

为什么不能只写类里面那一行？

在传统写法中：

```cpp
static int playerCount;
```

只是告诉编译器：

> `Player` 有一个共享的静态成员变量，名字叫 `playerCount`。

但它还没有真正获得一块存储空间。

所以类外还要写：

```cpp
int Player::playerCount = 0;
```

意思是：

> 现在真正定义这个变量，并且初始值为 `0`。

### 类比一下

类里面：

```cpp
static int playerCount;
```

像是登记：

> 我们班有一个公共班费账户。

类外：

```cpp
int Player::playerCount = 0;
```

像是真正开户，并存入初始金额 `0` 元。

从 C++17 开始，也可以写成：

```cpp
struct Player
{
    inline static int playerCount = 0;
};
```

这样就不需要再在类外单独定义了。

---

## 十、类里面的 `static` 函数：不需要具体对象也能调用

普通成员函数：

```cpp
struct Player
{
    int score = 0;

    void PrintScore()
    {
        std::cout << score << std::endl;
    }
};
```

使用时必须先有一个对象：

```cpp
Player a;
a.score = 10;
a.PrintScore();
```

因为 `PrintScore()` 打印的是「某一个玩家自己的分数」。

但静态函数是这样的：

```cpp
struct Player
{
    static int playerCount;

    static void PrintCount()
    {
        std::cout << playerCount << std::endl;
    }
};

int Player::playerCount = 0;
```

你可以直接：

```cpp
Player::PrintCount();
```

不需要：

```cpp
Player a;
a.PrintCount();
```

原因是：

> 静态函数不属于某一个具体对象，它属于整个 `Player` 类型。

静态成员函数调用时没有 `this` 指针，因此不能直接访问某个对象的普通成员变量。

---

## 十一、为什么静态函数不能直接访问普通成员变量？

看这个代码：

```cpp
struct Player
{
    int score = 0;

    static void PrintScore()
    {
        std::cout << score << std::endl; // 错误
    }
};
```

为什么错误？

因为 `score` 是每个对象单独拥有的：

```cpp
Player a;
a.score = 10;

Player b;
b.score = 100;
```

现在你这样调用：

```cpp
Player::PrintScore();
```

问题来了：

> 到底打印 `a.score` 还是 `b.score`？

静态函数根本不知道你指的是哪个玩家，因为调用它时没有对象。

所以静态函数可以直接访问静态变量：

```cpp
struct Player
{
    static int playerCount;

    static void PrintCount()
    {
        std::cout << playerCount << std::endl; // 正确
    }
};
```

因为 `playerCount` 本来就是所有玩家共享的，只有一份，不存在「到底访问哪个对象」的问题。

---

## 十二、拿游戏学习方向举例

假设你做一个游戏，有很多敌人：

```cpp
struct Enemy
{
    int health = 100;
};
```

`health` 不能写成 `static`，因为每个敌人血量不同：

```cpp
Enemy enemy1;
Enemy enemy2;

enemy1.health = 20;
enemy2.health = 80;
```

但「当前场景一共有多少敌人」就适合写成 `static`：

```cpp
struct Enemy
{
    int health = 100;

    static int enemyCount;

    Enemy()
    {
        enemyCount++;
    }
};

int Enemy::enemyCount = 0;
```

使用：

```cpp
int main()
{
    Enemy a;
    Enemy b;
    Enemy c;

    std::cout << Enemy::enemyCount << std::endl;
}
```

输出：

```text
3
```

这里：

```text
health
```

属于某一个具体敌人。

```text
enemyCount
```

属于整个 `Enemy` 类型，由所有敌人共享。

---

## 十三、五种 `static` 一张表看懂

| 写在哪里 | 示例 | 现在怎么理解 |
| --- | --- | --- |
| 函数里面的变量 | `static int count = 0;` | 函数结束后变量还活着，下次继续用 |
| 函数外面的变量 | `static int score = 0;` | 只给当前 `.cpp` 文件使用 |
| 函数外面的函数 | `static void Helper();` | 只给当前 `.cpp` 文件使用 |
| 类里面的变量 | `static int count;` | 所有对象共享同一个变量 |
| 类里面的函数 | `static void Print();` | 不需要对象就能调用，只能直接使用静态成员 |

---

## 十四、最应该先掌握的最小知识

先不要背「链接性」「存储期」「翻译单元」这些术语。目前先掌握下面三句话就够了：

### 第一句

```cpp
void Test()
{
    static int x = 0;
}
```

这里的 `x`：

> 只能在 `Test()` 里用，但不会因为 `Test()` 结束而消失。

### 第二句

```cpp
static int x = 0;
```

如果它写在函数外面：

> 它只给当前 `.cpp` 文件使用。

### 第三句

```cpp
struct Player
{
    static int count;
};
```

这里的 `count`：

> 不属于某一个玩家，而是所有玩家共享。

---

## 十五、小测试

看下面代码：

```cpp
#include <iostream>

struct Player
{
    int health = 100;
    static int count;

    Player()
    {
        count++;
    }
};

int Player::count = 0;

int main()
{
    Player a;
    Player b;

    a.health = 50;

    std::cout << a.health << std::endl;
    std::cout << b.health << std::endl;
    std::cout << Player::count << std::endl;
}
```

输出是什么？

答案是：

```text
50
100
2
```

原因：

```cpp
a.health = 50;
```

只修改 `a` 自己的生命值，不影响 `b`。

而：

```cpp
Player::count
```

是两个对象共享的。创建了 `a` 和 `b` 两个玩家，因此它变成 `2`。

---

## 参考资料

- The Cherno, *Static in C++*，YouTube。
- The Cherno, *Static for Classes and Structs in C++*，YouTube。
- cppreference, *Storage duration*：<https://en.cppreference.com/w/cpp/language/storage_duration>
- cppreference, *Static members*：<https://en.cppreference.com/w/cpp/language/static>
