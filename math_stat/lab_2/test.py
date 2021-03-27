from dataclasses import dataclass


@dataclass
class A:
    a: int
    b: float


a = A(a=1, b=2)
print(a)
