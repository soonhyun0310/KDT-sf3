#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cout << "만들고자 하는 마방진의 행 또는 열의 수를 홀수로 입력해라: ";
	cin >> n;
	while (n % 2 == 0) {
		cout << "입력한 수가 홀수가 아닙니다. 홀수로 입력해라: ";
		cin >> n;
	}
	//2차원 벡터 배열 생성
	vector<vector<int>> magicSquare(n, vector<int>(n)); // 초기화

	//1은 첫 행의 가운데에 위치한다.
	int x = n / 2; //(열의 가운데)
	int y = 0; //첫 번째 행
	magicSquare[y][x] = 1;

	for (int i = 2; i <= n * n; i++) { // i=2 부터 증가

		// 오른쪽 대각선 위로 이동
		x = x + 1;
		y = y - 1;

		if (y < 0 && x >= n) {//첫번째 행의 마지막 열에서는 우상단으로 이동하는 것이 아니라 바로 아래칸으로 이동
			y = y + 2;
			x = x - 1;
		}

		if (y < 0) { // 첫번째 행에서 우상단으로 이동할 때는 마지막 행의 다음 열로 이동
			y = n - 1; //마지막 행으로 이동
		}

		if (x >= n) {// 마지막 열에서 우상단으로 이동할 때는 첫번째 열의 이전 행으로 이동
			x = 0; // 첫번째 열로 이동
		}

		if (magicSquare[y][x] != 0) { // 우상단으로 이동하는 도중 이미 칸이 채워져 있으면 바로 아래 칸으로 이동
			y = y + 2;
			x = x - 1;
		}

		magicSquare[y][x] = i; // 값이 비어있다면 i 저장
	}

	// 마방진 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << magicSquare[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}