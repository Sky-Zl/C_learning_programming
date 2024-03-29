#include <stdio.h>
int main()
{
    int n, m, i, s = 0;
    printf ("N M = ");
    scanf("%d%d", &n, &m);
    for (i = 2; i <= n; i++)
    {
        s = (s + m) % i;
        printf("%d\n",s);
    }
    printf ("\nThe winner is %d\n", s+1);
}

/*
约瑟夫环问题 （ 最简单的数学解法）
基本问题描述：
已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。从编号为1的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；依此规律重复下去，直到圆桌周围的人全部出列。（也类似于变态杀人狂问题）通常解决这类问题时我们把编号从0~n-1，最后结果+1即为原问题的解。通常，我们会要求输出最后一位出列的人的序号。那么这里主要研究的是最后一个出列的人的序号要怎么确定。

当n，m数据量很小的时候，我们可以用循环链表模拟约瑟夫环的过程。当模拟到人数等于1的时候，输出剩下的人的序号即可。
具体解法这种方法往往实现起来比较简单，而且也很容易理解。但是时间复杂度却是很糟糕的，达到了O（nm），这样的话，其实在n，m比较大的时候（nm达到10^8或者更大），那么要得出结果往往需要耗费很长的时间，但是我们可以运用一点数学上的技巧，将最后结果推导出来。

为了简化出列的过程：
首先我们把这n个人的序号编号从0~n-1（理由很简单，由于m是可能大于n的，而当m大于等于n时，那么第一个出列的人编号是m%n，而m%n是可能等于0的，这样编号的话能够简化后续出列的过程），当数到m-1的那个人出列，因此我们编号完成之后，开始分析出列的过程：
第一次出列：
一开始的时候，所有人的编号排成序列的模式即为：
0,1,2,3,4,5...n-2，n-1
那么第一次出列的人的编号则是(m-1)%n1，那么在第一个人出列之后，从他的下一个人又开始从0开始报数，为了方便我们设k1 = m%n1（n1为当前序列的总人数）那么在第一个人出列之后，k1则是下一次新的编号序列的首位元素，那么我们得到的新的编号序列为：
k1，k1+1，k1+2，k1+3...n-2，n-1，0，1，2...k1-3，k1-2 (k1-1第一次已出列)
那么在这个新的序列中，第一个人依旧是从0开始报数，那么在这个新的序列中，每个人报的相应数字为：
0,1，2,3....n-2
那么第二次每个人报的相应数字与第一次时自己相应的编号对应起来的关系则为：
0 --> k1
1 --> k1+1
2 --> k1+2
...
n-2 ---> (k1+n-2)%n1(n1为当前序列的总人数，因为是循环的序列，k1+n-1可能大于总人数)
那么这时我们要解决的问题就是n-1个人的报数问题（即n-1阶约瑟夫环的问题）
可能以上过程你还是觉得不太清晰，那么我们重复以上过程，继续推导剩余的n-1个人的约瑟夫环的问题：
那么在这剩下的n-1个人中，我们也可以为了方便，将这n-1个人编号为：
0,1,2,3,4...n-2
那么此时出列的人的编号则是（m-1） % n2（n2为当前序列的总人数），同样的我们设k2 = m % n2，那么在这个人出列了以后，序列重排，重排后新的编号序列为：
k2，k2+1，k2+2，k2+3...n-2，n-1，0，1，2...k2-3，k2-2 (k2-1第一次已出列)
那么在这个新的序列中，第一个人依旧是从1开始报数，那么在这个新的序列中，每个人报的相应数字为：
1,2，3,4....n-2
那么这样的话是不是又把问题转化成了n-2阶约瑟夫环的问题呢？
后面的过程与前两次的过程一模一样，那么递归处理下去，直到最后只剩下一个人的时候，便可以直接得出结果
当我们得到一个人的时候（即一阶约瑟夫环问题）的结果，那么我们是否能通过一阶约瑟夫环问题的结果，推导出二阶约瑟夫环的结果呢？
借助上面的分析过程，我们知道，当在解决n阶约瑟夫环问题时，序号为k1的人出列后，剩下的n-1个人又重新组成了一个n-1阶的约瑟夫环，那么
假如得到了这个n-1阶约瑟夫环问题的结果为ans（即最后一个出列的人编号为ans），那么我们通过上述分析过程，可以知道，n阶约瑟夫环的结果
(ans + k)%n(n为当前序列的总人数)，而k = m%n
则有：
n阶约瑟夫环的结果

(ans + m % n)%n，那么我们还可以将该式进行一下简单的化简：

当m<n时，易得上式可化简为：（ans + m）% n

而当m>=n时，那么上式则化简为：（ans % n + m%n%n）% n
即为：（ans % n + m%n）% n
而 （ans + m）% n = （ans % n + m%n）% n
因此得证
(ans + m % n)%n = （ans + m）% n
这样的话，我们就得到了递推公式，由于编号是从0开始的，那么我们可以令
f[1] = 0； //当一个人的时候，出队人员编号为0
f[n] = (f[n-1] + m)%n //m表示每次数到该数的人出列，n表示当前序列的总人数
而我们只需要得到第n次出列的结果即可，那么不需要另外声明数组保存数据，只需要直接一个for循环求得n阶约瑟夫环问题的结果即可
由于往往现实生活中编号是从1-n，那么我们把最后的结果加1即可。
*/ 
