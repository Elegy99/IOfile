#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    // 1. 写文件 (去掉D盘和空格，直接用相对路径)
    ofstream ofile("w2.txt");
    ofile << "abcde" << endl;
    ofile << endl;
    ofile << "xd" << endl; // 别用 \xa 了，直接换行

    int i1 = 80, i2 = 110;
    cin >> i1 >> i2; // 黑窗口输入时，敲两个数字加空格

    ofile << i1 << " " << i2 << endl; // 英文双引号
    ofile.close();

    // 2. 读文件
    ifstream ifile("w2.txt"); // 读同一个文件
    if (!ifile) {
        cout << "文件打开失败" << endl;
        cin.get();
        return 1;
    }//报错防呆

    int sum = 0, value1 = 0, value2 = 0;
    string skip;

    // 跳过前面两行字母：abcde 和 xd
    ifile >> skip >> skip;

    // 读数字
    ifile >> value1 >> value2;
    sum = value1 + value2;

    cout << "data: " << value1 << ", " << value2 << endl;
    cout << "sum is: " << sum << endl;
    ifile.close();

    cin.get();
    return 0;
}