#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    srand(time(NULL));          // �ð��� �������� ���� ����
    const int number = 3;       // ��� ����
    int comp_num[number] = {};  // ��ǻ�Ͱ� ���� ���� ���� �迭
    int user_num[number] = {};  // ����ڰ� ���ڸ� ���� �迭
    int strike = 0;             // ��Ʈ����ũ ���� ���� ����
    int ball = 0;               // �� ���� ���� ����
    int count = 0;              // �õ��� Ƚ���� ������ ����

    // �������� 3���� ���ڸ� �̾� comp_num �迭�� ���� (�ߺ� ����)
    for (int i = 0; i < number; i++) {
        bool found = true;
        while (found) {
            found = false;
            comp_num[i] = rand() % 9 + 1;  // 1~9 ������ ���� ����
            for (int j = 0; j < i; j++) {
                if (comp_num[j] == comp_num[i]) {
                    found = true;
                    break;
                }
            }
        }
    }

    cout << "���� �߱� ������ �����մϴ�!" << endl;
    while (true) {
        // ����ڿ��� 3���� ���� �Է� ����
        cout << "1~9 ������ ���� 3���� �Է��ϼ��� (�̿��� ����: ����)\n ";
        cin >> user_num[0] >> user_num[1] >> user_num[2];

        // �Է��� ���ڰ� 1~9 ���� ���� ������ Ȯ��
        bool valid = true;
        for (int i = 0; i < number; i++) {
            if (user_num[i] < 1 || user_num[i] > 9) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "������ �����մϴ�." << endl;
            break;
        }

        // ��Ʈ����ũ�� ���� ����
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
        cout << "���: " << strike << " ��Ʈ����ũ, " << ball << " ��" << endl;

        if (strike >= 3) {
            cout << "�����մϴ�! " << count << "ȸ���� ������ ���߼̽��ϴ�." << endl;
            break;
        }
    }
    return 0;
}