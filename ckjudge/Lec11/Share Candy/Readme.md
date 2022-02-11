Share Candy
-----------

### Description

<div>

You are a teacher in a kindergarten. Today you bring a bag of candies to
the class, and you want to share them with your kids. Kids all LOVE
candy! They all want as many as they can have. But for the fairness, you
have to give each kid the same number of candies. Given the total number
of candies and the number of kids, how many candies can a kid have? And
how many candies will remain?

Attention: You HAVE TO implement this logic in a function.

你是一個幼稚園老師，今天你買了一包糖糖想要分給班上的小朋友們。小朋友都愛死糖果了，所以每個人都想要儘量得到最多的糖果，但是為了公平起見，每個人分到的糖果數必須要一樣多。給定糖果的個數與小朋友的人數，請問每個人可以得到幾顆糖果呢？最後你會剩下幾顆糖果呢？

注意：你必須將以上邏輯實作在函數裏面。

</div>

### Input

The input consists of 2 integers m, n. m is the number of candies, and n
is the number of kids. Notice that 0 \< n \< m \< 100000.

### Output

Your function need to \"return\" 2 number q, r. q is the number of
candies each kid can have, and r is the number of candies remained.

### Loader Code

<div>

Your code will be judge using this program:

</div>

    #include<‍stdio.h>

    void share_candy(int m, int n, int* q, int* r);

    int main(){
        int m, n, candy_each, candy_remain;
        scanf("%d %d", &m, &n);
        share_candy(m, n, &candy_each, &candy_remain);
        printf("%d %d", candy_each, candy_remain);
        return 0;
    }

    // Your code goes here

<div>

### Sample1

#### Input

    114 28

#### Output

    4 2

</div>

<div>

### Sample2

#### Input

    500 100

#### Output

    5 0

</div>
