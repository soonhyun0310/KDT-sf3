#include <ctime>
#include <iostream>

using namespace std;

// �迭 arr�� num�� �ִ��� Ȯ���ϴ� �Լ�
bool isDuplicated(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}

// ���� ������ �������� ����� ����ϰ� ����ϴ� �Լ�
void calculateRank(int count) {
    int rank = 7 - count;
    cout << "���� ����: " << count << endl;
    cout << rank << "" << endl;
}

int main() {
    srand(time(NULL));

    const int NUMBER = 6; // ��� ����
    int comp_num[NUMBER] = {};
    int user_num[NUMBER] = {};

    // ��ǻ�Ͱ� 1~45 �� �ߺ� ���� 6���� ���� �������� �����ϴ� �κ�
    for (int i = 0; i < NUMBER; i++) {
        comp_num[i] = rand() % 45 + 1;
        // �ߺ��� ���ڰ� ���õǾ��� ��� i�� ���ҽ��Ѽ� �ٽ� ������ ���� �����ϵ��� ��
        for (int j = 0; j < i; j++) {
            if (comp_num[i] == comp_num[j]) {
                i--;
                break;
            }
        }
    }

    // �÷��̾�κ��� 1~45 �� �ߺ� ���� 6���� ���� �Է¹޾� user_num �迭�� �����ϴ� �κ�
    cout << "6������ 1~45������ ���ڸ� �Է����ּ���" << endl;

    for (int i = 0; i < NUMBER; i++) {
        cout << i + 1 << "��° ���ڸ� �Է��ϼ��� : ";
        cin >> user_num[i];
        if (user_num[i] > 45 || user_num[i] < 1) {  // ���� ���� 1~45
            cout << "������ ��� �����Դϴ�. �ٽ� �Է����ּ���." << endl;
            i--;
            continue;
        }
        if (isDuplicated(user_num, i, user_num[i])) {  // �ߺ� Ȯ��
            cout << "�ߺ��� �����Դϴ�. �ٽ� �Է����ּ���." << endl;
            i--;
            continue;
        }
    }

    // comp_num�� ����� ���ڸ� ���, �÷��̾ ���� ������ ������ ���� ����� ����ϴ� �κ�
    cout << "----------------------------------------" << endl;
    cout << "�ζǹ�ȣ��÷: ";
    int count = 0;
    for (int i = 0; i < NUMBER; i++) {
        cout << comp_num[i] << " ";
        // ��ǻ�Ͱ� ������ ���ڿ� �÷��̾ ������ ���ڸ� ���Ͽ� ���� ������ ������ ī��Ʈ
        for (int j = 0; j < NUMBER; j++) {
            if (comp_num[i] == user_num[j]) {
                count++;
                break;
            }
        }
    }
    cout << endl << endl;
    calculateRank(count);

    return 0;
}