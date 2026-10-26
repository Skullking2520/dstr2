# C++ 이메일 목록 관리

연결 리스트를 활용해 받은편지함과 보낸편지함의 추가·조회·삭제·전송 흐름을 구현한 과제 코드입니다. [학교 과제 모음](https://github.com/Skullking2520/JunsooHyun_Portfolio)의 확장 버전과는 파일 구성이 다릅니다.

## 구성

[main.cpp](main.cpp)는 메뉴, `Inbox`·`Outbox`는 편지함, `EL`·`EM`은 목록과 이메일 객체를 담당합니다.

```bash
g++ -std=c++11 main.cpp Inbox.cpp Outbox.cpp EL.cpp EM.cpp -o EmailSystem
./EmailSystem
```

이 저장소 루트에서 실행합니다. 기존 `main.exe`는 과거 빌드 결과물이므로 소스를 직접 빌드하는 것을 권장합니다. 실제 메일 서버와 통신하는 프로그램은 아닙니다.
