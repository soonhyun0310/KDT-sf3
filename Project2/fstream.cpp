#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string name, password;

	// ����ڿ��� "�̸��� �Է��ϼ���: "��� �޼����� ����� �� �̸� �Է¹ޱ�
	cout << "�̸��� �Է��ϼ���: ";
	cin >> name;

	// ����ڿ��� "��й�ȣ�� �Է��ϼ���: "��� �޼����� ����� �� ��� �Է� �ޱ�
	cout << "��й�ȣ�� �Է��ϼ���: ";
	cin >> password;

	// member.txt. ���� �� �پ� "�̸�"�� "��й�ȣ"�� �˻��Ͽ�,
	// �α��� ������ "�α��� ����" ���н� "�α��� ����" ���
	string fileName, filePassword;
	ifstream inputFile("member.txt");
	bool is_login = false; //�α��� ���� ���θ� �����ϴ� ����
	while (inputFile >> fileName >> filePassword) {
		if (name == fileName && password == filePassword) {
			is_login = true;
			break;
		}
	}

	inputFile.close();

	if (is_login) {
		cout << "�α��� ����" << endl;

		string InTel, fileTel, member_tel_tmp;
		cout << "��ȭ��ȣ�� �Է��� �ּ���: ";
		cin >> InTel;
		//������ �о� �ߺ� name�� �ִ��� Ȯ�� �� �ִٸ� ��ȭ��ȣ�� ����
		ifstream inputTel("member_tel.txt");

		bool is_modify = false; // �������� Ȯ�� ����
		if (inputTel.fail()) {
			while (inputTel >> fileName >> fileTel) {
				if (name == fileName) { //�̹� ���Ͽ� ����� ȸ�� member_tel_tmp�� ����
					is_modify = true;
					member_tel_tmp += fileName + " " + InTel + "\n";
				}
				else {
					member_tel_tmp += fileName + " " + fileTel + "\n";
				}
			}
		}

		//���� ���� -> ȸ�� �̸��� ��ȭ��ȣ ����
		ofstream outputTel;

		//member_tel.txt�� �ִ� ȸ�� ���� ����
		if (is_modify) {
			outputTel.open("member_tel.txt");
			outputTel << member_tel_tmp;
		}
		//member_tel.txt�� ���� ȸ���� ���� �߰�
		else {
			outputTel.open("member_tel.txt", ios::app);
			outputTel << name + " " + InTel + "\n";
		}
		outputTel.close();
	}
	else cout << "�α��� ����";
}