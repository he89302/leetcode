### using map store input all char and sliding window to solved
> sliding window to decide left and right moving.
> this case moving right index and using meet criteria to find left index
> criteria is substring define

if map already find char
compare index and map exist index + 1 to as left location
if map not find char
then map push {char , index of input}
check return len if max before len or index of input - index + 1

