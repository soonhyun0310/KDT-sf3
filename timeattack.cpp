#include <ctime>
#include <iostream>

using namespace std;

int main() {
    string word = "start";
    int count = 0;

    cout << "�����ձ� ����: " << word << "\n";
    while (true) {
        // �Է� �ޱ� �� ����
        clock_t startTime = clock();

        cout << "�ܾ �Է��ϼ���: ";
        string new_word;
        cin >> new_word;

        int n = word.size();

        // ���� ���ڿ� �Է� ������ �� �� ���� Ȯ��
        bool rool = (word[n - 1] == new_word[0]);  // new_word.front() ����

        clock_t endTime = clock();
        if ((endTime - startTime) / CLOCKS_PER_SEC >= 10) {  // TimeAttack 10��
            cout << "�ð� �ʰ�!! ���� ����. \n�Է��� �ܾ� ����: " << count << "\n";
            break;
        }

        // �� �� ���� ��ġ �� ���
        if (rool) {
            word += (" --> " + new_word);

            count++;
        }

        // Ʋ�� �Է½�
        else {
            cout << "Ʋ�� �Է��Դϴ�.\n";
        }
        cout << word << endl;
    }
}