#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	double n[5];
	double max;

	cout << "5개의 실수를 입력하라 >> ";

	for (int i = 0; i < 5; i++) {
		cin >> n[i];
		if (i == 0)max = n[i];
		if (n[i] > max)max = n[i];
	}
	cout << "가장 큰 수는 " << max << endl;

	/////////////////////////////////////////////////////////////////////////////////////

	char str[100];
	char find;
	int cnt = 0;

	cout << "문자들을 입력하라(100개 미만)." << endl;
	cin.getline(str, 100);
	cout << "찾으려는 문자 입력 : ";
	cin >> find;

	for (int i = 0; i < strlen(str); i++)
		if (str[i] == find) cnt++;
	cout << find << "의 개수는 " << cnt << endl;

	//////////////////////////////////////////////////////////////////////////////////////

	string name;
	string longName;
	int len = 0;

	cout << "5 명의 이름을 ','으로 구분하여 입력하시오" << endl << ">> ";
	for (int i = 0; i < 5; i++) {
		getline(cin, name, ',');
		cout << i + 1 << " : " << name << endl;
		if (name.length() > len) {
			len = name.length();
			longName = name;
		}
	}
	cout << "가장 긴 이름은 " << longName << ", 길이가 " << len << endl;

	////////////////////////////////////////////////////////////////////////////////////////////////////

	string s2;
	char op;
	int n1, n2, res;

	cout << "종료는 exit 입력하기" << endl;

	while (1)
	{
		cout << "? ";
		getline(cin, s2);
		if (s2 == "exit")break;

		int index = 0;

		index = s2.find(' '); 
		n1 = stoi(s2); 
		char op = s2[index + 1]; 

		index = (s2, index + 1);
		string sub = s2.substr(index + 1);
		n2 = stoi(sub);

		switch (op) {
		case '+':res = n1 + n2; break;
		case '-':res = n1 - n2; break;
		case '*':res = n1 * n2; break;
		case '/':res = n1 / n2; break;
		default:break;
		}
		cout << n1 << ' ' << op << ' ' << n2 << " = " << res << endl;
	}
}