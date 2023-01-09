# CPP06_ex02

- dynamic_cast
	- 포인터는 포인터, 레퍼런스는 레퍼런스로 변환해야 한다.
	- 실행 중에 타입을 점검하여 안전한 캐스팅만 허가한다.
	- 입력값이 포인터일 때 실패할경우 반환값 : null pointer
	- 입력값이 레퍼런스일 때 실패할경우 반환값 : bad_cast (exception 처리)
	- RTTI(Run Time Type Information)의 type_info를 사용하기 때문에 가상 함수가 사용된 클래스에 한해서만 사용가능하다.
		- 클래스의 타입 관련 정보가 vtable에 같이 저장되기 때문