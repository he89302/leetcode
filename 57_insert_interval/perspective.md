### Question : given intervals and then return new interval
#### intervals = [[1, 3],[6, 9]], newIntervals = [2,5]
> start value 1 to 3
> end value 9
> for each intervals 
> interval[1] > newInterval[0]
> interval[0] > newInterval[1]

>intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval = [4,8]

```shell
foreach intervals in intervals[i].back < newInterval.front then collect interval to result, i++

foreach intervals in intervals[i].front > newInterval[0].back 
{
    newInterval.front = min(interval[0], newInterval[0]); 
    newInterval.back = max(interval[1], newInterval[1]); 
    i++;
}

push_back(newInterval);

foreach intervals in intervals[i] push intervals[i]; i++;
```
> result [ [1,2], [3,10], [12,16] ]


