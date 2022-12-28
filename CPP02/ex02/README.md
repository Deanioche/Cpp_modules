### CPP02 - ex01

float을 저장하기
float 값에 256 (1 << 8)을 곱해 roundf 로 반올림해서 int 형으로 저장
float으로 출력할 때 : 저장한 int값을 256으로 나눠 출력.
int로 출력할 때  : (int값 >> 8) 이렇게 하면 아마 소수점 이하가 잘려나가는듯.

```c++
roundf 반올림 땜에 오차가 생긴다.

f : 42.42
_fractionalBits : 8
1 << _fractionalBits : 256
f * (1 << _fractionalBits) : 10859.5
roundf(f * (1 << _fractionalBits)) : 10860
 
static_cast<float>(_fixed_point) : 10860
static_cast<float>(_fixed_point) / (1 << 8) : 42.4219
```

```c++
Fixed(1234.4321f)
이렇게 하면 float 변수에 1234.4321f가 담기게 되는데,
출력하면 1234.43만 출력된다.
그 이유는 cout의 precision (정밀도)가 6으로 되어 있기 때문에 가장 높은자리부터 6자리만 출력된다.
std::setprecision() 함수는 c++11부터 쓸수있다.


_fractionalBits : 8
1 << _fractionalBits : 256
f * (1 << _fractionalBits) : 316015
roundf(f * (1 << _fractionalBits)) : 316015

static_cast<float>(_fixed_point) : 316015
static_cast<float>(_fixed_point) / (1 << 8) : 1234.43
```