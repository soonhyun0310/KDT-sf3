#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string name, password;

	// 사용자에게 "이름을 입력하세요: "라는 메세지를 출력한 뒤 이름 입력받기
	cout << "이름을 입력하세요: ";
	cin >> name;

	// 사용자에게 "비밀번호를 입력하세요: "라는 메세지를 출력한 뒤 비번 입력 받기
	cout << "비밀번호를 입력하세요: ";
	cin >> password;

	// member.txt. 에서 한 줄씩 "이름"과 "비밀번호"를 검사하여,
	// 로그인 성공시 "로그인 성공" 실패시 "로그인 실패" 출력
	string fileName, filePassword;
	ifstream inputFile("member.txt");
	bool is_login = false; //로그인 성공 여부를 저장하는 변수
	while (inputFile >> fileName >> filePassword) {
		if (name == fileName && password == filePassword) {
			is_login = true;
			break;
		}
	}

	inputFile.close();

	if (is_login) {
		cout << "로그인 성공" << endl;

		string InTel, fileTel, member_tel_tmp;
		cout << "전화번호를 입력해 주세요: ";
		cin >> InTel;
		//파일을 읽어 중복 name이 있는지 확인 후 있다면 전화번호만 수정
		ifstream inputTel("member_tel.txt");

		bool is_modify = false; // 수정여부 확인 변수
		if (inputTel.fail()) {
			while (inputTel >> fileName >> fileTel) {
				if (name == fileName) { //이미 파일에 저장된 회원 member_tel_tmp에 저장
					is_modify = true;
					member_tel_tmp += fileName + " " + InTel + "\n";
				}
				else {
					member_tel_tmp += fileName + " " + fileTel + "\n";
				}
			}
		}

		//파일 쓰기 -> 회원 이름과 전화번호 저장
		ofstream outputTel;

		//member_tel.txt에 있는 회원 정보 수정
		if (is_modify) {
			outputTel.open("member_tel.txt");
			outputTel << member_tel_tmp;
		}
		//member_tel.txt에 없는 회원의 정보 추가
		else {
			outputTel.open("member_tel.txt", ios::app);
			outputTel << name + " " + InTel + "\n";
		}
		outputTel.close();
	}
	else cout << "로그인 실패";
}