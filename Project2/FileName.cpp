#include <iostream>
#include <fstream>
#include <string>

int main() {

	std::ofstream my_file;
	my_file.open("member.txt");
	std::string arr[3][2];
	std::cout << "3���� ȸ���� ���� �̸� ��й�ȣ�� ���������� �Է��ϼ���.\n";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			std::cin >> arr[i][j];
			my_file << arr[i][j] << " ";
		}
		my_file << std::endl;
	}

	my_file.close();



	return 0;

}
