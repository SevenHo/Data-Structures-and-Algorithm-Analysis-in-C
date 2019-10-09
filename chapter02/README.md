# Chapter 2: Algorithm Analysis

## Exercise 2.6

+ [code](./ex2.6_algorithm-1.0.c)

a.给出运行的时间分析(使用大 O)

| alg_1    | alg_2     | alg_3     | alg_4       | alg_5      | alg_6      |
| -------- | --------- | --------- | ----------- | ---------- | ---------- |
| $ O(N) $ | $O(N^2) $ | $O(N^3) $ | $$O(N^2) $$ | $$O(N^5)$$ | $$O(N^4)$$ |

*note:*

````c
/*alg_6*/
sum = 0;
for(i = 1 ; i < N ; i++)
    for(j = 1 ; j < i*i ; j++)
        if(j%i == 0)
            for(k = 0 ; k < j ; k++ )
                sum++;
````

`if` 语句最多被执行$$N^3$$次，但因为$$1<j<i^2$$,所以$$ j \% i = 0$$最多成立 $i$ 次。所以`if`语句为$$O(N^2)$$,$$k < N^2$$ ；总时间复杂度就为$$O(N^4)$$ 

----



## Exercise 2.7

+ [code](./ex2.7_algorithm-1.0.c)

| alg_1          | alg_2        | alg_3      |
| -------------- | ------------ | ---------- |
| $$O(N^2logN)$$ | $$O(NlogN)$$ | $$ O(N) $$ |

*note*:

```C
/*alg_1*/
for (int i = 0; i < length; i++)
    {
        int j = 0;
        temp = rand() % length + 1;
        while (j != i)
        {
            for (j; j < i; j++)
            {
                if (array[j] == temp)
                {
                    temp = rand() % length + 1;
                    break;
                }
            }
        }
        array[i] = temp;
    }
```

随机产生未出现的数的概率为：$$p = \frac{N-i}{N}$$ ,独立随机试验的期望次数为：$$\frac{N}{N-i}$$,则$$\sum_{i=0}^{N-i}\frac{N \cdot i}{N-i} < \sum_{i=0}^{N-i}\frac{N^2}{N-i} < N^2\sum_{i=0}^{N-i}\frac{1}{N-i}< N^2logN$$ 

---

