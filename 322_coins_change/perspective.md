### using dynamic program
> prepare record 1 ~ amount coin change and default value = INT_MAX
> dp[0] = 0
> sort coins
> 
> coins = {1, 2, 5}, amount = 6
> so {0, int_max, int_max, int_max, int_max, int_max, int_max}

#### i = 1
> coin = 1
> dp[1 - 1] => 0
> dp[1] = min(dp[1], dp[1 - 1] + 1) ==> 1
>
 
1. dp = {0, 1, int_max, int_max, ...}

#### i = 2
> coin = {1, 2}
> dp = {0, 1, dp[2] = min(dp[2], 1+dp[2-1, 2-2], int_max, int_max, ...}
> dp = {0, 1, 1, int_max, ...}

2. dp = {0, 1, 1, int_max, ...}

#### i = 3
> coin = {1, 2}
> dp = {0, 1, 1, dp[3] = min(dp[3], 1+dp[3-1, 3-2])}
> dp = {0, 1, 1, 2, int_max, int_max, ...}

#### i = 4
> coin = {1, 2}
> dp = {0, 1, 1, 2, dp[4-1, 4-2]}
> dp = {0, 1, 1, 2, 2, int_max, int_max, ...}

#### i = 5
> coin = {1, 2, 5}
> dp = {0, 1, 1, 2, 2, dp[5-1, 5-2, 5-5] + 1}
> dp = {0, 1, 1, 2, 2, 1}

#### i = 6
> coin = {1, 2, 5}
> dp = {0, 1, 1, 2, 2, 1, dp[6-1, 6-2, 6-5] + 1}
> return dp[amount] = 2

