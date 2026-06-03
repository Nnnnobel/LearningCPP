// #include <iostream>
// #include <string>

// class Entity
// {
// public:
//     int x;
// public:
//     void Print() const { std::cout << "Hello!" << std::endl; } 
//     //const 放在方法名右侧（只在类中有效），表示只读不写
// };

// class ScopedPtr
// {
// private:
//     Entity* m_Obj;
// public:
//     ScopedPtr(Entity* entity) : m_Obj(entity) {}

//     ~ScopedPtr()
//     {
//         delete m_Obj;
//     }
    
//     // Entity* GetObject() { return m_Obj; }

//     const Entity* operator->() const
//     {
//         return m_Obj;
//     }

// };

// int main()
// {
//     // Entity e;
//     // e.Print();

//     // Entity* ptr = &e;
//     // ptr -> Print();
//     // ptr -> x = 2;

//     // // Entity& entity = *ptr;  //等价于Entity& entity = e; int& b= a;
//     // // entity.Print();

//     // // (*ptr).Print();

//     const ScopedPtr entity = new Entity(); // == ScopedPtr entity(new Entity());
//     // entity.GetObject() -> Print();
//     entity -> Print();


//     std::cin.get();
// }