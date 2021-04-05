from dataclasses import dataclass, field

 

    
@dataclass(frozen=True, order=True)
class Point:
    x : float
    y : float
    
@dataclass(frozen=True, order=True)
class Points:
    data : list[Point] = field(default_factory=list )
    
    
lst = [Point(1,2), Point(2,3), Point(4,5)]
points = Points(lst)


for p in points.data:
    print(p)

    
    
