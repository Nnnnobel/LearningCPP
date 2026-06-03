# The Cherno 智能指针这一节笔记

智能指针可以先理解成一句话：

> 智能指针就是「会自动 delete 的指针包装类」。

普通指针需要手动管理内存：

```cpp
Entity* e = new Entity();
delete e;
```

如果忘记写 `delete`，就可能造成内存泄漏。

智能指针的作用就是：**对象不需要你手动 delete，离开作用域时会自动释放。**

---

## 1. 原始指针的问题

普通写法：

```cpp
void Function()
{
    Entity* e = new Entity();

    // 做一些事情

    delete e;
}
```

这里的 `new Entity()` 是在堆上创建对象，不会自动销毁。

如果忘记 `delete`：

```cpp
void Function()
{
    Entity* e = new Entity();

    // 忘记 delete
}
```

那么这个 `Entity` 就不会被销毁，造成内存泄漏。

---

## 2. 你之前写的 ScopedPtr 其实就是智能指针雏形

```cpp
class ScopedPtr
{
private:
    Entity* m_Ptr;

public:
    ScopedPtr(Entity* ptr)
        : m_Ptr(ptr) {}

    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};
```

这个类的核心逻辑是：

```text
ScopedPtr 自己离开作用域
↓
调用 ScopedPtr 的析构函数
↓
析构函数里 delete m_Ptr
↓
堆上的 Entity 被销毁
```

所以智能指针本质上就是标准库帮我们写好了这种自动释放机制。

---

## 3. C++ 中常见的三种智能指针

C++ 标准库中常用的智能指针有三种：

```cpp
std::unique_ptr
std::shared_ptr
std::weak_ptr
```

它们都需要包含头文件：

```cpp
#include <memory>
```

---

## 4. unique_ptr：只有一个主人

`unique_ptr` 是最推荐先掌握的智能指针。

基本写法：

```cpp
std::unique_ptr<Entity> entity = std::make_unique<Entity>();
```

它的意思是：

> 创建一个 Entity 对象，并且这个对象只能由 entity 这个智能指针管理。

当 `entity` 离开作用域时，`Entity` 会自动销毁。

例如：

```cpp
{
    std::unique_ptr<Entity> entity = std::make_unique<Entity>();
}
```

执行逻辑：

```text
进入作用域
↓
创建 Entity
↓
离开作用域
↓
unique_ptr 析构
↓
自动 delete Entity
```

---

### 4.1 unique_ptr 为什么不能复制？

下面这样写是错误的：

```cpp
std::unique_ptr<Entity> e1 = std::make_unique<Entity>();

std::unique_ptr<Entity> e2 = e1; // 错误
```

原因是：

如果允许复制，就会变成：

```text
e1 指向 Entity
e2 也指向同一个 Entity
```

这样最后会出现问题：

```text
e1 要 delete 这个对象
e2 也要 delete 这个对象
```

同一个对象被释放两次，程序就可能崩溃。

所以 `unique_ptr` 的规则是：

> 一个对象只能有一个拥有者。

---

### 4.2 unique_ptr 可以转移所有权

虽然 `unique_ptr` 不能复制，但可以转移所有权：

```cpp
std::unique_ptr<Entity> e1 = std::make_unique<Entity>();

std::unique_ptr<Entity> e2 = std::move(e1);
```

意思是：

```text
原来由 e1 管理 Entity
现在转交给 e2 管理
```

转移之后，`e1` 就不再拥有这个对象了。

---

## 5. shared_ptr：可以有多个主人

`shared_ptr` 允许多个智能指针共同管理同一个对象。

基本写法：

```cpp
std::shared_ptr<Entity> e1 = std::make_shared<Entity>();
```

比如：

```cpp
std::shared_ptr<Entity> e1 = std::make_shared<Entity>();

{
    std::shared_ptr<Entity> e2 = e1;
}
```

这里的意思是：

```text
e1 管理 Entity
e2 也管理同一个 Entity
```

`shared_ptr` 内部会记录现在有多少个智能指针正在管理这个对象。

这个数量叫做：

> 引用计数

---

### 5.1 shared_ptr 的引用计数

例如：

```cpp
std::shared_ptr<Entity> e1 = std::make_shared<Entity>();
```

此时引用计数是：

```text
1
```

然后：

```cpp
std::shared_ptr<Entity> e2 = e1;
```

此时引用计数变成：

```text
2
```

当 `e2` 离开作用域后，引用计数变回：

```text
1
```

当 `e1` 也离开作用域后，引用计数变成：

```text
0
```

这时对象才会真正被销毁。

---

### 5.2 shared_ptr 的核心规则

`shared_ptr` 的核心规则是：

> 只要还有 shared_ptr 指着这个对象，对象就不会被销毁。  
> 最后一个 shared_ptr 消失时，对象才会被 delete。

所以它适合这种情况：

> 一个对象确实要被多个地方共同使用，而且你不确定谁最后用完。

---

## 6. weak_ptr：只观察，不拥有

`weak_ptr` 是三者里最抽象的。

可以先记住一句话：

> weak_ptr 只观察对象，不拥有对象。

例如：

