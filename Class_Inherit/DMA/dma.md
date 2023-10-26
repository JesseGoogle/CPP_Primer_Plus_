# DMA (Dynamic Memory Allocation 动态内存分配)

本板块主要是演示继承是如何与动态内存分配 (new delete) 进行互动的。

例如，基类使用动态内存分配，并重新定义赋值和复制构造函数，这将会怎样影响派生类的实现呢？

这个问题取决于派生类的属性。

若派生类也使用了动态内存分配，就需要一些技巧来编写更加健壮的代码。

所以，我会设计  Base_DMA Lacks_DMA  和 Has_DMA 这三个类，详细解答上面的疑问。