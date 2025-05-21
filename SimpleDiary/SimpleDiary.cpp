#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 寫入日記並加密
void Write() {
    string info;
    string file_name;
    int code;

    cout << "請輸入檔案名稱: ";
    cin >> file_name;
    cout << "請輸入要寫入的資訊: ";
    cin.ignore(); // 清除 cin 剩餘換行符
    getline(cin, info);
    cout << "請輸入密碼（整數）: ";
    cin >> code;

    string content = "<<CHECK>>" + info;    //加入CHECK方便後續檢驗
    for (char& c : content) {
        c = c + 79 - code;
    }

    ofstream file(file_name, ios::binary);
    if (file) {
        file.write(content.c_str(), content.size());
        file.close();
        cout << "加密日記已儲存。\n";
    }
    else {
        cout << "檔案寫入失敗。\n";
    }
}

// 輸入密碼讀取日記
void Read() {
    string file_name;
    cout << "請輸入檔案名稱: ";
    cin >> file_name;

    ifstream file(file_name, ios::binary);
    if (!file) {
        cout << "找不到檔案，請重新輸入檔案名稱。\n";
        return;
    }

    string Content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    int userCode;
    string decoded;

    do {
        cout << "請輸入密碼（整數）: ";
        cin >> userCode;

        decoded = Content;
        for (char& c : decoded) {
            c = c - 79 + userCode;
        }

        if (decoded.substr(0, 9) == "<<CHECK>>") {
            cout << "解密成功，日記內容如下：\n";
            cout << decoded.substr(9) << endl;
            break;
        }
        else {
            cout << "密碼錯誤，請再試一次。\n";
        }

    } while (true);
}

// 主選單
int main() {
    char choice;

    do {
        cout << "\n========== 簡易日記系統 ==========" << endl;
        cout << "(1) 寫入加密日記" << endl;
        cout << "(2) 讀取解密日記" << endl;
        cout << "(3) 離開" << endl;
        cout << "請選擇功能: ";
        cin >> choice;

        switch (choice) {
        case '1':
            Write();
            break;
        case '2':
            Read();
            break;
        case '3':
            cout << "再見！" << endl;
            return 0;
        default:
            cout << "無效選項，請重新選擇。" << endl;
        }

    } while (true);
}