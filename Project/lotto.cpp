#include <ctime>
#include <iostream>

using namespace std;

int main() {
    srand(time(NULL));

    int comp_num[6] = {};
    int user_num[6] = {};
    int number = 6;

    // ��ǻ�Ͱ� 1~25 �� �ߺ� ���� 6���� ���� �������� ����
    for (int i = 0; i < number; i++) {
        comp_num[i] = rand() % 25 + 1;
        // �ߺ��� ���ڰ� ���õǾ��� ��� i�� ���ҽ��Ѽ� �ٽ� ������ ���� �����ϵ���
        // ��
        for (int j = 0; j < i; j++) {
            if (comp_num[i] == comp_num[j]) {
                i--;
                break;
            }
        }
    }

    // �÷��̾�κ��� 1~25 �� �ߺ� ���� 6���� ���� �Է¹޾� user_num �迭�� ����
    cout << "6������ 1~25������ ���ڸ� �Է��ض�" << endl;

    for (int i = 0; i < number; i++) {
        cout << i + 1 << "��° ���ڸ� �Է��� : ";
        cin >> user_num[i];
        if (user_num[i] > 25 || user_num[i] < 1) {  // ���� ���� 1~25
            cout << "������ ��� ����. �ٽ� �Է��ض�." << endl;
            i--;
            continue;
        }
        for (int j = 0; j < i; j++) {
            if (user_num[i] == user_num[j]) {  // �ߺ� Ȯ��
                cout << "�ߺ��� ����. �ٽ� �Է��ض�." << endl;
                i--;
                break;
            }
        }
    }

    // comp_num�� ����� ���ڸ� ���, �÷��̾ ���� ������ ������ ���� �����
    // ���
    cout << "----------------------------------------" << endl;
    cout << "��÷��ȣ: ";
    int count = 0;
    for (int i = 0; i < number; i++) {
        cout << comp_num[i] << " ";
        // ��ǻ�Ͱ� ������ ���ڿ� �÷��̾ ������ ���ڸ� ���Ͽ� ���� ������
        // ������ ī��Ʈ
        for (int j = 0; j < number; j++) {
            if (comp_num[i] == user_num[j]) {
                count++;
                break;
            }
        }
    }
    cout << endl;
    cout << endl;

    cout << "���� ����: " << count << endl;
    cout << 7 - count << "�� �Դϴ�! ���Ͽ�";

}