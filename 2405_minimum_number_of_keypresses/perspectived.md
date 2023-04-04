> input s = "abacaba"
> output : 4

> a -> set[a]
> b -> set[ab]
> a -> count(a) and res += 1 and set[a]
> c -> set[ac]
> a -> count(a) and res += 1 and set[a]
> b -> set[ab]
> a -> count(a) and res += 1 and set[a]

if res = 1 then res += 3 => res = 4

result subarray = {ab, ac, ab, a}