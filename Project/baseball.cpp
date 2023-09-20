#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    srand(time(NULL));          // 시간을 기준으로 난수 생성
    const int number = 3;       // 상수 선언
    int comp_num[number] = {};  // 컴퓨터가 뽑은 숫자 저장 배열
    int user_num[number] = {};  // 사용자가 숫자를 저장 배열
    int strike = 0;             // 스트라이크 개수 저장 변수
    int ball = 0;               // 볼 개수 저장 변수
    int count = 0;              // 시도한 횟수를 저장할 변수

    // 랜덤으로 3개의 숫자를 뽑아 comp_num 배열에 저장 (중복 없이)
    for (int i = 0; i < number; i++) {
        bool found = true;
        while (found) {
            found = false;
            comp_num[i] = rand() % 9 + 1;  // 1~9 사이의 난수 생성
            for (int j = 0; j < i; j++) {
                if (comp_num[j] == comp_num[i]) {
                    found = true;
                    break;
                }
            }
        }
    }

    cout << "숫자 야구 게임을 시작합니다!" << endl;
    while (true) {
        // 사용자에게 3개의 숫자 입력 받음
        cout << "1~9 사이의 숫자 3개를 입력하세요 (이외의 숫자: 종료)\n ";
        cin >> user_num[0] >> user_num[1] >> user_num[2];

        // 입력한 숫자가 1~9 범위 내의 수인지 확인
        bool valid = true;
        for (int i = 0; i < number; i++) {
            if (user_num[i] < 1 || user_num[i] > 9) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "게임을 종료합니다." << endl;
            break;
        }

        // 스트라이크와 볼의 개수
        for (int i = 0; i < number; i++) {
            if (user_num[i] == comp_num[i]) {
                strike++;
            }
            else {
                for (int j = 0; j < number; j++) {
                    if (i != j && user_num[i] == comp_num[j]) {
                        ball++;
                    }
                }
            }
        }

        count++;
        cout << "결과: " << strike << " 스트라이크, " << ball << " 볼" << endl;

        if (strike >= 3) {
            cout << "축하합니다! " << count << "회만에 정답을 맞추셨습니다." << endl;
            break;
        }
    }
    return 0;
}