```cpp
std::shared_ptr<Entity> shared = std::make_shared<Entity>();

std::weak_ptr<Entity> weak = shared;
```

这里的关系是：

```text
shared 拥有 Entity
weak 只是观察 Entity
```

`weak_ptr` 不会让引用计数增加。

也就是说，如果所有 `shared_ptr` 都销毁了，那么对象还是会销毁，即使还有 `weak_ptr` 存在。

---

### 6.1 为什么需要 weak_ptr？

`weak_ptr` 主要是为了解决 `shared_ptr` 的循环引用问题。

比如：

```cpp
class A
{
public:
    std::shared_ptr<B> b;
};

class B
{
public:
    std::shared_ptr<A> a;
};
```

这会导致：

```text
A 拥有 B
B 又拥有 A
```

结果就是：

```text
A：我不能死，因为 B 还指着我
B：我不能死，因为 A 还指着我
```

最后引用计数永远不会归零，对象就无法被释放。

这时通常把其中一边改成：

```cpp
std::weak_ptr<A> a;
```

意思是：

```text
B 可以知道 A
但 B 不拥有 A
```

---

## 7. 智能指针不是「指针变聪明了」

智能指针本质上是一个类对象。

比如：

```cpp
std::unique_ptr<Entity> entity;
```

这里的 `entity` 不是普通的 `Entity*`。

它是一个对象，内部包着一个真正的原始指针。

可以粗略理解成：

```cpp
class unique_ptr
{
private:
    Entity* ptr;

public:
    ~unique_ptr()
    {
        delete ptr;
    }
};
```

当然，标准库里的实现比这个复杂很多，但核心思想差不多。

---

## 8. 智能指针自己通常在栈上

例如：

```cpp
{
    std::unique_ptr<Entity> entity = std::make_unique<Entity>();
}
```

可以理解成：

```text
entity 这个智能指针对象在栈上
Entity 这个真正对象在堆上
```

当作用域结束时：

```text
栈上的 entity 自动销毁
↓
entity 的析构函数被调用
↓
析构函数销毁堆上的 Entity
```

---

## 9. 不推荐直接写 new

可以这样写：

```cpp
std::unique_ptr<Entity> entity(new Entity());
```

但更推荐这样写：

```cpp
std::unique_ptr<Entity> entity = std::make_unique<Entity>();
```

对于 `shared_ptr`，推荐这样写：

```cpp
std::shared_ptr<Entity> entity = std::make_shared<Entity>();
```

原因是：

1. 更安全；
2. 更符合现代 C++ 写法；
3. 代码更清晰；
4. 对 `shared_ptr` 来说，`make_shared` 通常也更高效。

---

## 10. 三种智能指针怎么选？

| 类型 | 什么时候用 | 记忆方式 |
|---|---|---|
| `std::unique_ptr` | 默认优先用它 | 只有一个主人 |
| `std::shared_ptr` | 多个地方都要共同拥有对象 | 多个主人 |
| `std::weak_ptr` | 只想观察，不想拥有 | 不增加引用计数 |

最重要的规则：

```text
能用 unique_ptr 就先用 unique_ptr。
真的需要共享所有权，再用 shared_ptr。
遇到 shared_ptr 循环引用，再考虑 weak_ptr。
```

---

## 11. 用之前的代码对比

原始指针写法：

```cpp
Entity* e1 = new Entity();
```

这种写法需要手动：

```cpp
delete e1;
```

否则可能造成内存泄漏。

改成智能指针：

```cpp
std::unique_ptr<Entity> e1 = std::make_unique<Entity>();
```

就不需要手动写 `delete`。

---

## 12. 完整示例

```cpp
#include <iostream>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "Entity Created!" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Entity Destroyed!" << std::endl;
    }

    void Print()
    {
        std::cout << "Hello!" << std::endl;
    }
};

int main()
{
    {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        entity->Print();
    }

    std::cin.get();
}
```

输出大概是：

```text
Entity Created!
Hello!
Entity Destroyed!
```

你会发现：

```text
代码里没有写 delete
但 Entity 还是被自动销毁了
```

这就是智能指针的意义。

---

## 13. 最简记忆版

### unique_ptr

```cpp
std::unique_ptr<Entity> e = std::make_unique<Entity>();
```

意思是：

> 创建一个 Entity，只有 e 能管它，出了作用域自动销毁。

---

### shared_ptr

```cpp
std::shared_ptr<Entity> e = std::make_shared<Entity>();
```

意思是：

> 创建一个 Entity，可以被多个 shared_ptr 一起管，最后一个不用它的时候自动销毁。

---

### weak_ptr

```cpp
std::weak_ptr<Entity> e;
```

意思是：

> 我只是看看，不负责它的生死。

---

## 14. 初学阶段重点

初学阶段不用一下子把所有细节都吃透。

重点掌握：

1. `unique_ptr` 是默认首选；
2. `shared_ptr` 是共享所有权；
3. `weak_ptr` 是观察者，不拥有对象；
4. 智能指针的核心价值是自动释放内存；
5. 尽量用 `make_unique` 和 `make_shared`，少直接写 `new`。

一句话总结：

> 智能指针不是让指针本身变聪明，而是用一个类对象把原始指针包起来，在合适的时候自动帮你 delete。
