#include<stdio.h>

/*
 *  O(1) 描述了一种算法，无论输入数据集的大小如何，它都将始终在相同的时间（或空间）执行。
 *
 *  近似伪代码，理解
 */

bool IsFirstElementNull(IList<string> elements)
{
  return elements[0] == null;
}

/*
 *  O(N) 描述了一种算法，其性能将线性增长并与输入数据集的大小成正比。
 *  下面的例子还展示了 Big O 如何支持最坏的性能场景；
 *  在 for 循环的任何迭代过程中都可以找到匹配的字符串，并且函数会提前返回，但 Big O 符号将始终假设算法将执行最大迭代次数的上限。
 *
 *  近似伪代码，理解
 */

bool ContainsValue(IEnumerable<string> elements, string value)
{
    foreach (var element in elements)
    {
        if (element == value) return true; 
    }     
    return false; 
}

/*
 *  O(N²) 表示一种算法，其性能与输入数据集大小的平方成正比。
 *  这在涉及对数据集进行嵌套迭代的算法中很常见。更深的嵌套迭代将导致 O(N³)、O(N⁴) 等。
 * 
 *  近似伪代码，理解
 * 
 */

bool ContainsDuplicates(IList<string> elements)
{
    for (var outer = 0; outer < elements.Count; outer++) 
    {
        for (var inner = 0; inner < elements.Count; inner++) 
        { 
            // Don't compare with self 
            if (outer == inner) continue;             
            
            if (elements[outer] == elements[inner]) return true; 
        }
    }    
    return false;
}

/*
 *  O(2^N) 表示一种算法，其增长随着输入数据集的每次添加而增加一倍。
 *  O(2^N) 函数的增长曲线是指数级的——从非常浅的开始，然后迅速上升。
 *  O(2^N) 函数的一个例子是斐波那契数的递归计算：
 *  
 *  近似伪代码，理解
 */

int Fibonacci(int number)
{
    if (number <= 1) return number;
       
    return Fibonacci(number - 2) + Fibonacci(number - 1); 
}

/*
 * 这种类型的算法被描述为 O(log N)。二分搜索示例中描述的数据集的迭代减半产生了一条增长曲线，该曲线在开始时达到峰值，随着数据集大小的增加而逐渐变平，
 * 例如，包含 10 个项目的输入数据集需要一秒钟才能完成，一个数据集包含 100 个项目需要两秒钟，包含 1,000 个项目的数据集需要三秒钟。
 * 将输入数据集的大小加倍对其增长几乎没有影响，因为在算法的单次迭代之后，数据集将减半，因此与输入数据集大小减半相同。这使得像二进制搜索这样的算法在处理大型数据集时非常有效。
 * 
 * 
 */
