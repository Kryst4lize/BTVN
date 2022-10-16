#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
// codelearn.io
/*Cho một mảng các số nguyên arr, bạn hãy chọn ra một tập gồm các phần tử trong arr sao cho giữa các phần tử trong tập này không có chữ số trùng nhau và tổng của các phần tử là lớn nhất.Sau đó trả về tổng của tập tìm được.
Ví dụ nếu arr = [22, 34, 13] thì bạn có thể chọn ra các tập con là{ 22 }, { 34 }, { 13 }, { 22, 13 }, { 22, 34 }. Lưu ý rằng{ 34, 13 } không phải là tập hợp lệ do 34 và 13 có cùng chữ số 3.

Ví dụ

Với arr = [12, 24, 35, 52] thì output là maxSum(arr) = 59.
Giải thích : từ arr có thể tạo thành các tập{ 12 }, { 24 }, { 35 }, { 52 }, { 12, 35 }, { 24, 35 }. Trong đó{ 24, 35 } là tập có tổng lớn nhất và tổng các phần tử trong tập này là 24 + 35 = 59.
Với arr = [11, 22, 33, 44] thì output là maxSum(arr) = 110.
Giải thích : 11 + 22 + 33 + 44 = 110.
Với arr = [51, 82, 34, 235] thì output là maxSum(arr) = 235.
Giải thích : tập các phần tử cần tìm là{ 235 }.
Với arr = [16, 26, 82, 55, 78] thì output là maxSum(arr) = 159.
Giải thích : tập các phần tử thỏa mãn có tổng lớn nhất là{ 26, 55, 78 } và tổng của tập này là 159. */
vector<int> maxSum(std::vector<int> arr)
{
    sort(arr.rbegin(), arr.rend());
    vector<int>data;
    for (int j = 0; j < arr.size(); j++) {
        //data
        int sum = 0;
        vector<bool>c(10);
        for (int i = j; i < arr.size(); i++) {
            //xu ly so theo thu tu
            int n = arr[i];
            vector<bool>check(10);
            while (n != 0) {
                if (c[n % 10] == 0) {
                    n /= 10;
                    check[n % 10] = 1;
                }
                else {
                    cout << n << endl;
                    break;
                }
            }
            if (n == 0) {
                for (int k = 0; k < c.size(); k++) {
                    if (check[k] == 1) {
                        c[k] = check[k];
                    }
                }
                sum += arr[i];
            }
            for (auto k : c) {
                cout << k;
            }
            cout << endl;
        }
        data.push_back(sum);
    }
    sort(data.begin(), data.end());
    return data;
}
int mainre() {
    vector<int>arr = { 12, 24, 35, 52 };
    arr = maxSum(arr);
    for (auto a : arr) {
        cout << a<<" ";
    }
    return 0;

}