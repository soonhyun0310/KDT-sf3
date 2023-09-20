#include <iostream>
#include <cstdlib>  // rand() ����� ���� �������
#include <ctime>    // srand() ����� ���� �������

using std::cin;
using std::cout;
using std::endl;



const int MAX_NUMBER = 3;       // �Է� ������ ������ �ִ�
const int WINNING_NUMBER = 31;  // �¸��ϱ� ���� ������ �ϴ� ����

int main() {
    int currentCount = 0;
    bool win = true;         // ����
    bool isUserTurn = true;  // false: ��ǻ��, true: �����

    srand((unsigned int)time(NULL));  // rand() �Լ��� ����ϱ� ���� �� ���� ȣ��

    while (currentCount < WINNING_NUMBER) {
        int num = 0;

        if (isUserTurn) {
            cout << "1���� " << MAX_NUMBER << "������ ���ڸ� �Է��ϼ���: ";
            cin >> num;
            while (num < 1 ||
                num > MAX_NUMBER) {  // �Է°��� ��ȿ�� ���� ���� �ִ��� Ȯ��
                cout << "�߸��� �Է��Դϴ�!!\n1���� " << MAX_NUMBER
                    << "������ ���ڸ� �Է��ϼ���: ";
                cin >> num;
            }
            isUserTurn = false;
        }
        else {
            num = rand() % MAX_NUMBER + 1;
            cout << "��ǻ�� �Է�: ";
            cout << num << endl;
            isUserTurn = true;
        }

        currentCount += num;
        cout << currentCount << endl;
    }
    cout << endl;
    isUserTurn ? cout << "����: ��ǻ�Ͱ� 31�� ���ع��Ƚ��ϴ�!!\n������� �¸�!"
        : cout << "���� : ����ڰ� 31�� ���ع��Ƚ��ϴ�!!\n��ǻ���� �¸�!";

    return 0;
}