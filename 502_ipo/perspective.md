### Intution

#### Greedy

k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]

base capital and choose high profits
choosen one shell take w until k

i < n = profits.size()

k = 1
w = 0
choose 0; profits = 1 proroity_queue = [1]
w += 1

k = 2
w = 1
choose 1; profits = 2 choose 1; profits = 3  proroity_queue : [3,2]
w += 3

res = 4
